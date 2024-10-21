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


// 简易版搜索二叉树实现    递归版
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	// 构造函数
	BSTree()
		:_root(nullptr)
	{}

	// 搜索二叉树拷贝构造
	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}

	// 搜索二叉树赋值
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	// 析构函数
	~BSTree()
	{
		Destroy(_root);
	}

	// 搜索二叉树的插入
	bool insert(const K& key)
	{
		return _insert(_root, key);
	}

	// 搜索二叉树的查找
	bool find(const K& key)
	{
		return _find(_root, key);
	}

	// 搜索二叉树的删除
	bool erase(const K& key)
	{
		return _erase(_root, key);
	}

	// 搜索二叉树中序打印
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	// 拷贝构造子函数
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* copyroot = new Node(root->_key);
		copyroot->_left = Copy(root->_left);
		copyroot->_right = Copy(root->_right);

		return copyroot;
	}

	// 搜索二叉树析构子函数
	void Destroy(Node*& root)
	{
		if (root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}

	// 搜索二叉树删除子函数
	bool _erase(Node*& root, const K& key)
	{
		// 搜索二叉树为空树
		if (root == nullptr)
			return false;

		if (root->_key < key)
		{
			return _erase(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _erase(root->_left, key);
		}
		else
		{
			Node* del = root;
			// 搜索二叉树的左子树为空
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			// 搜索二叉树的右子树为空
			else if (root->_right == nullptr)
			{
				root = root->_right;
			}
			// 左右子树都不为空
			else
			{
				Node* leftMax = root->_left;
				// 找替换值
				while (leftMax->_right)
				{
					leftMax = leftMax->_right;
				}
				// 交换替换值
				swap(root->_key, leftMax->_key);
				return _erase(root->_left, key);
			}
			delete del;
			return true;
		}
	}

	// 搜索二叉树插入子函数
	bool _insert(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			// 插入值
			root = new Node(key);
			return true;
		}

		if (root->_key < key)
		{
			return _insert(root->_right, key);
		}
		else if (root->_key > key)
		{
			return _insert(root->_left, key);
		}
		else
		{
			// 找到了相等的值，不能插入
			return false;
		}
	}

	// 搜索二叉树中序打印子函数
	void _InOrder(Node* root)
	{
		if (root == nullptr)  return;
		// 先打印左子树
		_InOrder(root->_left);
		cout << root->_key << " ";
		// 打印右子树
		_InOrder(root->_right);
	}

	// 搜索二叉树查找子函数
	bool _find(Node* root, const K& key)
	{
		// 空树
		if (root == nullptr)  return false;
		// 要找的值大于当前结点的值
		if (root->_key < key)
			return _find(root->_right, key);
		// 要找的值小于当前结点的值
		else if (root->_key > key)
			return _find(root->_left, key);
		else
			return true;
		// 没有找到
		return false;
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

	for (auto e : a)
	{
		t.erase(e);
		t.InOrder();
	}
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
	t.InOrder();
}



// 搜索二叉树测试
void TestBSTree3()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}
	t.InOrder();

	BSTree<int> bs;
	bs = t;
	bs.InOrder();
}

