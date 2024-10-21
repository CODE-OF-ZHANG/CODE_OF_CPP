#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

// 搜索二叉树结点定义
template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	// 构造函数
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};

// 简易版搜索二叉树    非递归实现
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	// 构造函数
	BSTree()
		:_root(nullptr)
	{}

	// 插入
	bool insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			// 要插入的值大于当前结点的值
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			// 要插入的值小于当前节点的值
			else if (cur->_key > key) 
			{
				parent = cur;
				cur = cur->_left;
			}
			else 
				return false;
		}

		cur = new Node(key);
		// 插入并建立链接
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	// 搜索二叉树查找
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			// key 比 cur 的 _key 大，走右子树
			if (cur->_key < key)  cur = cur->_right;
			// key 比 cur 的 _key 小，走左子树
			else if (cur->_key > key)  cur = cur->_left;
			// 相等，找到了
			else return true;
		}
		// 没有找到
		return false;
	}

	// 搜索二叉树的删除
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		
		// 先找到要删除的结点
		while (cur)
		{
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (cur->_key > key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				// 当前结点的左子树为空
				if (cur->_left == nullptr)
				{
					// 要删除的结点就是 _root 结点
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)  // 当前结点为父结点的右子树
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}
				}
				// 当前结点的右子树为空
				else if (cur->_right == nullptr)
				{
					// 要删除的结点就是 _root 结点
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur)  // 当前结点为父结点的右子树
							parent->_right = cur->_left;
						else
							parent->_left = cur->_left;
					}
				}
				// 当前结点的左右子树都不为空
				else
				{
					Node* parent = cur;
					// 先找替代结点，以左子树最大节点为例
					Node* leftMax = cur->_left;
					while (leftMax->_right)
					{
						parent = leftMax;
						leftMax = leftMax->_right;
					}
					// 进行替换
					swap(cur->_key, leftMax->_key);

					if (parent->_left == leftMax)
						parent->_left = leftMax->_left;
					else
						parent->_right = leftMax->_left;

					cur = leftMax;
				}
				delete cur;
				return true;
			}
		}
		return false;  // 没有找到
	}

	// 中序打印
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	// 中序打印子函数
	void _InOrder(Node* root)
	{
		if (root == NULL)  return;
		// 左子树
		_InOrder(root->_left);
		cout << root->_key << " ";
		// 右子树
		_InOrder(root->_right);
	}

	Node* _root;
};



// 搜索二叉树测试
void TestBSTree1()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}

	t.InOrder();
	cout << endl;
	cout << t.find(1) << endl;

	// 删除元素
	t.erase(4);
	t.InOrder();

	t.erase(6);
	t.InOrder();

	t.erase(7);
	t.InOrder();

	t.erase(3);
	t.InOrder();

	for (auto e : a)
	{
		t.erase(e);
	}
	t.InOrder();
}




// 搜索二叉树测试
void TestBSTree2()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}

	// 删除元素
	t.erase(13);
	t.InOrder();

	t.erase(14);
	t.InOrder();

	//t.erase(6);
	//t.InOrder();

	//t.erase(7);
	//t.InOrder();


	//for (auto e : a)
	//{
	//	t.erase(e);
	//	t.InOrder();
	//}
	//t.InOrder();
}