#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

/*
vector
和数组一样，vector使用连续的空间存储数据，可以使用指针偏移量来访问vector中的元素
和数组不同的是，vector使用动态方式改变大小，容器会自动控制大小
当插入新元素时，vector可能会重新分配内存，以适应新的大小，这是一个较为耗时的任务
所以vector不会每次都重新分配内存
vector会额外的开辟一部分空间，库会协调好开辟空间所需的时间和空间

和数组相比，vector消耗更多的内存来交换管理内存和动态增长的能力

vector的特性：
1.元素是线性的
2.允许直接访问顺序表中的元素，可以通过指针
3.动态处理存储需求
*/

int main()
{
	//构造函数
	//vector<int> v1;//默认构造
	//vector<int> v2(10, 5);//填充10个5
	//vector<int>::iterator it1 = v2.begin();
	//vector<int>::iterator it2 = v2.end();

	//vector<int> v3(it1, it2);
	////vector<int> v4(++it1, --it2);//使用迭代器区间构造

	//vector<int> v5(v2);//拷贝构造

	//v1 = v2;//赋值重载
	//

	////使用迭代器遍历
	//size_t i = 1;
	//for (; it1 < v2.end(); ++it1, ++i)
	//{
	//	*it1 += i;
	//}

	//it1 = v2.begin();
	//for (; it1 < v2.end(); ++it1)
	//{
	//	cout << *it1 << " ";
	//}
	//cout << endl;

	//vector<int>::reverse_iterator rit1 = v2.rbegin();
	//vector<int>::reverse_iterator rit2 = v2.rend();
	//while (rit1 != rit2)
	//{
	//	cout << *rit1 << " ";
	//	rit1++;
	//}
	//cout << endl;

	//int ret1 = v2.size();
	//int ret2 = v2.capacity();

	//cout << ret1 << " " << ret2 << endl;

	//reserve修改容量，不影响vector本身的元素
	
	vector<int> v1;
	size_t capacity = v1.capacity();
	size_t i = 0;
	for (; i < 100; ++i)
	{
		v1.push_back(i);
		if (capacity != v1.capacity())
		{
			capacity = v1.capacity();
			cout << "capacity :" << v1.capacity() << endl;//对数型增长
		}
	}

	vector<int> v2;
	size_t capacity2 = v2.capacity();
	i = 0;
	v2.reserve(100);
	for (; i <= 100; ++i)
	{
		v2.push_back(1);
		if (capacity2 != v2.capacity())
		{
			capacity2 = v2.capacity();
			cout << "capacity2 :" << v2.capacity() << endl;//对数型增长
		}
	}

	//resize 调整大小
	v2.resize(50);

	return 0;
}