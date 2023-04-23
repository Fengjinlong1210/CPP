#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
#include <algorithm>
using namespace Fjl;

//迭代器失效：迭代器在对数据进行处理后，不指向任何元素或指向位置发生了改变
/*
例如，insert后，容器开辟了新的空间，而迭代器仍然指向原有的空间

erase后，原本的位置被删除，而迭代器还指向原本位置
在使用迭代器之前，要对迭代器重新赋值
*/

void Test1()
{
	vector<int> v1(10);
	size_t i = 0;
	for (; i < v1.size(); ++i)
	{
		v1[i] = i + 1;
	}
	v1.Print();

	//删除所有的偶数
	vector<int>::iterator it1 = v1.begin();
	vector<int>::iterator pos = std::find(v1.begin(), v1.end(), 2);
	while (pos != v1.end())
	{
		if (*pos % 2 == 0)
		{
			v1.erase(pos);
		}
		else
		{
			pos++;
		}
	}
	v1.Print();
}

int main()
{
	
	vector<std::string> v1;
	v1.push_back("hahaha");
	v1.push_back("123124");
	v1.push_back("hahahe");
	v1.push_back("hahahasd");
	v1.push_back("hafgas");

	v1.Print();

	return 0;
}