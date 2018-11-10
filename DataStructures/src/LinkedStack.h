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
		LinkedStack();
		~LinkedStack();
		LinkedStack(const LinkedStack<T>&);
		LinkedStack<T>& operator=(const LinkedStack<T>&);
		bool empty() const;
		int length() const;
		void push(const T&);
		void pop();
		T& top() const;
	private:
		struct Node
		{
			T data;
			Node* link;
		};
		Node* start;
		int len;
		void copyStack(const LinkedStack<T>&);
		void deleteStack();
	};
}