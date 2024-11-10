#define _CRT_SECURE_NO_WARNINGS 1
#include<vector>
#include "RBTree.h"

//int main()
//{
//	int a[] = { 16,3,7,11,9,26,18,14,15 };
//	RBTree<int, int> t;
//	for (auto& e : a)
//	{
//		t.insert(make_pair(e, e));
//	}
//
//	return 0;
//}

int main()
{
	const int N = 100000;
	vector<int> v;
	v.reserve(N);
	srand(time(0));

	for (int i = 0; i < N; i++)
	{
		v.push_back(rand());
	}
	RBTree<int, int> t;
	for (auto e : v)
	{
		t.insert(make_pair(e, e));
	}

	return 0;
}


