#include <iostream>
#include "Deque.h"
#include "inputModule.h"

using namespace std;

int main()
{
	try
	{
		while (true)
		{
			cout << "enter type of double-linked node deque:\n"
				<< " 1 - integer\n"
				<< " 2 - double\n"
				<< " elseware - quit\n"
				<< "ok, your choise: ";
			int typeResponse = inputNumber();
			switch (typeResponse)
			{
				case 1:
				{
					Deque<int> deque;
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
							<< " 9 - clear all\n"
							<< " 10 - sort\n"
							<< " 11 - find\n"
							<< " elseware - back\n"
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
							cout << "enter int number: ";
							deque.insertFront(inputNumber());
						}
						else if (cmdResponse == 5) {
							cout << "enter int number: ";
							deque.insertBack(inputNumber());
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
							if (!deque.empty()) {
								deque.clear();
							}
							cout << "deque is cleared!\n";
						}
						else if (cmdResponse == 10) {
							cout << "order:\n"
								<< " 1 - ascending\n"
								<< " else - descending\n"
								<< ">> ";
							int order = inputNumber();
							if (order == 1) deque.bubbleSort(true);
							else deque.bubbleSort(false);
						}
						else if (cmdResponse == 11) {
							cout << "enter number: ";
							if (deque.find(inputNumber())) cout << "found!\n";
							else cout << "not found!\n";
						}
						else
						{
							break;
						}
					}
				}
				case 2:
				{
					Deque<double> deque;
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
							<< " 9 - clear all\n"
							<< " 10 - sort\n"
							<< " 11 - find\n"
							<< " elseware - back\n"
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
							cout << "enter dec number: ";
							deque.insertFront(inputDecimalForMatr());
						}
						else if (cmdResponse == 5) {
							cout << "enter dec number: ";
							deque.insertBack(inputDecimalForMatr());
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
							if (!deque.empty()) {
								deque.clear();
							}
							cout << "deque is cleared!\n";
						}
						else if (cmdResponse == 10) {
							cout << "order:\n"
								<< " 1 - ascending\n"
								<< " else - descending\n"
								<< "cin: ";
							int order = inputNumber();
							if (order == 1) deque.bubbleSort(true);
							else deque.bubbleSort(false);
						}
						else if (cmdResponse == 11) {
							cout << "enter number: ";
							if (deque.find(inputDecimalForMatr())) cout << "found!\n";
							else cout << "not found!\n";
						}
						else
						{
							break;
						}
					}
				}
				default: return 0;
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
}
	
/*	try {
		// DEQUE 1
		Deque<int> deque1;
		deque1.insertFront(20);
		deque1.insertFront(10);
		deque1.insertBack(30);
		deque1.insertBack(40);
		cout << "Size: "
			<< deque1.size() << endl;
		cout << "Is deque empty? "
			<< deque1.empty() << endl;
		cout << "Front: "
			<< deque1.front() << endl;
		cout << "Back: "
			<< deque1.back() << endl;
		deque1.print();

		// DEQUE 2
		Deque<int> deque2;
		deque2.insertFront(70);
		deque2.insertFront(60);
		deque2.insertBack(80);
		deque2.insertBack(90);
		deque2.removeFront();
		deque2.removeBack();

		cout << "Size: "
			<< deque2.size() << endl;
		cout << "Is deque empty? "
			<< deque2.empty() << endl;
		cout << "Front: "
			<< deque2.front() << endl;
		cout << "Back: "
			<< deque2.back() << endl;
		deque2.print();
		deque2.clear();
		deque2.print();
		deque2 = deque1;
		deque2.print();
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
	return 0;
}
*/