#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

int Date::GetMonthDay(int year, int month)
{
	static int day[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if ((month == 2) && (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)))
		return 29;
	return day[month];
}

bool Date::operator==(const Date d) const
{
	return (_year == d._year) &&
		(_month == d._month) &&
		(_day == d._day);
}

bool Date::operator>(const Date d) const
{
	if (_year > d._year)
		return true;
	else if ((_year == d._year) && (_month > d._month))
		return true;
	else if ((_year == d._year) && (_month == d._month) && (_day > d._day))
		return true;
	return false;
}

bool Date::operator<(const Date d) const
{
	return !(*this > d);
}

bool Date::operator>=(const Date d) const
{
	return (*this > d) || (*this == d);
}

bool Date::operator<=(const Date d) const
{
	return !(*this >= d);
}

bool Date::operator!=(const Date d) const
{
	return !(*this == d);
}

Date& Date::operator+=(int day)
{
	_day += day;
	while(_day > GetMonthDay(_year, _month))
	{
		_day -= GetMonthDay(_year, _month);
		++_month;
		if (_month > 12)
		{
			_month = 1;
			++_year;
		}
	}
	return *this;
}

Date Date::operator+(int day)
{
	Date d = *this;
	d += day;
	return d;
}

Date& Date::operator++()
{
	*this += 1;
	return *this;
}

Date Date::operator++(int)
{
	Date d = *this;
	*this += 1;
	return d;
}


