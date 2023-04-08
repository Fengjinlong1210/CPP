#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
c_str ����һ��ָ�룬ָ���string��ͬ���ַ���

fopen()�ĵ�һ��������const char* ���ͣ�Ҫʹ��string�������
��Ҫc_str()ת����char����


int main()
{
	string filename("2023_4_8.cpp");
	FILE* fout = fopen(filename.c_str(), "r");
	if (fout == nullptr)
	{
		exit(-1);
	}
	char ch = fgetc(fout);

	while (ch != EOF)
	{
		cout << ch;
		ch = fgetc(fout);
	}

	fclose(fout);

	return 0;
}
*/

//int main()
//{
//	string str("abcdefghjk");
//	cout << str << endl;
//	cout << str.c_str() << endl;
//
//	str += ' ';
//	str += ' ';
//	str += "haha";
//	cout << str << endl;
//	cout << str.c_str() << endl;
//	return 0;
//}

/*
��ȡ�ļ���׺
����substr


int main()
{
	string web("www.abcdefg.com");
	int pos = web.rfind('.');
	cout << web.substr(pos);
	return 0;
}
*/

/*
��ȡ����
*/

int main()
{
	string url("https://cplusplus.com/reference/string/basic_string/substr/");
	size_t pos = url.find("://");
	pos += 3;
	size_t end = url.find('/', pos);
	string address = url.substr(pos, end - pos);
	cout << address << endl;
	return 0;
}