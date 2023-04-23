#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
#include <algorithm>
using namespace Fjl;

//������ʧЧ���������ڶ����ݽ��д���󣬲�ָ���κ�Ԫ�ػ�ָ��λ�÷����˸ı�
/*
���磬insert�������������µĿռ䣬����������Ȼָ��ԭ�еĿռ�

erase��ԭ����λ�ñ�ɾ��������������ָ��ԭ��λ��
��ʹ�õ�����֮ǰ��Ҫ�Ե��������¸�ֵ
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

	//ɾ�����е�ż��
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