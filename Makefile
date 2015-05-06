# Makefile for Team 5's Final Project CPSC 254, Spring 2016

all: log_parser

# link the object files into executable
log_parser: log_parser.o CmdRecord.o CmdList.o
	g++ log_parser.o CmdRecord.o CmdList.o -o bin/log_parser
	rm *.o

# compile log_parser.cpp
log_parser.o: CmdRecord.o CmdList.o
	g++ -c src/log_parser.cpp

# compile CmdRecord.cpp
CmdRecord.o: 
	g++ -c src/CmdRecord.cpp

# compile CmdList.cpp
CmdList.o: 
	g++ -c src/CmdList.cpp

