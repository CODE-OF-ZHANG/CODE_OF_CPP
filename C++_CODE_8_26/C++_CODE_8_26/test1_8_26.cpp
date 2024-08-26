#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//class Stack
//{
//public:
//	Stack()
//	{
//		
//	}
//private:
//	int* a;
//	int _top;
//	int _capacity;
//
//};

//class Date
//{
//public:
//	void Print()
//	{
//		cout << _year << _month << _day << endl;
//	}
//private:
//	int _day = 1;
//	int _month = 1;
//	int _year = 1;
//};

//int main()
//{
//	Date d1;
//	d1.Print();
//
//	return 0;
//}


//class Date
//{
//public:
//	void Init(int year, int month, int day)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//
//	void Print()
//	{
//		cout << _year << "/" << _month << "/" << _day << endl;
//	}
//
//private:
//	int _year;
//	int _month;
//	int _day;
//};

//int main()
//{
//	Date d1;
//	d1.Init(2024, 8, 26);
//	d1.Print();
//
//	Date d2;
//	d2.Init(2024, 9, 1);
//	d2.Print();
//	return 0;
//}

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
		cout << _year << "/" << _month << "/" << _day << endl;
	}

private:
	int _year;
	int _month;
	int _day;
};

//int main()
//{
//	Date d1(2024, 8, 26);
//	d1.Print();
//
//	return 0;
//}