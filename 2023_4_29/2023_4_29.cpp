#define _CRT_SECURE_NO_WARNINGS 1
#include "priority_queue.h"
using namespace Fjl;

/*
deque ˫�˶���double ended queue
priority_queue  �������е�k��Ԫ�أ���ģ��ʵ�֣�
���������
*/


/*
deque֧��������ʺ�Ч�ʽϸߵ�ͷ��ͷɾ�������������ܶ����ܴﵽvector��list��ˮƽ
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
���ȼ�����:������������Ĭ��������vector

Ĭ�ϰ���ѵ�������	
��Ҫmake_heap��push_heap��pop_heap�㷨
�����㷨�ĸ��Ӷ�O(N)
push�ĸ��Ӷ�O(logN)
pop�ĸ��Ӷ�O(logN)


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