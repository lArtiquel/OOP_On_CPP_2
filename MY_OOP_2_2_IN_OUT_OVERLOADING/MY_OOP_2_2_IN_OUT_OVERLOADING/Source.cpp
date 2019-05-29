#include <iostream>
#include <vector>
#include "HouseholdGoods.h"

using namespace std;

int main()
{
	vector<HouseholdGoods> hgv;
	while (true)
	{
		cout << "\nenter cmd:\n"
			<< " 1 - add my household good\n"
			<< " 2 - view my household goods\n"
			<< " 3 - del my household goods\n"
			<< " else - quit\n"
			<< "choise: ";

		int ch = inputNumber();
		system("cls");

		switch (ch)
		{
			case 1:
			{
				HouseholdGoods hg;
				cin >> hg;
				hgv.push_back(hg);
				cout << "added!\n";
				break;
			}
			case 2: 
			{
				if (!hgv.empty())
					for (HouseholdGoods hg : hgv) cout << hg << '\n';
				else
					cout << "empty!\n";
				break;
			}
			case 3:
			{
				hgv.clear();
				cout << "cleared!\n";
				break;
			}
			default: return 0;
		}
	}
}