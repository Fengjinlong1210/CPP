#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<typeinfo>
using namespace std;

/*
1.类型模板参数
2.非类型模板参数
3.模板特化
4.链接错误问题
*/

//1.
/*
template<class T>  //类型模板参数，
T Add(T& a, T& b)
{
	return a + b;
}

template<class T, size_t N = 10>  //非类型模板参数  提供一个常数可以当成常量来使用
class arr
{
public:
	arr()
	{}
private:
	T _arr[N];	
};

int main()
{
	arr<int, 20> arr;
}*/

//2.模板特化
/*
	//函数模板特化
template<class T>
bool myless(const T& a, const T& b)
{
	return a < b;
}

template<>
bool myless<const int*&>(const int*& pa, const int*& pb)
{
	return *pa < *pb;
}

bool myless(int* pa, int* pb)
{
	return *pa < *pb;
}

int main()
{
	int a = 10;
	int b = 20;
	int ret1 = myless(a, b);
	int* pa = &a;
	int* pb = &b;
	int ret2 = myless(pa, pb);
	//对于指针类型，less函数无法比较指向值的大小
	cout << ret1 << endl;
	cout << ret2 << endl;
	return 0;
}*/

/*
类模板特化
全特化

template<class T1, class T2>
class test
{
public:
	test()
	{
		cout << "test<T1, T2>" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

template<>
class test<int, char>	//全特化
{
public:
	test()
	{
		cout << "test<int, char>" << endl;
	}
private:
	int _t1;
	char _t2;
};

int main()
{
	test<int, int> t;
	test<int, char> t2;
	return 0;
}
*/

//偏特化
/*
template<class T1, class T2>
class test
{
public:
	test()
	{
		cout << "test<T1, T2>" << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

template<class T1>	//偏特化，将一部分参数特化
class test<T1, int>	//将第二个模板参数默认设置为int
{
public:
	test()
	{
		cout << "test<T, int>" << endl;
	}
private:
	T1 _t1;
	int _t2;
};

template<class T1, class T2>
class test<T1*, T2*>	//将模板特化为指针类型,传入指针类型时，会转到该类中
{
public:
	test()
	{
		cout << "test<T1*, T2*>" << endl;
		cout << typeid(_t1).name() << endl;
		cout << typeid(_t2).name() << endl;

	}
private:
	T1 _t1;
	T2 _t2;
};

template<class T1, class T2>
class test<T1&, T2&>
{
public:
	test(T1& a, T2& b)
	{
		cout << "test<T1&, T2&>" << endl;
		cout << typeid(_t1).name() << endl;
		cout << typeid(_t2).name() << endl;
	}
private:
	T1 _t1;
	T2 _t2;
};

int main()
{
	test<int, char> t1;
	test<char, int> t2;
	test<int*, char*> t3;
	int a = 0;
	int b = 0;
	test<int&, int&> t4(a, b);
	return 0;
}*/

//类模板特化
template<class T>
struct Less
{
	bool operator()(T x, T y) const
	{
		return x < y;
	}
};

template<>
struct Less<int*>
{
	bool operator()(int* x, int* y) const
	{
		return *x < *y;
	}
};

template<>
struct Less<const int*>
{
	bool opeartor()(const int* x, const int* y) const
	{
		return *x < *y;
	}
};

int main()
{
	int a = 10;
	int b = 20;
	int* pa = &a;
	int* pb = &b;
	//int ret = Less<int>()(a, b); //匿名对象调用成员函数
	cout << Less<int>()(a, b) << endl;
	cout << Less<int*>()(pa, pb) << endl;	//原有的Less只能比较值，不能比较指针指向的内容

	return 0;
}