/*=================================================================================================
* Log Parser (CmdRecord.h)
* Team 5 is Roger Hoang, Stephen Casica, Jarret Fenner, Eric Lara, and RJ Kretschmar
* Assignment 6
* Session: Spring 2015
*
* This is the header file for the CmdRecord class
=================================================================================================*/

#ifndef CMDRECORD_H
#define CMDRECORD_H
#include <stdlib.h>
#include <string>
#include <vector>

// This class is used to store the various pieces of information from the log file.
class CmdRecord
{
public:
	CmdRecord();
	//~CmdRecord;
	void	Set_Line_Number(std::string);
	std::string	Get_Line_Number() const;
	void	Set_Address(std::string);
	std::string	Get_Address() const;
	void Set_Data(int, std::string);
	std::vector<std::string> Get_Data() const;
	void Set_Total_Words(int);
	int Get_Total_Words() const;
	void	Set_Size(std::string);
	std::string	Get_Size() const;
	void	Set_Cycle(std::string);
	std::string	Get_Cycle() const;
	void	Set_RelTime(std::string);
	std::string  Get_RelTime() const;
    std::string HexToBit(std::string);
    int HexToDec(std::string);
	std::string LookUpTable(int word, int bit_value);
	CmdRecord& operator=(const CmdRecord &other);

private: // All data members are assumed to be strings
	std::string line_number;
	std::string address;
	std::vector<std::string> data; // turned into a vector
	std::string size;
	std::string cycle;
	std::string reltime;
	int wordsLength;
    //std::string total_words;
}; // end of CmdRecord class

#endif
