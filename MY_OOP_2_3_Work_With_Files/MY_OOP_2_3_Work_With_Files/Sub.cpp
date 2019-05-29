#include "Sub.h"

Sub::Sub()
{

}

Sub::~Sub()
{

}

ifstream& operator>>(ifstream &is, Sub &sub)
{
	getline(is, sub.fullName);
	getline(is, sub.instDate);
	getline(is, sub.telNum);
	string space;
	getline(is, space);
	return is;
}

ofstream& operator<<(ofstream &os, Sub &sub)
{
	os << sub.fullName << '\n';
	os << sub.instDate << '\n';
	os << sub.telNum << '\n';
	return os;
}

ostream& operator<<(ostream &os, Sub &sub)
{
	cout << "  Sub's Full Name: ";
	os << sub.fullName << '\n';

	cout << "  Sub's installation date: ";
	os << sub.instDate << '\n';

	cout << "  Sub's telephone number: ";
	os << sub.telNum << '\n';

	return os;
}

istream& operator>>(istream& is, Sub& sub)
{
	cout << "Enter sub's Full Name: ";
	sub.fullName = inputString();

	cout << "Enter sub's installation date(dd/mm/yyyy): ";
	sub.instDate = inputDate();

	cout << "Enter sub's telephone number: ";
	sub.telNum = inputString();

	return is;
}
