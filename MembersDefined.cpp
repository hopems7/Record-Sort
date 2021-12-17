//member function definitions for the member class

#include "membersDeclared.h"

Members::Members()  //set the default constructor
{
	fName = "";
	mName = "";
	lName = "";
	emailA = "";
	emptyString = "";	//default for empty column
	address = "";
	city = "";
	state = "";
	zip = "";
	phoneNum = "";
	compName = "";
}

//copy constructor
Members::Members(const Members &obj)
{
	fName = obj.fName;
	mName = obj.mName;
	lName = obj.lName;
	emailA = obj.emailA;
	emptyString = obj.emptyString;
	address = obj.address;
	city = obj.city;
	state = obj.state;
	zip = obj.zip;
	phoneNum = obj.phoneNum;
	compName = obj.compName;
}
//initializing constructor
Members::Members(string f, string m, string l, string e, string es, string add, string c,
	string s, string z, string pn, string cn)
{
	setFname(f);
	setMname(m);
	setLname(l);
	setEmail(e);
	setEmpty(es);	//initializing for empty column
	setAddress(add);
	setCity(c);
	setState(s);
	setZip(z);
	setPhoneNum(pn);
	setCompName(cn);
}

//setter functions
bool Members::setFname(string f)
{
	if (f.empty())
	{
		fName = "invalid";
		return false;
	}
	fName = f;
	return true;
}
bool Members::setMname(string m)
{
	if (m.empty())
	{
		mName = "invalid";
		return false;
	}
	mName = m;
	return true;
}
bool Members::setLname(string l)
{
	if (l.empty())
	{
		lName = "invalid";
		return false;
	}
	lName = l;
	return true;
}
bool Members::setEmail(string e)
{
	if (e.empty())
	{
		emailA = "invalid";
		return false;
	}
	emailA = e;
	return true;
}
bool Members::setEmpty(string es) //setter for empty column
{
	if (es.empty())
	{
		emptyString = "invalid";
		return false;
	}
	emptyString = es;
	return true;
}
bool Members::setAddress(string add)
{
	if (add.empty())
	{
		address = "invalid";
		return false;
	}
	address = add;
	return true;
}
bool Members::setCity(string c)
{
	if (c.empty())
	{
		city = "invalid";
		return false;
	}
	city = c;
	return true;
}
bool Members::setState(string s)
{
	if (s.empty())
	{
		state = "invalid";
		return false;
	}
	state = s;
	return true;
}
bool Members::setZip(string z)
{
	if (z.empty())
	{
		zip = "invalid";
		return false;
	}
	zip = z;
	return true;
}
bool Members::setPhoneNum(string pn)
{
	if (pn.empty())
	{
		phoneNum = "invalid";
		return false;
	}
	phoneNum = pn;
	return true;
}
bool Members::setCompName(string cn)
{
	if (cn.empty())
	{
		compName = "invalid";
		return false;
	}
	compName = cn;
	return true;
}

//getter functions for member variables
string Members::getFname()
{
	return fName;
}
string Members::getMname()
{
	return mName;
}
string Members::getLname()
{
	return lName;
}
string Members::getEmail()
{
	return emailA;
}
string Members::getEmpty() //getter for empty column
{
	return emptyString;
}
string Members::getAddress()
{
	return address;
}
string Members::getCity()
{
	return city;
}
string Members::getState()
{
	return state;
}
string Members::getZip()
{
	return zip;
}
string Members::getPhoneNum()
{
	return phoneNum;
}
string Members::getCompName()
{
	return compName;
}

//overloaded operators
bool Members::operator>(const Members &right)
{
	if (this->lName > right.lName)
		return true;
	else
		return false;
}
bool Members::operator<(const Members &left)
{
	if (left.fName < this->fName)	//reverse above notation to make sure it still goes 
		return true;				// in ascending order for first name
	else
		return false;
}
