#pragma once
#include <string>
using namespace std;

//Members class declaration
class Members
{
private:
		string fName,
		mName,
		lName,
		emailA,
		emptyString,	//csv file has extra column that needs to be accounted for
		address,
		city,
		state,
		zip,
		phoneNum,
		compName;

public:
	Members();		//default constructor
	Members(const Members& obj); //copy constructor
	Members(string f, string m, string l, string e, string es, string add, string c,
		string s, string z, string pn, string cn);		//initializing constructor

	//set function for private member variables
	bool setFname(string f);
	bool setMname(string m);
	bool setLname(string l);
	bool setEmail(string e);
	bool setEmpty(string es);
	bool setAddress(string add);
	bool setCity(string c);
	bool setState(string s);
	bool setZip(string z);
	bool setPhoneNum(string pn);
	bool setCompName(string cn);

	//get functions for private member variables
	string getFname();
	string getMname();
	string getLname();
	string getEmail();
	string getEmpty();
	string getAddress();
	string getCity();
	string getState();
	string getZip();
	string getPhoneNum();
	string getCompName();

	//class also needs overloaded < and > operators to sort records in order
	bool operator>(const Members &right);
	bool operator<(const Members &left);
}; 
