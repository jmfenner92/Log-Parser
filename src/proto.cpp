#include <iostream>
#include <string>
//#include "CmdRecord.h"
#include "CmdList.h"
using namespace std;

int main()
{
	/*
	CmdRecord temp;
	temp.Set_Line_Number("1");
	temp.Set_Address("40000810");
	temp.Set_Size("0C");
	temp.Set_Cycle("Rd");
	temp.Set_RelTime("1.2s");

	cout << temp.Get_Line_Number() << " " << temp.Get_Address() << " " << temp.Get_Cycle() << " " << temp.Get_Size()
	     << " " << temp.Get_RelTime() << endl << endl;
*/
	CmdList list;

	CmdRecord temp1;
	temp1.Set_Line_Number("1");
	temp1.Set_Address("40000810");
	temp1.Set_Size("0C");
	temp1.Set_Cycle("Rd");
	temp1.Set_RelTime("1.2s");

	CmdRecord temp2;
	temp2.Set_Line_Number("2");
	temp2.Set_Address("40000810");
	temp2.Set_Size("4");
	temp2.Set_Cycle("Rd");
	temp2.Set_RelTime("1.2s");

	CmdRecord temp3;
	temp3.Set_Line_Number("3");
	temp3.Set_Address("40000810");
	temp3.Set_Size("1C");
	temp3.Set_Cycle("Rd");
	temp3.Set_RelTime("1.2s");

	list.AddRecord(&temp1);
	list.AddRecord(&temp2);
	list.AddRecord(&temp3);

	list.Display();

	list.RemoveRecord("2");

	list.Display();
	
	return 0;
} // end of main
