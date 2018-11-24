#pragma once

namespace DSP
{
	namespace ArrQueueConsts { const int MAXSIZE = 20; }
	template <typename T = int>
	class ArrayQueue
	{
	public:
		ArrayQueue(int maxSize = ArrQueueConsts::MAXSIZE)
			: front(0), rear(0), maxLen(maxSize), len(0), data(nullptr)
		{
			if (maxSize <= 0) maxLen = ArrStackConsts::MAXSIZE;
			data = new T[maxSize];
		}

		ArrayQueue(const ArrayQueue<T>& other)
		{
			copyQueue(other);
		}

		virtual ~ArrayQueue()
		{
			deleteQueue();
		}

		ArrayQueue<T>& operator=(const ArrayQueue<T>& other)
		{
			if (this != &other)
			{
				deleteQueue();
				copyQueue(other);
			}
			return *this;
		}

		bool empty() const
		{
			return len == 0;
		}

		bool full() const
		{
			return len == maxLen;
		}

		void push(const T& elem)
		{
			if (full())
				throw std::runtime_error("overflow");

			data[rear] = elem;
			len++;
			rear = (rear + 1) % maxLen;
		}

		T& pop()
		{
			if (empty())
				throw std::runtime_error("underflow");
			
			int curFront = front;
			len--;
			front = (front + 1) % maxLen;
			return data[curFront];
		}

		T& head() const
		{
			if (empty())
				throw std::runtime_error("empty");
			return data[front];
		}

	private:
		int front, rear, maxLen, len;
		T *data;

		void copyQueue(const ArrayQueue<T>& other)
		{
			front = other.front;
			rear = other.rear;
			maxLen = other.maxLen;
			len = other.len;
			data = new T[maxLen];

			for (int i = 0; i < maxLen; i++) 
				data[i] = other.data[i];
		}

		void deleteQueue()
		{
			delete[] data;
		}
	};
}
