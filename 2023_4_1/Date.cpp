#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

ostream& operator<<(ostream& out, const Date& dt)
{
	out << dt._year << "��" << dt._month << "��" << dt._day << "��" << endl;
	return out;
}

istream& operator>>(istream& in, Date& dt)
{
	in >> dt._year >> dt._month >> dt._day;
	return in;
}

