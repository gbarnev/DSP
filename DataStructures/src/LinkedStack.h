#pragma once

namespace DSP {

	template <typename T = int>
	class LinkedStack
	{
	public:
		LinkedStack()
			: start(nullptr), len(0) {}

		~LinkedStack()
		{
			deleteStack();
		}

		LinkedStack(const LinkedStack<T>& other)
		{
			copyStack(other);
		}

		LinkedStack<T>& operator=(const LinkedStack<T>& other)
		{
			if (this != &other) {
				deleteStack();
				copyStack(other);
			}
			return *this;
		}

		bool empty() const
		{
			return len == 0;
		}

		int length() const
		{
			return len;
		}

		void push(const T& elem)
		{
			start = new Node{ elem, start };
			++len;
		}

		void pop()
		{
			if (empty())
				throw std::out_of_range("underflow");

			Node* temp = start;
			start = start->link;
			delete temp;
			--len;
		}

		T& top() const
		{
			if (empty())
				throw std::out_of_range("underflow");

			return start->data;
		}

	private:
		struct Node
		{
			T data;
			Node* link;
		};
		Node* start;
		int len;

		void copyStack(const LinkedStack<T>& other)
		{
			len = other.len;

			if (other.empty()) {
				start = nullptr;
				return;
			}

			start = new Node;
			start->data = other.start->data;

			Node* currThis = start;
			Node* tmpOther = other.start->link;

			while (tmpOther != nullptr) {
				currThis->link = new Node;
				currThis->link->data = tmpOther->data;
				currThis = currThis->link;
				tmpOther = tmpOther->link;
			}
			currThis->link = nullptr;
		}

		void deleteStack()
		{
			while (!empty()) {
				pop();
			}
		}
	};
}