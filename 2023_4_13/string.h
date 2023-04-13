#pragma once
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;

namespace Fjl
{
	class string
	{

	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//����1:���ַ���
		string(const char* str = "")//�Զ�����\0
			:_size(strlen(str))
		{
			_capacity = (_size == 0) ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//��������:��string��ʼ��
		string(const string& str)
			:_size(str._size),
			_capacity(str._capacity)
		{
			//���
			_str = new char[_capacity + 1];
			strcpy(_str, str._str);
		}
		
		//����
		~string()
		{
			//std::cout << "~string()" << this << std::endl;
			//�ͷ�_str
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		//��ֵ���������
		string& operator=(const string& s)
		{
			//���
			//�ж���ֵ����ֵ�Ƿ����
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				_capacity = s._capacity;
				_size = s._size;
				//�ͷ�_strԭ���Ŀռ�
				delete[] _str;
				_str = tmp;
				strcpy(_str, s._str);				
			}
			return *this;
		}

		//size
		size_t size() const
		{
			return _size;
		}

		//capacity
		size_t capacity() const
		{
			return _capacity;
		}

		//reserve
		void reserve(size_t newsize)
		{
			//newsize����capacityʱ��������Ч
			if (newsize >= _capacity)
			{
				//�¿���һ��ռ�
				char* tmp = new char[newsize + 1];
				_capacity = newsize;
				strcpy(tmp, _str);
				delete[] _str;
				_str = tmp;
			}
		}

		//operator[] const
		char& operator[](size_t pos) const
		{
			assert(pos < _size);
			return _str[pos];
		}

		//operator[]  ��stringʹ��[]
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		//append׷��c�����ַ���
		string& append(const char* str)
		{
			//Ϊ�ַ��������㹻�Ĵ�С
			int length = strlen(str);
			if (_capacity < _size + length)
			{
				reserve(_capacity + length);
			}
			strcpy(_str + _size, str);
			_size += length;
			return *this;
		}

		//push_back
		void push_back(const char ch)
		{
			if (_size + 1 > _capacity)
			{
				reserve(_capacity + 1);
			}
			_str[_size] = ch;
			++_size;

			_str[_size] = '\0';
		}

		//insert ::char
		string& insert(size_t pos, const char ch)
		{
			//�жϳ����Ƿ��㹻
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);;
			}

			//Ų��Ԫ��
			size_t end = _size + 1;
			//while (end >= pos)//pos==0ʱ������ѭ��
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			while (end > pos)//pos==0ʱ��endҲ��==0
			{
				_str[end] = _str[end - 1];
				--end;
			}

			_str[pos] = ch;
			++_size;

			return *this;
		}

		//insert  str
		string& insert(size_t pos, const char* str)
		{
			//�жϳ���
			size_t length = strlen(str);
			if (_size + length > _capacity)
			{
				reserve(_capacity + length);
			}

			//Ų������:δ���
			memmove(_str + pos + length, _str + pos, sizeof(char)*(_size - pos));

			strncpy(_str + pos, str, length);
			_size += length;
			_str[_size] = '\0';

			return *this;
		}

		//resize
		void resize(size_t newsize, const char ch = '\0')
		{
			//��newsize > capacityʱ
			//��newsize����size��capacityʱ
			//��newsize < capacityʱ
			if (newsize < _size)
			{
				_size = newsize;
				_str[_size] = '\0';
			}
			else//newsize >= _size
			{
				if (newsize > _capacity)
				{
					//����
					reserve(newsize);
				}
				size_t i = _size;
				for (; i < newsize; ++i)
				{
					_str[i] = ch;
				}
				_size = newsize;
			}
		}

		//erase

		//c_str
		char* c_str()
		{
			return _str;
		}
			
		//>
		bool operator>(const string& s) const
		{
			return strcmp(_str, s._str) > 0;
		}

		//>=
		bool operator>=(const string& s) const
		{
			return (*this == s) || (*this > s);
		}

		//==
		bool operator==(const string& s) const
		{
			return strcmp(_str, s._str) == 0;
		}

		//!=
		bool operator!=(const string& s) const
		{
			return !(*this == s);
		}

		//<
		bool operator<(const string& s) const
		{
			return !(*this >= s);
		}

		//<=
		bool operator<=(const string& s) const
		{
			return !(*this > s);
		}

		//+=
		string& operator+=(const char ch)
		{
			push_back(ch);
			return *this;
		}

		string& operator+=(const char* str)
		{
			append(str);
			return *this;
		}

		iterator begin()
		{
			return _str;
		}

		const_iterator begin() const
		{
			return _str;
		}

		iterator end()//���ؽ������һ���ַ�
		{
			return _str + _size;
		}

		const_iterator end() const//���ؽ������һ���ַ�
		{
			return _str + _size;
		}

		void Print() const
		{
			size_t i = 0;
			for (; i < _size; i++)
			{
				cout << _str[i];
			}
			cout << endl;
		}

	private:
		char* _str;
		size_t _size;
		size_t _capacity;
	};
}