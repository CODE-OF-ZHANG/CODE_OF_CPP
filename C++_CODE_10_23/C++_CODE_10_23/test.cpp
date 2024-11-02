#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<map>
#include<set>
using namespace std;

//void test_set1()
//{
//	set<int> myset;
//	myset.insert(5);
//	myset.insert(7);
//	myset.insert(9);
//	myset.insert(4);
//	myset.insert(3);
//	myset.insert(6);
//	for (auto e : myset)
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//}

//void test_set2()
//{
//	set<string> myset;
//	myset.emplace("foo");
//	myset.emplace("bar");
//	auto ret = myset.emplace("foo");
//	if (!ret.second)
//		cout << "在myset里面" << endl;
//
//}

void test_set3()
{
	set<int> myset;
	myset.insert(10);
	myset.insert(20);
	myset.insert(30);
	myset.insert(40);
	myset.insert(50);
	myset.insert(60);
	myset.insert(70);

	// myset.equal_range(30);
	pair<set<int>::const_iterator, set<int>::const_iterator> ret;
	ret = myset.equal_range(30);
	cout << "the lower bound points to: " << *ret.first << endl;
	cout << "the upper bound points to: " << *ret.second << endl;

	//// 删除元素
	//myset.erase(ret.first, ret.second);

	//for (auto& e : myset)
	//{
	//	cout << e << " ";
	//}
	//cout << endl;



}

void test_map1()
{
	map<string, string> dict;
	pair<string, string> kv("sort", "排序");
	dict.insert(kv);
	dict.insert(pair<string, string>("insert", "插入"));
	dict.insert(make_pair("string", "字符串"));

	// C++11支持的多参数隐式类型转换
	dict.insert({ "test", "测试" });


	// 范围for访问元素
	//for (auto& d : dict)
	//{
	//	cout << d.first << " " << d.second << " ";
	//}
	//cout << endl;


	// 迭代器访问元素  *号解引用
	// map<string, string>::iterator it = dict.begin();
	//
	//while (it != dict.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}
	//cout << endl;


	// 迭代器访问元素  ->访问
	//map<string, string>::iterator it = dict.begin();

	//while (it != dict.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;


	// map元素修改
	//map<string, string>::iterator it = dict.begin();
	//while (it != dict.end())
	//{
	//	// it->first = "xxxx";  // key不支持修改
	//	it->second = "xxxx";  // value支持修改
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;

	 // 插入key相同，但value不同的元素
	dict.insert(make_pair("insert", "charu"));

	for (const auto& d : dict)
	{
		// 插入失败，说明map插入不是按value比较的
		cout << d.first << ":" << d.second << endl;
	}
	cout << endl;

	// 插入value相同，但key不同的元素
	dict.insert(make_pair("insert1", "插入"));

	for (const auto& d : dict)
	{
		// 插入成功，说明map插入是按key比较的
		cout << d.first << ":" << d.second << endl;
	}
	cout << endl;
}

void test_map2()
{
	map<string, string> dict;
	// 插入
	pair<string, string> kv("insert", "插入");
	dict.insert(kv);
	// 匿名对象插入
	dict.insert(pair<string, string>("first", "第一"));
	// make_pair插入
	dict.insert(make_pair("sort", "排序"));
	// 多参数的隐式类型转换 --> C++11支持
	dict.insert({ "second", "第二" });
	// 迭代器遍历
	map<string, string>::iterator it = dict.begin();
	//while (it != dict.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}

	// ->访问
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	dict["map"];  // 插入
	dict["map"] = "地图";  // 查找 + 修改
	cout << dict["map"] << endl;  // 查找 + 读
	dict["set"] = "集合";  // 插入 + 修改
	cout << endl;
	// 范围for访问
	for (const auto& d : dict)
	{
		cout << d.first << ":" << d.second << endl;
	}

}

// class Solution {
// public:
//     // 仿函数
//     struct Greater
//     {
//         bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
//         {
//             return kv1.second > kv2.second || (kv1.second == kv2.second && kv1.first < kv2.first);
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k) {
//         // 1. 遍历 + 按字典序进行排序
//         map<string, int> countMap;
//         for(const auto& e : words)
//         {
//             countMap[e]++;
//         }
//         // 按出现频率进行排序
//         vector<pair<string, int>> kvVector(countMap.begin(), countMap.end());
//         sort(kvVector.begin(), kvVector.end(), Greater());
//         vector<string> ret;
//         for (int i = 0; i < k; ++i)
//         {
//             ret.push_back(kvVector[i].first);
//         }
//         return ret;
//     }
// };

// class Solution
// {
// public:
//     // 仿函数
//     struct Greater
//     {
//         bool operator()(const pair<string, int> &kv1, const pair<string, int> &kv2)
//         {
//             return kv1.second > kv2.second;
//         }
//     };

//     vector<string> topKFrequent(vector<string> &words, int k)
//     {
//         // 1. 遍历 + 按字典序进行排序
//         map<string, int> countMap;
//         for (const auto &e : words)
//         {
//             countMap[e]++;
//         }
//         // 按出现频率进行排序
//         vector<pair<string, int>> kvVector(countMap.begin(), countMap.end());
//         // 使用稳定的排序
//         stable_sort(kvVector.begin(), kvVector.end(), Greater());
//         vector<string> ret;
//         for (int i = 0; i < k; ++i)
//         {
//             ret.push_back(kvVector[i].first);
//         }
//         return ret;
//     }
// };

class Solution
{
public:
	vector<string> topKFrequent(vector<string>& words, int k)
	{
		// 1. 遍历 + 按字典序进行排序
		map<string, int> countMap;
		for (const auto& e : words)
		{
			countMap[e]++;
		}
		multimap<int, string, greater<int>> sortMap;
		for (auto& kv : countMap)
		{
			sortMap.insert(make_pair(kv.second, kv.first));
		}
		vector<string> ret;
		auto it = sortMap.begin();
		while (k--)
		{
			ret.push_back(it->second);
			++it;
		}
		return ret;
	}
};

//int main()
//{
//	// test_set1();
//	// test_set2();
//	// test_set3();
//	// test_map1();
//	test_map2();
//	return 0;
//}


//int main()
//{
//	vector<string> words;
//	// ["i","love","leetcode","i","love","coding"]
//	words.push_back("i");
//	words.push_back("love");
//	words.push_back("leetcode");
//	words.push_back("i");
//	words.push_back("love");
//	words.push_back("coding");
//	Solution s;
//	
//	
//	for (auto& e : s.topKFrequent(words, 2))
//	{
//		cout << e << " ";
//	}
//	cout << endl;
//	return 0;
//}