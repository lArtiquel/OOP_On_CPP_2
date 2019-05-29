#include <iostream>
#include "Deque.h"
#include "Sub.h"

using namespace std;

int main() {
	try {
		Deque<Sub> deque;
		while (true)
		{
			cout << "enter command to execute:\n"
				<< " 1 - view front\n"
				<< " 2 - view back\n"
				<< " 3 - is empty?\n"
				<< " 4 - insert front\n"
				<< " 5 - insert back\n"
				<< " 6 - remove front\n"
				<< " 7 - remove back\n"
				<< " 8 - print all\n"
				<< " 9 - print after year\n"
				<< " 10 - clear all\n"
				<< " 11 - sort\n"
				<< " 12 - read from file\n"
				<< " 13 - write to file\n"
				<< " else - back\n"
				<< "ok, enter: ";
			int cmdResponse = inputNumber();

			if (cmdResponse == 1) {
				cout << "front: " << deque.front() << '\n';
			}
			else if (cmdResponse == 2) {
				cout << "back: " << deque.back() << '\n';
			}
			else if (cmdResponse == 3) {
				if (deque.empty()) cout << "empty!\n"; else cout << "not empty!\n";
			}
			else if (cmdResponse == 4) {
				cout << "enter new subscriber: \n";
				Sub sub;
				cin >> sub;									// fill sub using overloaded operator
				deque.insertBack(sub);
			}
			else if (cmdResponse == 5) {
				cout << "enter new subscriber: \n";
				Sub sub;
				cin >> sub;
				deque.insertBack(sub);
			}
			else if (cmdResponse == 6) {
				deque.removeFront();
			}
			else if (cmdResponse == 7) {
				deque.removeBack();
			}
			else if (cmdResponse == 8) {
				if (deque.empty()) cout << "empty!\n"; else
					deque.print();
			}
			else if (cmdResponse == 9) {
				if (deque.empty()) cout << "empty!\n"; else
					cout << "enter date to print: ";
				string date = inputDate();
				deque.printAllSubsFromDate(date);
			}
			else if (cmdResponse == 10) {
				if (!deque.empty()) {
					deque.clear();
				}
				cout << "deque is cleared!\n";
			}
			else if (cmdResponse == 11) {
				cout << "order:\n"
					<< " 1 - ascending\n"
					<< " else - descending\n";

				int order = inputNumber();
				if (order == 1) deque.bubbleSort(true);
				else deque.bubbleSort(false);
			}
			else if (cmdResponse == 12) {
				deque.readFromFile();
			}
			else if (cmdResponse == 13) {
				deque.writeToFile();
			}
			else
			{
				break;
			}
		}
	}
	catch (invalid_argument &e) {
		cout << "Invalid argument: "
			<< e.what() << endl;
	}
	catch (NoSuchObject &e) {
		cout << "No such object: "
			<< e.what() << endl;
	}
	catch (logic_error &e) {
		cout << "Logic error: "
			<< e.what() << endl;
	}
	catch (...) {
		cout << "Uncaught exception" << endl;
	}

	system("pause");
}