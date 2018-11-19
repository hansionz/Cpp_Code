#pragma once

#include<iostream>
#include<stdio.h>

using namespace std;
class Date
{
public:
	//全缺省构造器
	Date(int year = 1900, int month = 1, int day = 1);
	//拷贝构造
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//赋值运算符重载
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//析构函数
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	//重载比较类运算符
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	//加减类运算符重载
	Date operator+(int day);
	Date& operator+=(int day);
	Date operator-(int day);
	Date& operator-=(int day);
	int operator-(const Date& d);
	Date operator++(); // ++d => d.operator++(&d)
	Date operator++(int); // d++ => d.operator(&d, 0);
	Date operator--(); // --d 
	Date operator--(int); // d--
	void Print();
	//重载输入和输出
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
	//获取月为month的天数
	inline int GetMonthDay(int year, int month);
private:
	int _year; //年
	int _month;//月
	int _day;  //日
};
