#pragma once
#pragma once
#include <iostream>
#include <assert.h>
#include "iterator.h"
using std::cout;
using std::endl;


//模拟实现stl_list
/*
双向带头循环链表
需要定义一个struct node充当头结点
*/
namespace Fjl
{
	template<class T>
	struct ListNode
	{
		ListNode<T>* _next;
		ListNode<T>* _prev;
		T _val;

		ListNode(const T& val = T())
			:_next(nullptr), _prev(nullptr), _val(val)
		{
		}
	};

	template<class T, class Ref, class Ptr>
	struct __list_iterator		//还要实现const迭代器和const解引用
	{
		typedef __list_iterator<T, T&, T*> self;
		typedef ListNode<T> node;

		node* _node;  //创建一个node用于迭代器指向链表结点

		__list_iterator(node* x)
			:_node(x)
		{}

		Ref operator*()  //返回Ref模板参数,如果是const对象调用,会返回const类型引用
		{
			return _node->_val;
		}

		//对迭代器的解引用
		Ptr operator->()
		{
			return &_node->_val;
		}

		bool operator==(const self& x)
		{
			return _node == x._node;
			//x是迭代器,_node是迭代器类中声明的结点指针,要比较两个指针是否相等
		}

		bool operator!=(const self& x)
		{
			return _node != x._node;
		}

		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}

		self operator++(int)
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

		self operator--(int)
		{
			self tmp(*this);
			_node = _node->_prev;
			return tmp;
		}
	};

	template<class T>
	class list
	{
		typedef ListNode<T> node;
	public:
		typedef __list_iterator<T, T&, T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;

		typedef ReverseIterator<iterator, T&, T*> reverse_iterator;


		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& val = T())//使用T类型的默认构造做缺省值
		{
			//node* tail = _head->_prev;
			//node* newnode = new node(val);  //用val创建出一个新结点
			//tail->_next = newnode;
			//newnode->_prev = tail;
			//_head->_prev = newnode;
			//newnode->_next = _head;
			insert(end(), val);
		}

		void push_front(const T& val = T())
		{
			insert(begin(), val);
		}

		void pop_back()
		{
			//node* tail = _head->_prev;
			//node* tailprev = tail->_prev;  //找到最后一个结点的前一个结点
			//tailprev->_next = _head;
			//_head->_prev = tailprev;
			//delete tail;
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		iterator erase(iterator pos)
		{
			assert(_head);
			assert(pos != end());
			node* pos_prev = pos._node->_prev;
			node* pos_next = pos._node->_next;
			pos_prev->_next = pos_next;
			pos_next->_prev = pos_prev;

			delete pos._node;
			return iterator(pos_next);
		}

		iterator insert(iterator pos, const T& val)
		{
			node* pos_prev = pos._node->_prev;
			node* newnode = new node(val);

			pos_prev->_next = newnode;
			newnode->_prev = pos_prev;
			newnode->_next = pos._node;
			pos._node->_prev = newnode;

			return iterator(newnode);
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		const_iterator cbegin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}

		const_iterator cend() const
		{
			return const_iterator(_head);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}

		void Print()
		{
			assert(_head->_next != _head);
			assert(_head);
			iterator start = _head->_next;
			while (start != end())
			{
				cout << *start << " ";
				++start;
			}
			cout << endl;
		}

	private:
		node* _head;
	};

	struct AA
	{
		int _a1;
		int _a2;

		AA(int a1 = 0, int a2 = 0)
			:_a1(a1), _a2(a2)
		{}
	};

}