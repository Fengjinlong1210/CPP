#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//内存管理
//new  调用operator new，开辟一块空间，返回这块空间的地址
//int main()
//{
//	int* pa = new int;		//不进行初始化
//	int* pb = new int(100); //初始化
//	int* pc = new int[10];  //开辟连续的十个空间,不初始化
//	int* pd = new int[10]{ 1,2,3,4,5 }; //对数组进行初始化
//	delete pa;
//	delete pb;
//	delete[] pc;
//	delete[] pd;   //销毁时要匹配使用，对数组加上[]
//	return 0;
//}

/*
new失败会抛出异常，malloc失败会返回nullptr
*/


//
//int main()
//{
//	//A* pa = new A(10);//new的自定义类型对象会默认调用构造函数
//	//delete pa;		  //delete的自定义类型对象会调用默认析构函数
//
//	stack st;
//
//	stack* pst = new stack();
//	//new的对象需要delete才会调用默认析构函数
//	delete pst;
//	return 0;
//}

/*
class A
{
public:
	A(int a = 0) :_a(a)
	{
		cout << "构造函数" << this << endl;
	}

	~A()
	{
		cout << "析构函数" << this << endl;
	}
private:
	int _a;
};

class stack
{
public:
	stack()
	{
		cout << "stack()" << endl;
		_capacity = 4;
		_top = 0;
		_data = new int[4];
	}

	~stack()
	{
		cout << "~stack()" << endl;

		delete[] _data;
		_top = _capacity = 0;
	}
private:
	int* _data;
	int _top;
	int _capacity;
};

//定位new
int main()
{
	//对已经开辟好的空间进行初始化（不是赋值）
	A* pa = (A*)malloc(sizeof(A));
	if (!pa)
	{
		exit(-1);
	}
	
	new(pa)A(10); //主动调用构造函数
	pa->~A();     //主动调用析构函数

	return 0;
}

*/


//范式编程：编写与类型无关的代码，是代码复用的一种手段，模板是范式编程的一种手段

/*
使用Swap函数时，需要定义对不同类型的处理，重复率较高，维护难


template<typename T>
//可以用typename和class

//模板是一个蓝图，由编译器对函数进行实例化

void Swap(T& a, T& b)  //T是类型的统称
{
	T tmp = a;
	a = b;
	b = tmp;
}

template<typename X>

X Add(const X& a, const X& b)
{
	return a + b;
}

//允许和模板函数相同名称的函数同时存在
//会优先选择自定义的函数调用
int Add(int& a, int& b, int& c)
{
	return a + b;
}

int main()
{
	int a = 10;
	int b = 20;

	double c = 3.14;
	double d = 5.11;

	Swap(a, b);
	Swap(c, d);

	Add<int>(a, b);//显式实例化，直接指定函数的类型
	return 0;
}
*/

//类模板
template<typename T>

class Stack
{
public:
	Stack(int capacity = 4):_capacity(capacity)
	{
		_data = new T[capacity];
		_top = 0;
		int i = 0;
		for (; i < _capacity; i++)
		{
			_data[i] = (T)0;
		}
	}

	~Stack()
	{
		delete[] _data;
		_top = _capacity = 0;
	}
private:
	T* _data;
	int _top;
	int _capacity;
};

int main()
{
	Stack<int> st1(10);//显示实例化
	Stack<double> st2(20);
	return 0;
}