//class definition for the HTML Table

#include "HTMLTable.h"

//writeRow method to use tags to write the table
void HTMLTable::writeRow(ostream &out, string tag, vector<string> row)
{
	out << "<tr>\n";
	for (unsigned int i = 0; i < row.size(); i++)
	{
		out << "<" << tag << ">"
			<< row[i] << "</" << tag << "> ";
	}
	out << "\n</tr>\n";
}

//Overloaded stream operator <<
ostream &operator<<(ostream &out, HTMLTable htmlTable)
{
	out << "<table border=\"1\">\n";
	string sTitleTag;	//for writing the title
	sTitleTag = "th colspan=\"" + to_string(htmlTable.headers.size())
		+ "\"\n";
	htmlTable.writeRow(out, sTitleTag, htmlTable.title);

	htmlTable.writeRow(out, "th", htmlTable.headers); //to write the headers

	//to write the rows of the table
	for (unsigned int i = 0; i < htmlTable.rows.size(); i++)
		htmlTable.writeRow(out, "td", htmlTable.rows[i]);

	out << "</table>\n";	//the ending tag
	return out;	//return output
}
