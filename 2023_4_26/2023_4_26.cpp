#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include "list.h"
#include "stl_list.h"
using namespace Fjl;
using namespace bit;
using std::cout;
using std::endl;

void test()
{
	bit::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);

	bit::list<int>::iterator it = lt.begin();
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	lt.Print();
}

void test2()
{
	bit::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_front(100);
	lt.push_front(200);
	lt.push_front(300);
	lt.Print();

}

void test3()
{
	bit::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_front(100);
	lt.push_front(200);
	lt.push_front(300);
	lt.Print();

	bit::list<int>lt2(lt);
	lt2.Print();
}

int main()
{
	Fjl::list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.Print();

	Fjl::list<int> lt2(lt);
	lt2.Print();

	return 0;
}