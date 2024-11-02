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
//		cout << "��myset����" << endl;
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

	//// ɾ��Ԫ��
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
	pair<string, string> kv("sort", "����");
	dict.insert(kv);
	dict.insert(pair<string, string>("insert", "����"));
	dict.insert(make_pair("string", "�ַ���"));

	// C++11֧�ֵĶ������ʽ����ת��
	dict.insert({ "test", "����" });


	// ��Χfor����Ԫ��
	//for (auto& d : dict)
	//{
	//	cout << d.first << " " << d.second << " ";
	//}
	//cout << endl;


	// ����������Ԫ��  *�Ž�����
	// map<string, string>::iterator it = dict.begin();
	//
	//while (it != dict.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}
	//cout << endl;


	// ����������Ԫ��  ->����
	//map<string, string>::iterator it = dict.begin();

	//while (it != dict.end())
	//{
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;


	// mapԪ���޸�
	//map<string, string>::iterator it = dict.begin();
	//while (it != dict.end())
	//{
	//	// it->first = "xxxx";  // key��֧���޸�
	//	it->second = "xxxx";  // value֧���޸�
	//	cout << it->first << ":" << it->second << endl;
	//	++it;
	//}
	//cout << endl;

	 // ����key��ͬ����value��ͬ��Ԫ��
	dict.insert(make_pair("insert", "charu"));

	for (const auto& d : dict)
	{
		// ����ʧ�ܣ�˵��map���벻�ǰ�value�Ƚϵ�
		cout << d.first << ":" << d.second << endl;
	}
	cout << endl;

	// ����value��ͬ����key��ͬ��Ԫ��
	dict.insert(make_pair("insert1", "����"));

	for (const auto& d : dict)
	{
		// ����ɹ���˵��map�����ǰ�key�Ƚϵ�
		cout << d.first << ":" << d.second << endl;
	}
	cout << endl;
}

void test_map2()
{
	map<string, string> dict;
	// ����
	pair<string, string> kv("insert", "����");
	dict.insert(kv);
	// �����������
	dict.insert(pair<string, string>("first", "��һ"));
	// make_pair����
	dict.insert(make_pair("sort", "����"));
	// ���������ʽ����ת�� --> C++11֧��
	dict.insert({ "second", "�ڶ�" });
	// ����������
	map<string, string>::iterator it = dict.begin();
	//while (it != dict.end())
	//{
	//	cout << (*it).first << ":" << (*it).second << endl;
	//	++it;
	//}

	// ->����
	while (it != dict.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
	dict["map"];  // ����
	dict["map"] = "��ͼ";  // ���� + �޸�
	cout << dict["map"] << endl;  // ���� + ��
	dict["set"] = "����";  // ���� + �޸�
	cout << endl;
	// ��Χfor����
	for (const auto& d : dict)
	{
		cout << d.first << ":" << d.second << endl;
	}

}

// class Solution {
// public:
//     // �º���
//     struct Greater
//     {
//         bool operator()(const pair<string, int>& kv1, const pair<string, int>& kv2)
//         {
//             return kv1.second > kv2.second || (kv1.second == kv2.second && kv1.first < kv2.first);
//         }
//     };

//     vector<string> topKFrequent(vector<string>& words, int k) {
//         // 1. ���� + ���ֵ����������
//         map<string, int> countMap;
//         for(const auto& e : words)
//         {
//             countMap[e]++;
//         }
//         // ������Ƶ�ʽ�������
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
//     // �º���
//     struct Greater
//     {
//         bool operator()(const pair<string, int> &kv1, const pair<string, int> &kv2)
//         {
//             return kv1.second > kv2.second;
//         }
//     };

//     vector<string> topKFrequent(vector<string> &words, int k)
//     {
//         // 1. ���� + ���ֵ����������
//         map<string, int> countMap;
//         for (const auto &e : words)
//         {
//             countMap[e]++;
//         }
//         // ������Ƶ�ʽ�������
//         vector<pair<string, int>> kvVector(countMap.begin(), countMap.end());
//         // ʹ���ȶ�������
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
		// 1. ���� + ���ֵ����������
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