#include "LinkedList.h"
#include <iostream>
using namespace DSP;
using namespace std;

template <typename T>
void printList(LinkedList<T> list)
{

	for (auto i = list.begin(); i != list.end(); ++i)
	{
		cout << *i << ' ';
	}
	cout << endl;
}

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
	LinkedList<T> result;
	auto iter1 = l1.begin();
	auto iter2 = l2.begin();

	while (iter1 != l1.end() && iter2 != l2.end())
	{
		if (*iter1 == *iter2)
		{
			result.push_back(*iter1);
			result.push_back(*iter2);
			++iter1;
			++iter2;
		}
		else if (*iter1 > *iter2)
		{
			result.push_back(*iter2);
			++iter2;
		}
		else
		{
			result.push_back(*iter1);
			++iter1;
		}
	}
	while (iter1 != l1.end()) result.push_back(*iter1++);
	while (iter2 != l2.end()) result.push_back(*iter2++);
	return result;
}


template<typename T>
void mergeSort(LinkedList<T>& list)
{
	if (list.size() < 2) return;

	LinkedList<T> l1, l2;
	auto iter = list.begin();
	int i = 0;
	while (iter != list.end())
	{
		(i % 2) == 0 ? l1.push_back(*iter) : l2.push_back(*iter);
		++i;
		++iter;
	}
	mergeSort(l1);
	mergeSort(l2);
	list = mergeLists(l1, l2);
}

template <typename T>
bool member(const T& item, const LinkedList<T>& list)
{
	auto iter = list.begin();
	while (iter != list.end())
	{
		if (item == *iter)
			return true;
		++iter;
	}
	return false;
}

template <typename T>
LinkedList<T> unionSet(const LinkedList<T>& l1, const LinkedList<T>& l2)
{
	LinkedList<T> result;
	auto iter1 = l1.begin();
	auto iter2 = l2.begin();

	while (iter1 != l1.end())
	{
		if (!member(*iter1, result))
		{
			result.push_back(*iter1);
		}
		++iter1;
	}
	
	while (iter2 != l2.end())
	{
		if (!member(*iter2, result))
		{
			result.push_back(*iter2);
		}
		++iter2;
	}
	return result;
}

template<typename T>
T plusOp(T first, T second) { return first + second; }

template<typename T>
T accumulate(T(*op)(T, T), T initVal, const LinkedList<T>& list)
{
	T result = initVal;
	for (auto& elem : list)
	{
		result = op(result, elem);
	}
	return result;
}

template<typename T, typename R>
LinkedList<R> map(R(*op)(T), const LinkedList<T>& list)
{
	LinkedList<R> result;
	for (auto& elem : list)
	{
		result.push_back(op(elem));
	}
	return result;
}

template<typename T>
bool positivePred(T item) { return item > 0; }

template<typename T>
LinkedList<T> filter(bool(*pred)(T), const LinkedList<T>& list)
{
	LinkedList<T> result;
	for (auto& elem : list)
	{
		if (pred(elem))
		{
			result.push_back(elem);
		}
	}
	return result;
}







