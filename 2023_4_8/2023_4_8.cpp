#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

/*
c_str 返回一个指针，指向跟string相同的字符串

fopen()的第一个参数是const char* 类型，要使用string类的名称
需要c_str()转化成char类型


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
提取文件后缀
利用substr


int main()
{
	string web("www.abcdefg.com");
	int pos = web.rfind('.');
	cout << web.substr(pos);
	return 0;
}
*/

/*
提取域名
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