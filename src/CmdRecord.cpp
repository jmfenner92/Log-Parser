/*=================================================================================================
* Log Parser (CmdRecord.cpp)
* Team 5 is Roger Hoang, Stephen Casica, Jarret Fenner, Eric Lara, and RJ Kretschmar
* Assignment 6
* Session: Spring 2015
*
* This is the .cpp file for the CmdRecord class
=================================================================================================*/

#include "CmdRecord.h"

// constructor
CmdRecord::CmdRecord()
{
	line_number = "";
	address = "";
	// space for "data"
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

// Include "data" functions when way to handle data is settled...

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

std::string HexToBit (std::string hex_string)
{
	string bit_string = "";
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

CmdRecord CmdRecord::operator=(const CmdRecord &other)
{
	line_number = other.Get_Line_Number();
	address = other.Get_Address();
	// add something for data
	size = other.Get_Size();
	cycle = other.Get_Cycle();
	reltime = other.Get_RelTime();
}

