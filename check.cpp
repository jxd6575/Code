/*
 * check.cpp
 *
 *  Created on: Apr 22, 2020
 *      Author: Joseph DiCaro
 *      ARGUMENT ORDER WITH FUNCTION
 */

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <stdexcept>
using namespace std;

template <typename ar> // able to accept any type
int CheckOrder(ar a, ar b, ar c , ar d) // function accepting any type
// returns int depending on the order
{
	if (a > b)
	{
		if(b > c)
		{
			if(c > d)
			{
				//cout << "They are in descending order" << endl;
				return 1;
			}
		}
	}
	else if(d > c)
	{
		if(c > b)
				{
					if(b > a)
					{
						//cout << "They are in ascending order" << endl;
						return -1;
					}
				}
	}
	else
	{
		//cout << "unordered" << endl;
		return 0;

	}
	//cout << "unordered" << endl;
	return 0;
}
int main()
{
	char choice;
	int one, two, three, four, asc;
	string sone, stwo, sthree, sfour;
	char cone, ctwo, cthree, cfour;
	double done, dtwo, dthree, dfour;
	bool isaidso = true, work;
	while(isaidso)
	{
		cout << "Which type would you like to enter? Int, string, char, or double? Q for quit" << endl;
		cin >> choice;
		cin.ignore();
		choice = toupper (choice);
		switch(choice){
		case 'I':	cout << "Enter four ints" << endl; // for int
					cin >> one >> two >> three>> four;
					cin.ignore();
					asc = CheckOrder(one, two, three, four);
					work = true;
					break;
		case 'S':	cout << "Enter four strings" << endl; // for string
					cin >> sone >> stwo >> sthree>> sfour;
					cin.ignore();
					asc = CheckOrder(sone, stwo, sthree, sfour);
					work = true;
					break;
		case 'C':	cout << "Enter four chars" << endl; // for char
					cin >> cone >> ctwo >> cthree>> cfour;
					cin.ignore();
					asc = CheckOrder(cone, ctwo, cthree, cfour);
					work = true;
					break;
		case 'D':	cout << "Enter four doubles" << endl; // for doubles
					cin >> done >> dtwo >> dthree>> dfour;
					cin.ignore();
					asc = CheckOrder(done, dtwo, dthree, dfour);
					work = true;
					break;
		case 'Q':   exit(1); // exits program
					break;
		default: 	cout <<  "Nice error! lets rewind real quick" << endl;
					work = false; // congratulate for mistakes
					break;


		}
		if(work == true)
		{
			if(asc == 1) // use int to decide if its descending or not
			{
				cout << "They are in descending order" << endl;
			}
			else if(asc == -1)
			{
				cout << "They are in ascending order" << endl;
			}
			else
			{
				cout << "unordered" << endl;
			}
		}

	}

	return 0;
}


