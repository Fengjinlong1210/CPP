#define _CRT_SECURE_NO_WARNINGS 1
#include <iostream>
#include <vector>
using namespace std;

//int main()
//{
//	int n = 1;  //00000000  00000000  00000000  00000001
//	int n2 = -1;//11111111  11111111  11111111  11111111
//
//	int n3 = -15;
//	//00000000  00000000  00000000  00001111
//	//11111111  11111111  11111111  11110001
//
//	//一个数按位与上他的负数，得到的是最低位的1
//
//	//00000000  00000000  00000000  00001010
//	//11111111  11111111  11111111  11110111
//
//	int i = 0;
//	for (i = 0; i < 40; ++i)
//	{
//		printf("%d\n", i & (-i));
//	}
//
//
//	return 0;
//}

//int main() {
//    int year;
//    int month;
//    int day;
//    vector<int> days(13);
//    days[0] = 0;
//    days[1] = 31;
//    days[2] = 28;
//    days[3] = 31;
//    days[4] = 30;
//    days[5] = 31;
//    days[6] = 30;
//    days[7] = 31;
//    days[8] = 31;
//    days[9] = 30;
//    days[10] = 31;
//    days[11] = 30;
//    days[12] = 31;
//
//    cin >> year >> month >> day;
//    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
//    {
//        ++days[2];
//    }
//    int count = 0;
//    
//    int i = 1;
//    for (i = 1; i < month; ++i)
//    {
//        count += days[i];
//    }
//
//    printf("%d\n", count + day);
//
//    return 0;
//
//}

class Date {
public:
    Date(int num = 0) {
        _year = num / 10000;
        _month = num % 10000 / 100;
        _day = num % 10000 % (_month * 100);
    }

    int GetMonthDay(int year, int month) {
        static int Month[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

        if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0) {
            if (month == 2) {
                return Month[month] + 1;
            }
        }
        return Month[month];
    }

    bool operator>(const Date& dt2) {
        if (this->_year > dt2._year) {
            return true;
        }
        else if (this->_year == dt2._year && this->_month > dt2._month) {
            return true;
        }
        else if (this->_year == dt2._year && this->_month == dt2._month &&
            this->_day > dt2._day) {
            return true;
        }
        else {
            return false;
        }
    }

    Date& operator+=(int day) {
        _day += day;
        while (_day > GetMonthDay(_year, _month)) {
            _day -= GetMonthDay(_year, _month);
            ++_month;
            if (_month > 12) {
                ++_year;
                _month = 1;
            }
        }
        return *this;
    }

    bool operator==(const Date& dt2)
    {
        return this->_year == dt2._year &&
            this->_month == dt2._month &&
            this->_day == dt2._day;
    }

    //不等于运算符 !=
    bool operator!=(const Date& dt2)
    {
        return this->_year != dt2._year ||
            this->_month != dt2._month ||
            this->_day != dt2._day;
    }

    int operator-(const Date& d2)
    {
        Date min = *this;
        Date max = d2;
        int flag = 1;
        if (min > max)
        {
            min = d2;
            max = *this;
            flag = -1;
        }
        int count = 0;
        while (min != max)
        {
            min += 1;
            ++count;
        }
        return count * flag;
    }

private:
    int _year;
    int _month;
    int _day;
};

int main()
{
    int year1;
    int year2;
    //while (cin >> year1 >> year2)

    { // 注意 while 处理多个 case
        Date y1(20110412);
        Date y2(20110422);
        int ret = y1 - y2 + 1;
        cout << ret << endl;
    }
}