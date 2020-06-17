// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: carpoolfuncs.cpp
// Course: Computational Problem Solving II CPET.321.01-02
// Developer: Joseph DiCaro, James Paul
// Date last edited: 12/3/2019
// Description: Has all the functions required for this
// project including a few extra
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

resNum *InitResNum() // creates the resNum linked list and returns the head
{
	resNum *head, *current;
	current = new resNum;
	head = current;
	for(int i = 0; i < 24; i++)
	{
		current->avail = true;
		if(i == 23)
		{
			current->nextaddr = NULL;
		}
		else
		{
			current->nextaddr = new resNum;
			current = current->nextaddr;
		}
	}
	return head;
}

void Assignment(resNum *head, People *person) // assigns the resNum to the person who is brought in as an argument
{
	resNum *current;
	current = head;
	int i = 0;

	while(current->avail == false)
	{
		current = current->nextaddr;
		i++;
	}

	current->avail = false;
	person->resNum = i;
	cout << "Reservation Number : " << i << endl;

}

void unAssignment(resNum *head, People *person) // takes away the resNum
{
	resNum *cur;
	cur = head;
	int i = 0;
	while(i < person->resNum) // the number of the resnum is how many nodes away it is
	{
		cur = cur->nextaddr;
		i++;
	}
	cur->avail = true;  // changes the availability to true
	person->resNum = 99; // puts their resNum to 99 as an invalid number which essentially deletes it.
	cout << "Reservation Number Unassigned" << endl;

}


void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3)
{
	cout << "============================================================================================" << endl;
	cout << "         Pickup                          Compact                           Sedan" << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "           P1                               C1                              S1" << endl;
	cout << "          -----                            -----                           -----" << endl;
	cout << "Location  value  #available      Location  value  #available     Location  value  #available" << endl;
	cout << "--------  -----  ----------      --------  -----  ----------     --------  -----  ----------" << endl;
	cout << " Front      5     " << p1.spotsLeft << "               Front      5     " << c1.frontSeats << "              Front      5     " << s1.frontSeats << endl;
	cout << "                                  Back       3     " << c1.backSeats  <<  "              BackM      1     " << s1.backMid << endl;
	cout << "                                                                  BackW      2     " << s1.backWin << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "           P2                               C2                              S2" << endl;
	cout << "          -----                            -----                           -----" << endl;
	cout << "Location  value  #available      Location  value  #available     Location  value  #available" << endl;
	cout << "--------  -----  ----------      --------  -----  ----------     --------  -----  ----------" << endl;
	cout << " Front      5     " << p2.spotsLeft << "               Front      5     " << c2.frontSeats << "              Front      5     " << s2.frontSeats << endl;
	cout << "                                  Back       3     " << c2.backSeats  <<  "              BackM      1     " << s2.backMid << endl;
	cout << "                                                                  BackW      2     " << s2.backWin << endl;
	cout << "--------------------------------------------------------------------------------------------" << endl;
	cout << "           P3                               C3                              S3" << endl;
	cout << "          -----                            -----                           -----" << endl;
	cout << "Location  value  #available      Location  value  #available     Location  value  #available" << endl;
	cout << "--------  -----  ----------      --------  -----  ----------     --------  -----  ----------" << endl;
	cout << " Front      5     " << p3.spotsLeft << "               Front      5     " << c3.frontSeats << "              Front      5     " << s3.frontSeats << endl;
	cout << "                                  Back       3     " << c3.backSeats  <<  "              BackM      1     " << s3.backMid << endl;
	cout << "                                                                  BackW      2     " << s3.backWin << endl;
	cout << "============================================================================================" << endl;
}

People *Read()
{
	ifstream inFile;
	inFile.open("seat_credits.txt"); // file to read

	if (inFile.fail()) // fails to open file
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	People *current, *head;

	current = new People;
	head = current;
	bool loop = true;

	do // gets the data from the file
	{
		getline(inFile, current->name);
		inFile >> current->points; inFile.ignore();


		if (inFile.eof()) // when the file is over the nextaddr is null
		{
			current->nextaddr = NULL;
			break;
			loop = false;
		}
		else
		{
			current->nextaddr = new People;
			current = current->nextaddr;
		}
	}
	while (loop == true);

	inFile.close();

	return (head);

}

People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3) // creates the assignment
{
	People *current;
	bool cont = true;
	bool cont2 = true;
	bool veh = true;
	char sel, sel1, sel2, sel4;
	int sel3;   // selection of catagory or specific seat
	current = head_main;
	string pass; // name of passenger
	cout << "Enter the passengers name to create reservation: ";
	cin.ignore();
	getline(cin, pass);
	do{
		if(current->name == pass)
		{
			cont = false;
			cout << "Name found" << endl;
			cout << "You have " << current->points << " credits." << endl;
			if(current->points == 0)
			{
				cout << "You have no credits to spend.";
				break;
			}


			Display(p1, p2, p3, c1, c2, c3, s1, s2, s3);

			do{
			cout << "Select seat by (c)ategory or choose a (s)pecific seat: ";
			cin >> sel;
			sel = toupper(sel);
			switch(sel)
		{
			case 'C':
				do{
					cout << "(F)ront seat or (B)ack seat.. ";
					cin >> sel1;
					sel1 = toupper(sel1);
					switch(sel1)
					{
					case 'F':
						if(current->points < 5)
						{
							cout << "sorry you do not have enough to choose this option.." << endl;
						}
						else
						{
							if(p1.spotsLeft == 1)
							{
								current->points = current->points - 5;
								current->car = "p1";
								current->seat = "front";
								p1.spotsLeft = 0;
								cont2 = false;
							}
							else if(p2.spotsLeft == 1)
							{
								current->points = current->points - 5;
								current->car = "p2";
								current->seat = "front";
								p2.spotsLeft = 0;
								cont2 = false;
							}
							else if(p3.spotsLeft == 1)
							{
								current->points = current->points - 5;
								current->car = "p3";
								current->seat = "front";
								p3.spotsLeft = 0;
								cont2 = false;
							}
							else if(c1.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "c1";
								current->seat = "front";
								c1.frontSeats = 0;
								cont2 = false;
							}
							else if(c2.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "c2";
								current->seat = "front";
								c2.frontSeats = 0;
								cont2 = false;
							}
							else if(c3.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "c3";
								current->seat = "front";
								c3.frontSeats = 0;
								cont2 = false;
							}
							else if(s1.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "s1";
								current->seat = "front";
								s1.frontSeats = 0;
								cont2 = false;
							}
							else if(s2.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "s2";
								current->seat = "front";
								s2.frontSeats = 0;
								cont2 = false;
							}
							else if(s3.frontSeats == 1)
							{
								current->points = current->points - 5;
								current->car = "s3";
								current->seat = "front";
								s3.frontSeats = 0;
								cont2 = false;
							}
							else
							{
								cout << "sorry there were no spots open in the front" << endl;
								cont2 = false;
							}
						}
					break;
					case 'B':
						if(current->points < 3)
						{
							if(current->points < 2)
							{
								if(current->points < 1)
								{
									cout << "sorry you do not have enough credits to have any spot" << endl;
									cont2 = false;
								}
								else
								{
									if(s1.backMid == 1)
									{
										current->points = current->points - 1;
										current->car = "s1";
										current->seat = "BackM";
										s1.backMid = 0;
										cont2 = false;
									}
									else if(s2.backMid == 1)
									{
										current->points = current->points - 1;
										current->car = "s2";
										current->seat = "BackM";
										s2.backMid = 0;
										cont2 = false;
									}
									else if(s3.backMid == 1)
									{
										current->points = current->points - 1;
										current->car = "s3";
										current->seat = "BackM";
										s3.backMid = 0;
										cont2 = false;
									}
									else
									{
										cout << "sorry there are no available seats using this option.. " << endl;
										cont2 = false;
									}
								}
							}
							else
							{
								if(s1.backWin > 0 )
								{
									current->points = current->points - 2;
									current->car = "s1";
									current->seat = "BackW";
									s1.backWin = s1.backWin - 1;
									cont2 = false;
								}
								else if(s2.backWin > 0)
								{
									current->points = current->points - 2;
									current->car = "s2";
									current->seat = "BackW";
									s2.backWin = s2.backWin - 1;
									cont2 = false;
								}
								else if(s3.backWin > 0)
								{
									current->points = current->points - 2;
									current->car = "s3";
									current->seat = "BackW";
									s3.backWin = s3.backWin - 1;
									cont2 = false;
								}
								else if(s1.backMid == 1)
								{
									current->points = current->points - 1;
									current->car = "s1";
									current->seat = "BackM";
									s1.backMid = 0;
									cont2 = false;
								}
								else if(s2.backMid == 1)
								{
									current->points = current->points - 1;
									current->car = "s2";
									current->seat = "BackM";
									s2.backMid = 0;
									cont2 = false;
								}
								else if(s3.backMid == 1)
								{
									current->points = current->points - 1;
									current->car = "s3";
									current->seat = "BackM";
									s3.backMid = 0;
									cont2 = false;
								}
								else
								{
									cout << "sorry there are no available seats using this option.. " << endl;
									cont2 = false;
								}
							}
						}
						else
						{
							if(c1.backSeats > 0 )
							{
								current->points = current->points - 3;
								current->car = "c1";
								current->seat = "Back";
								c1.backSeats = c1.backSeats - 1;
								cont2 = false;
							}
							else if(c2.backSeats > 0)
							{
								current->points = current->points - 3;
								current->car = "c2";
								current->seat = "Back";
								c2.backSeats = c2.backSeats - 1;
								cont2 = false;
							}
							else if(c3.backSeats > 0)
							{
								current->points = current->points - 3;
								current->car = "c3";
								current->seat = "Back";
								c3.backSeats = c3.backSeats - 1;
								cont2 = false;
							}
							else if(s1.backWin > 0 )
							{
								current->points = current->points - 2;
								current->car = "s1";
								current->seat = "BackW";
								s1.backWin = s1.backWin - 1;
								cont2 = false;
							}
							else if(s2.backWin > 0)
							{
								current->points = current->points - 2;
								current->car = "s2";
								current->seat = "BackW";
								s2.backWin = s2.backWin - 1;
								cont2 = false;
							}
							else if(s3.backWin > 0)
							{
								current->points = current->points - 2;
								current->car = "s3";
								current->seat = "BackW";
								s3.backWin = s3.backWin - 1;
								cont2 = false;
							}
							else if(s1.backMid == 1)
							{
								current->points = current->points - 1;
								current->car = "s1";
								current->seat = "BackM";
								s1.backMid = 0;
								cont2 = false;
							}
							else if(s2.backMid == 1)
							{
								current->points = current->points - 1;
								current->car = "s2";
								current->seat = "BackM";
								s2.backMid = 0;
								cont2 = false;
							}
							else if(s3.backMid == 1)
							{
								current->points = current->points - 1;
								current->car = "s3";
								current->seat = "BackM";
								s3.backMid = 0;
								cont2 = false;
							}
							else
							{
								cout << "sorry there are no available seats using this option.. " << endl;
								cont2 = false;
							}
						}
					break;
					default:
						cout << "your input was incorrect... " << endl;
						cont2 = true;
					}
				}while(cont2 == true);
				break;
			case 'S':
				do{
					cout << "select vehicle: (P)ickup, (C)ompact, (S)edan: ";
					cin >> sel2;
					sel2 = toupper(sel2);
					switch(sel2)
					{
					case 'P':
						if(current->points < 5)
						{
							cout << "Sorry you do not have enough credits for this vehicle." << endl;
							break;
						}
						else
						{
							cout << "Select 1, 2 or 3: ";
							cin >> sel3;
							switch(sel3)
							{
							case 1:
								if(p1.spotsLeft == 1)
								{
									current->points = current->points - 5;
									current->car = "p1";
									current->seat = "front";
									p1.spotsLeft = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 2:
								if(p2.spotsLeft == 1)
								{
									current->points = current->points - 5;
									current->car = "p2";
									current->seat = "front";
									p2.spotsLeft = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 3:
								if(p3.spotsLeft == 1)
								{
									current->points = current->points - 5;
									current->car = "p3";
									current->seat = "front";
									p3.spotsLeft = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							default:
								cout << "Please Retry.." << endl;
								veh = true;
								break;
							}
						}

						break;
					case 'C':
						cout << "Select 1, 2 or 3: ";
						cin >> sel3;
						switch(sel3)
						{
						case 1:
							cout << "(F)ront or (B)ack: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c1.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "c1";
									current->seat = "front";
									c1.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 3)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c1.backSeats > 0)
								{
									current->points = current->points - 3;
									current->car = "c1";
									current->seat = "Back";
									c1.backSeats = c1.backSeats - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						case 2:
							cout << "(F)ront or (B)ack: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c2.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "c2";
									current->seat = "front";
									c2.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 3)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c2.backSeats > 0)
								{
									current->points = current->points - 3;
									current->car = "c2";
									current->seat = "Back";
									c2.backSeats = c2.backSeats - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						case 3:
							cout << "(F)ront or (B)ack: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c3.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "c3";
									current->seat = "front";
									c3.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 3)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(c3.backSeats > 0)
								{
									current->points = current->points - 3;
									current->car = "c3";
									current->seat = "Back";
									c3.backSeats = c3.backSeats - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						default:
							cout << "Please Retry.." << endl;
							veh = true;
							break;
						}
						break;
					case 'S':
						cout << "Select 1, 2 or 3: ";
						cin >> sel3;
						switch(sel3)
						{
						case 1:
							cout << "(F)ront, (B)ack Window, or Back (M)iddle: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s1.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "s1";
									current->seat = "front";
									s1.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 2)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s1.backWin > 0)
								{
									current->points = current->points - 2;
									current->car = "s1";
									current->seat = "BackW";
									s1.backWin = s1.backWin - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							case 'M':
								if(current->points < 1)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s1.backMid > 0)
								{
									current->points = current->points - 1;
									current->car = "s1";
									current->seat = "BackM";
									s1.backMid = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						case 2:
							cout << "(F)ront, (B)ack Window, or Back (M)iddle: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s2.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "s2";
									current->seat = "front";
									s2.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 2)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s2.backWin > 0)
								{
									current->points = current->points - 2;
									current->car = "s2";
									current->seat = "BackW";
									s2.backWin = s2.backWin - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							case 'M':
								if(current->points < 1)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s2.backMid > 0)
								{
									current->points = current->points - 1;
									current->car = "s2";
									current->seat = "BackM";
									s2.backMid = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						case 3:
							cout << "(F)ront, (B)ack Window, or Back (M)iddle: ";
							cin >> sel4;
							sel4 = toupper(sel4);
							switch(sel4)
							{
							case 'F':
								if(current->points < 5)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s3.frontSeats == 1)
								{
									current->points = current->points - 5;
									current->car = "s3";
									current->seat = "front";
									s3.frontSeats = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry this spot is taken.." << endl;
								}
								break;
							case 'B':
								if(current->points < 2)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s3.backWin > 0)
								{
									current->points = current->points - 2;
									current->car = "s3";
									current->seat = "BackW";
									s3.backWin = s3.backWin - 1;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							case 'M':
								if(current->points < 1)
								{
									cout << "sorry not enough credits.." << endl;
								}
								else if(s3.backMid > 0)
								{
									current->points = current->points - 1;
									current->car = "s3";
									current->seat = "BackM";
									s3.backMid = 0;
									cont2 = false;
									veh = false;
								}
								else
								{
									cout << "Sorry there are no more spots here.." << endl;
								}
								break;
							default:
								cout << "please retry.." << endl;
								veh = true;
								break;
							}
							break;
						default:
							cout << "Please Retry.." << endl;
							veh = true;
							break;
						}
						break;
					default:
						cout << "Please Retry.." << endl;
						veh = true;
						break;
					}
				}while(veh == true);

				break;
			default:
				cout << "your input was incorrect.. please only 'C' or 'S'" << endl;
				cont2 = true;
				break;

		}
			}while(cont2 == true);

			cout << "Car                : " << current->car << endl;
			cout << "Seat               : " << current->seat << endl;
			return current;

			break;
		}
		else
		{
			current = current->nextaddr;
			if(current == NULL)
			{
				cout << "Name not found.. Returning to menu.." << endl;
				cont = false;
				return(current);
			}
		}
	}while(cont == true);
	return(current);

}


People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3)
{
	bool cont = true;
	People *current;
	current = head_main;

	int resNum;
	cout << "Please enter a Reservation Number..." << endl;
	cin >> resNum;

	do{

		if (current->resNum == resNum)
		{
			cont = false;

			if (current->car == "p1" || current->car == "p2" || current->car == "p3" )
			{
				if(current->car == "p1")
				{
					p1.spotsLeft = 1;
				}
				else if(current->car == "p2")
				{
					p2.spotsLeft = 1;
				}
				else if(current->car == "p3")
				{
					p3.spotsLeft = 1;
				}

				current->car = "Empty";
				current->seat = "Empty";
				current->points = current->points + 5;
			}
			if (current->car == "c1" || current->car == "c2" || current->car == "c3" )
			{

				if(current->seat == "front")
				{
					if(current->car == "c1")
					{
						c1.frontSeats = c1.frontSeats + 1;
					}
					else if(current->car == "c2")
					{
						c2.frontSeats = c2.frontSeats + 1;
					}
					else if(current->car == "c3")
					{
						c3.frontSeats = c3.frontSeats + 1;
					}
					current->points = current->points + 5;
				}
				else
				{
					if(current->car == "c1")
					{
						c1.backSeats = c1.backSeats + 1;
					}
					else if(current->car == "c2")
					{
						c2.backSeats = c2.backSeats + 1;
					}
					else if(current->car == "c3")
					{
						c3.backSeats = c3.backSeats + 1;
					}
					current->points = current->points + 3;
				}
				current->car = "Empty";
				current->seat = "Empty";
			}
			if (current->car == "s1" || current->car == "s2" || current->car == "s3" )
			{
				if(current->seat == "front")
				{
					if(current->car == "s1")
					{
						s1.frontSeats = s1.frontSeats + 1;
					}
					else if(current->car == "s2")
					{
						s2.frontSeats = s2.frontSeats + 1;
					}
					else if(current->car == "s3")
					{
						s3.frontSeats = s3.frontSeats + 1;
					}
					current->points = current->points + 5;
				}
				else if (current->seat == "BackM")
				{
					if(current->car == "s1")
					{
						s1.backMid = s1.backMid + 1;
					}
					else if(current->car == "s2")
					{
						s2.backMid = s2.backMid + 1;
					}
					else if(current->car == "s3")
					{
						s3.backMid = s3.backMid + 1;
					}
					current->points = current->points + 1;
				}
				else
				{
					if(current->car == "s1")
					{
						s1.backWin = s1.backWin + 1;
					}
					else if(current->car == "s2")
					{
						s2.backWin = s2.backWin + 1;
					}
					else if(current->car == "s3")
					{
						s3.backWin = s3.backWin + 1;
					}
					current->points = current->points + 2;
				}

			}
			current->car = "Empty";
			current->seat = "Empty";
			return current;
		}
		else
		{
			current = current->nextaddr;
			if (current == NULL)
			{
				cont = false;
				cout << "Reservation number not found" << endl;
			}

		}
	}while (cont == true);
	return current;
}

void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3) // changes it by deleting and creating again
{
	Delete(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3);
	Create(head_main, p1, p2, p3, c1, c2, c3, s1, s2, s3);

}
void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3) // puts it in a text file
{
	ofstream outFile;
	People *current;
	current = head_main;
	bool cont = true;

	int car;

	if (outFile.fail())
	{
		cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
		exit (1);
	}

	do
	{
		cout << "Enter a Specific Vehicle... " << endl;
		cout << " (1) Purple Pickup (2) Yellow Pickup (3) Red Pickup" << endl;
		cout << "(4) Green Compact (5) Blue Compact (6) Yellow Compact" << endl;
		cout << "(7) Red Sedan (8) Green Sedan (9) Blue Sedan" << endl;
		cin >> car;

		switch (car)
		{
		case 1:
			outFile.open("Purple_Pickup(p1).txt");

			while (current != NULL)
			{
				if (current->car == "p1")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}

			}
			outFile.close();
			cont = false;
			break;

		case 2:
			outFile.open("Yellow_Pickup(p2).txt");

			while (current != NULL)
			{
				if (current->car == "p2")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 3:
			outFile.open("Red_Pickup(p3).txt");

			while (current != NULL)
			{
				if (current->car == "p3")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 4:
			outFile.open("Green_Compact(c1).txt");

			while (current != NULL)
			{
				if (current->car == "c1")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 5:
			outFile.open("Blue_Compact(c2).txt");

			while (current != NULL)
			{
				if (current->car == "c2")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 6:
			outFile.open("Yellow_Compact(c3).txt");

			while (current != NULL)
			{
				if (current->car == "c3")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 7:
			outFile.open("Red_Sedan(s1).txt");

			while (current != NULL)
			{
				if (current->car == "s1")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 8:
			outFile.open("Green_Sedan(s2).txt");

			while (current != NULL)
			{
				if (current->car == "s2")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;

		case 9:
			outFile.open("Blue_Sedan(s3).txt");

			while (current != NULL)
			{
				if (current->car == "s1")
				{
				outFile << current->name << endl;
				outFile << current->points << endl;
				outFile << current->resNum << endl;
				outFile << current->seat << endl;
				current = current->nextaddr;
				}
				else
				{
					current = current->nextaddr;
				}
			}
			outFile.close();
			cont = false;
			break;
		}
	}

	while(cont == true);
	cout << "Print Complete.. " << endl;
}

void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3) // puts all in a text file
{
	ofstream outFile;
	People *current;
	current = head_main;
	string password, correct;
	correct = "letmein";
	cout << "To confirm this is System Admin enter the password: ";
	cin >> password;
	if(password == correct)
	{
		outFile.open("all_reservations.txt");

		if (outFile.fail())
		{
			cout << "\nThe file did not successfully open... Program Terminated\n" << endl;
			exit (1);
		}
		////////////////////////////////////////////////////////
		outFile << "Purple Pickup (p1)" << endl;
		while (current != NULL)
		{
			if (current->car == "p1")
			{
			outFile << "Name    : "<< current->name << endl;
			outFile << "Credits : "<< current->points << endl;
			outFile << "Res Num : "<< current->resNum << endl;
			outFile << "Seat    : "<< current->seat << endl;
			current = current->nextaddr;
			}
			else
			{
				current = current->nextaddr;
			}
		}
		if(p1.spotsLeft == 1)
		{
			outFile << "Front Seat: Unassigned " << endl;
		}
		current = head_main;
		////////////////////////////////////////////////////////

		outFile << "Yellow Pickup (p2)" << endl;
				while (current != NULL)
				{
					if (current->car == "p2")
					{
					outFile << "Name    : "<< current->name << endl;
					outFile << "Credits : "<< current->points << endl;
					outFile << "Res Num : "<< current->resNum << endl;
					outFile << "Seat    : "<< current->seat << endl;
					current = current->nextaddr;
					}
					else
					{
						current = current->nextaddr;
					}
				}
				if(p2.spotsLeft == 1)
				{
					outFile << "Front Seat: Unassigned " << endl;
				}
				current = head_main;
		////////////////////////////////////////////////////////

		outFile << "Red Pickup (p3)" << endl;
				while (current != NULL)
				{
					if (current->car == "p3")
					{
					outFile << "Name    : "<< current->name << endl;
					outFile << "Credits : "<< current->points << endl;
					outFile << "Res Num : "<< current->resNum << endl;
					outFile << "Seat    : "<< current->seat << endl;
					current = current->nextaddr;
					}
					else
					{
						current = current->nextaddr;
					}
				}
				if(p3.spotsLeft == 1)
				{
					outFile << "Front Seat: Unassigned " << endl;
				}
				current = head_main;
		////////////////////////////////////////////////////////

		outFile << "Green Compact (c1)" << endl;
				while (current != NULL)
				{
					if (current->car == "c1")
					{
					outFile << "Name    : "<< current->name << endl;
					outFile << "Credits : "<< current->points << endl;
					outFile << "Res Num : "<< current->resNum << endl;
					outFile << "Seat    : "<< current->seat << endl;
					current = current->nextaddr;
					}
					else
					{
						current = current->nextaddr;
					}
				}
				if(c1.frontSeats == 1)
				{
					outFile << "Front Seat: Unassigned " << endl;
				}
				if(c1.backSeats > 0)
				{
					int i = c1.backSeats;
					while(i > 0)
					{
						outFile << "Back Seat " << i << ": Unassigned" << endl;
						i--;
					}
				}
				current = head_main;
		////////////////////////////////////////////////////////

			outFile << "Blue Compact (c2)" << endl;
					while (current != NULL)
					{
						if (current->car == "c2")
						{
						outFile << "Name    : "<< current->name << endl;
						outFile << "Credits : "<< current->points << endl;
						outFile << "Res Num : "<< current->resNum << endl;
						outFile << "Seat    : "<< current->seat << endl;
						current = current->nextaddr;
						}
						else
						{
							current = current->nextaddr;
						}
					}
					if(c2.frontSeats == 1)
					{
						outFile << "Front Seat: Unassigned " << endl;
					}
					if(c2.backSeats > 0)
					{
						int i = c2.backSeats;
						while(i > 0)
						{
							outFile << "Back Seat " << i << ": Unassigned" << endl;
							i--;
						}
					}
					current = head_main;
			////////////////////////////////////////////////////////


				outFile << "Yellow Compact (c3)" << endl;
						while (current != NULL)
						{
							if (current->car == "c3")
							{
							outFile << "Name    : "<< current->name << endl;
							outFile << "Credits : "<< current->points << endl;
							outFile << "Res Num : "<< current->resNum << endl;
							outFile << "Seat    : "<< current->seat << endl;
							current = current->nextaddr;
							}
							else
							{
								current = current->nextaddr;
							}
						}
						if(c3.frontSeats == 1)
						{
							outFile << "Front Seat: Unassigned " << endl;
						}
						if(c3.backSeats > 0)
						{
							int i = c3.backSeats;
							while(i > 0)
							{
								outFile << "Back Seat " << i << ": Unassigned" << endl;
								i--;
							}
						}
						current = head_main;
				////////////////////////////////////////////////////////

				outFile << "Red Sedan (s1)" << endl;
						while (current != NULL)
						{
							if (current->car == "s1")
							{
							outFile << "Name    : "<< current->name << endl;
							outFile << "Credits : "<< current->points << endl;
							outFile << "Res Num : "<< current->resNum << endl;
							outFile << "Seat    : "<< current->seat << endl;
							current = current->nextaddr;
							}
							else
							{
								current = current->nextaddr;
							}
						}
						if(s1.frontSeats == 1)
						{
							outFile << "Front Seat: Unassigned " << endl;
						}
						if(s1.backWin > 0)
						{
							int i = s1.backWin;
							while(i > 0)
							{
								outFile << "Back Window Seat " << i << ": Unassigned" << endl;
								i--;
							}
						}
						if(s1.backMid == 1)
						{
							outFile << "Back Middle Seat: Unassigned " << endl;
						}

						current = head_main;
				////////////////////////////////////////////////////////

				outFile << "Green Sedan (s2)" << endl;
						while (current != NULL)
						{
							if (current->car == "s2")
							{
							outFile << "Name    : "<< current->name << endl;
							outFile << "Credits : "<< current->points << endl;
							outFile << "Res Num : "<< current->resNum << endl;
							outFile << "Seat    : "<< current->seat << endl;
							current = current->nextaddr;
							}
							else
							{
								current = current->nextaddr;
							}
						}
						if(s2.frontSeats == 1)
						{
							outFile << "Front Seat: Unassigned " << endl;
						}
						if(s2.backWin > 0)
						{
							int i = s1.backWin;
							while(i > 0)
							{
								outFile << "Back Window Seat " << i << ": Unassigned" << endl;
								i--;
							}
						}
						if(s2.backMid == 1)
						{
							outFile << "Back Middle Seat: Unassigned " << endl;
						}

						current = head_main;
				////////////////////////////////////////////////////////

				outFile << "Blue Sedan (s3)" << endl;
						while (current != NULL)
						{
							if (current->car == "s3")
							{
							outFile << "Name    : "<< current->name << endl;
							outFile << "Credits : "<< current->points << endl;
							outFile << "Res Num : "<< current->resNum << endl;
							outFile << "Seat    : "<< current->seat << endl;
							current = current->nextaddr;
							}
							else
							{
								current = current->nextaddr;
							}
						}
						if(s3.frontSeats == 1)
						{
							outFile << "Front Seat: Unassigned " << endl;
						}
						if(s3.backWin > 0)
						{
							int i = s1.backWin;
							while(i > 0)
							{
								outFile << "Back Window Seat " << i << ": Unassigned" << endl;
								i--;
							}
						}
						if(s3.backMid == 1)
						{
							outFile << "Back Middle Seat: Unassigned " << endl;
						}

						current = head_main;
				////////////////////////////////////////////////////////
	}
	else
	{
		cout << "Nice try Hackerman.. " << endl;
	}
	outFile.close();
	cout << "Reservation Print Complete.. " << endl;
}
