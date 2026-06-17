# CXX Make variable for compiler
CXX=g++
CXXFLAGS= -c

# object files
#OBJS = main.o xsh.o
OBJS = shell.o 

# Program name
PROGRAM = xsh

$(PROGRAM) : $(OBJS)
	$(CXX) -o $(PROGRAM) $^

#xsh.o : xsh.cpp xsh.h
#	$(CXX) $(CXXFLAGS) xsh.cpp
#main.o : main.cpp 
#	$(CXX) $(CXXFLAGS) main.cpp

shell.o : shell.cpp
	$(CXX) $(CXXFLAGS) shell.cpp	
clean :
	rm -f *.o $(PROGRAM)

