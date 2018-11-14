#pragma once

#include<iostream>
#include<stdio.h>

using namespace std;
class Date
{
public:
	//ȫȱʡ������
	Date(int year = 1900, int month = 1, int day = 1);
	//��������
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//��ֵ���������
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
	//��������
	~Date()
	{
		_year = 0;
		_month = 0;
		_day = 0;
	}
	//���رȽ��������
	bool operator>(const Date& d);
	bool operator<(const Date& d);
	bool operator<=(const Date& d);
	bool operator>=(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	//�Ӽ������������
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
	//������������
	friend ostream& operator<<(ostream& _cout, const Date& d);
	friend istream& operator>>(istream& _cin, Date& d);
	//��ȡ��Ϊmonth������
	inline int GetMonthDay(int year, int month);
private:
	int _year; //��
	int _month;//��
	int _day;  //��
};
