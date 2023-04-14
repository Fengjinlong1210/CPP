#define _CRT_SECURE_NO_WARNINGS 1
#include "string.h"
using namespace Fjl;

int main()
{
	string s1("aaaaabbbbbcccccdddddeeeee");

	string s2("hahahaha");

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;
	s1.swap(s2);

	cout << s1.c_str() << endl;
	cout << s2.c_str() << endl;


	return 0;
}