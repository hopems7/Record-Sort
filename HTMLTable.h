#pragma once

//class declaration for the HTML Table

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

//class for 2D HTML table
class HTMLTable
{
private:
	vector<string> title;
	vector<string> headers;
	vector<vector<string> > rows;
	// method to add each row to the HTML Table
	void writeRow(ostream &out, string tag, vector<string> row);

public:
	void setTitle(const vector<string> &title) //create table title
	{
		this->title = title;
	}
	void setHeaders(const vector<string> &headers) //create table headers
	{
		this->headers = headers;
	}
	void addRows(const vector<string> &row)	//method to add a new row
	{
		rows.push_back(row);
	}
	// write table in HTML form using << operator
	friend ostream & operator<<(ostream &out, HTMLTable htmlTable);
};
