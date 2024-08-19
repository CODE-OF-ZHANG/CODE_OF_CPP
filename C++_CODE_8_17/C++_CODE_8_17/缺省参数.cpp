#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//void test1(int a = 20)
//{
//	cout << a << endl;
//}
//
//int main()
//{
//	int a = 10;
//	test1();  // 没有传参时，使用参数的默认值
//	test1(a);  // 有参数传递时，使用指定的实参
//	return 0;
//}


//void test2(int a = 10, int b = 20, int c = 30)
//{}


void test3(int a, int b = 10, int c = 20)
{}

//int main()
//{
//	test3(1);
//	return 0;
//}


//void test4(int a, int b, int c);
//int main()
//{
//	test4(1);
//	return 0;
//}
//
//void test4(int a, int b = 10, int c = 20)
//{
//	cout << a << endl;
//}

//int Add(int a, int b)
//{
//	return a + b;
//}
//
//double Add(double a, double b)
//{
//	return a + b;
//}

//// 参数个数不同
//void test01()
//{
//	cout << "test01()" << endl;
//}
//// 参数类型不同
//void test01(int a)
//{
//	cout << "test01(int a)" << endl;
//}
//// 参数类型顺序不同
//void test01(int a, double b)
//{
//	cout << "test01(int a, double b)" << endl;
//}
//
//void test01(double a, int b)
//{
//	cout << "test01(double a, int b)" << endl;
//}

//int test(int a)
//{
//	return a;
//}
//
//double test(int a) // err
//{
//	return (double)a;
//}

