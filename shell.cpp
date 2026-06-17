#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/wait.h>
#include <cstring> 
#include <cstdlib>

using namespace std;

// spilts input into separate arguments for execvp()
vector<char*> parseCommand(string& input) {
    vector<char*> args;
    stringstream ss(input);
    string word;

    // Split the input by spaces
    while (ss >> word) {
        // create string large enough to hold the word + 1
        char* arg = new char[word.length() + 1];

        // copy string as a char* argument
        strcpy(arg, word.c_str());

        // combine argument with argument list
        args.push_back(arg);
    }

    // add nullptr to end of argument array due to using execvp()
    args.push_back(nullptr);

    return args;
}

int main() {
    string input;

    // grab the current username from the USER environment variable
    const char* user = getenv("USER");

    // if user is nullptr, use 'xsh' as the default prompt username
    if (user == nullptr) {
        user = "xsh";
    }

    // infinite loop that keeps the shell running
    while (true) {
        cout << user << "%";
        getline(cin, input);

        // If user doesn't input anything, prompt will show up again
        if (input.empty()) {
            continue;
        }

        // 'exit' will exit break of the infinite loop and the shell
        if (input == "exit") {
            break;
        }
        
        // change user's input into an argument list
        vector<char*> args = parseCommand(input);

        // create a new process
        pid_t pid = fork();

        // If fork() returns a negative number, process creation failed
        if (pid < 0) {
            perror("fork failed");
        }

        // if fork() returns 0, code running inside child process
        else if (pid == 0) {
            // Replace the child process with the command the user typed
            if (execvp(args[0], args.data()) == -1) {
                perror("execvp failed");
            }

            exit(1);
        } 

        // if fork() returns a positive number, code is running
        else {
            // waiting for child process to finish before prompt shows up
            waitpid(pid, nullptr, 0);
        }

        // delete memory from parseCommand()
        for (char* arg : args) {
            delete[] arg;
        }
    }
    
    return 0;
}
