#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

ostream& operator<<(ostream& out, const Date& dt)
{
	out << dt._year << "Äê" << dt._month << "ÔÂ" << dt._day << "ÈÕ" << endl;
	return out;
}

istream& operator>>(istream& in, Date& dt)
{
	in >> dt._year >> dt._month >> dt._day;
	return in;
}

