#include "Date.h"
//天数不固定(闰年2月)
int Date::GetMonthDay(int year, int month)
{
	static const int monthDay[13] = { 0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((month == 2) && (year % 4 == 0 && year % 100 != 0)
		|| (year % 400 == 0))
	{
		return 29;
	}

	return monthDay[month];
}

Date::Date(int year, int month, int day)
{
	if (year >= 0
		&& month > 0 && month < 13
		&& day > 0 && day <= GetMonthDay(year, month))
	{
		_year = year;
		_month = month;
		_day = day;
	}
	else
	{
		//assert(false);
		cout << "Date Invalid" << endl;
	}
}

inline bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year)
	{
		if (_month > d._month)
		{
			return true;
		}
		else if (_month == d._month)
		{
			if (_day > d._day)
			{
				return true;
			}
		}
	}

	return false;
}

inline bool Date::operator==(const Date& d)
{
	return _year == d._year
		&& _month == d._month
		&& _day == d._day;
}

bool Date::operator<(const Date& d)
{
	return !(*this >= d);
}
bool Date::operator<=(const Date& d)
{
	return !(*this > d);
}

// d1 >= d2
bool Date::operator>=(const Date& d)
{
	return *this > d || *this == d;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

// d1 + 100
Date Date::operator+(int day)
{
	//Date ret(*this);
	//ret._day += day;

	//while (ret._day > GetMonthDay(ret._year, ret._month))
	//{
	//	ret._day += GetMonthDay(ret._year, ret._month);
	//	++ret._month
	//	if (ret._month == 13){
	//		++ret._year;
	//		ret._month = 1;
	//	}
	//}
	////不能返回引用，因为函数结束ret对象销毁了
	//return ret;
	//复用+=
	Date ret(*this);
	ret._day += day;
	return ret;
}
//d1 += day
Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return *this -= (-day);
	}
	_day += day;
	while (_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month == 13){
			++_year;
			_month = 1;
		}
	}
	return *this;
	//复用+
	//*this = *this + day;
	//return *this;
}
void Date::Print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}
Date Date::operator-(int day)
{
	Date d(*this);
	d -= day;
	return d;
}
Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return *this += (-day);
	}
	_day -= day;
	while (_day <= 0)
	{
		--_month;
		_day += GetMonthDay(_year, _month);
		if (_month == 0)
		{
			--_year;
			_month = 12;
		}
	}
	return *this;
}
//++d
Date Date::operator++()
{
	*this += 1;
	return *this;
}
//d++
Date Date::operator++(int)
{
	Date d(*this);
	*this += 1;
	return d;
}
//--d
Date Date::operator--()
{
	*this -= 1;
	return *this;
}
Date Date::operator--(int)
{
	Date ret(*this);
	*this -= 1;
	return ret;
}
//两个日期相减
int Date::operator-(const Date& d)
{
	Date max = *this;
	Date min = d;
	int flag = 1;

	if (max < min)
	{
		flag = -1;
		max = d;
		min = *this;
	}
	int count = 0;
	while (min < max)
	{
		++count;
		++min;
	}
	return flag*count;
}