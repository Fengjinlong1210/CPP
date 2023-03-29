#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <stdbool.h>
using namespace std;

/*
类和对象

构造函数和析构函数
构造函数与类同名，不需要返回值，在声明对象时自动调用，用来初始化类的成员
构造函数可以函数重载

析构函数在类名前加上~  ，在对象生命周期结束时自动调用，用来销毁类的成员
*/


//不适用构造函数，需要定义初始化函数并且每次声明变量都需要调用
/*
class Date
{
public:
	void Init(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day<< endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1;
	Date d2;

	d1.Init(2023, 3, 10);
	d2.Init(2023, 3, 29);

	d1.Print();
	d2.Print();
}
*/

//使用构造函数
/*
typedef class DateWithConstructor
{
public:
	//构造函数支持函数重载，缺省值

	//无参构造函数和全缺省构造函数都称为默认构造函数
	//默认构造函数只能有一个！！！
	//所以：存在无参的构造函数时，不能使用全缺省，编译器无法识别调用了哪一个构造函数
	DateWithConstructor()
	{
		_year = 9999;
		_month = 9999;
		_day = 9999;
	}
	DateWithConstructor(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
}DWC;

int main()
{
	//DWC d1; 会报错
	//因为同时存在两个默认构造函数（无参构造函数和全缺省构造函数）
	DWC d2(2023, 1, 10);
	return 0;
}
*/

/*
typedef class DateWithConstructor
{
public:
	DateWithConstructor()
	{
		_year = 9999;
		_month = 9999;
		_day = 9999;
	}
	DateWithConstructor(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

private:
	int _year;
	int _month;
	int _day;
}DWC;

int main()
{
	DWC d1;//调用无参的构造函数
	DWC d2(2023, 1, 10);//有参的构造函数
	return 0;
}
*/

/*
编译器默认的构造函数

class Time
{
public:
	Time()
	{
		cout << "Time()" << endl;
		_hour = 0;
		_minute = 0;
		_second = 0;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class Date
{
private:
	// 基本类型(内置类型)  不进行初始化，但可以在声明是赋初值
	int _year = 1;
	int _month = 1;
	int _day = 1;
	// 自定义类型
	Time _t;
};
int main()
{
	Date d1;
	//默认的构造函数形成了随机值
	//本质上因为编译器不对内置类型进行初始化

	//但是d1中的Time类的_t进行了初始化
	return 0;
}

*/

/*
析构函数
编译器自带的析构函数可以销毁内置类型，但是对申请了资源的自定义类型
必须要编辑析构函数，否则会造成内存泄漏
*/

//用构造函数和析构函数实现Stack
typedef int STDatatype;

class Stack
{
public:
	void Push(STDatatype val)
	{
		CheckCapacity();
		_data[_top++] = val;
	}

	void Pop()
	{
		if (isEmpty())
		{
			return;
		}
		_top--;
	}

	STDatatype Top()
	{
		if (isEmpty())
		{
			printf("NULL\n");
			return -1;
		}
		return _data[_top - 1];
	}

	bool isEmpty()
	{
		return _top == 0;
	}

	void CheckCapacity()
	{
		if (_top != _capacity)
		{
			return;
		}
		_capacity *= 2;
		STDatatype* tmp = (STDatatype*)realloc(_data, sizeof(STDatatype) * _capacity);
		if (!tmp)
		{
			return;
		}
		_data = tmp;
	}

	Stack(int capacity = 4)
	{
		_capacity = capacity;
		STDatatype* tmp = (STDatatype*)malloc(sizeof(STDatatype) * capacity);
		if (!tmp)
		{
			perror("malloc");
			return;
		}
		_data = tmp;
		_top = 0;
	}

	~Stack()
	{
		STDatatype* tmp = _data;
		free(tmp);
		_data = nullptr;
		_top = _capacity = 0;
	}

private:
	STDatatype* _data = nullptr;
	int _top = 0;
	int _capacity;
};

int main()
{
	Stack st1;//使用构造函数和全缺省，自动进行初始化
	Stack st2(8);//指定初始化

	st1.Push(1);
	st1.Push(2);
	st1.Push(3);
	st1.Push(4);
	st1.Push(5);
	st1.Push(6);
	st1.Pop();
	st1.Pop();
	st1.Pop();
	st1.Pop();

	return 0;
}