#include "MembersMain.h"
#include "HTMLTable.h"

// main function for record sort
int main()
{
	//declare vectors and strings
	string mFileLine;
	vector<string> parsedLine;	//vector to hold each parsed line
	vector<Members> members;	//vector of member objects

	ifstream fin;
	ofstream fout;
	OpenFile(fin);

	while (!fin.eof())
		members.push_back(readFile(mFileLine, parsedLine, fin));	//push back on vector
	fin.close(); //closing input file that was read from

	int choice;	//variable to hold user menu choice

	do
	{
		string fileName;
		displayMenu();	
		cout << "Please select the report you wish to run from the above menu (0-3): ";
		cin >> choice;	//get user choice
		if (choice < 0 || choice > 3)	//menu selection validation
		{
			cout << endl << "Menu choices are limited to options 0-3. Please enter a number 0-3: ";
			cin >> choice;
		}
		if (choice == 0)	//exit loop if 0
			break;
		cout << endl << "Please enter the name a filename for the report with the extension \'.html\': ";
		cin >> fileName; 
		cout << endl << "Note: HTML reports can be found in file folder."<<endl<<endl;
		OpenFile(fout, fileName);

		//switch statement to go through menu options
		string stateChoice;
		switch (choice)
		{
		case 1: //option 1 sort members ascending by lname
			memberSortLname(members);
			writeFileHelper(fout, members);
			writeHTMLTable(fileName);
			break;
		case 2: //option 2 sort members ascending by Fname
			memberSortFname(members);
			writeFileHelper(fout, members);
			writeHTMLTable(fileName);
			break;
		case 3:	//option 3 sort by user selected state, then city ascending order
			cout << endl << "Please choose a state to sort by. Must be abbreviated in all capital letters (Ex: TX): ";
			cin >> stateChoice;
			citySort(members);
			writeFileHelper2(fout, members, stateChoice);
			writeHTMLTable2(fileName);
			break;
		case 0:	//default case to end program
			cout << "Now exiting the program..." << endl << endl;
			exit(0);	//user decides to exit program
		}
		fout.close();	//close file at the end so menu still works

	} while (choice != 0);
	return 0;
} //end of main

//function to open input file
void OpenFile(ifstream &input)
{
	input.open("members.csv");
	if (!input)	//input file opening validation
	{
		cout << "Input file did not open. Exiting program" << endl;
		exit(0);
	}
}//end open input file

//functin to open output file
void OpenFile(ofstream &output, string filename)
{

	output.open(filename);
	if (!output)	//output file opening validation
	{
		cout << "Output file did not open. Exiting the program" << endl;
		exit(0);
	}
}//end open output file

//function to read the members.csv file
Members readFile(string &pLine, vector<string> &pParsed, ifstream &fin)
{
	getline(fin, pLine);
	stringstream lineStream(pLine);
	string field;
	pParsed.clear();	//used to clear each parsed line

	while (getline(lineStream, field, ','))
	{
		pParsed.push_back(field);	//add to vector
	}

	return Members(pParsed[0], pParsed[1], pParsed[2], pParsed[3], pParsed[4], pParsed[5], pParsed[6],
		pParsed[7], pParsed[8], pParsed[9], pParsed[10]); 
}

//function to display menu
void displayMenu()
{
	cout << endl;
	cout << setw(5) << "           Keep America Beautiful Reports Menu" << endl;
	cout << "=========================================================" << endl;
	cout<<  setw(7)<<  "1: All Members Sorted Ascending by Last Name" << endl;
	cout << setw(7) << "2: All Members Sorted Ascending by First Name" << endl;
	cout << setw(7) << "3: Members in One State Only, Sorted by Ascending City" << endl;
	cout << setw(7) << "0: Exit the program" << endl << endl;
}//end display menu function

//function to display the HTML Table
void writeHTMLTable(string fname)
{
	
	// includes sentinel to stop the write loop
	vector<string> sTitle = { "Friends of Dana Peak Parks"};
	vector<string> sHeaders = { "First Name", "MI", "Last Name", "Email",
		"Address", "City", "State", "Zip Code", "Phone"};
	
	HTMLTable hTable;	// HTML Table object
	hTable.setTitle(sTitle);	//set Title members
	hTable.setHeaders(sHeaders);	//set header members

	ifstream in("helper.csv");	//input file
	if (!in)
	{
		cout << "Input file didn't open. Program will exit...";
		exit(0);
	}

	ofstream out(fname); //open the user chosen name for output
	if (!out)
	{
		cout << "Output table file didn't open. Program will exit...";
		exit(0);
	}

	string mLine;	//to read and hold output
	vector<string> mParsed; //holds each record
	string field;	//temporary placement for each field

	while (!in.eof())	//a loop to create the table from the file
	{
		getline(in, mLine);
		stringstream lineStream(mLine);
		mParsed.clear();	//empty for next record
		while (getline(lineStream, field, ','))
		{
				mParsed.push_back(field);	
		}
		hTable.addRows(mParsed);	//add row to table
	}
	out << hTable;	//write to desired file
	in.close();
	out.close();	
} // end of writeHTMLTable function

//function to sort members by last name in ascending order
void memberSortLname(vector<Members> &m)
{
	Members temp;	//temp to hold members objects
	bool swap;	//flag

	do
	{
		swap = false;
		for (int count = 0; count <long(m.size() - 1); count++)
		{
			if (m[count] > m[count + 1]) //sort by last name
			{
				temp = m[count];
				m[count] = m[count + 1];
				m[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
} //end memberSortLname

//function to sort members by first name
void memberSortFname(vector<Members> &m)
{
	Members temp;	//temp to hold members objects
	bool swap;	//flag

	do
	{
		swap = false;
		for (int count = 0; count <long(m.size() - 1); count++)
		{
			if (m[count] < m[count + 1]) //sort by first name
			{
				temp = m[count];
				m[count] = m[count + 1];
				m[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
} //end memberSortFname function

//function to sort the city in ascending order
void citySort(vector<Members> &m)
{
	Members temp;	//temp to hold members objects
	bool swap;	//flag

	do
	{
		swap = false;
		for (int count = 0; count <long(m.size() - 1); count++)
		{
			if (m[count].getCity() > m[count + 1].getCity()) //sort by city
			{
				temp = m[count];
				m[count] = m[count + 1];
				m[count + 1] = temp;
				swap = true;
			}
		}
	} while (swap);
}// end citySort function

//write to csv 
void writeFileHelper(ofstream &fout, vector<Members> m)
{
	ofstream helperFile;
	helperFile.open("helper.csv");
	//output file validation
	if (!helperFile)
	{
		cout << "Output file didn't open. Exiting program.." << endl;
		exit(0);
	}
	
	for (int i = 0; i < long(m.size() - 1); i++)
	{
		helperFile << m[i].getFname() <<","<< m[i].getMname() <<","<< m[i].getLname() <<","<<
			m[i].getEmail() <<","<< m[i].getAddress() <<","<< m[i].getCity() <<","<<
			m[i].getState() <<","<< m[i].getZip() <<","<< m[i].getPhoneNum() << endl;
	}
	helperFile.close();
} //end of helperfile function

//helper file for the third selection
void writeFileHelper2(ofstream &fout, vector<Members> m, string type)
{
	ofstream helperFile2;
	helperFile2.open("helper2.csv");

	if (!helperFile2)
	{
		cout << "Output file didn't open. Exiting program.." << endl;
		exit(0);
	}
	for (int i = 0; i < long(m.size() - 1); i++)
	{
		if (type == m[i].getState())
		{
			helperFile2 << m[i].getFname() << "," << m[i].getMname() << "," << m[i].getLname() << "," <<
				m[i].getEmail() << "," << m[i].getAddress() << "," << m[i].getCity() << "," <<
				m[i].getState() << "," << m[i].getZip() << "," << m[i].getPhoneNum() << endl;
		}
	}	
} //end helperfile function

//function to write the HTML Table for choice 3
void writeHTMLTable2(string fname)
{
	// includes sentinel to stop the write loop
	vector<string> sTitle = { "Friends of Dana Peak Parks"};
	vector<string> sHeaders = { "First Name", "MI", "Last Name", "Email", "Address", "City", "State", "Zip Code", "Phone"};

	HTMLTable hTable;	// HTML Table object
	hTable.setTitle(sTitle);	//set Title members
	hTable.setHeaders(sHeaders);	//set header members

	ifstream in("helper2.csv");	//input file
	if (!in)
	{
		cout << "Input file didn't open. Program will exit...";
		exit(0);
	}

	ofstream out(fname); //open the user chosen name for output
	if (!out)
	{
		cout << "Output table file didn't open. Program will exit...";
		exit(0);
	}

	string mLine;	//to read and hold output
	vector<string> mParsed; //holds each record
	string field;	//temporary placement for each field

	while (!in.eof())	//a loop to create the table from the file
	{
		getline(in, mLine);
		stringstream lineStream(mLine);
		mParsed.clear();	//empty for next record
		while (getline(lineStream, field, ','))
		{
			mParsed.push_back(field);
		}
		hTable.addRows(mParsed);	//add row to table
	}
	out << hTable;	//write to desired file
	in.close();
	out.close();
} //end writeHTMLTable2 function
