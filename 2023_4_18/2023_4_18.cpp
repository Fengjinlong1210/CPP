#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

/*
vector
������һ����vectorʹ�������Ŀռ�洢���ݣ�����ʹ��ָ��ƫ����������vector�е�Ԫ��
�����鲻ͬ���ǣ�vectorʹ�ö�̬��ʽ�ı��С���������Զ����ƴ�С
��������Ԫ��ʱ��vector���ܻ����·����ڴ棬����Ӧ�µĴ�С������һ����Ϊ��ʱ������
����vector����ÿ�ζ����·����ڴ�
vector�����Ŀ���һ���ֿռ䣬���Э���ÿ��ٿռ������ʱ��Ϳռ�

��������ȣ�vector���ĸ�����ڴ������������ڴ�Ͷ�̬����������

vector�����ԣ�
1.Ԫ�������Ե�
2.����ֱ�ӷ���˳����е�Ԫ�أ�����ͨ��ָ��
3.��̬����洢����
*/

int main()
{
	//���캯��
	//vector<int> v1;//Ĭ�Ϲ���
	//vector<int> v2(10, 5);//���10��5
	//vector<int>::iterator it1 = v2.begin();
	//vector<int>::iterator it2 = v2.end();

	//vector<int> v3(it1, it2);
	////vector<int> v4(++it1, --it2);//ʹ�õ��������乹��

	//vector<int> v5(v2);//��������

	//v1 = v2;//��ֵ����
	//

	////ʹ�õ���������
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

	//reserve�޸���������Ӱ��vector�����Ԫ��
	
	vector<int> v1;
	size_t capacity = v1.capacity();
	size_t i = 0;
	for (; i < 100; ++i)
	{
		v1.push_back(i);
		if (capacity != v1.capacity())
		{
			capacity = v1.capacity();
			cout << "capacity :" << v1.capacity() << endl;//����������
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
			cout << "capacity2 :" << v2.capacity() << endl;//����������
		}
	}

	//resize ������С
	v2.resize(50);

	return 0;
}