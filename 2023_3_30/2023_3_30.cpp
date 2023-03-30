#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
默认构造函数/析构函数
编译器对内置类型不进行初始化处理，但是对自定义类型会调用默认的构造函数
析构函数对自定义类型会调用默认的构造函数
*/

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time的默认构造函数" << endl;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//	int _year;
//	int _hour;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	//这里编译器会调用Time的默认构造函数
//
//	//如果自己定义了构造函数，（含参的）
//	//编译器会报错,因为缺少默认的构造函数
//	return 0;
//}

/*
拷贝构造函数  拷贝构造函数是构造函数的一种重载
在进行类的拷贝时调用拷贝构造函数（编译器无法自己拷贝自定义类型）
class (class& classname)
拷贝构造函数的参数只能有一个，就是对象的引用

如果未定义拷贝函数，编译器会自动生成一个默认的拷贝构造函数
对字节进行一一拷贝
内置类型按照字节进行拷贝，自定义类型使用拷贝函数进行拷贝
*/
/*
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& dt)//传递的是原本的对象的引用
	{
		_year = dt._year;
		_month = dt._month;
		_day = dt._day;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	//利用默认拷贝构造函数， 只能对内置类型进行拷贝
	Date d2 = d1;
	Date d3(d2);
	return 0;
}
*/

/*
当涉及到资源申请时，不能使用拷贝构造函数进行浅拷贝

拷贝构造函数会在下列条件下被调用：
1.使用已经存在的类对象创建新对象
2.函数参数为类类型对象
3.函数返回值为类类型对象


class Date
{
public:
	//构造函数
	Date(int year, int month, int day)
	{
		cout << "Date:构造函数" <<this<< endl;
	}
	//拷贝构造函数
	Date(const Date& dt)//传递的是原本的对象的引用
	{
		cout << "Date:拷贝构造函数" <<this<< endl;
	}

	~Date()
	{
		cout << "Date:析构函数函数" <<this<< endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date Test(Date d)//d1传入时调用一次拷贝构造函数，拷贝到形参
{
	Date tmp = d;//利用形参拷贝构造tmp，再一次调用拷贝构造函数
	return tmp;	  //返回tmp时，调用拷贝构造函数创建一个临时对象用于返回tmp
}

int main()
{
	Date d1(2023, 3, 30);
	Test(d1);
	//销毁时，优先销毁test中创建的tmp，然后销毁test的形参d
	//最后销毁临时创建的用于返回的对象
	return 0;
	//此时销毁d1
}
*/

/*
赋值运算符重载
返回类型  operator+(操作符) 函数参数
重载操作符必须有一个类类型参数
作为类成员函数重载时，参数少一个，是一个隐含的this指针



class Date
{
public:
	//构造函数
	Date(int year, int month, int day)
	{
		cout << "Date:构造函数" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	//拷贝构造函数
	Date(const Date& dt)//传递的是原本的对象的引用
	{
		cout << "Date:拷贝构造函数" << this << endl;
		_year = dt._year;
		_month = dt._year;
		_day = dt._day;
	}

	~Date()
	{
		cout << "Date:析构函数" << this << endl;
	}

	//等于运算符重载
	//左操作数是隐含的this指针
	bool operator==(const Date& dt)
	{
		return _year == dt._year &&
			_month == dt._month &&
			_day == dt._day;
	}

	//赋值运算符 只能作为成员函数定义在内部

	//若不定义赋值重载，编译器会自动包含默认的赋值重载函数
	//默认的复制重载函数能对内置类型进行赋值
	//但涉及到资源的操作时，需要自己定义赋值重载函数

	//成员操作符重载的函数参数看起来只有一个， 包含一个隐含的this指针（指向左操作数）
	Date& operator=(const Date& dt)
	{
		cout << "赋值重载函数" << endl;
		if (this != &dt) //判断this指针和取地址dt是否相等，相等说明是同一个类对象
		{
			this->_year = dt._year;
			this->_month = dt._month;
			this->_day = dt._day;
		}

		return *this;//返回this以便连续赋值
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023, 3, 30);
	Date d2(2023, 3, 3);
	cout << (d1 == d2) << endl;
	Date d3(d2);//拷贝构造函数：创建新对象时利用现有对象进行赋值
	Date d4(d2);//拷贝构造函数
	Date d5(1234, 1, 1);
	d5 = d2;//赋值重载：对已有的两个类对象进行赋值操作
	return 0;
}
*/

class Date
{
public:
	//构造函数
	Date(int year = 0, int month = 0, int day = 0)
	{
		cout << "Date() : 构造函数" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	//析构函数
	~Date()
	{
		cout << "~Date() : 析构函数" << this << endl;
	}
	//拷贝构造函数
	Date(const Date& dt)
	{
		cout << "Date(Date& ) : 拷贝构造函数" << this << endl;

		_year = dt._year;
		_month = dt._month;
		_day = dt._day;
	}
	//赋值重载
	Date& operator==(const Date& dt)
	{
		cout << "operator==(Date& ) : 赋值重载函数" << this << endl;
		if (this != &dt)
		{
			this->_year = dt._year;
			this->_month = dt._month;
			this->_day = dt._day;
		}
		return *this;
	}

	//实现一个日期增加的函数

	Date& DateAdd(int day)
	{
		Date tmp = *this;
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}

		return tmp;
	}

	int GetMonthDay(int year, int month)
	{
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) && month == 2)
		{
			return Month[2] + 1;
		}
		return Month[month];
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2023, 3, 30);
	Date ret = d1.DateAdd(100);
	ret.Print();
	return 0;
}