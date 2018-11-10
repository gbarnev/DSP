#include <stdexcept>
#include <iostream>
#include "ArrayStack.h"

namespace DSP {

	template <typename T>
	ArrayStack<T>::ArrayStack(int size)
		:stack_size(size), stack_top(-1), arr(nullptr)
	{
		if (size <= 0) stack_size = MAXSIZE;
		arr = new T[stack_size];
	}

	template <typename T>
	ArrayStack<T>::ArrayStack(const ArrayStack& from)
	{
		copyStack(from);
	}

	template <typename T>
	ArrayStack<T>& ArrayStack<T>::operator=(const ArrayStack<T>& other)
	{
		if (this != &other) {
			deleteStack();
			copyStack(other);
		}
		return *this;
	}

	template <typename T>
	ArrayStack<T>::~ArrayStack()
	{
		deleteStack();
	}

	template <typename T>
	bool ArrayStack<T>::empty() const
	{
		return stack_top == -1;
	}

	template <typename T>
	bool ArrayStack<T>::full() const
	{
		return stack_top == stack_size - 1;
	}

	template <typename T>
	void ArrayStack<T>::push(const T& elem)
	{

		if (full()) throw std::runtime_error("overflow");
		arr[++stack_top] = elem;
	}

	template <typename T>
	void ArrayStack<T>::pop()
	{

		if (empty()) throw std::runtime_error("underflow");
		stack_top--;
	}

	template <typename T>
	T& ArrayStack<T>::top() const
	{

		if (empty()) throw std::runtime_error("underflow");
		return arr[stack_top];
	}

	template <typename T>
	void ArrayStack<T>::printDestroy()
	{
		while (!empty()) {
			std::cout << top() << " ";
			pop();
		}
		std::cout << std::endl;
	}

	template <typename T>
	void ArrayStack<T>::copyStack(const ArrayStack<T>& other)
	{
		this->stack_size = other.stack_size;
		this->stack_top = other.top;
		this->arr = new T[other.stack_size];

		for (int i = 0; i < stack_size; i++) {
			arr[i] = other.arr[i];
		}
	}

	template <typename T>
	void ArrayStack<T>::deleteStack()
	{
		delete[] arr;
	}
}