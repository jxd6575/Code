// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
// Title: carpoolfuncs.h
// Course: Computational Problem Solving II CPET.321.01-02
// Developer: Joseph DiCaro, James Paul
// Date last edited: 12/3/2019
// Description: Has the classes, function prototypes, and structs
// +++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

#ifndef CARPOOLFUNCS_H_
#define CARPOOLFUNCS_H_


using namespace std;
struct People {  // people has every bit of info about every person
	string name;
	int points;
	int resNum;
	string car;
	string seat;
	People *nextaddr;
};

struct resNum { // the boolean is if the spot is available based on which node the current pointer is positioned on
	bool avail;
	resNum *nextaddr;
};
class Sedan;  // declaring the classes
class Compact;
class Pickup;
class Vehicle // these friend functions are required to be able to access all the private information in the classes
{

	public:
	friend void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);

};
class Pickup: public Vehicle // Pass by reference is required for each object if it is to be changed in the function
{
	private:
	int spotsLeft;
	public:
	Pickup()
	{
		spotsLeft = 1;
	}
	Pickup(int s =1)
	{
		spotsLeft = s;
	}
	friend void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);

};
class Compact: public Vehicle
{
	private:
	int frontSeats;
	int backSeats;
	public:
	Compact(int f = 1, int b = 2)
	{
		frontSeats = f;
		backSeats = b;
	}
	friend void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);

};
class Sedan : public Vehicle
{
	private:
	int frontSeats;
	int backMid;
	int backWin;
	public:
	Sedan(int f = 1, int b = 1, int w = 2)
	{
		frontSeats = f;
		backMid = b;
		backWin = w;
	}
	friend void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
	friend void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
	friend void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);

};
void Display(Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
People *Read();
People *Create(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
resNum *InitResNum();
People *Delete(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
void Modify(People *head_main, Pickup &p1, Pickup &p2, Pickup &p3, Compact &c1, Compact &c2, Compact &c3, Sedan &s1, Sedan &s2, Sedan &s3);
void Assignment(resNum *head, People *person);
void unAssignment(resNum *head, People *person);
void Print(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
void Reservation(People *head_main, Pickup p1, Pickup p2, Pickup p3, Compact c1, Compact c2, Compact c3, Sedan s1, Sedan s2, Sedan s3);
#endif /* CARPOOLFUNCS_H_ */
