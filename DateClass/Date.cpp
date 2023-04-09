#define _CRT_SECURE_NO_WARNINGS 1
#include "Date.h"

int Date::GetMonthDay(int year, int month)
{
	int day[13] = { 0, 31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((((year % 4 == 0) && (year % 100 != 0)) || (year && 400 == 0)) && month ==2)
	{
		return 29;
	}
	else
	{
		return day[month];
	}
}

Date& Date::operator+=(int day)
{
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month > 12)
		{
			++_year;
			_month = 1;
		}
	}
	return *this;
}

Date Date::operator+(int day) const
{
	//this本身不改变,返回拷贝
	Date tmp(*this);
	tmp += day;
	return tmp;
}

Date& Date::operator-=(int day)
{
	//日期-天数
	int i = 0;
	for (i = 0; i < day; ++i)
	{
		--_day;
		if (_day < 1)
		{
			if (_month > 1)
			{
				--_month;
				_day = GetMonthDay(_year, _month);
			}
			else
			{
				--_year;
				_month = 12;
				_day = GetMonthDay(_year, _month);

			}
		}
	}
	return *this;
}

Date Date::operator-(int day)
{
	Date tmp(*this);
	tmp -= day;
	return tmp;
}

Date& Date::operator++()
{
	return *this += 1;
}

Date Date::operator++(int)//后置
{
	Date tmp(*this);
	*this += 1;
	return tmp;
}

Date& Date::operator--()
{
	return *this -= 1;
}

Date Date::operator--(int)
{
	Date tmp(*this);
	*this -= 1;
	return tmp;
}

bool Date::operator==(const Date& d)
{
	return this->_year == d._year &&
		this->_month == d._month &&
		this->_day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return this->_year != d._year ||
		this->_month != d._month ||
		this->_day != d._day;
}


bool Date::operator>(const Date& d)
{
	if (this->_year < d._year)
	{
		return false;
	}
	else if (this->_year == d._year && this->_month < d._month)
	{
		return false;
	}
	else if (this->_year == d._year && this->_month == d._month && this->_day < d._day)
	{
		return false;
	}
	else
	{
		return true;
	}
}

bool Date::operator>=(const Date& d)
{
	return *this == d || *this > d;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}

bool Date::operator<=(const Date& d)
{
	return !(*this < d);
}

int Date::operator-(const Date& d)//日期-日期
{
	Date greater = *this;
	Date smaller = d;
	int flag = 0;
	if (*this < d)
	{
		greater = d;
		smaller = *this;
		flag = 1;
	}
	int count = 0;
	while (greater != smaller)
	{
		greater -= 1;
		count++;
	}
	return count;
}
