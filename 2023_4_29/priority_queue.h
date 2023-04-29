#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include <deque>
#include <algorithm>
#include <queue>
using std::vector;
using std::swap;
using std::cout;
using std::endl;
//模拟实现priority_queue
namespace Fjl
{
	//仿函数
	template<class T>
	struct less
	{
		bool operator()(const T& x, const T& y)
		{
			return x < y;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& x, const T& y)
		{
			return x > y;
		}
	};

	template<class T, class Container = vector<T>, class Compare = less<T>>
	class priority_queue
	{
	public:
		//向上调整
		void adjust_up(int child)
		{
			Compare cmp;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				if (cmp(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		//向下调整
		void adjust_down(int parent)
		{
			Compare cmp;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				if (child + 1 < _con.size() && cmp(_con[child], _con[child + 1]))
				{
					++child;
				}
				if (cmp(_con[parent], _con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& val)
		{
			_con.push_back(val);
			adjust_up(_con.size() - 1);
		}

		void pop()
		{
			swap(_con[0], _con[size() - 1]);
			_con.pop_back();
			adjust_down(0);
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		const T& top()
		{
			return _con[0];
		}

	private:
		Container _con;
	};
}
