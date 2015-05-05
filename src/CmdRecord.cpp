/*=================================================================================================
* Log Parser (CmdRecord.cpp)
* Team 5 is Roger Hoang, Stephen Casica, Jarret Fenner, Eric Lara, and RJ Kretschmar
* Assignment 6
* Session: Spring 2015
*
* This is the .cpp file for the CmdRecord class
=================================================================================================*/

#include <string>
#include "CmdRecord.h"
#include <sstream>

// Taken from http://stackoverflow.com/questions/12975341/to-string-is-not-a-member-of-std-says-so-g
//in order to fix a bug in to_string. Apparently there needs to be an offical patch? Strange....
namespace patch
{
    template < typename T > std::string to_string( const T& n )
    {
        std::ostringstream stm ;
        stm << n ;
        return stm.str() ;
    }
}

// constructor
CmdRecord::CmdRecord()
{
	line_number = "";
	address = "";
	//data [100];
	std::vector<std::string>(100);
	size = "";
	cycle = "";
	reltime = "";
}

// destructor getting error...
//CmdRecord::~CmdRecord()
//{
//}

// All sets and gets for CmdRecord, can add proper documentation later
void CmdRecord::Set_Line_Number(std::string number)
{
	line_number = number;
}

std::string CmdRecord::Get_Line_Number() const
{
	return line_number;
}

void CmdRecord::Set_Address(std::string new_address)
{
	address = new_address;
}

std::string CmdRecord::Get_Address() const
{
	return address;
}

void CmdRecord::Set_Data(int index,std::string new_data)
{
	data.push_back(new_data);
}

std::vector<std::string> CmdRecord::Get_Data() const
{
	return data;
}


void CmdRecord::Set_Size(std::string new_size)
{
	size = new_size;
}

std::string CmdRecord::Get_Size() const
{
	return size;
}

void CmdRecord::Set_Cycle(std::string new_cycle)
{
	cycle = new_cycle;
}

std::string CmdRecord::Get_Cycle() const
{
	return cycle;
}

void CmdRecord::Set_RelTime(std::string time)
{
	reltime = time;
}

std::string CmdRecord::Get_RelTime() const
{
	return reltime;
}

void CmdRecord::Set_Total_Words(int length)
{
	int wordsLength = length;
}
int CmdRecord::Get_Total_Words() const
{
	return wordsLength;
}
std::string CmdRecord::HexToBit(std::string hex_string)
{
	std::string bit_string = "";
	for (int i=0; i < hex_string.length(); ++i)
	{
		switch (hex_string [i])
		{
			case '0': bit_string.append ("0000"); break;
			case '1': bit_string.append ("0001"); break;
			case '2': bit_string.append ("0010"); break;
			case '3': bit_string.append ("0011"); break;
			case '4': bit_string.append ("0100"); break;
			case '5': bit_string.append ("0101"); break;
			case '6': bit_string.append ("0110"); break;
			case '7': bit_string.append ("0111"); break;
			case '8': bit_string.append ("1000"); break;
			case '9': bit_string.append ("1001"); break;
			case 'A': bit_string.append ("1010"); break;
			case 'B': bit_string.append ("1011"); break;
			case 'C': bit_string.append ("1100"); break;
			case 'D': bit_string.append ("1101"); break;
			case 'E': bit_string.append ("1110"); break;
			case 'F': bit_string.append ("1111"); break;
		}
	}
	return bit_string;
}

int CmdRecord::HexToDec (std::string hex_string)
{
	return (int)strtol(hex_string.c_str(),0,16);
}

// This is the lookup table in a function as suggested, returns a 
// string to be printed to stdout
std::string CmdRecord::LookUpTable(int word, int bit_value)
{
	// declare necessary variables
	std::string printString = "";

	// switch over word number, then, possibly bit_value
	// while assembling printString
	switch(word)
	{
	case 0:
	{
		printString += "Word 0: Rec_Ctrl = ";
		switch(bit_value)
		{
		case 0: printString += "0 (no recording)"; break;
		case 2: printString += "2 (no processing)"; break;
		case 3: printString += "3 (processing & recording)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}	
	case 1:
	{
		printString += "Word 1: Cmd_Type = ";
		switch(bit_value)
		{
		case 4: printString += "4 (Type A)"; break;
		case 5:	printString += "5 (Type B)"; break;
		case 6: printString += "6 (Type C)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 4:
	{
		printString += "Word 4: Rec_Raw = ";
		switch(bit_value)
		{
		case 0: printString += "0 (disable)"; break;
		case 1: printString += "1 (enable)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 5: printString += "Word 5: Cmd_ID = " + patch::to_string(bit_value); break;
	case 10: printString += "Word 10: Num_Responses = " + patch::to_string(bit_value); break;
	case 15:
	{
		printString += "Word 15: Reset_Enable = ";
		switch(bit_value)
		{
		case 0: printString += "0 (disable)"; break;
		case 1: printString += "1 (enable)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 22:
	{
		printString += "Word 22: Direction = ";
		switch(bit_value)
		{
		case 0: printString += "0 (Right)"; break;
		case 1: printString += "1 (Left)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}	
	case 32: printString += "Word 32: Num_Samples = " + patch::to_string(bit_value); break;
	case 37:
	{
		printString += "Word 37: Parity = ";
		switch(bit_value)
		{
		case 0: printString += "0 (even)"; break;
		case 1: printString += "1 (odd)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 38:
	{
		printString += "Word 38: Test = ";
		switch(bit_value)
		{
		case 0: printString += "0 (disable)"; break;
		case 1: printString += "1 (enable)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 40:
	{
		printString += "Word 40: Ctrl_Enable = ";
		switch(bit_value)
		{
		case 0: printString += "0 (disable)"; break;
		case 1: printString += "1 (enable)"; break;
		default: printString += patch::to_string(bit_value) + " (unknown)"; break;
		}
		break;
	}
	case 41: printString += "Word 41: Code = " + patch::to_string(bit_value); break;
	default: printString += "Error has occurred in lookup"; break;
	}
	// attach endline to string?
	printString += "\n";
	
	return printString;

} // end of printString()

CmdRecord& CmdRecord::operator=(const CmdRecord &other)
{
	line_number = other.Get_Line_Number();
	address = other.Get_Address();
	data = other.Get_Data();
	size = other.Get_Size();
	cycle = other.Get_Cycle();
	reltime = other.Get_RelTime();
	return *this;
}

