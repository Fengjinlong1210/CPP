#pragma once
#include <iostream>
#include <vector>
#include <list>
#include <stack>
using namespace std;

namespace Fjl
{
	template<class T, class Container = vector<T>>
	class stack
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_back();
		}

		T& top()
		{
			return _con.back();
		}
		
		bool empty() const
		{
			return _con.empty();
		}

		size_t size() const
		{
			return _con.size();
		}

	private:
		Container _con;
	};

	template<class T, class Container = list<T>>
	class queue
	{
	public:
		void push(const T& val)
		{
			_con.push_back(val);
		}

		void pop()
		{
			_con.pop_front(val);
		}

		bool empty()
		{
			return _con.empty();
		}

		T& front()
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}

		size_t size()
		{
			return _con.size();
		}

	private:
		Container _con;
	};
}