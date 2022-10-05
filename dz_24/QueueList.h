#pragma once

#include <iostream>

using namespace std;

template<typename T>
struct Node
{
	T data;
	Node<T>* next;
	Node<T>* prev;
};

template<typename T>
class QueueList
{
	Node<T>* head;
	Node<T>* tail;

	unsigned int count;

public:
	QueueList();
	~QueueList();

	void push(T _a);
	Node<T> extract();
	bool is_empty();
	void print();
	unsigned int getCount();
	T getFirst();
};

template<typename T>
inline QueueList<T>::QueueList() : head(nullptr), tail(nullptr), count(0U) {}

template<typename T>
inline QueueList<T>::~QueueList()
{
	while (!is_empty()) extract();
}

template<typename T>
inline void QueueList<T>::push(T _a)
{
	tail = (count == NULL ? head : tail->prev) = new Node <T>{ _a, tail, nullptr };
	count++;
}

template<typename T>
inline Node<T> QueueList<T>::extract()
{
	Node<T> temp = *head;

	if (head == tail) delete head;
	else
	{
		head = head->prev;
		delete head->next;
	}
	count--;

	return temp;
}

template<typename T>
inline bool QueueList<T>::is_empty()
{
	return count == 0U ? true : false;
}

template<typename T>
inline void QueueList<T>::print()
{
	for (Node<T>* i = head; i != tail; i = i->prev ) cout << i->data;
	cout << tail->data << endl;
}

template<typename T>
inline unsigned int QueueList<T>::getCount()
{
	return count;
}

template<typename T>
inline T QueueList<T>::getFirst()
{
	return T(head->data);
}
