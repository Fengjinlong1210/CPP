#pragma once
#include <iostream>
using namespace std;

class Date
{
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1)
		:_year(year), _month(month), _day(day)
	{}

	//�������캯����Ĭ��
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}

	//��ֵ����:ʹ��Ĭ�ϼ���
	Date& operator=(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
		return *this;
	}

	//��������
	~Date()
	{}

	void Print()
	{
		cout << _year << "��" << _month << "��" << _day << "��" << endl;
	}

	//����+����
	Date operator+(int day) const;

	//����+=����
	Date& operator+=(int day);

	//����-����
	Date operator-(int day);

	//����-=����
	Date& operator-=(int day);

	//ǰ��++
	Date& operator++();

	//����++
	Date operator++(int);

	//ǰ��--
	Date& operator--();

	//����--
	Date operator--(int);

	//����>���������
	bool operator>(const Date& d);

	//С��<���������
	bool operator<(const Date& d);

	//���ڵ���>=���������
	bool operator>=(const Date& d);

	//С�ڵ���<=���������
	bool operator<=(const Date& d);

	//����==���������
	bool operator==(const Date& d);

	//������!=���������
	bool operator!=(const Date& d);

	//����-����
	int operator-(const Date& d);

	//���ÿ������
	int GetMonthDay(int year, int month);
private:
	int _year;
	int _month;
	int _day;
};

