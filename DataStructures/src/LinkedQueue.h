#pragma once

namespace DSP {

	template <typename T = int>
	class LinkedQueue
	{
	public:
		LinkedQueue()
			: front(nullptr), rear(nullptr), len(0) {}

		virtual ~LinkedQueue()
		{
			deleteQueue();
		}

		LinkedQueue(const LinkedQueue<T>& other) : LinkedQueue()
		{
			copyQueue(other);
		}

		LinkedQueue<T>& operator=(const LinkedQueue<T>& other)
		{
			if (this != &other) {
				deleteQueue();
				copyQueue(other);
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
			Node* newEl = new Node{ elem, nullptr };

			if (front != nullptr)
				rear->link = newEl;
			else
				front = newEl;
			rear = newEl;
			len++;
		}

		void pop()
		{
			if (empty())
				throw std::out_of_range("underflow");

			Node* cur = front;

			if (front == rear)
			{
				front = nullptr;
				rear = nullptr;
			}
			else
			{
				front = front->link;
			}
			
			delete cur;
			--len;
		}

		T& head() const
		{
			if (empty())
				throw std::out_of_range("empty");

			return front->data;
		}

	private:
		struct Node
		{
			T data;
			Node* link;
		};

		Node* front;
		Node* rear;
		int len;

		void copyQueue(const LinkedQueue<T>& other)
		{
			front = rear = nullptr;
			Node* cur = other.front;
			while (cur != nullptr)
			{
				push(cur->data);
				cur = cur->link;
			}
		}

		void deleteQueue()
		{
			while (!empty())
			{
				pop();
			}
		}
	};
}