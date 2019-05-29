#pragma once
#include <string>
#include <iostream>
#include "inputModule.h"

using namespace std;

class HouseholdGoods
{
private:
	string shampooName;
	int numOfCups;
	int numOfSocks;
	int numOfKnifes;
	string detergentName;
	string elKettleName;
	int numOfPowerSupplyUnits;

public:
	HouseholdGoods();
	~HouseholdGoods();

	friend ostream& operator<< (ostream& out, const HouseholdGoods& hg);
	friend istream& operator>> (istream &in, HouseholdGoods &hg);
};



