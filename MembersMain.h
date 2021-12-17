#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <iomanip>
#include "membersDeclared.h"
#include "HTMLTable.h"
using namespace std;

//function prototypes for Main
void OpenFile(ifstream &input);
void OpenFile(ofstream &output, string filename);
void writeHTMLTable(string fname);
void displayMenu();
Members readFile(string &pLine, vector<string> &pParsed, ifstream &fin);
void memberSortLname(vector<Members> &m);
void memberSortFname(vector<Members> &m);
void citySort(vector<Members> &m);
void writeFileHelper(ofstream &fout, vector<Members> m);
void writeFileHelper2(ofstream &fout, vector<Members> m, string type);
void writeHTMLTable2(string fname);
