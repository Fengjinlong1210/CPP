#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
#include "list.h"
using namespace Fjl;
//反向迭代器
/*
通过封装正向迭代器实现
*/

void testvec()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	Fjl::vector<int>::reverse_iterator rit = v1.rbegin();
	while (rit != v1.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

void testlist()
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

	auto rit = lt.rbegin();
	while (rit != lt.rend())
	{
		cout << *rit << " ";
		++rit;
	}
	cout << endl;
}

int main()
{
	testvec();
	testlist();
	return 0;
}