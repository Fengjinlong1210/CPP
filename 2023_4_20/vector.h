#pragma once
#include <iostream>
#include <assert.h>
#include <algorithm>
using std::cout;
using std::endl;

namespace Fjl
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		//构造
		vector<T>() :_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const_iterator cbegin() const
		{
			return _start;
		}

		const_iterator cend() const
		{
			return _finish;
		}

		void push_back(T val)
		{
			//判断扩容
			if (_finish == _end_of_storage)
			{
				//扩容
				int n = capacity() == 0 ? 4 : capacity() * 2;
				reserve(n);
			}

			*_finish = val;
			++_finish;

		}

		void reserve(size_t n)
		{
			size_t sz = size();
			size_t cap = capacity();
			if (n > cap)
			{
				T* tmp = new T[n];
				if (_start != nullptr)//如果start中有数据，需要拷贝到新空间
				{
					memcpy(tmp, _start, sizeof(T) * sz);
				}
				
				_start = tmp;
				_finish = _start + sz;
				_end_of_storage = _start + n;
			}
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _end_of_storage - _start;
		}

		T& operator[](size_t pos)
		{
			assert(pos < size());
			return _start[pos];
		}

		bool empty() const
		{
			return _start == _finish;
		}

		void resize(size_t n, T val = T())//默认构造
		{
			if (n > capacity())
			{
				//扩容到capacity并且填充val
				reserve(n);
				while (_finish != _end_of_storage)
				{
					*_finish = val;
					++_finish;
				}
			}
			else//n <= capacity
			{
				if (n < size())
				{
					_finish = _start + n;
				}
				else//n >= size && n <= capacity
				{
					//填充到n个val
					while (_finish != (_start + n))
					{
						*_finish = val;
						++_finish;
					}
				}
			}
		}

		void pop_back()
		{
			assert(!empty());
			--_finish;
		}

		iterator insert(iterator pos, const T& val)
		{
			assert(pos >= _start);
			assert(pos <= _finish);
			//再pos前插入元素
			//判断是否需要扩容
			if (_finish = _end_of_storage)
			{
				size_t len = pos - _start;
				size_t n = (capacity() == 0) ? 4 : 2 * capacity();
				//扩容后地址会发生改变，原来的pos会失效
				reserve(n);
				pos = _start + len;
				//防止出现迭代器失效问题
			}
			//挪动元素
			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}

			*pos = val;
			++_finish;

			return pos;
		}

		void erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);
			assert(!empty());
			//挪动数据
			iterator end = pos + 1;
			while (end < _finish - 1)
			{
				*(end - 1) = *(end);
				++end;
			}

			--_finish;
		}

		const T& operator[](size_t pos) const
		{
			assert(pos < size());
			return _start[pos];
		}

		void Print() const
		{
			size_t i = 0;
			for (; i < size(); ++i)
			{
				cout << _start[i] << " ";
			}
			cout << endl;
		}

	private:
		iterator _start;
		iterator _finish;
		iterator _end_of_storage;
	};
}