#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


/*
string�ĸ�ֵ���������

int main()
{
	string s1("abcdefghijklmnopqrstuvwxyz");
	string s2;
	s2 = s1;
	cout << s2 << endl;
	s2 = "hahaha";
	cout << s2 << endl;
	s2 = 'a';
	cout << s2 << endl;

	return 0;
}
*/

/*
������


int main()
{
	string str("abcdefghijklmnopqrstuvwxyz");
	string::iterator it = str.begin();//������ȡ�ַ�����һ���ַ�
	string::iterator it2 = str.end();//end()��ʾ�ַ�������֮����ַ�����������û�Խ��
	for (; it < str.end(); ++it)
	{
		cout << *it << " ";
	}
	cout << endl;
	//cout << *it2 << endl;
	for (auto s : str)
	{
		cout << s << " ";
	}
	cout << endl;

	//���������
	//reverse_iterator  ��rbegin/rend���ʹ��
	string::reverse_iterator rit = str.rbegin();
	for (; rit < str.rend(); ++rit)
	{
		cout << *rit << " ";//�����ӡ
	}
	cout << endl;

	//ʹ��const�ĵ�����

	string::const_iterator cit = str.cbegin();
	for (; cit < str.cend(); ++cit)
	{
		cout << *cit << " ";
		//(*cit)++;  ����const���������ε������޷��ı�
	}

	return 0;
}
*/

/*
resize��reserve������

resize�������¸ı�string�Ĵ�СΪn�����n��ԭ����С������С��n
���n�����ڵĳ��ȳ���������n�������ڵڶ�������ָ����չ�������ַ�'c'

reserve�޸�string��capacity�������г�ʼ��


int main()
{
	string str("This is a test program");

	str.resize(50);

	str.resize(50, 'c');//�������n���
	cout << str << endl;

	str.resize(10);//��С��10
	cout << str << endl;
	return 0;
}
*/

/*
clear��empty

clear���string��ʹ���ȱ�Ϊ0

empty���string�Ƿ�Ϊ��


int main()
{
	string str("hahahahahahahahaha");
	cout << str.empty() << endl;
	str.clear();
	cout << str.empty() << endl;

	return 0;
}
*/

/*
insert:���������ַ�  ��һ�������ǲ���λ��(�±�)
1.�ַ�����string�����������ַ������Ӵ���
2.�ַ�
3.������

erase��ɾ�������ַ��������ַ�������


replace���滻�����ַ�


int main()
{
	string str("abcdefghijklmnopqrstuvwxyz");
	cout << str << endl;

	str.insert(5, "hahaha");
	cout << str << endl;
	
	str.insert(10, 10, 'a');
	cout << str << endl;

	str.erase(10,5);//���±�10��λ�ò���5����λ
	cout << str << endl;

	str.replace(10, 10, "asdfghjkl");//�±�10��λ���޸ĳ�ָ���ַ���
	cout << str << endl;


	return 0;
}
*/

/*
string::swap  ��  algorithm::swap������
string�е�swap����ֱ�ӽ���ָ���ָ��Ч�ʸ����㷨���е�swap

int main()
{
	string str1("hahahaa");
	string str2("hehehehe");
	cout << str1 << endl;
	cout << str2 << endl;

	str1.swap(str2);
	cout << str1 << endl;
	cout << str2 << endl;
}
*/

/*
find:������ҵ�һ�γ��ֵ�ĳ���ַ����ַ���
posȱʡֵΪ1

rfind:�������


int main()
{
	string str("this is a program used to test find and rfind");
	int ret = str.find(" ");//�ӿ�ʼ���ҵ�һ�γ��ֵ�ĳ�ַ�
	cout << ret << endl;

	int ret2 = str.find('a', 4);//���±�4��λ�ò���'a'
	cout << ret2 << endl;

	int ret3 = str.find("ed", 4, 2);
	cout << ret3 << endl;

	return 0;
}
*/

/*
substr:�����Ӵ���pos, len = n_pos��


int main()
{
	string str1("abcdefghijklmnopqrstuvwxyz");
	string str2;
	str2 = str1.substr(5, 10);
	cout << str2 << endl;
	return 0;
}
*/

int main()
{
	string s(5000, '\0');
	getline(cin, s);
	size_t pos = s.rfind(' ', s.size() - 1);
	if (pos != -1)
	{
		//�������һ���ո�
		cout << s.size() - pos - 1 << endl;
	}
	else
	{
		//�����ַ�
		cout << s.size() << endl;
	}
}