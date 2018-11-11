#pragma once

#ifdef MAKEDLL
#  define DLLEXPORT __declspec(dllexport)
#else
#  define DLLEXPORT __declspec(dllimport)
#endif

namespace DSP {

	const int MAXSIZE = 200;

	template <typename T = int>
	class DLLEXPORT ArrayStack
	{
	public:
		ArrayStack(int size = MAXSIZE)
			: stack_size(size), stack_top(-1), arr(nullptr)
		{
			if (size <= 0) stack_size = MAXSIZE;
			arr = new T[stack_size];
		}

		ArrayStack(const ArrayStack<T>& from)
		{
			copyStack(from);
		}

		virtual ~ArrayStack()
		{
			deleteStack();
		}

		ArrayStack<T>& operator=(const ArrayStack<T>& other)
		{
			if (this != &other) {
				deleteStack();
				copyStack(other);
			}
			return *this;
		}

		bool empty() const
		{
			return stack_top == -1;
		}

		bool full() const
		{
			return stack_top == stack_size - 1;
		}

		void push(const T& elem)
		{
			if (full())
				throw std::runtime_error("overflow");
			arr[++stack_top] = elem;
		}

		void pop()
		{
			if (empty())
				throw std::runtime_error("underflow");
			stack_top--;
		}

		T& top() const
		{
			if (empty())
				throw std::runtime_error("underflow");
			return arr[stack_top];
		}

		int length() const
		{
			return stack_top + 1;
		}

		void printDestroy()
		{
			while (!empty()) {
				std::cout << top() << " ";
				pop();
			}
			std::cout << std::endl;
		}

	private:
		int stack_size;
		int stack_top;
		T* arr;

		void copyStack(const ArrayStack<T>& other)
		{
			this->stack_size = other.stack_size;
			this->stack_top = other.stack_top;
			this->arr = new T[other.stack_size];

			for (int i = 0; i < stack_size; i++) {
				arr[i] = other.arr[i];
			}
		}

		void deleteStack()
		{
			delete[] arr;
		}
	};
}
