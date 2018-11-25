#include "DataStructures.h"
#include "ListExamples.h"
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

int main(int argc, char** argv)
{
	LinkedList<int> myList = LinkedList<int>();
	myList.push_back(3);
	myList.push_back(1);
	myList.push_back(5);
	myList.push_back(12);
	myList.push_back(15);
	myList.push_front(2);

	LinkedList<int> myListCpy = myList;
	myListCpy.insert((++(++(++myListCpy.begin()))), 999);
	myListCpy.erase((--(--myListCpy.end())));

	printList(myList);
	cout << "Accumulation of plus is: " << accumulate(plusOp, 0, myList) << endl;

	cout << "Mapping chars to integers: ";
	LinkedList<const char*> strL = LinkedList<const char*>();
	strL.push_back("-123");
	strL.push_back("13");
	strL.push_back("-11");
	strL.push_back("3");
	strL.push_back("8");
	auto ints = map(atoi, strL);
	printList(ints);

	auto filtered = filter(positivePred, ints);
	printList(filtered);


	return 0;
}