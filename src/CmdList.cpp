#include <iostream>
#include "CmdList.h"

// constructor
CmdList::CmdList()
{
	head = NULL;
}

// destructor
CmdList::~CmdList()
{
	CmdNode *temp;
	CmdNode *current = head;

	while(current != NULL)
	{
		temp = current;
		current = current->next;
		delete temp;
	}
	
	head = NULL;
}
		
// Simple Add function that adds new record at end of the list
void CmdList::AddRecord(CmdRecord *record)
{
	CmdNode *temp = head;

	// Check if list is empty
	if(temp == NULL)
	{
		temp->info = *record;
	}
	else // list exists
	{
		// loop thru list till end
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		// add new record to end of list
		temp->info = *record;
	}
} // end of AddRecord()

// simple find function
bool CmdList::FindRecord(std::string line) const
{
	CmdNode *temp = head;
	bool	found = false;

	while(temp != NULL && !found)
	{
		if(temp->info.Get_Line_Number() == line)
		{
			found = true;
		}
		else
		{
			temp = temp->next;
		}
	}

	return found;
} // end of FindRecord()

// simple remove function
bool CmdList::RemoveRecord(std::string line)
{
	CmdNode *previous;
	CmdNode *current = head;
	bool	success = false;

	// check if list is not empty
	if(current != NULL)
	{
		if(current->next == NULL)
		{
			delete current;
			head = NULL;
			success = true;
		}
		else
		{
			while(current != NULL)
			{	
				previous = current;
				if(current->info.Get_Line_Number() == line)
				{
					previous->next = current->next;
					delete current;
					success = true;
				}
				else
				{
					current = current->next;
				}
			}
		}
	}

	return success;
} // end of RemoveRecord()
	
// simple Display function, still needs to be worked on...
void CmdList::Display() const
{
	CmdNode *temp = head;
	
	// loop thru list and display
	while(temp != NULL)
	{
		// display line number
		std::cout << temp->info.Get_Line_Number() << ": ";

		// display Read or Write
		if(temp->info.Get_Cycle() == "Wr")
		{
			std::cout << "Write ";
		}
		else
		{
			std::cout << "Read ";
		}
		
		// display command type
		if(temp->info.Get_Address() == "0x40000810")
		{
			std::cout << "S-t0-D command: ";
		}
		else
		{
			std::cout << "D-to-S command: ";
		}

		// Need to display number of words and any data...
	}
} // end of Display()
