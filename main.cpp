// Programmers: Julie Tong and Ryan Dong

// Julie Tong's Class Account Username:
// Ryan Dong's Class Account Username: cssc3118

// Class Information: CS480, Summer 2026

// Assignment Information: Programming Assignment 2

// Filename: main.cpp

#include <iostream>
#include <vector>
#include <string>
#include <unistd.h>
#include <sys/wait.h>

#include "xsh.h"

using namespace std;

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
