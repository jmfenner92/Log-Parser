/*=================================================================================================
* Log Parser (log_parser.cpp)
* Team 5 is Roger Hoang, Stephen Casica, Jarret Fenner, Eric Lara, and RJ Kretschmar
* Assignment 6
* Session: Spring 2015
*
* This is the main driver for the Log Parser. Yay!
=================================================================================================*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cmath>
#include "CmdList.h"

using namespace std;

// define macros for readability of the desired columns and commands
#define RELTIME 3
#define ADDRESS 7
#define DATA 8
#define SIZE 9
#define CYCLE 10
#define ENDLINE 14

#define CMD1 "0x40000810"
#define CMD2 "0x40000C18"

// global variables
int line_count = 0;
int total_time = 0;

// function prototypes
void dataCollection(CmdRecord*, ifstream&, int&);
int lookAndAdd(string, int, int);
float timeConverter(string);

int main(int argc, char** argv) {

	// check the number of arguments. it should be 2: one for the name of the program and 
	// one for the log file to be read in
	if (argc != 2) {
		cerr << "Invalid number of arguments!" << endl;
		cerr << "Usage: ./log_parser.cpp <log file>" << endl;
		exit(-1);
	}

	// open the file for reading and check for success
	ifstream log_file = open(argv[1]);
	if (!log_file) {
		cerr << "File failed to open. Are you sure it exists?" << endl;
		exit(-1);
	}

	/* 
	** Okay, real talk...
	** We set up a temp_record variable of type CmdRecord to start collecting the data for the
	** record to be put into the list. If we see one the the addresses that we need, we can
	** insert the record at the end of the record loop. If it's not, then just keep moving on.
	** TODO: this might be better as a function. 
	*/
	

	// now that we're in the clear, let's define some useful variables
	string curr_field = "";
	int counter = 0;
	int field_counter = 0;
	string temp_data = "";
	string past_time = "";

	// we also have to set up a new command list, and a temporary record collector
	CmdList commands;
	CmdRecord temp_record;

	// do a getline() to remove the header and fire up the record collection loop
	log_file.getline();
	while(log_file >> curr_field) {
		field_counter++;

		if (field_counter == RELTIME) {
			// we have the Rel Time field value
			temp_record.Set_RelTime(curr_field);

		} else if (field_counter == ADDRESS) {
			// we have the Address field value
			temp_record.Set_Address(curr_field);

		} else if (field_counter == DATA) {
			// we have the Data field value (this is special if it's in the address of
			// a command we want, so set it aside for later)
			temp_data = curr_field;

		} else if(field_counter == SIZE) {
			// we have the Size field value
			temp_record.Set_Size(curr_field);

		} else if(field_counter == CYCLE) {
			// we have the Cycle field value
			temp_record.Set_Cycle(curr_field);

		}

		// if the field_counter is 14, that means we've hit the end of a line. this is
		// where decision making comes in. two things can happen here: if it's not a 
		// record want (the easist), we reset the field_counter and increment the 
		// line_count. if it's a record we want, we do the above and calculate the size
		// of the data, and then enter the data collection loop.
		if (field_counter == ENDLINE) {
			if (temp_record.Get_Address() == CMD1 || 
				temp_record.Get_Address() == CMD2) {
				// set the line number and past time (which is the time for the 
				// current command)
				temp_record.Set_Line_Number(line_count);
				temp_record.Set_RelTime(past_time);

				// pass the current node and the ifstream to the dataCollection 
				// function to keep this from getting cluttered
				dataCollection(curr_record, log_file);

				// add it to the command list
				commands.AddRecord(curr_record);
			}
			
			// this happens every time we reach the end of a line
			past_time = temp_record.reltime;
			field_counter = 0;
			line_count++;
		}  

	}


	return 0;
}

void dataCollection(CmdRecord* curr_record, ifstream& log_file) {
	// find the length in words of the command data
	int length = (hexToDec(curr_record.Get_Size()) / 4)
	int field_counter = 0;

	for (int i = 0; i < length; i+=2)  {
		log_file >> curr_field
		field_counter++;

		if (field_counter == DATA) {
			// we have the Data field value (this is special if it's in the address of
			// a command we want, so set it aside for later)
			curr_node->curr_record.Set_Data(i, curr_field.substr(0,4);
			curr_node->curr_record.Set_Data(i+1, curr_field.substr(4,4));
		} else if (field_counter == ENDLINE) {
			field_counter = 0;
			line_count++;
		}

	// curr_record.Set_Total_Words(length);
	return;
}

//given a bitstring, return the decimal value of the given range
int lookAndAdd(string bitString, int startRange, int endRange) {
	int result = 0;
	string str = bitString.substr(startRange, endRange-startRange);
	int powerCounter = len(str) - 1;
	int indexCounter = 0;
	while(powerCounter != -1){
			if(str[indexCounter] == '0') {
				indexCounter++;
				powerCounter--;			
			}
			else {
				result += exp2(powerCounter)
				indexCounter++;
				powerCounter--;
			}
	}
	return result;
}

//convert us and ns to s
float timeConverter(string timeString) {
	string str = timeString.substr(0, len(timeString) - 2);
	float result = atof(str.c_str());
	string time = timeString.substr(len(timeString) - 2, 2);
	if(time == "us")
		return pow(result, -6);
	else if (time == "ns")
		return pow(result, -9);
}
	
	
	
	
