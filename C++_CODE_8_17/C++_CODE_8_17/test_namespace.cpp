#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

//int main()
//{
//	std::cout << "hello cpp" << std::endl;
//	return 0;
//}

// 命名空间的展开
using namespace std;

//int main()
//{
//	cout << "hello cpp" << endl;
//	return 0;
//}

namespace N1
{
	int a = 10;
	void test()
	{
		cout << "test01" << endl;
	}
}

namespace N2
{
	int a = 20;
	void test()
	{
		cout << "test02" << endl;
	}
}

//int main()
//{
//	cout << N1::a << endl;
//	cout << N2::a << endl;
//	N1::test();
//	N2::test();
//	return 0;
//}
