#include "DataStructures.h"
#include "ListExamples.cpp"
#include <iostream>
using namespace DSP;
using namespace std;

template <typename T>
void printQueue(LinkedQueue<T> queue)
{
	while (!queue.empty())
	{
		cout << queue.head() << " ";
		queue.pop();
	}
	cout << endl; 
}

template <typename T>
void printList(LinkedList<T> list)
{

	for (auto i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}


int main(int argc, char** argv)
{
	LinkedList<int> myList = LinkedList<int>();
	myList.push_back(3);
	myList.push_back(43);
	myList.push_back(1);
	myList.push_back(5);
	myList.push_back(12);
	myList.push_back(15);
	myList.push_front(2);
	myList.push_back(35);
	myList.push_back(21);

	LinkedList<int> myListCpy = myList;
	myListCpy.insert((++(++(++myListCpy.begin()))), 999);
	myListCpy.erase((--(--myListCpy.end())));

	printList(myList);
	printList(myListCpy);

	LinkedList<int> reverse = reverseList(myList);
	printList(reverse);

	return 0;
}