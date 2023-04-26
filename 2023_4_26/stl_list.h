#pragma once
#include <iostream>
#include <algorithm>
#include <assert.h>
using std::cout;
using std::endl;

namespace Fjl
{
	template<class T>
	struct list_node
	{
		list_node* _next;
		list_node* _prev;
		T _val;

		list_node(const T& val = T())
			:_next(nullptr), _prev(nullptr), _val(val)
		{}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator
	{
		typedef __list_iterator<T, Ref, Ptr> self;
		typedef list_node<T> node;

		node* _node;

		__list_iterator(node* x)
			:_node(x)
		{}

		bool operator!=(const self& it)
		{
			return _node != it._node;
		}

		bool operator==(const self& it)
		{
			return _node == it._node;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self& operator++(int)
		{
			self tmp(*this);
			_node = _node->_next;
			return tmp;
		}

		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}

		self& operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}

		Ref operator*()
		{
			return _node->_val;
		}

		Ptr operator->()
		{
			return &_node->_val;
		}

	};

	template<class T>
	class list
	{
		typedef list_node<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		void empty_init()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list()
		{
			empty_init();
		}
		
		//传统写法
		/*
		list(const list<T>& lt)
		{
			empty_init();
			for (auto e : lt)
			{
				push_back(e);
			}
		}
		*/

		void Swap(list<T>& tmp)
		{
			std::swap(_head, tmp._head);
		}

		//现代写法
		list(const list<T>& lt)
		{
			empty_init();

			list<T> tmp(lt.begin(), lt.end());
			Swap(*this, lt);
		}

		list<T>& operator=(list<T>& lt)
		{
			swap(lt);
			return *this;
		}

		~list()
		{
			clear();
			delete _head;
			_head = nullptr;
		}

		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}

		template <class Iterator>
		list(Iterator first, Iterator last)
		{
			empty_init();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);
			_head->_prev = newnode;
			newnode->_next = _head;
			tail->_next = newnode;
			newnode->_prev = tail;
		}

		void pop_back()
		{
			assert(*this);
			assert(!empty());
			erase(iterator(_head->_prev));
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void pop_front()
		{
			assert(!empty());
			erase(iterator(_head->_next));
		}

		bool empty()
		{
			return _head->_next = _head;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos._node);
			node* pos_prev = pos._node->_prev;
			node* newnode = new node(val);
			pos_prev->_next = newnode;
			newnode->_prev = pos_prev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;

			return iterator(newnode);
		}

		iterator erase(iterator pos)
		{
			node* pos_prev = pos._node->_prev;
			node* pos_next = pos._node->_next;
			pos_prev->_next = pos_next;
			pos_next->_prev = pos_prev;
			delete pos._node;

			return iterator(pos_next);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator end() const
		{
			return const_iterator(_head);
		}

		void Print()
		{
			iterator it = begin();
			while (it != end())
			{
				cout << *it << " ";
				++it;
			}
			cout << endl;
		}

	private:
		node* _head;
	};
}