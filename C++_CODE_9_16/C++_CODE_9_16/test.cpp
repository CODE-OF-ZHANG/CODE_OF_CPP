#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

//int main()
//{
//	printf("hello" "world\n");
//	return 0;
//}

//int main()
//{
//	string s1("hello world");
//	string s2(s1);
//	printf("%p\n", s1.c_str());
//	printf("%p\n", s2.c_str());
//	return 0;
//}

void test_vector1()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;


	vector<int>::iterator it = v.begin();
	while (it != v.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;

	for (auto e : v)
	{
		cout << e << " ";
	}
	cout << endl;
}



void test_vector2()
{
	vector<int> v1(10, 1);
	vector<string> v2(10, "***");
	
	for (int i = 0; i < v1.size(); i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;



	vector<string>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it << " ";
		it++;
	}
	cout << endl;
}



void test_vector3()
{
	vector<int> v;
	v.push_back(3);
	v.push_back(2);
	v.push_back(1);
	v.push_back(9);
	v.push_back(5);
	v.push_back(10);
	v.push_back(7);
	v.push_back(8);
	v.push_back(4);
	v.push_back(6);

	vector<int>::iterator it = v.begin();
	// ÉýÐò
	sort(v.begin(), v.end());
	while (it != v.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;


	vector<int>::iterator it1 = v.begin();
	// ½µÐò
	sort(v.begin(), v.end(), greater<int>());
	while (it1 != v.end())
	{
		cout << *it1 << " ";
		++it1;
	}
	cout << endl;
}



void test_vector4()
{
	size_t numRows = 5;
	vector<vector<int>> vv;
	vv.resize(numRows);
	for (int i = 0; i < numRows; i++)
	{
		vv[i].resize(i + 1);
	}
	for (int i = 0; i < numRows; i++)
	{
		vv[i][0] = vv[i][i] = 1;
	}
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (vv[i][j] == 0)
				vv[i][j] = vv[i - 1][j - 1] + vv[i - 1][j];
		}
	}
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < i + 1; j++)
		{
			cout << vv[i][j] << " ";
		}
		cout << endl;
	}
}



void test_vector5()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	v.push_back(7);
	v.push_back(8);

	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	v.pop_back();
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;

	// v.clear();
	cout << v.size() << endl;

	// v.empty();
	// cout << v.size() << endl;

	v.erase(v.begin() + 1);
	for (int i = 0; i < v.size(); i++)
	{
		cout << v[i] << " ";
	}
	cout << endl;
}




//int main()
//{
//	std::vector<int> myvector;
//	int sum(0);
//
//	for (int i = 1; i <= 10; i++) myvector.push_back(i);
//
//	while (!myvector.empty())
//	{
//		sum += myvector.back();
//		myvector.pop_back();
//	}
//
//	std::cout << "total: " << sum << '\n';
//
//	return 0;
//}


//int main()
//{
//	test_vector1();
//	test_vector2();
//	test_vector3();
//	test_vector4();
//	test_vector5();
//	return 0;
//}
