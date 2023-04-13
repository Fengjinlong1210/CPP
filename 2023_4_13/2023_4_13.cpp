#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
using namespace Fjl;
using std::cout;
using std::endl;

//int main()
//{
//	string s1;
//	string s2("hello world");
//	string s3(s2);
//	string s4;
//	s4 = s3;
//	s4[5] = 'a';
//	int i = 0;
//	for (i = 0; i < s4.size(); ++i)
//	{
//		cout << s4[i] << " ";
//	}
//	cout << endl;
//
//	const string s5("hahahahaha");
//	string::const_iterator it1 = s5.begin();//const声明的对象要用const迭代器
//	return 0;
//}

int main()
{
	string s1("hello world");
	string s2("hahahahahahahahahhahahahahahaha");
	string s3(s2);

	s1.Print();
	s2.Print();
	s3.Print();

	size_t i = 0;
	for (; i < s3.size(); ++i)
	{
		++s3[i];
	}
	s3.Print();

	s3.append("abceasdfasdf");
	s3.Print();

	s3.push_back('a');
	s3.Print();

	s3 += "hahahaha";
	s3.Print();

	s3 += 'z';
	s3.Print();

	s3.insert(10, 'z');
	s3.Print();

	s3.insert(10, "zzzzzzzbbbbb");
	s3.Print();

	string s4("aaaaabbbbbcccccdddddeeeee");

	s4.insert(0, "hello");
	s4.Print();

	return 0;
}