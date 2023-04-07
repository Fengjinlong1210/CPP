#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
using namespace std;


/*
string的赋值运算符重载

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
迭代器


int main()
{
	string str("abcdefghijklmnopqrstuvwxyz");
	string::iterator it = str.begin();//迭代器取字符串第一个字符
	string::iterator it2 = str.end();//end()表示字符串结束之后的字符，对其解引用会越界
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

	//倒序迭代器
	//reverse_iterator  和rbegin/rend配合使用
	string::reverse_iterator rit = str.rbegin();
	for (; rit < str.rend(); ++rit)
	{
		cout << *rit << " ";//倒序打印
	}
	cout << endl;

	//使用const的迭代器

	string::const_iterator cit = str.cbegin();
	for (; cit < str.cend(); ++cit)
	{
		cout << *cit << " ";
		//(*cit)++;  报错，const迭代器修饰的内容无法改变
	}

	return 0;
}
*/

/*
resize和reserve的区别

resize可以重新改变string的大小为n，如果n比原来的小，就缩小到n
如果n比现在的长度长，就扩大到n，可以在第二个参数指定扩展后填充的字符'c'

reserve修改string的capacity，不进行初始化


int main()
{
	string str("This is a test program");

	str.resize(50);

	str.resize(50, 'c');//扩大后用n填充
	cout << str << endl;

	str.resize(10);//缩小到10
	cout << str << endl;
	return 0;
}
*/

/*
clear和empty

clear清空string，使长度变为0

empty坚持string是否为零


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
insert:插入额外的字符  第一个参数是插入位置(下标)
1.字符串（string变量、常量字符串、子串）
2.字符
3.迭代器

erase：删除部分字符，减少字符串长度


replace：替换部分字符


int main()
{
	string str("abcdefghijklmnopqrstuvwxyz");
	cout << str << endl;

	str.insert(5, "hahaha");
	cout << str << endl;
	
	str.insert(10, 10, 'a');
	cout << str << endl;

	str.erase(10,5);//从下标10的位置擦除5个单位
	cout << str << endl;

	str.replace(10, 10, "asdfghjkl");//下标10的位置修改成指定字符串
	cout << str << endl;


	return 0;
}
*/

/*
string::swap  和  algorithm::swap的区别
string中的swap可以直接交换指针的指向，效率高于算法库中的swap

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
find:正序查找第一次出现的某个字符或字符串
pos缺省值为1

rfind:倒序查找


int main()
{
	string str("this is a program used to test find and rfind");
	int ret = str.find(" ");//从开始查找第一次出现的某字符
	cout << ret << endl;

	int ret2 = str.find('a', 4);//从下标4的位置查找'a'
	cout << ret2 << endl;

	int ret3 = str.find("ed", 4, 2);
	cout << ret3 << endl;

	return 0;
}
*/

/*
substr:生成子串（pos, len = n_pos）


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
		//存在最后一个空格
		cout << s.size() - pos - 1 << endl;
	}
	else
	{
		//整个字符
		cout << s.size() << endl;
	}
}