#define _CRT_SECURE_NO_WARNINGS 1
//#include "stack.h"
//using namespace Fjl;
//
//int main()
//{
//	Fjl::stack<int> st1;
//	st1.push(1);
//	st1.push(2);
//	st1.push(3);
//	st1.push(4);
//	st1.push(5);
//
//	while (!st1.empty())
//	{
//		cout << st1.top() << " ";
//		st1.pop();
//	}
//	cout << endl;
//
//	return 0;
//}

//#include <iostream>
//#include <string>
//#include <cctype>
//using namespace std;
//
//int main()
//{
//    string str;
//    string cur;
//    string longest;
//    getline(cin, str);
//    int i = 0;
//    for (i = 0; i <= str.size(); ++i)
//    {
//        if (!isdigit(str[i]))
//        {
//            if (longest.size() < cur.size())
//            {
//                longest.swap(cur);
//                cur.clear();
//            }
//            else
//            {
//                cur.clear();
//            }
//        }
//        else
//        {
//            cur += str[i];
//        }
//    }
//    cout << longest;
//}

#include <iostream>
#include <cmath>
using namespace std;

//int main()
//{
//	long long a = 1, b = 2, c = 3;
//
//	printf("%d, %d, %d, %d, %d, %d\n", a, b, c);
//	//%d 每次读取32个比特位，先读取到a的低32位字节，然后读a的高32位字节
//	//再分别读取b和c的低位和高位	
//
//	//低于32位的整形，会先整型提升到32位，然后进行打印
//	return 0;
//}

//class Solution {
//public:
//    bool isNum(char ch)
//    {
//        if (ch >= '0' && ch <= '9')
//            return true;
//        return false;
//    }
//
//    int StrToInt(string str)
//    {
//        if ((str[0] != '-' && str[0] != '+') && !isNum(str[0]))
//            return 0;
//        int num = 0;
//        int i = 0;
//        int flag = 1;
//        for (i = 0; i < str.size(); ++i)
//        {
//            if (i == 0 && str[i] != '-')
//            {
//                flag = -1;
//            }
//            if (i != 0 && !isNum(str[i]))
//            {
//                return 0;
//            }
//            num += (int)(str[i] - '0') * pow(10, str.size() - i - 1);
//        }
//
//        return num * flag;
//    }
//};

class Solution {
public:
    string addStrings(string num1, string num2)
    {
        long long n1 = 0;
        long long n2 = 0;
        int i1 = 0;
        int i2 = 0;
        while (i1 < num1.size())
        {
            n1 = 10 * n1 + (int)(num1[i1] - '0');
            ++i1;
        }
        while (i2 < num2.size())
        {
            n2 = 10 * n2 + (int)(num2[i2] - '0');
            ++i2;
        }
        long long ans = n1 + n2;
        string ret;
        while (ans > 0)
        {
            ret += ans % 10 + '0';
            ans /= 10;
        }
        reverse(ret.begin(), ret.end());

        return ret;
    }
};

//int main()
//{
//    Solution s;
//    string ret = s.addStrings("11", "123");
//    cout << ret << endl;
//}

int main()
{
    string num("123");
    int i = 0;
    int n = 0;
    while (i < num.size())
    {
        n = n * 10 + (num[i] - '0');
        ++i;
    }
    cout << n << endl;
}