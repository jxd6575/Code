// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: main.cpp
// Course: Computational Problem Solving II CPET.321.01-02
// Developer: Joseph DiCaro, James Paul
// Date last edited: 12/3/2019
// Description: The main menu for calling all functions
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include "carpoolfuncs.h"

using namespace std;

int main()
{
	Pickup p1(1), p2(1), p3(1);  // create the objects
	Compact c1, c2, c3;
	Sedan s1, s2, s3;
	People *head_main, *current; // create the head and current for linked lists
	resNum *resHead;
	head_main = Read();
	resHead = InitResNum(); // give pointers the head of the list returned by functions
	bool cont = true;
	int sel;
	while(cont == true)
	{
		cout << "1: Create" << endl; // menu to select
		cout << "2: Display" << endl;
		cout << "3: Modify" << endl;
		cout << "4: Delete" << endl;
		cout << "5: Print" << endl;
		cout << "6: Reservation" << endl;
		cout << "7: Quit" << endl;
		cout << "Enter 1-7 for selection: ";
		cin >> sel;
		switch(sel)
		{
		case 1:
			current = Create(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3);  // calls create and returns the current person to assign the resNum
			if(current != NULL)
			{
				Assignment(resHead, current);
			}

			break;
		case 2:
			Display(p1, p2, p3, c1, c2, c3, s1, s2, s3); // displays the list of the cars and spots in a table
			cont = true;
			break;
		case 3:
			Modify(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3); // uses delete and create functions to change the reservation without changing the resnum
			cont = true;
			break;
		case 4:
			current = Delete(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3); // deletes the resnum and makes the spot empty again while refunding points
			unAssignment(resHead, current);
			cont = true;
			break;
		case 5:
			Print(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3);  // depending on which car is selected, a text file is created showing the names of passengers
			cont = true;
			break;
		case 6:
			Reservation(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3); // this creates a text file of all passengers riding in all vehicles
			cont = true;
			break;
		case 7:
			cont = false;  // quit.. just ends it all
			break;
		default:
			cout << "Invalid input.. " << endl; // wrong input
			cont = true;
			break;
		}
		continue;
	}

}


