#pragma once
// telephone subscriber class
#include <string>
#include <iostream>
#include <fstream>
#include "inputModule.h"

using namespace std;

class Sub
{
	string fullName;
	string instDate;
	string telNum;

public:
	Sub();

	string getFullName() { return this->fullName; }
	string getInstDate() { return this->instDate; }
	string getTelNum() { return this->telNum; }

	void setFullName(const string& fullName) { this->fullName = fullName; }
	void setInstDate(const string& instDate) { this->instDate = instDate; }
	void setTelNum(const string& telNum) { this->telNum = telNum; }

	friend ifstream& operator>>(ifstream&, Sub&);
	friend ofstream& operator<<(ofstream&, Sub&);
	friend ostream& operator<<(ostream&, Sub&);
	friend istream& operator>>(istream&, Sub&);

	~Sub();
};

