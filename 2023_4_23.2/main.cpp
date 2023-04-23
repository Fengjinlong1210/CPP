#define _CRT_SECURE_NO_WARNINGS 1
#include <list>
#include <iostream>
using namespace std;

void test1()
{
	list<int> lt1;//�޲�
	list<int> lt2(10, 9);//10��9
	list<int> lt3(lt2.begin(), lt2.end());//����������
	list<int> lt4(lt3);			//��������

	for (auto e : lt2)
	{
		cout << e << " ";
	}
	cout << endl;

	size_t i = 0;
	for (; i < 10; ++i)
	{
		lt1.push_back(i);
	}
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt4.assign(lt1.begin(), lt1.end());//���·���
	for (auto e : lt4)
	{
		cout << e << " ";
	}
	cout << endl;
}

void test2()
{
	list<int> lt1;
	size_t i = 0;
	for (; i < 10; ++i)
	{
		lt1.push_back(i + 1);
		lt1.push_back(i + 1);
	}
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;

	lt1.unique();
	for (auto e : lt1)
	{
		cout << e << " ";
	}
	cout << endl;
}

int main()
{
	test2();
	return 0;
}