#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

//const ���ζ���ͳ�Ա����
/*class A
{
public:
	//��const��Ա����
	void NonConst()
	{
		++_a;
		this->ConstFunc();
		this->NonConst();
	}
	//const��Ա����
	void ConstFunc() const
	{
		cout << _a << endl;
		this->ConstFunc();
	}
private:
	int _a = 0;
};


1. const������Ե��÷�const��Ա������  ������
2. ��const������Ե���const��Ա������	����
3. const��Ա�����ڿ��Ե��������ķ�const��Ա������ ������
4. ��const��Ա�����ڿ��Ե���������const��Ա�����𣿿���

int main()
{
	const A a1;
	a1.ConstFunc();//a1���ܵ��÷�const��Ա����

	A a2;
	a2.NonConst();
	a2.ConstFunc();//a2���ֺ��������Ե���
	return 0;
}

*/


/*
explicit�ؼ���
һ�������Ĺ��캯����û��explicit����ʱ�����Է�������ת��
explicit���κ󣬲��ܷ�������ת��
*/

/*
static���γ�Ա�����ͳ�Ա����
*/



class A
{
	friend void Add(int a, int b);

public:
	//���캯��
	A() :_sum(0),_s(10) {};

	static int Getnum()//��̬��Ա������ֻ�ܷ��ʾ�̬����
	{
		//��̬��Ա�������ܵ��÷Ǿ�̬��Ա����
		return _num;
	}

	int add()
	{
		Getnum();//�Ǿ�̬��Ա�������Ե��þ�̬��Ա����
		return ++_sum;
	}
private:
	static int _num;//��̬����
	int _sum;
	int _s;
};

void Add(int a, int b)
{
	cout << a + b << endl;
}

//static������ʼ��Ҫ��������
int A::_num = 0;
//��̬��Ա���������ж���������ھ�̬��
//�ྲ̬��Ա������ ����::��̬��Ա  ����  ����::��̬��Ա������
//��̬��Ա����û�����ص�thisָ�룬���ܷ��ʷǾ�̬��Ա

/*
��Ԫ��������Ԫ��
��Ԫ�������Է������˽�г�Ա���Ƕ��������ⲿ����ͨ��������������������Ա��Ȩ��
��Ԫ����������thisָ�룬����޷���const����

*/

int main()
{
	A a;

	return 0;
}