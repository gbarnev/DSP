#include "LinkedList.h"

using namespace DSP;
using namespace std;

template<typename T>
LinkedList<T> concatLists(const LinkedList<T>& l1, const LinkedList<T>& l2)
{
	LinkedList<T> result = l1;
	for (auto i = l2.begin(); i != l2.end(); ++i)
	{
		result.push_back(*i);
	}
	return result;
}

template<typename T>
LinkedList<T> reverseList(const LinkedList<T>& list)
{
	LinkedList<T> result;
	for (auto i = list.begin(); i != list.end(); ++i)
	{
		result.push_front(*i);
	}
	return result;
}


template<typename T>
LinkedList<T> mergeLists(const LinkedList<T>& l1, const LinkedList<T>& l2)
{
	//TODO implement this function
	//LinkedList<T> result;
	

}





