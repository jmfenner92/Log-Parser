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

