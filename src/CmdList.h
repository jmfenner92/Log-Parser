/*=================================================================================================
* Log Parser (CmdRecord.cpp)
* Team 5 is Roger Hoang, Stephen Casica, Jarret Fenner, Eric Lara, and RJ Kretschmar
* Assignment 6
* Session: Spring 2015
*
* This is the header file for the CmdList class
===================================================================================================*/

#include "CmdRecord.h"

struct	CmdNode
{
	CmdRecord info;
	CmdNode	*next;
};

class	CmdList
{
public:
	CmdList();
	~CmdList();
	void	AddRecord(CmdRecord *record);
	bool	RemoveRecord(std::string line);
	bool	FindRecord(std::string line) const;
	void	Display() const;
private:
	CmdNode *head;
};
