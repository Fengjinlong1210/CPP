#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include<typeinfo>
using namespace std;

/*
1.����ģ�����
2.������ģ�����
3.ģ���ػ�
4.���Ӵ�������
*/

//1.
/*
template<class T>  //����ģ�������
T Add(T& a, T& b)
{
	return a + b;
}

template<class T, size_t N = 10>  //������ģ�����  �ṩһ���������Ե��ɳ�����ʹ��
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

//2.ģ���ػ�
/*
	//����ģ���ػ�
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
	//����ָ�����ͣ�less�����޷��Ƚ�ָ��ֵ�Ĵ�С
	cout << ret1 << endl;
	cout << ret2 << endl;
	return 0;
}*/

/*
��ģ���ػ�
ȫ�ػ�

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
class test<int, char>	//ȫ�ػ�
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

//ƫ�ػ�
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

template<class T1>	//ƫ�ػ�����һ���ֲ����ػ�
class test<T1, int>	//���ڶ���ģ�����Ĭ������Ϊint
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
class test<T1*, T2*>	//��ģ���ػ�Ϊָ������,����ָ������ʱ����ת��������
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

//��ģ���ػ�
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
	//int ret = Less<int>()(a, b); //����������ó�Ա����
	cout << Less<int>()(a, b) << endl;
	cout << Less<int*>()(pa, pb) << endl;	//ԭ�е�Lessֻ�ܱȽ�ֵ�����ܱȽ�ָ��ָ�������

	return 0;
}