#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//STL�⣺string

/*
c�����е��ַ����ͺ�����Щ���룬�������������ı��˼��
����c++�ṩ��string�࣬
*/

/*
int main()
{
	//���캯��
	string s1("abcdefghijklmnopqrstuvwxyz");
	string s2 = "hahaha";
	string s3(s1, 5, 100);
	//���±�5��λ�ÿ����ĸ��ַ���������������������ַ������Ϳ������е��ַ���

	string s4(s2);
	string s5;//���ַ���
	string s6("abcdefghijklmnopqrstuvwxyz", 10);
	//���ַ����п���n���ַ�
	
	string s7(10, 'a');
	//����n���ַ�

	cout << s1 << endl;
	cout << s2 << endl;
	cout << s3 << endl;
	cout << s4 << endl;
	cout << s5 << endl;
	cout << s6 << endl;
	cout << s7 << endl;


	return 0;
}
*/

/*
int main()
{
	string s1("hello world!");
	size_t i = 0;
	for (; i < s1.size(); ++i)
	{
		cout << s1[i];
	}
	cout << endl;
	//string.capacity()����Ϊ�ַ������ٵĿռ�Ĵ�С,������\0
	cout << s1.capacity() << endl;
	//string.size��string.length�����ַ�������
	cout << s1.size() << endl;
	return 0;
}
*/

/*
int main()
{
	string s1("hello");
	s1.push_back(' ');//�ں�������ַ�
	s1.push_back('s');
	s1.push_back('b');

	s1.append("hahahaha");//׷���ַ���

	s1 += ' ';//ʹ��+=�����ֱ��׷��
	s1 += 's';
	s1 += 'b';

	s1 += "hello";

	cout << s1 << endl;
	return 0;
}
*/

/*
int main()
{
	string s1;
	s1.reserve(100);//���������ַ�������
	//���reserve�Ĳ�������Ŀǰstring��capacity,�ú��������������capacity
	//���ַ����ĳ���û��Ӱ��
	string s2("abcdefghijklmnopqrstuvwxyz");
	s2.reserve(50);
	return 0;
}


int main()
{
	string s1("abcdefghijklmnopqrstuvwxyz");
	s1.resize(10);//�޸��ַ�������
	cout << s1 << endl;
	s1.resize(20, 'a');//�޸�+��ʼ��
	s1.resize(30);

	cout << s1 << endl;


	return 0;
}

*/

/*
������ string::iterator ����һ��������,ָ��XXX
*/

//int main()
//{
//	string s1("abcdefghijklmnopqrstuvwxyz");
//	string::iterator it1 = s1.begin();//����һ��ָ��ʼλ�õĵ�����
//	while (it1 != s1.end())
//	{
//		cout << *it1;
//		++it1;
//	}
//	cout << endl;
//
//	return 0;
//}

int main()
{
	string s(5000, '\0');
	getline(cin, s);
	size_t end = s.size() - 1;
	size_t begin = 0;
	while (begin < end && s[end] != ' ')
	{
		--end;
	}
	//��ѭ��ʱ��Ҫôbegin=end��Ҫôendָ�����һ���ո�
	cout << s.size() - end - 1<< endl;
}