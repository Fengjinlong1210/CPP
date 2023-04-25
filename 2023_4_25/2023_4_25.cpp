#define _CRT_SECURE_NO_WARNINGS 1
#include "stl_list.h"
#include <iostream>
using namespace Fjl;
using std::cout;
using std::endl;

void test1()
{
	list<int> lt1;
	lt1.push_back(1);
	lt1.push_back(2);
	lt1.push_back(3);
	lt1.push_back(4);
	lt1.push_back(5);
	lt1.push_back(6);
	lt1.push_back(7);
	lt1.push_back(8);

	list<int>::iterator it = lt1.begin();
	lt1.erase(++it);
	lt1.Print();

	list<int>::iterator it2 = lt1.begin();
	lt1.insert(++it2, 100);
	lt1.Print();
}

void test2()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	lt.push_back(6);
	lt.push_back(7);
	lt.push_back(8);

	lt.Print();
	
	list<int>::iterator it = lt.begin();
	cout << it._node->_val << endl;  //没有重载*运算符时需要这样调用
	cout << *it << endl;			//重载了*运算符

	list<AA> lt2;
	lt2.push_back(AA(1, 2));
	lt2.push_back(AA(3, 4));
	lt2.push_back(AA(5, 6));
	list<AA>::iterator it2 = lt2.begin();
	cout << it2._node->_val._a1 << " " << it2._node->_val._a2 << endl;//没有运算符重载时
	cout << it2->_a1 << " " << it2->_a2 << endl;   //重载了->时

	while (it2 != lt2.end())
	{
		cout << it2->_a1 << " " << it2->_a2 << endl;
		++it2;
	}


}

int main()
{
	test2();

	return 0;
}