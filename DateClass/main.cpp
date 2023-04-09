#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

int main()
{
	Date d1(2023, 4, 6);
	Date d2(2021, 1, 1);
	//d1 -= 2;
	cout << (d1 >= d2) << endl;
	cout << (d1 - d2) << endl;
	return 0;
}