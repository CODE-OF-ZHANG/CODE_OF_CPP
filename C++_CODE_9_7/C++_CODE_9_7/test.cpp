#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;

//int main()
//{
//	int a = 10;
//	int& b = a;  // b是a的引用
//	cout << a << endl;
//	cout << b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << &a << endl;
//	cout << &b << endl;  // a 和 b 使用的是同一块内存地址
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a;
//	b = 20;
//	cout << a << " " << b << endl;
//	return 0;
//}


//void testref01()
//{
//	int a = 10;
//	int& b;
//}

//void testref02()
//{
//	int a = 10;
//	int& b = a;
//	int& c = b;
//	int& d = a;
//}

//void testref02()
//{
//	int a = 10;
//	int b = 20;
//	int& c = a;
//	int& c = b;
//}

//void testref03()
//{
//	const int& a = 10;
//}


//void testref04()
//{
//	/*char ch = 'a';
//	int& a = ch;*/
//}

//void testref05()
//{
//	char ch = 'a';
//	const int& a = ch;
//}

//void Swap(int a, int b)
//{
//	int tmp = a;
//	a = b;
//	b = tmp;
//}
//
//void Swap(int* pa, int* pb)
//{
//	int tmp = *pa;
//	*pa = *pb;
//	*pb = tmp;
//}

//void func(int& x, int& y)
//{
//	cout << &x << endl;
//	cout << &y << endl;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	cout << &a << endl;
//	cout << &b << endl;
//	cout << "-------------" << endl;
//	func(a, b);
//	return 0;
//}


//int main()
//{
//	// testref();
//	// testref02();
//	// testref03();
//	// testref04();
//	return 0;
//}

void Swap(int& a, int& b)
{
	int tmp = a;
	a = b;
	b = tmp;
}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	return 0;
//}

//#include <time.h>
//// 传值
//struct A{ int a[10000]; }; 
//void TestFunc1(A a) {}
//// 传引用
//void TestFunc2(A& a) {}
//
//void TestRefAndValue()
//{
//	A a;
//	// 以值作为函数参数
//	size_t begin1 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		TestFunc1(a);
//	}
//	size_t end1 = clock();
//	// 以引用作为函数参数
//	size_t begin2 = clock();
//	for (size_t i = 0; i < 10000; i++)
//	{
//		TestFunc2(a);
//	}
//	size_t end2 = clock();
//	// 分别计算两个函数运行结束后的时间
//	cout << "TestFunc1(A)-time:" << end1 - begin1 << endl;
//	cout << "TestFunc2(A&)-time:" << end2 - begin2 << endl;
//}

//int main()
//{
//	TestRefAndValue();
//	return 0;
//}

//int& Count()
//{
//	static int n = 0;
//	n++;
//	// ... 
//	return n;
//}

//int main()
//{
//	Count();
//	return 0;
//}

//int& Add(int a, int b)
//{
//	int c = a + b;
//	return c;
//}

//int& Count()
//{
//	int n = 0;
//	n++;
//	// ...
//	return n;
//}


//int main()
//{
//	int ret = Count();
//	int a = 10;
//	cout << a << endl;
//	cout << ret << endl;
//	cout << a << endl;
//	cout << ret << endl;
//
//	return 0;
//}

//int main()
//{
//	int ret = Count();
//	for (int i = 0; i < 10; i++)
//	{
//		cout << ret << endl;
//	}
//	return 0;
//}

#include<time.h>
struct A { int a[10000]; };

A a;
// 值返回
A TestFunc1() { return a; }
// 引用返回
A& TestFunc2() { return a; }

void TestReturnByRefOrValue()
{
	// 以值作为函数的返回值类型
	size_t begin1 = clock();
	for (int i = 0; i < 100000; i++)
		TestFunc1();
	size_t end1 = clock();
	// 以引用作为函数的返回值类型
	size_t begin2 = clock();
	for (int i = 0; i < 100000; i++)
		TestFunc2();
	size_t end2 = clock();
	// 计算两个函数运算完成之后的时间
	cout << "TestFunc1() Time:" << begin1 - end1 << endl;
	cout << "TestFunc2() Time:" << begin2 - end2 << endl;
}

//int main()
//{
//	TestReturnByRefOrValue();
//	return 0;
//}


//int main()
//{
//	int a = 10;
//	int& b = a;
//	cout << &a << endl;
//	cout << &b << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	ra = 20;
//	int* pa = &a;
//	*pa = 20;
//	return 0;
//}

//int main()
//{
//	int a = 20;
//	int* pa;
//	int& ra;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int b = 20;
//	int* pa = &a;
//	pa = &b;
//	int& ra = a;
//	int& ra = b;
//	return 0;
//}

//int main()
//{
//	int* pa = NULL;
//	int& ra = NULL;
//	return 0;
//}

// #include<string>
//int main()
//{
//	string str = "abcdef";
//	string& rstr = str;
//	string* pstr = &str;
//	cout << "string& rstr = str: " << sizeof(rstr) << endl;
//	cout << "string* pstr = &str: " << sizeof(pstr) << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int& ra = a;
//	int* pa = &a;
//	ra++;
//	pa++;
//	cout << "int& ra = a:  " << ra << endl;
//	cout << "int* pa = &a: " << pa << endl;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int** ppa = &pa;
//	int& ra = a;
//	int&& rra = ra;
//	return 0;
//}

//int main()
//{
//	int a = 10;
//	int* pa = &a;
//	int& ra = a;
//	cout << ra << endl;
//	cout << *pa << endl;
//	return 0;
//}

