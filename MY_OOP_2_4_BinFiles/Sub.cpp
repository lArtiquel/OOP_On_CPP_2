#include "Sub.h"

Sub::Sub()
{

}

Sub::~Sub()
{

}

ifstream& operator>>(ifstream &is, Sub &sub)
{
	char c[sizeof('\n')];
	string name, instDate, tel;

	while (is.read(c, sizeof('\n'))) {
		if (*c == '\n') {
			sub.setFullName(name);
			break;
		}
		else {
			name += *c;
		}
	}
	
	if (is.eof()) {
		cout << "error reading file\n";
		sub.setFullName("");
		return is;
	}

	while (is.read(c, sizeof('\n'))) {
		if (*c == '\n') {
			sub.setInstDate(instDate);
			break;
		}
		else {
			instDate += *c;
		}
	}

	if (is.eof()) {
		cout << "error reading file\n";
		sub.setFullName("");
		sub.setInstDate("");
		return is;
	}
	
	while (is.read(c, sizeof('\n'))) {
		if (*c == '\n') {
			sub.setTelNum(tel);
			break;
		}
		else {
			tel += *c;
		}
	}                     

	return is;
}

ofstream& operator<<(ofstream &os, Sub &sub)
{
	char ch = '\n';
	os.write(sub.getFullName().c_str(), sub.getFullName().size());
	os.write(&ch, sizeof(ch));
	os.write(sub.getInstDate().c_str(), sub.getInstDate().size());
	os.write(&ch, sizeof(ch));
	os.write(sub.getTelNum().c_str(), sub.getTelNum().size());
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
