#pragma once
#include <iostream>
#include <cassert>
using std::cout;
using std::endl;
using std::ostream;
using std::istream;

namespace Fjl
{
	class string
	{
		friend ostream& operator<<(ostream& out, const string& str);
		friend istream& operator>>(istream& out, string& str);

	public:
		typedef char* iterator;
		typedef const char* const_iterator;
		//构造1:空字符串
		string(const char* str = "")//自动加上\0
			:_size(strlen(str))
		{
			_capacity = (_size == 0) ? 3 : _size;
			_str = new char[_capacity + 1];
			strcpy(_str, str);
		}

		//拷贝构造:用string初始化
		string(const string& str)
			:_size(str._size),
			_capacity(str._capacity)
		{
			//深拷贝
			_str = new char[_capacity + 1];
			strcpy(_str, str._str);
		}

		//析构
		~string()
		{
			//std::cout << "~string()" << this << std::endl;
			//释放_str
			delete[] _str;
			_str = nullptr;
			_capacity = _size = 0;
		}

		//赋值运算符重载
		string& operator=(const string& s)
		{
			//深拷贝
			//判断左值和右值是否相等
			if (this != &s)
			{
				char* tmp = new char[s._capacity + 1];
				_capacity = s._capacity;
				_size = s._size;
				//释放_str原本的空间
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
			//newsize大于capacity时函数才生效
			if (newsize >= _capacity)
			{
				//新开辟一块空间
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

		//operator[]  对string使用[]
		char& operator[](size_t pos)
		{
			assert(pos < _size);
			return _str[pos];
		}

		//append追加c类型字符串
		string& append(const char* str)
		{
			//为字符串开辟足够的大小
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
			//判断长度是否足够
			if (_size + 1 > _capacity)
			{
				reserve(_capacity * 2);;
			}

			//挪动元素
			size_t end = _size + 1;
			//while (end >= pos)//pos==0时，会死循环
			//{
			//	_str[end + 1] = _str[end];
			//	--end;
			//}

			while (end > pos)//pos==0时，end也能==0
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
			//判断长短
			size_t length = strlen(str);
			if (_size + length > _capacity)
			{
				reserve(_capacity + length);
			}

			//挪动数据:未解决
			memmove(_str + pos + length, _str + pos, sizeof(char) * (_size - pos));

			strncpy(_str + pos, str, length);
			_size += length;
			_str[_size] = '\0';

			return *this;
		}

		//resize
		void resize(size_t newsize, const char ch = '\0')
		{
			//当newsize > capacity时
			//当newsize介于size和capacity时
			//当newsize < capacity时
			if (newsize < _size)
			{
				_size = newsize;
				_str[_size] = '\0';
			}
			else//newsize >= _size
			{
				if (newsize > _capacity)
				{
					//扩容
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
		string& erase(size_t pos, size_t len = npos)
		{
			//从pos位置开始删除len个元素
			if (pos + len >= _size)
			{
				_size = pos;
				_str[_size] = '\0';
			}
			else
			{
				//把pos后面的元素向前挪len个单位
				strcpy(_str + pos, _str + pos + len);
				_size -= len;
			}
			return *this;
		}

		//swap
		void swap(string& str)
		{
			char* tmp = _str;
			_str = str._str;
			str._str = tmp;
			
			int n = _size;
			_size = str._size;
			str._size = n;

			n = _capacity;
			_capacity = str._capacity;
			str._capacity = n;
		}

		//find
		size_t find(char ch, size_t pos)
		{
			size_t i = 0;
			for (; i < _size; ++i)
			{
				if (_str[i] == ch)
				{
					return i;
				}
			}
			return -1;
		}

		size_t find(const char* str, size_t pos)
		{
			assert(pos < _size);

			char* tmp = strstr(_str + pos, str);
			if (tmp == nullptr)
			{
				return npos;
			}
			else
			{
				return tmp - _str;
			}
		}

		void clear()
		{
			_size = 0;
			_str[_size] = '\0';
		}

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

		iterator end()//返回结束后的一个字符
		{
			return _str + _size;
		}

		const_iterator end() const//返回结束后的一个字符
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
		//static const只能给整形默认值
		//例如
		//static const size_t N = 10;
		//float arr[N];

		//static const double a = 1.1;错误
		static const size_t npos = -1;

	};

	ostream& operator<<(ostream& out, const string& str)
	{
		for (auto ch : str)
		{
			out << ch;
		}
		return out;
	}

	istream& operator>>(istream& in, string& str)
	{
		//模拟cin，遇到空格和换行就停下
		char ch = in.get();
		char buffer[128] = "";
		size_t i = 0;
		while (ch != '\n' && ch != ' ')
		{
			buffer[i++] = ch;
			if (i == 127)
			{
				buffer[127] = '\0';
				str += buffer;
				i = 0;
			}
			ch = in.get();
		}

		if (i != 0)
		{
			buffer[i] = '\0';
			str += buffer;
		}

		return in;
	}
}