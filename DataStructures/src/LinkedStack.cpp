#include <stdexcept>
#include <iostream>
#include "LinkedStack.h"

namespace DSP {

	template <typename T>
	LinkedStack<T>::LinkedStack()
		: start(nullptr), len(0) {}

	template <typename T>
	LinkedStack<T>::LinkedStack(const LinkedStack<T>& other)
	{
		copyStack(other);
	}

	template <typename T>
	LinkedStack<T>::~LinkedStack()
	{
		deleteStack();
	}

	template <typename T>
	LinkedStack<T>& LinkedStack<T>::operator=(const LinkedStack<T>& other)
	{
		if (this != &other) {
			deleteStack();
			copyStack(other);
		}
		return *this;
	}

	template <typename T>
	bool LinkedStack<T>::empty() const
	{
		return len == 0;
	}

	template <typename T>
	int LinkedStack<T>::length() const
	{
		return len;
	}

	template <typename T>
	void LinkedStack<T>::push(const T& elem)
	{
		start = new Node{ elem, start };
		++len;
	}

	template <typename T>
	void LinkedStack<T>::pop()
	{
		if (empty())
			throw std::out_of_range("underflow");

		Node* temp = start;
		start = start->link;
		delete temp;
		--len;
	}

	template <typename T>
	T& LinkedStack<T>::top() const
	{
		if (empty())
			throw std::out_of_range("underflow");

		return start->data;
	}

	template <typename T>
	void LinkedStack<T>::copyStack(const LinkedStack<T>& other)
	{
		this->len = other.len;

		if (other.empty()) {
			this->start = nullptr;
			return;
		}

		this->start = new Node;
		this->start->data = other.start->data;

		Node* currThis = this->start;
		Node* tmpOther = other.start->link;

		while (tmpOther != nullptr) {
			currThis->link = new Node;
			currThis->link->data = tmpOther->data;
			currThis = currThis->link;
			tmpOther = tmpOther->link;
		}
		currThis->link = nullptr;
	}

	template <typename T>
	void LinkedStack<T>::deleteStack()
	{
		while (!empty()) {
			pop();
		}
	}
}

