#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//��̬��Ա��������̬��Ա����
/*
��̬��Ա�����������κζ���Ҫ����������г�ʼ��
��̬��Ա�����������ʾ�̬����


class Count
{
public:
	//���캯��
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
���������Ż�
*/

class A
{
public:
	//����
	A(int a = 0):_a(a)
	{
		cout << "���캯��  A()" << this << endl;
	}
	//����
	~A()
	{
		cout << "�������� ~A()" << this << endl;
	}

	//��������
	A(const A& ra):_a(ra._a)
	{
		cout << "��������  A(const)" << this << endl;
	}

	//��ֵ����
	A& operator=(const A& ra)
	{
		cout << "��ֵ���� A&(const)" << this << endl;
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
	//��ֵ����ʱ���õĺ���������ʱ����һ�ο������캯��
	//A a1;
	//func1(a1);
	cout << "---------------------------" << endl;
	//����ʱ����������һ����ʱ����Ȼ�����ٴ���ʱ����������βΣ���������ʱ�����Ķ���
	//func2();

	//func1(1); // ����+��������-->�Ż�Ϊֱ�ӹ���

	//func1(A(1));//	��һ�����ʽ�У���������+���������Ż�Ϊֱ�ӹ���	

	A a2 = func2(); //һ�����ʽ�У��������������Ż�Ϊһ����������

	return 0;
}