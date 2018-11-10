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
		ArrayStack(int = MAXSIZE);
		~ArrayStack();
		ArrayStack(const ArrayStack<T>&);
		ArrayStack<T>& operator=(const ArrayStack<T>&);
		bool empty() const;
		bool full() const;
		void push(const T&);
		void pop();
		T& top() const;
		void printDestroy();
	private:
		int stack_size;
		int stack_top;
		T* arr;
		void copyStack(const ArrayStack<T>&);
		void deleteStack();
	};
}
