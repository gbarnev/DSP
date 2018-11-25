#pragma once
#include <stdexcept>
namespace DSP
{
	//Implements Doubly Linked List
	template <typename T = int>
	class LinkedList
	{
		struct Node;
	public:
		
		#pragma region Iterator
		class Iterator
		{
		private:
			Node *_ptr;

		public:
			friend class LinkedList<T>;
			Iterator() : _ptr(nullptr) {};
			Iterator(Node* ptr) : _ptr(ptr) {};

			bool operator==(const Iterator& other) const
			{
				return _ptr == other._ptr;
			}

			bool operator!=(const Iterator& other) const
			{
				return !(*this == other);
			}

			operator bool() const
			{
				return _ptr;
			}

			Iterator& operator++()
			{
				_ptr = _ptr->_next;
				return *this;
			}

			Iterator operator++(int)
			{
				Iterator old = *this;
				++(*this);
				return old;
			}

			Iterator& operator--()
			{
				_ptr = _ptr->_prev;
				return *this;
			}

			Iterator operator--(int)
			{
				Iterator old = *this;
				--(*this);
				return *this;
			}

			T& operator*()
			{
				return _ptr->_data;
			}
		};
		#pragma endregion

		LinkedList()
			: _len(0)
		{
			_start = _end = new Node();
		};

		~LinkedList()
		{
			deleteList();
		}

		LinkedList(const LinkedList& other)
			: LinkedList()
		{
			copyList(other);
		}

		LinkedList& operator=(const LinkedList& other)
		{
			if (this != &other)
			{
				deleteList();
				copyList(other);
			}
			return *this;
		}

		bool empty() const
		{
			return _len == 0;
		}

		Iterator begin() const
		{
			return Iterator(_start);
		}

		Iterator end() const
		{
			return Iterator(_end);
		}

		Iterator insert(const Iterator& it, const T& elem)
		{
			if (empty())
			{
				push_front(elem);
				return begin();
			}

			Node* node = new Node(elem, it._ptr->_prev, it._ptr);
			it._ptr->_prev->_next = node;
			it._ptr->_prev = node;
			++_len;
			return Iterator(node);
		}

		void push_front(const T& elem)
		{
			Node* node = new Node(elem, nullptr, _start);
			_start->_prev = node;
			_start = node;
			++_len;
		}

		void push_back(const T& elem)
		{
			if (empty())
			{
				push_front(elem);
				return;
			}
			insert(end(), elem);
		}

		int size() const
		{
			return this->_len;
		}

		void pop_back()
		{
			if (empty())
				throw std::out_of_range("underflow");

			Iterator tmp = Iterator(_end->_prev);
			erase(tmp);
		}

		void pop_front()
		{
			if (empty())
				throw std::out_of_range("empty");

			Node* toDelete = _start;
			_start = _start->_next;
			_start->_prev = nullptr;
			delete toDelete;
			--_len;
		}

		Iterator erase(Iterator& it)
		{
			if (empty())
				throw std::out_of_range("empty");

			if (!it || it == end())
				throw std::out_of_range("invalid iterator");

			if (it == begin())
			{
				pop_front();
				it._ptr = nullptr;
				return begin();
			}

			Iterator next = Iterator(it._ptr->_next);
			it._ptr->_next->_prev = it._ptr->_prev;
			it._ptr->_prev->_next = it._ptr->_next;
			--_len;
			delete it._ptr;
			it._ptr = nullptr;
			return next;
		}

	private:
		struct Node
		{
			T _data;
			Node *_prev, *_next;
			Node(const T& data, Node *prev = nullptr, Node* next = nullptr)
				: _data(data), _prev(prev), _next(next) {}
			Node() = default;
		};

		Node *_start, *_end;
		int _len;

		void copyList(const LinkedList<T>& other)
		{
			_len = 0;
			_start = _end = new Node();

			for (const T& elem : other)
			{
				push_back(elem);
			}
		}

		void deleteList()
		{
			while (!empty())
			{
				pop_front();
			}
			delete _end;
		}
	};
}
