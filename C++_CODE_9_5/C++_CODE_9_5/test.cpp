#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"

//void test_date01()
//{
//	Date d1(2024, 9, 2);
//	d1.Print();
//	Date d2(2024, 9, 2);
//	cout << (d1 == d2) << endl;
//}

void test_date02()
{
	Date d1(2024, 9, 3);
	Date d2(2024, 9, 2);
	cout << (d1 > d2) << endl;
	cout << (d1 < d2) << endl;
}

void test_date03()
{
	Date d1(2024, 9, 3);
	Date d2(2024, 9, 2);
	Date d3(d2);
	// cout << (d1 >= d2) << endl;
	// d3.Print();
	cout << (d3 >= d2) << endl;
}

void test_date04()
{
	Date d1(2024, 9, 4);
	Date d2 = (d1 += 100);
	d2.Print();
	d2++;
	d2.Print();
}

void test_date05()
{
	Date d1(2024, 9, 5);
	Date d2 = (d1 -= 1000);
	d2.Print();
}

void test_date06()
{
	Date d1(2024, 9, 5);
	Date d2(2024, 10, 1);
	int ret = d1 - d2;
	cout << ret << endl;
}

void test_date07()
{
	Date d1(2024, 9, 5);
	Date d2(2024, 10, 1);
	int ret = d1 - d2;
	cout << ret << endl;
	//cout << d1 << endl;
	//cout << d2 << endl;
	cin >> d1 >> d2;
	cout << d1 << endl << d2 << endl;
}

int main()
{
	// test_date01();
	// test_date02();
	// test_date03();
	// test_date04();
	// test_date05();
	// test_date06();
	test_date07();
	return 0;
}

