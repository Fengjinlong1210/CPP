#define _CRT_SECURE_NO_WARNINGS 1
#include "priority_queue.h"
using namespace Fjl;

/*
deque 双端队列double ended queue
priority_queue  （数组中第k个元素）（模拟实现）
反向迭代器
*/


/*
deque支持随机访问和效率较高的头插头删，但这两个功能都不能达到vector和list的水平
*/
//int main()
//{
//	srand(time(nullptr));
//	deque<int> dq;
//	vector<int> vc;
//
//	size_t i = 0; 
//	int n = 50000;
//	int t1 = clock();
//	for (; i < n; ++i)
//	{
//		dq.push_front(i);
//	}
//	int t2 = clock();
//
//	int t3 = clock();
//	for (i = 0; i < n; ++i)
//	{
//		vc.insert(vc.begin(), i);
//	}
//	int t4 = clock();
//
//	cout << "deque:" << t2 - t1 << endl;
//	cout << "vector:" << t4 - t3 << endl;
//
//
//	return 0;
//}

/*
priority_queue
优先级队列:容器适配器，默认容器是vector

默认按大堆调整数据	
需要make_heap、push_heap、pop_heap算法
建堆算法的复杂度O(N)
push的复杂度O(logN)
pop的复杂度O(logN)


int main()
{
	priority_queue<int> pq1;
	priority_queue<int, vector<int>, greater<int>> pq2;

	pq1.push(1);
	pq1.push(5);
	pq1.push(-5);
	pq1.push(19);
	pq1.push(120);
	pq1.push(90);
	pq1.push(54);
	while(!pq1.empty())
	{
		cout << pq1.top() << " ";
		pq1.pop();
	}
	cout << endl;

	pq2.push(1);
	pq2.push(5);
	pq2.push(-5);
	pq2.push(19);
	pq2.push(120);
	pq2.push(90);
	pq2.push(54);

	while (!pq2.empty())
	{
		cout << pq2.top() << " ";
		pq2.pop();
	}
	cout << endl;
	return 0;
}
*/

void test_pq()
{
	Fjl::priority_queue<int> pq1;
	pq1.push(1);
	pq1.push(2);
	pq1.push(3);
	pq1.push(4);
	pq1.push(5);
	pq1.push(6);
	while (!pq1.empty())
	{
		cout << pq1.top() << "";
		pq1.pop();
	}
	cout << endl;
}

int main()
{
	test_pq();
	return 0;
}