#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;

//STL库：string

/*
c语言中的字符串和函数有些分离，不符合面向对象的编程思想
所以c++提供了string类，
*/

/*
int main()
{
	//构造函数
	string s1("abcdefghijklmnopqrstuvwxyz");
	string s2 = "hahaha";
	string s3(s1, 5, 100);
	//从下标5的位置拷贝四个字符，如果第三个参数超出字符串，就拷贝所有的字符串

	string s4(s2);
	string s5;//空字符串
	string s6("abcdefghijklmnopqrstuvwxyz", 10);
	//从字符串中拷贝n个字符
	
	string s7(10, 'a');
	//放置n个字符

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
	//string.capacity()返回为字符串开辟的空间的大小,不包含\0
	cout << s1.capacity() << endl;
	//string.size和string.length返回字符串长度
	cout << s1.size() << endl;
	return 0;
}
*/

/*
int main()
{
	string s1("hello");
	s1.push_back(' ');//在后面插入字符
	s1.push_back('s');
	s1.push_back('b');

	s1.append("hahahaha");//追加字符串

	s1 += ' ';//使用+=运算符直接追加
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
	s1.reserve(100);//重新申请字符串容量
	//如果reserve的参数大于目前string的capacity,该函数会把容量扩大到capacity
	//对字符串的长度没有影响
	string s2("abcdefghijklmnopqrstuvwxyz");
	s2.reserve(50);
	return 0;
}


int main()
{
	string s1("abcdefghijklmnopqrstuvwxyz");
	s1.resize(10);//修改字符串长度
	cout << s1 << endl;
	s1.resize(20, 'a');//修改+初始化
	s1.resize(30);

	cout << s1 << endl;


	return 0;
}

*/

/*
迭代器 string::iterator 返回一个迭代器,指向XXX
*/

//int main()
//{
//	string s1("abcdefghijklmnopqrstuvwxyz");
//	string::iterator it1 = s1.begin();//返回一个指向开始位置的迭代器
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
	//出循环时，要么begin=end，要么end指向最后一个空格
	cout << s.size() - end - 1<< endl;
}