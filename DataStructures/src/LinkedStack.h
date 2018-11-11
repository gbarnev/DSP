#pragma once

#ifdef MAKEDLL
#  define DLLEXPORT __declspec(dllexport)
#else
#  define DLLEXPORT __declspec(dllimport)
#endif

namespace DSP {

	template <typename T = int>
	class DLLEXPORT LinkedStack
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

		void deleteStack()
		{
			while (!empty()) {
				pop();
			}
		}
	};
}