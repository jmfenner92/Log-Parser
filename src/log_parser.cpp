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
// TODO: add the team's headers later

using namespace std;

// define macros for readability of the desired columns and commands
#define RELTIME 3
#define ADDRESS 7
#define DATA 8
#define SIZE 9
#define CYCLE 10
#define ENDLINE 14

// TODO: make this strings? ...or use hex?
#define CMD1 0x40000810
#define CMD2 0x40000C18

// global variables
int line_count = 0;

// function prototypes
void dataCollection(CmdRecord*, ifstream&);
int lookAndAdd(string, int, int);

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
	CmdRecord temp_record;
	Node* curr_node = new Node; // TODO: head of the linked list. work on this later.

	// do a getline() to remove the header and fire up the record collection loop
	log_file.getline();
	while(log_file >> curr_field) {
		field_counter++;

		if (field_counter == RELTIME) {
			// we have the Rel Time field value
			temp_record.reltime = curr_field;

		} else if (field_counter == ADDRESS) {
			// we have the Address field value
			temp_record.address = curr_field;

		} else if (field_counter == DATA) {
			// we have the Data field value (this is special if it's in the address of
			// a command we want, so set it aside for later)
			temp_data = curr_field;

		} else if(field_counter == SIZE) {
			// we have the Size field value
			temp_record.size = curr_field;

		} else if(field_counter == CYCLE) {
			// we have the Cycle field value
			temp_record.cycle = curr_field;

		}

		// if the field_counter is 14, that means we've hit the end of a line. this is
		// where decision making comes in. two things can happen here: if it's not a 
		// record want (the easist), we reset the field_counter and increment the 
		// line_count. if it's a record we want, we do the above and calculate the size
		// of the data, and then enter the data collection loop.
		if (field_counter == ENDLINE) {
			if (temp_record.address == CMD1 || temp_record.address == CMD2) {
				// calculate the size of the data, and loop through to collect
				// the subsequent lines and put them into the data array
				temp_record.line = line_count;

				// make a new record, populate it with the information, and
				// add it to the linked list
				Node* new_node = new Node();
				curr_node.next_ptr = new_node;
				// make new_node the position that our pointer is pointing to
				new_node = curr_node;

				// pass the current node and the ifstream to the dataCollection 
				// function to keep this from getting cluttered
				dataCollection(curr_node, log_file);

				// TODO:
				// copy constructor?
				// new_node->record = curr_record;
				// ...or regular instaniation? (maybe with a constructor that can
				// set all the values 
				// new_node->record = new CmdRecord();
			}
			
			// this happens every time we reach the end of a line
			field_counter = 0;
			line_count++;
		}  

	}


	return 0;
}

void dataCollection(CmdRecord* curr_node, ifstream& log_file, int field_counter) {
	// TODO: compute the size of the data

	while(/* not at end of data */) {
		log_file >> curr_field
		field_counter++;

		if (field_counter == DATA) {
			// TODO: fill this out more

			// we have the Data field value (this is special if it's in the address of
			// a command we want, so set it aside for later)
			curr_node->CmdRecord.data[i] = curr_field;
		}
}

//given a bitstring, return the decimal value of the given range
int lookAndAdd(string bitString, int startRange, int endRange) {
	int result = 0;
	str = bitString.substr(startRange, endRange-startRange);
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

