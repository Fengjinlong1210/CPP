#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//const 修饰对象和成员函数
/*class A
{
public:
	//非const成员函数
	void NonConst()
	{
		++_a;
		this->ConstFunc();
		this->NonConst();
	}
	//const成员函数
	void ConstFunc() const
	{
		cout << _a << endl;
		this->ConstFunc();
	}
private:
	int _a = 0;
};


1. const对象可以调用非const成员函数吗？  不可以
2. 非const对象可以调用const成员函数吗？	可以
3. const成员函数内可以调用其它的非const成员函数吗？ 不可以
4. 非const成员函数内可以调用其它的const成员函数吗？可以

int main()
{
	const A a1;
	a1.ConstFunc();//a1不能调用非const成员函数

	A a2;
	a2.NonConst();
	a2.ConstFunc();//a2两种函数都可以调用
	return 0;
}

*/


/*
explicit关键字
一个参数的构造函数，没有explicit修饰时，可以发生类型转换
explicit修饰后，不能发生类型转换
*/

/*
static修饰成员函数和成员变量
*/



class A
{
	friend void Add(int a, int b);

public:
	//构造函数
	A() :_sum(0),_s(10) {};

	static int Getnum()//静态成员函数，只能访问静态变量
	{
		//静态成员函数不能调用非静态成员函数
		return _num;
	}

	int add()
	{
		Getnum();//非静态成员函数可以调用静态成员函数
		return ++_sum;
	}
private:
	static int _num;//静态变量
	int _sum;
	int _s;
};

void Add(int a, int b)
{
	cout << a + b << endl;
}

//static变量初始化要在类外面
int A::_num = 0;
//静态成员变量被所有对象共享，存放在静态区
//类静态成员可以用 类名::静态成员  或者  对象::静态成员来访问
//静态成员函数没有隐藏的this指针，不能访问非静态成员

/*
友元函数和友元类
友元函数可以访问类的私有成员，是定义在类外部的普通函数，赋予了其访问类成员的权力
友元函数不包含this指针，因此无法用const修饰

*/

int main()
{
	A a;

	return 0;
}