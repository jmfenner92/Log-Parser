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
bool CmdList::AddRecord(CmdRecord record)
{
	// declare and initialize necessary variables
	CmdNode *current = head;
	CmdNode *temp_node;
	bool success = false;

	// initialize new Cmd_Node
	temp_node = new CmdNode;
	temp_node->info = record;
	temp_node->next = NULL;

	// check if list is empty
	if(head == NULL)
	{
		head = temp_node;
		success = true;
	}
	else // otherwise, loop till end and add new node
	{
		while(current->next != NULL)
		{
			current = current->next;
		}
		current->next = temp_node;
		success = true;
	}
	
	return success;	
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
			while(current != NULL && !success)
			{	
				if(current->info.Get_Line_Number() == line)
				{
					previous->next = current->next;
					delete current;
					success = true;
				}
				else
				{
					previous = current;
					current = current->next;
				}
			}
		}
	}

	return success;
} // end of RemoveRecord()

// used for testing...
void CmdList::PrintList() const
{
	CmdNode *current = head;

	while(current != NULL)
	{
		std::cout << current->info.Get_Line_Number() << ": " << current->info.Get_Address() << "\n";
		current = current->next;
	}
} // end of PrintList()

// simple Display function, still needs to be worked on...
void CmdList::Display() const
{
	CmdNode *temp = head;
	
	// loop thru list and display
	while(temp != NULL)
	{
		// display line number
		std::cout << temp->info.Get_Line_Number() << ": " << current->info.Get_Address() << "\n"

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
            std::cout << "S-to-D command: " << current->info.Get_Total_Words << " words" << endl;
		}
		else
		{
            std::cout << "D-to-S command: " << current->info.Get_Total_Words << " words" << endl;
		}
        
        while ()  //is this right im not sure, what arg shall this while loop take
        {
            //cout << "Line" << current->info.Get_Line_Number() << " : " << info.LoopUpTable(data_address,bit_string)<< endl;
        }
        //Display number of words
        //std::cout << info.Get_Total_Words << " words" << endl;

		//Display data...
        
        //while loop?
        {
            //Display line number for individual word commands
		    //std::cout << temp->info.Get_Line_Number() << ": ";
            //Display word number (i.e. Word 41:)
            //std::cout << " Word " <<  WORD NUMBER << ": ";
            //std::cout << COMMAND << endl;
        }
        
        //create blank line for next command
        //std::cout << endl;
	}
} // end of Display()





