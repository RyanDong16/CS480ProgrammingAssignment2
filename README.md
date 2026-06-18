## Programmers: Julie Tong and Ryan Dong

## Julie Tong's Class Account Username: cssc3164
## Ryan Dong's Class Account Username: cssc3118

## Class Information: CS480, Summer 2026

## Assignment Information: Programming Assignment 2

## Filename: README.md


# File Structure
```
a2/
├── xsh.cpp
├── xsh.h
├── xsh
├── shell.cpp
├── shell.h
├── main.cpp
├── Makefile
└── README.md
```

# Compile Instructions
- To compile the program, run the listed command from the project directory 
- Using the Makefile
   ~/a2/$ make
- Running the executable file
   ~/a2/$ ./xsh
- Entering xsh shell
   csscXXXX%

# Operating instructions
To run the program, use the following command from inside the a2 directory: ./xsh
- Valid inputs:
    exectuablefilename (ie. ls)
        executablefilename argument (ie. ls -la)
        executablefilename | executablefilename (ie. ls | sort)
        executablefilename | executablefilename | executablefilename (ie. ls -la | sort | grep xsh.cpp)
        exit
    The shell rejects invalid formats, including commands with too many arguments,
    pipes at the beginning or end of the line, double pipes, and exit with extra words.


# List/ description of novel/ significant design decisions
- The main.cpp file, it acts as the table of content for the other files
- The xsh.cpp and xsh.h takes in the input, checks if it's a valid input, and parses the input
- The shell.cpp runs the commands that are inputed into our custom shell


# list/ description of any extra features/ algorithms/ functionality you included which were not required
- We didn't ultilize any extra features that were not required.


# List/ description of all known deficiencies or bugs
- Our submitted programming assignment 2 does not have any know deficiencies or bugs to our knowledge.


# Lessons Learned
- We learned how to create our own experimental shell
- Learned how to implement the pipe function to our custom shell
- Learned how to separate functions and code into separate files other than having all the code in one main file
- Learned how to adjust the Makefile for a different project
