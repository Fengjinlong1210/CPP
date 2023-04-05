#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//�ڴ����
//new  ����operator new������һ��ռ䣬�������ռ�ĵ�ַ
//int main()
//{
//	int* pa = new int;		//�����г�ʼ��
//	int* pb = new int(100); //��ʼ��
//	int* pc = new int[10];  //����������ʮ���ռ�,����ʼ��
//	int* pd = new int[10]{ 1,2,3,4,5 }; //��������г�ʼ��
//	delete pa;
//	delete pb;
//	delete[] pc;
//	delete[] pd;   //����ʱҪƥ��ʹ�ã����������[]
//	return 0;
//}

/*
newʧ�ܻ��׳��쳣��mallocʧ�ܻ᷵��nullptr
*/


//
//int main()
//{
//	//A* pa = new A(10);//new���Զ������Ͷ����Ĭ�ϵ��ù��캯��
//	//delete pa;		  //delete���Զ������Ͷ�������Ĭ����������
//
//	stack st;
//
//	stack* pst = new stack();
//	//new�Ķ�����Ҫdelete�Ż����Ĭ����������
//	delete pst;
//	return 0;
//}

/*
class A
{
public:
	A(int a = 0) :_a(a)
	{
		cout << "���캯��" << this << endl;
	}

	~A()
	{
		cout << "��������" << this << endl;
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

//��λnew
int main()
{
	//���Ѿ����ٺõĿռ���г�ʼ�������Ǹ�ֵ��
	A* pa = (A*)malloc(sizeof(A));
	if (!pa)
	{
		exit(-1);
	}
	
	new(pa)A(10); //�������ù��캯��
	pa->~A();     //����������������

	return 0;
}

*/


//��ʽ��̣���д�������޹صĴ��룬�Ǵ��븴�õ�һ���ֶΣ�ģ���Ƿ�ʽ��̵�һ���ֶ�

/*
ʹ��Swap����ʱ����Ҫ����Բ�ͬ���͵Ĵ����ظ��ʽϸߣ�ά����


template<typename T>
//������typename��class

//ģ����һ����ͼ���ɱ������Ժ�������ʵ����

void Swap(T& a, T& b)  //T�����͵�ͳ��
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

//�����ģ�庯����ͬ���Ƶĺ���ͬʱ����
//������ѡ���Զ���ĺ�������
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

	Add<int>(a, b);//��ʽʵ������ֱ��ָ������������
	return 0;
}
*/

//��ģ��
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
	Stack<int> st1(10);//��ʾʵ����
	Stack<double> st2(20);
	return 0;
}