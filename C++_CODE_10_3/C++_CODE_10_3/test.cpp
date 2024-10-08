#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<algorithm>
using namespace std;

//void test_priority_queue()
//{
//	// 大堆
//	// priority_queue<int> pq;
//
//	priority_queue<int, vector<int>, greater<int>> pq;
//	pq.push(4);
//	pq.push(2);
//	pq.push(5);
//	pq.push(1);
//	pq.push(3);
//
//	while (!pq.empty())
//	{
//		cout << pq.top() << " ";
//		pq.pop();
//	}
//	cout << endl;
//}
//
//int main()
//{
//	test_priority_queue();
//	return 0;
//}

void test_sort()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(5);
	v.push_back(6);
	v.push_back(4);

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;

	// sort(v.begin(), v.end());


	sort(v.begin(), v.end(), greater<int>());

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}

template<class Container>
void Print(const Container& v)
{
	// typename就是告诉编译器这是个类型
	typename Container::const_iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}


//void test_vector1()
//{
//	vector<int> v;
//	v.push_back(1);
//	v.push_back(2);
//	v.push_back(3);
//	v.push_back(4);
//	v.push_back(5);
//	Print(v);
//}

void test_list1()
{
	list<int> lt;
	lt.push_back(1);
	lt.push_back(2);
	lt.push_back(3);
	lt.push_back(4);
	lt.push_back(5);
	Print(lt);
}

int main()
{
	// test_sort();
	test_list1();
	return 0;
}