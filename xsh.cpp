// Programmers: Julie Tong and Ryan Dong

// Julie Tong's Class Account Username:
// Ryan Dong's Class Account Username: cssc3118

// Class Information: CS480, Summer 2026

// Assignment Information: Programming Assignment 2

// Filename: xsh.cpp


#include "xsh.h"
#include <vector>
#include <sstream>
#include <cstring> 

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
