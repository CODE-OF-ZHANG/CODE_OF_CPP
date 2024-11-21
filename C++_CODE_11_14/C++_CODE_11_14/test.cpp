#define _CRT_SECURE_NO_WARNINGS 1
#include<set>
#include "My_Map.h"
#include "My_Set.h"

int main()
{
	zx::map<int, int> m;
	m.insert(make_pair(1, 1));
	m.insert(make_pair(2, 2));
	m.insert(make_pair(4, 4));
	m.insert(make_pair(6, 6));
	m.insert(make_pair(5, 5));

	zx::set<int> s;
	s.insert(5);
	s.insert(2);
	s.insert(2);
	s.insert(12);
	s.insert(22);
	s.insert(332);
	s.insert(7);

	zx::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
	return 0;
}