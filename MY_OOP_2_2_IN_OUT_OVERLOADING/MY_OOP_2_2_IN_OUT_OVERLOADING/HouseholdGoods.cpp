#include "HouseholdGoods.h"


HouseholdGoods::HouseholdGoods()
{
	shampooName = "";
	numOfCups = 0;
	numOfSocks = 0;
	numOfKnifes = 0;
	detergentName = "";
	elKettleName = "";
	numOfPowerSupplyUnits = 0;
}

ostream& operator<< (ostream &out, const HouseholdGoods& hg)
{
	out << "Shampoo name: " << hg.shampooName
		<< "\nNumber of cups: " << hg.numOfCups
		<< "\nNumber of socks: " << hg.numOfSocks
		<< "\nNumber of knifes: " << hg.numOfKnifes
		<< "\nDetergent name: " << hg.detergentName
		<< "\nElectric kettle name: " << hg.elKettleName
		<< "\nNumber of power supply units: " << hg.numOfPowerSupplyUnits << '\n';

	return out;
}

istream& operator>> (istream &in, HouseholdGoods& hg)
{
	cout << "enter shampoo name: ";
	hg.shampooName = inputStringForMatr();

	cout << "enter number of cups: ";
	hg.numOfCups = inputNumber();

	cout << "enter number of socks: ";
	hg.numOfSocks = inputNumber();

	cout << "enter number of knifes: ";
	hg.numOfKnifes = inputNumber();

	cout << "enter detergent name: ";
	hg.detergentName = inputStringForMatr();

	cout << "enter electric kettle name: ";
	hg.elKettleName = inputStringForMatr();

	cout << "enter power supply units: ";
	hg.numOfPowerSupplyUnits = inputNumber();

	return in;
}


HouseholdGoods::~HouseholdGoods()
{
}
