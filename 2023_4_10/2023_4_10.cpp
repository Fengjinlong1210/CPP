#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

int exchangeBits(int num)
{
    //ͨ����λ�룬�ȵõ�����λ��ż��λ
    int getodd = 0b01010101010101010101010101010101;
    int geteven = 0b10101010101010101010101010101010;

    //����λ����һλ��ż��λ����һλ�����
    int odd = getodd & num;
    int even = geteven & num;

    odd <<= 1;
    even >>= 1;

    return odd + even;

}

char* compressString(char* S)
{
    int length = strlen(S);
    char* newS = (char*)malloc(length * 2 + 2);
    if (!newS)
    {
        exit(-1);
    }
    int slow = 0;
    int fast = 1;
    int pos = 0;
    while (fast <= length)
    {
        if (S[slow] == S[fast])
        {
            ++fast;
        }
        else
        {
            newS[pos++] = S[slow];
            sprintf(newS + pos, "%d", fast - slow);
            int count = fast - slow;
            while (count >= 10)
            {
                pos++;
                count /= 10;
            }
            pos++;
            slow = fast++;
        }
    }
    newS[pos] = '\0';
    if (pos >= length)
    {
        return S;
    }
    return newS;
}

int main()
{
    char str[] = "rrrrrLLLLLPPPPPPRRRRRgggNNNNNVVVVVVVVVVDDDDDDDDDDIIIIIIIIIIlllllllAAAAqqqqqqqbbbNNNNffffff";
    char* ret = compressString(str);
    printf("%s\n", ret);
	return 0;
}