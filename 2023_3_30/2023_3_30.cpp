#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
using namespace std;

/*
Ĭ�Ϲ��캯��/��������
���������������Ͳ����г�ʼ���������Ƕ��Զ������ͻ����Ĭ�ϵĹ��캯��
�����������Զ������ͻ����Ĭ�ϵĹ��캯��
*/

//class Time
//{
//public:
//	Time()
//	{
//		cout << "Time��Ĭ�Ϲ��캯��" << endl;
//	}
//
//private:
//	int _hour;
//	int _minute;
//	int _second;
//};
//
//class Date
//{
//	int _year;
//	int _hour;
//	int _day;
//
//	Time _t;
//};
//
//int main()
//{
//	Date d1;
//	//��������������Time��Ĭ�Ϲ��캯��
//
//	//����Լ������˹��캯���������εģ�
//	//�������ᱨ��,��Ϊȱ��Ĭ�ϵĹ��캯��
//	return 0;
//}

/*
�������캯��  �������캯���ǹ��캯����һ������
�ڽ�����Ŀ���ʱ���ÿ������캯�����������޷��Լ������Զ������ͣ�
class (class& classname)
�������캯���Ĳ���ֻ����һ�������Ƕ��������

���δ���忽�����������������Զ�����һ��Ĭ�ϵĿ������캯��
���ֽڽ���һһ����
�������Ͱ����ֽڽ��п������Զ�������ʹ�ÿ����������п���
*/
/*
class Time
{
public:
	Time(int hour = 0, int minute = 0, int second = 0)
	{
		_hour = hour;
		_minute = minute;
		_second = second;
	}

private:
	int _hour;
	int _minute;
	int _second;
};

class Date
{
public:
	//���캯��
	Date(int year = 1, int month = 1, int day = 1)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& dt)//���ݵ���ԭ���Ķ��������
	{
		_year = dt._year;
		_month = dt._month;
		_day = dt._day;
	}

private:
	int _year;
	int _month;
	int _day;
	Time _t;
};

int main()
{
	Date d1;
	//����Ĭ�Ͽ������캯���� ֻ�ܶ��������ͽ��п���
	Date d2 = d1;
	Date d3(d2);
	return 0;
}
*/

/*
���漰����Դ����ʱ������ʹ�ÿ������캯������ǳ����

�������캯���������������±����ã�
1.ʹ���Ѿ����ڵ�����󴴽��¶���
2.��������Ϊ�����Ͷ���
3.��������ֵΪ�����Ͷ���


class Date
{
public:
	//���캯��
	Date(int year, int month, int day)
	{
		cout << "Date:���캯��" <<this<< endl;
	}
	//�������캯��
	Date(const Date& dt)//���ݵ���ԭ���Ķ��������
	{
		cout << "Date:�������캯��" <<this<< endl;
	}

	~Date()
	{
		cout << "Date:������������" <<this<< endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

Date Test(Date d)//d1����ʱ����һ�ο������캯�����������β�
{
	Date tmp = d;//�����βο�������tmp����һ�ε��ÿ������캯��
	return tmp;	  //����tmpʱ�����ÿ������캯������һ����ʱ�������ڷ���tmp
}

int main()
{
	Date d1(2023, 3, 30);
	Test(d1);
	//����ʱ����������test�д�����tmp��Ȼ������test���β�d
	//���������ʱ���������ڷ��صĶ���
	return 0;
	//��ʱ����d1
}
*/

/*
��ֵ���������
��������  operator+(������) ��������
���ز�����������һ�������Ͳ���
��Ϊ���Ա��������ʱ��������һ������һ��������thisָ��



class Date
{
public:
	//���캯��
	Date(int year, int month, int day)
	{
		cout << "Date:���캯��" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	//�������캯��
	Date(const Date& dt)//���ݵ���ԭ���Ķ��������
	{
		cout << "Date:�������캯��" << this << endl;
		_year = dt._year;
		_month = dt._year;
		_day = dt._day;
	}

	~Date()
	{
		cout << "Date:��������" << this << endl;
	}

	//�������������
	//���������������thisָ��
	bool operator==(const Date& dt)
	{
		return _year == dt._year &&
			_month == dt._month &&
			_day == dt._day;
	}

	//��ֵ����� ֻ����Ϊ��Ա�����������ڲ�

	//�������帳ֵ���أ����������Զ�����Ĭ�ϵĸ�ֵ���غ���
	//Ĭ�ϵĸ������غ����ܶ��������ͽ��и�ֵ
	//���漰����Դ�Ĳ���ʱ����Ҫ�Լ����帳ֵ���غ���

	//��Ա���������صĺ�������������ֻ��һ���� ����һ��������thisָ�루ָ�����������
	Date& operator=(const Date& dt)
	{
		cout << "��ֵ���غ���" << endl;
		if (this != &dt) //�ж�thisָ���ȡ��ַdt�Ƿ���ȣ����˵����ͬһ�������
		{
			this->_year = dt._year;
			this->_month = dt._month;
			this->_day = dt._day;
		}

		return *this;//����this�Ա�������ֵ
	}

private:
	int _year;
	int _month;
	int _day;
};

int main()
{
	Date d1(2023, 3, 30);
	Date d2(2023, 3, 3);
	cout << (d1 == d2) << endl;
	Date d3(d2);//�������캯���������¶���ʱ�������ж�����и�ֵ
	Date d4(d2);//�������캯��
	Date d5(1234, 1, 1);
	d5 = d2;//��ֵ���أ������е������������и�ֵ����
	return 0;
}
*/

class Date
{
public:
	//���캯��
	Date(int year = 0, int month = 0, int day = 0)
	{
		cout << "Date() : ���캯��" << this << endl;
		_year = year;
		_month = month;
		_day = day;
	}
	//��������
	~Date()
	{
		cout << "~Date() : ��������" << this << endl;
	}
	//�������캯��
	Date(const Date& dt)
	{
		cout << "Date(Date& ) : �������캯��" << this << endl;

		_year = dt._year;
		_month = dt._month;
		_day = dt._day;
	}
	//��ֵ����
	Date& operator==(const Date& dt)
	{
		cout << "operator==(Date& ) : ��ֵ���غ���" << this << endl;
		if (this != &dt)
		{
			this->_year = dt._year;
			this->_month = dt._month;
			this->_day = dt._day;
		}
		return *this;
	}

	//ʵ��һ���������ӵĺ���

	Date& DateAdd(int day)
	{
		Date tmp = *this;
		tmp._day += day;
		while (tmp._day > GetMonthDay(tmp._year, tmp._month))
		{
			tmp._day -= GetMonthDay(tmp._year, tmp._month);
			tmp._month++;
			if (tmp._month > 12)
			{
				tmp._year++;
				tmp._month = 1;
			}
		}

		return tmp;
	}

	int GetMonthDay(int year, int month)
	{
		int Month[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };

		if (((year % 400 == 0) || ((year % 4 == 0) && (year % 100 != 0))) && month == 2)
		{
			return Month[2] + 1;
		}
		return Month[month];
	}

	void Print()
	{
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};


int main()
{
	Date d1(2023, 3, 30);
	Date ret = d1.DateAdd(100);
	ret.Print();
	return 0;
}