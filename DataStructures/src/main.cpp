#include "DataStructures.h"
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
	LinkedQueue<int> myQueue = LinkedQueue<int>();
	myQueue.push(3);
	myQueue.push(43);
	myQueue.push(1);
	myQueue.push(5);
	myQueue.push(12);
	myQueue.push(15);
	myQueue.push(2);
	myQueue.push(35);
	myQueue.push(21);
	printQueue(myQueue);
	return 0;
}