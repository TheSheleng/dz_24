#include <iostream>

#include "QueueList.h"

using namespace std;

int main()
{
	QueueList<int> test;

	test.push(5);
	test.push(4);
	test.push(3);
	test.push(2);
	test.push(1);

	test.print();

	cout << test.extract().data;
	cout << test.extract().data;
	cout << test.extract().data;
	cout << test.extract().data;
	cout << test.extract().data;

	test.push(2);

	cout << test.getFirst();
	cout << test.extract().data;
}