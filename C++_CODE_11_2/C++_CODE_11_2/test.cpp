#define _CRT_SECURE_NO_WARNINGS 1
#include "AVLTree.h"


int main()
{
	int a[] = { 16,3,7,11,9,26,18,14,15 };
	AVLTree<int, int> t;
	for (const auto& e : a)
	{
		t.insert(make_pair(e, e));
		// cout << "insert: " << e << "->" << t.IsBalance() << endl;
	}

	return 0;
}