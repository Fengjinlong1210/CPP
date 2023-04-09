#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	//构造函数
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{}

	//拷贝构造函数：默认
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//赋值重载:使用默认即可
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	//析构函数
	~Date()
	{}

	void Print()
	{
		cout << _year << "年" << _month << "月" << _day << "日" << endl;
	}

	//日期+天数
	Date operator+(int day) const;

	//日期+=天数
	Date& operator+=(int day);

	//日期-天数
	Date operator-(int day);

	//日期-=天数
	Date& operator-=(int day);

	//前置++
	Date& operator++();

	//后置++
	Date operator++(int);

	//前置--
	Date& operator--();

	//后置--
	Date operator--(int);

	//大于>运算符重载
	bool operator>(const Date& d);

	//小于<运算符重载
	bool operator<(const Date& d);

	//大于等于>=运算符重载
	bool operator>=(const Date& d);

	//小于等于<=运算符重载
	bool operator<=(const Date& d);

	//等于==运算符重载
	bool operator==(const Date& d);

	//不等于!=运算符重载
	bool operator!=(const Date& d);

	//日期-日期
	int operator-(const Date& d);

	//获得每月天数
	int GetMonthDay(int year, int month);
private:
	int _year;
	int _month;
	int _day;
};

