#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <fstream>
#include <stdexcept>
#include <new>
#include "Dlnode.h"
#include "NoSuchObject.h"
#include "Sub.h"

using namespace std;

template <typename T>
class Deque {

public:
	Deque();
	Deque(const Deque<T>&) throw (bad_alloc);
	bool empty() const;
	void bubbleSort(bool);
	unsigned size() const;
	void insertFront(const T&) throw (bad_alloc);
	void insertBack(const T&) throw (bad_alloc);
	T removeFront() throw (NoSuchObject);
	T& front() const throw (NoSuchObject);
	T removeBack() throw (NoSuchObject);
	T& back() const throw (NoSuchObject);
	const Deque<T> &operator=(const Deque<T>&) throw (bad_alloc);
	void print() const;
	void printAllSubsFromDate(const string& date) const;
	void clear();
	bool find(const T&);
	void writeToFile();
	void readFromFile();
	~Deque();

private:
	unsigned sz;
	DLNode<T>* frontPtr;
	DLNode<T>* backPtr;

	void initialize();

}; // Deque<T> class

template <typename T>
bool Deque<T>::find(const T& key)
{
	if (empty()) return false;
	
	DLNode<T> *i = frontPtr;
	while (i != backPtr)
	{
		if (i->getObject() = key)
			return true;
		i = i->getNextPtr();
	}
	return false;
}

template <typename T>
void Deque<T>::bubbleSort(bool order) {		// true - ascending order, false - descending order
	if (empty()) {
		cout << "empty deque\n"; return;
	}

	if (sz != 1)
	{
		DLNode<T> *jNode = frontPtr;
		for (int i = 0; i < sz-1; i++) {
			bool wasSwap = false;
			jNode = frontPtr;
			for (int j = 0; j < sz-1-i; j++) {
				if (order)
				{
					if (jNode->getObject() > jNode->getNextPtr()->getObject())
					{
						T temp = jNode->getObject();
						jNode->setObject(jNode->getNextPtr()->getObject());
						jNode->getNextPtr()->setObject(temp);
						wasSwap = true;
					}
				}
				else
					if (jNode->getObject() < jNode->getNextPtr()->getObject())
					{
						T temp = jNode->getObject();
						jNode->setObject(jNode->getNextPtr()->getObject());
						jNode->getNextPtr()->setObject(temp);
						wasSwap = true;
					}

				jNode = jNode->getNextPtr();
			}
			if (!wasSwap) break;
		}
	}
	else
		cout << "one el-t!\n";
}

template<>										// specialization of bubbleSort function for Sub type
void Deque<Sub>::bubbleSort(bool order) {		// true - ascending order, false - descending order
	if (empty()) {
		cout << "empty deque\n"; return;
	}

	if (sz != 1)
	{
		cout << "choose key to sort:\n"
			<< "1 - full name\n"
			<< "2 - installation day\n"
			<< "else - telephone number\n";
		
		int choise = inputNumber();

		DLNode<Sub> *jNode = frontPtr;
		for (int i = 0; i < sz - 1; i++) {
			bool wasSwap = false;
			jNode = frontPtr;
			for (int j = 0; j < sz - 1 - i; j++) {
				string iObj, jObj;

				switch (choise)
				{
					case 1: 
						iObj = jNode->getObject().getFullName();
						jObj = jNode->getNextPtr()->getObject().getFullName();
						break;
					case 2:
						iObj = jNode->getObject().getInstDate();
						jObj = jNode->getNextPtr()->getObject().getInstDate();
						break;
					default:
						iObj = jNode->getObject().getTelNum();
						jObj = jNode->getNextPtr()->getObject().getTelNum();
						break;
				}

				if (order)
				{
					if (iObj > jObj)	// yep, I know that this code will not work correctly with data strings, but it's 12:00 AM and it's goddamn laba
					{					// so, I know that this code will not be viewed by my grief teacher
										// so I leave the implementation of this task to you, dear reader!(really how did you get here?)
						Sub temp = jNode->getObject();
						jNode->setObject(jNode->getNextPtr()->getObject());
						jNode->getNextPtr()->setObject(temp);
						wasSwap = true;
					}
				}
				else
					if (iObj < jObj)
					{
						Sub temp = jNode->getObject();
						jNode->setObject(jNode->getNextPtr()->getObject());
						jNode->getNextPtr()->setObject(temp);
						wasSwap = true;
					}

				jNode = jNode->getNextPtr();
			}
			if (!wasSwap) break;
		}
	}
	else
		cout << "one el-t!\n";
}


template <typename T>
void Deque<T>::initialize() {
	frontPtr = 0;
	backPtr = 0;
	sz = 0;
}

template <typename T>
Deque<T>::Deque() {
	initialize();
}

template <typename T>
Deque<T>::Deque(const Deque<T>&s) throw (bad_alloc) {
	initialize();
	*this = s;
}

template <typename T>
bool Deque<T>::empty() const {
	return (sz == 0);
}

template <typename T>
unsigned Deque<T>::size() const {
	return sz;
}

template <typename T>
void Deque<T>::insertFront(const T &object)
throw (bad_alloc) {
	if (empty()) {
		DLNode<T> *temp = new DLNode<T>(object);
		frontPtr = temp;
		backPtr = temp;
	}
	else {
		DLNode<T> *temp = new DLNode<T>(object);
		temp->setNextPtr(frontPtr);
		frontPtr->setPrevPtr(temp);
		frontPtr = temp;
		frontPtr->setPrevPtr(0);
	}
	sz++;
}

template <typename T>
void Deque<T>::insertBack(const T &object)
throw (bad_alloc) {
	if (empty()) {
		DLNode<T> *temp = new DLNode<T>(object);
		frontPtr = temp;
		backPtr = temp;
	}
	else {
		DLNode<T> *temp = new DLNode<T>(object);
		backPtr->setNextPtr(temp);
		temp->setPrevPtr(backPtr);
		backPtr = temp;
	}
	sz++;
}

template <typename T>
T Deque<T>::removeFront() throw (NoSuchObject) {
	if (empty())
		throw NoSuchObject
		("Deque<T>::removeFront: empty deque");
	DLNode<T> *temp = frontPtr;
	frontPtr = frontPtr->getNextPtr();
	T object = temp->getObject();
	delete temp;
	if (frontPtr != 0)
		frontPtr->setPrevPtr(0);
	else
		backPtr = 0;
	sz--;
	return object;
}

template <typename T>
T Deque<T>::removeBack() throw (NoSuchObject) {
	if (empty())
		throw NoSuchObject
		("Deque<T>::removeBack: empty deque");
	DLNode<T> *temp = backPtr;
	backPtr = backPtr->getPrevPtr();
	T object = temp->getObject();
	delete temp;
	if (backPtr != 0)
		backPtr->setNextPtr(0);
	else
		frontPtr = 0;
	sz--;
	return object;
}

template <typename T>
T& Deque<T>::front() const throw (NoSuchObject) {
	if (empty())
		throw NoSuchObject
		("Deque<T>::front: empty deque");
	return frontPtr->getObject();
}

template <typename T>
T& Deque<T>::back() const throw (NoSuchObject) {
	if (empty())
		throw NoSuchObject
		("Deque<T>::back: empty deque");
	return backPtr->getObject();
}

template <typename T>
const Deque<T> &Deque<T>::operator=(const Deque<T> &s)
throw (bad_alloc) {
	if (&s != this) {
		if (!empty())
			clear();
		sz = s.sz;
		DLNode<T> *qptr = s.frontPtr;
		while (qptr != 0) {
			if (backPtr == 0) {
				frontPtr = backPtr = new DLNode<T>(*qptr);
			}
			else {
				backPtr->setNextPtr(new DLNode<T>(*qptr));
				backPtr->getNextPtr()->setPrevPtr(backPtr);
				backPtr = backPtr->getNextPtr();
			}
			qptr = qptr->getNextPtr();
		}
	}
	return *this;
}

template <typename T>
void Deque<T>::print() const {
	DLNode<T>* current = frontPtr;
	int i = 0;
	cout << "front ptr: " << frontPtr << endl;
	cout << "back ptr: " << backPtr << endl;
	while (current != 0) {
		cout << "DLNode " << i << endl;
		cout << "  address: " << current << endl;
		cout << "  object: \n";
		cout << "  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << current->getObject() << endl;
		cout << "  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
		cout << "  previous: "
			<< current->getPrevPtr() << endl;
		cout << "  next: "
			<< current->getNextPtr() << endl;
		current = current->getNextPtr();
		i++;
	}
}

// X2 yep, I know that this code will not work correctly with data strings, but it's 12:00 AM and it's goddamn laba
// so, I know that this code will not be viewed by my grief teacher
// so I leave the implementation of this task to you, dear reader!(really how did you get here?)

template<>										// it needed by the task ( there is only specialization of funstion because in needed only for "Sub" class
void Deque<Sub>::printAllSubsFromDate(const string& date) const {
	DLNode<Sub>* current = frontPtr;
	int i = 0;
	cout << "front ptr: " << frontPtr << endl;
	cout << "back ptr: " << backPtr << endl;
	while (current != 0) {
		if (current->getObject().getInstDate() >= date) {	// date should be only dd/mm/yyyy
			cout << "DLNode " << i << endl;					// thats why i need date parser
			cout << "  address: " << current << endl;
			cout << "  object: \n";
			cout << "  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout << current->getObject() << endl;
			cout << "  ++++++++++++++++++++++++++++++++++++++++++++++++++++++++\n";
			cout << "  previous: "
				<< current->getPrevPtr() << endl;
			cout << "  next: "
				<< current->getNextPtr() << endl;
		}
		
		current = current->getNextPtr();
		i++;
	}
}

template <typename T>
void Deque<T>::clear() {
	DLNode<T> *temp = frontPtr;
	while (temp != 0) {
		temp = temp->getNextPtr();
		delete frontPtr;
		frontPtr = temp;
	}
	sz = 0;
	backPtr = 0;
}

template <typename T>
void Deque<T>::writeToFile() {
	cout << "input name of file: ";
	string name = inputString();

	ofstream os(name, ios::trunc);

	if (os.is_open()) {
		DLNode<T> *current = frontPtr;

		while (current != 0) {
			os << current->getObject();
			if(current != backPtr)
				os << '\n';
			current = current->getNextPtr();
		}

		cout << "information has been written to file";
	}
	else {
		cout << "failed to open file!\n";
	}

	os.close();
}

template <typename T>
void Deque<T>::readFromFile() {
	cout << "input name of file: ";
	string name = inputString();

	ifstream is(name);

	if (is.is_open()) {
		clear();		// clear from prev data
		
		T temp;
		while(!is.eof()) {
			is >> temp;
			insertBack(temp);
		}
		cout << "information has been read from file\n";
	}
	else {
		cout << "failed to open file!\n";
	}

	is.close();
}

template <typename T>
Deque<T>::~Deque<T>() {
	clear();
}

#endif // DEQUE_H