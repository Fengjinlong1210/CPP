#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	string table = "0123456789ABCDEF";
	string str;
	int M, N;
	int flag = 1;
	cin >> M >> N;
	if (M < 0)
	{
		flag = -1;
		M = flag * M;
	}
	while (M)
	{
		str += table[M % N];
		M /= N;
	}
	if (flag == -1)
	{
		str += '-';
	}
	if (!str.size())
	{
		str += '0';
	}
	reverse(str.begin(), str.end());
	cout << str << endl;
}