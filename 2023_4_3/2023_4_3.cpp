#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//静态成员变量，静态成员函数
/*
静态成员变量不属于任何对象，要在类外面进行初始化
静态成员函数用来访问静态变量


class Count
{
public:
	//构造函数
	Count() :_num(0)
	{
		_sum++;
	}

	static int GetSum()
	{
		return _sum;
	}
private:
	static int _sum;
	int _num;
};

int Count::_sum = 0;

int main()
{
	cout << Count().GetSum() << endl;
	Count c1;
	Count c2;
	Count c3;
	Count c4;
	int ret = Count::GetSum();
	cout << ret << endl;
	return 0;
}
*/


/*
编译器的优化
*/

class A
{
public:
	//构造
	A(int a = 0):_a(a)
	{
		cout << "构造函数  A()" << this << endl;
	}
	//析构
	~A()
	{
		cout << "析构函数 ~A()" << this << endl;
	}

	//拷贝构造
	A(const A& ra):_a(ra._a)
	{
		cout << "拷贝构造  A(const)" << this << endl;
	}

	//赋值重载
	A& operator=(const A& ra)
	{
		cout << "赋值重载 A&(const)" << this << endl;
		if (this != &ra)
		{
			_a = ra._a;
		}
		return *this;
	}
private:
	int _a;
};

void func1(A aa)
{
}

A func2()
{
	A aa;
	return aa;
}

int main()
{
	//传值传参时调用的函数，传参时调用一次拷贝构造函数
	//A a1;
	//func1(a1);
	cout << "---------------------------" << endl;
	//返回时，拷贝构造一个临时对象，然后销毁传参时拷贝构造的形参，再销毁临时创建的对象
	//func2();

	//func1(1); // 构造+拷贝构造-->优化为直接构造

	//func1(A(1));//	在一个表达式中，连续构造+拷贝构造优化为直接构造	

	A a2 = func2(); //一个表达式中，连续拷贝构造优化为一个拷贝构造

	return 0;
}