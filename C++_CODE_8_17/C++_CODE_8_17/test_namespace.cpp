#define _CRT_SECURE_NO_WARNINGS 1
// #include<stdio.h>
#include<iostream>

namespace N1
{
	int a = 10;
	void test()
	{
		printf("test() a = 10\n");
	}
}

namespace N2
{
	int a = 20;
	void test()
	{
		printf("test() a = 20\n");
	}
	namespace N3
	{
		struct Node
		{
			struct Node* next;
			int data;
		};
	}
}

//int main()
//{
//	printf("%d\n", N1::a);
//	N1::test();
//	printf("%d\n", N2::a);
//	N2::test();
//	N2::N3::Node node;
//	node.data = 123;
//	printf("%d\n", node.data);
//	return 0;
//}

//using N1::a;
//using N2::N3::Node;
//int main()
//{
//	printf("%d\n", a);
//	printf("%d\n", N2::a);
//	Node node;
//	node.data = 456;
//	printf("%d\n", node.data);
//	return 0;
//}

//using namespace N2;
//
//int main()
//{
//	printf("%d\n", a);
//	test();
//	printf("%d\n", N1::a);
//	N1::test();
//	N3::Node node;
//	node.data = 789;
//	printf("%d\n", node.data);
//	return 0;
//}


//using std::cout;
//using std::endl;
//
//int main()
//{
//	cout << N1::a << endl;
//	cout << N2::a << endl;
//	N2::N3::Node node;
//	node.data = 111;
//	cout << node.data << endl;
//	return 0;
//}

//int main()
//{
//	int a;
//	int a = 20;
//	printf("%d\n", a);
//	return 0;
//}


//int main()
//{
//	std::cout << "hello cpp" << std::endl;
//	return 0;
//}

// 命名空间的展开
// using namespace std;

//int main()
//{
//	cout << "hello cpp" << endl;
//	return 0;
//}

//namespace N3
//{
//	int a = 10;
//	void test()
//	{
//		cout << "test01" << endl;
//	}
//}
//
//namespace N4
//{
//	int a = 20;
//	void test()
//	{
//		cout << "test02" << endl;
//	}
//}

//int main()
//{
//	cout << N1::a << endl;
//	cout << N2::a << endl;
//	N1::test();
//	N2::test();
//	return 0;
//}

#include<iostream>
using std::cout;
using std::cin;
using std::endl;

//int main()
//{
//	int a = 0;
//	cin >> a;
//	cout << a << endl;
//	return 0;
//}
