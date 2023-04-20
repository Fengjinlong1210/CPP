#define _CRT_SECURE_NO_WARNINGS 1
#include "vector.h"
#include <algorithm>

using namespace Fjl;
using std::find;

int main()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);

	v1.Print();

	v1.resize(20, 5);
	v1.Print();


	vector<int>::iterator pos = find(v1.begin(), v1.end(), 5);
	pos = v1.insert(pos, 100);
	v1.Print();

	//vector<int>::iterator pos2 = find(v1.begin(), v1.end(), 1);

	v1.erase(pos);
	v1.Print();

	return 0;
}