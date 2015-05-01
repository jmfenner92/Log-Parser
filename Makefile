default: log_parser

# Compile CmdList.cpp
CmdList.o: CmdList.cpp CmdList.h
	g++ -c CmdList.cpp

# Compile CmdRecord.cpp
CmdRecord.o: CmdRecord.cpp CmdRecord.h
	g++ -c CmdRecord.cpp

# Compile log_parser.cpp
log_parser.o: log_parser.cpp CmdRecord.o CmdList.o
	g++ -c log_parser.cpp

# Link the object files into executable
log_parser: log_parser.o CmdRecord.o CmdList.o
	g++ log_parser.o CmdRecord.o CmdList.o -o log_parser
