#pragma once
#include<iostream>
using namespace std;

class Date
{
public:
	Date(int year, int month, int day)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void Print()
	{
		cout << _year << "Äê" << _month << "ÔÂ" << _day << "ÈÕ" << endl;
	}

	int GetMonthDay(int year, int month);

	bool operator==(const Date d) const;
	bool operator>(const Date d) const;
	bool operator<(const Date d) const;
	bool operator>=(const Date d) const;
	bool operator<=(const Date d) const;
	bool operator!=(const Date d) const;
	Date& operator+=(int day);
	Date& operator++();
	Date operator++(int);
	Date operator+(int day);

private:
	int _year = 1;
	int _month = 1;
	int _day = 1;
};
