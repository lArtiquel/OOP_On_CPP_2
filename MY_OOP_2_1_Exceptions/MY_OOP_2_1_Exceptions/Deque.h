#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <stdexcept>
#include <new>
#include "Dlnode.h"
#include "NoSuchObject.h"

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
	void clear();
	bool find(const T&);
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
		cout << "  object: "
			<< current->getObject() << endl;
		cout << "  previous: "
			<< current->getPrevPtr() << endl;
		cout << "  next: "
			<< current->getNextPtr() << endl;
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
Deque<T>::~Deque<T>() {
	clear();
}

#endif // DEQUE_H