#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<list>
using namespace std;

void test_list01()
{
	list<int> lt;
	// 尾插
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	// 打印
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 在链表的第一个位置插入
	lt.insert(lt.begin(), 10);
	for (auto e : lt)
	{
		cout << e << " ";
	}
	cout << endl;

	// 在链表的第五个位置插入
	auto it = lt.begin();
	for (int i = 0; i < 5; i++)
	{
		++it;
	}
	lt.insert(it, 50);

	for (auto e : lt)
		cout << e << " ";
	cout << endl;
}

void test_list02()
{
	list<int> lt;
	// 尾插
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	// 打印
	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	// 查找
	auto it = find(lt.begin(), lt.end(), 4);
	// list<int>::iterator it = find(lt.begin(), lt.end(), 4);
	if (it != lt.end())
		lt.insert(it, 1000);

	for (auto e : lt)
		cout << e << " ";
	cout << endl;

	// 删除
	lt.erase(it);
	for (auto e : lt)
		cout << e << " ";
	cout << endl;
}

int main()
{
	// test_list01();
	test_list02();

	return 0;
}
