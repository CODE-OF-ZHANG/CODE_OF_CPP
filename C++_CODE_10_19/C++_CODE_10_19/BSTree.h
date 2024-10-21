#pragma once
#include<iostream>
#include<algorithm>
using namespace std;

// ������������㶨��
template<class K>
struct BSTreeNode
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	// ���캯��
	BSTreeNode(const K& key)
		:_left(nullptr)
		,_right(nullptr)
		,_key(key)
	{}
};


// ���װ�����������ʵ��    �ݹ��
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	// ���캯��
	BSTree()
		:_root(nullptr)
	{}

	// ������������������
	BSTree(const BSTree<K>& t)
	{
		_root = Copy(t._root);
	}

	// ������������ֵ
	BSTree<K>& operator=(BSTree<K> t)
	{
		swap(_root, t._root);
		return *this;
	}

	// ��������
	~BSTree()
	{
		Destroy(_root);
	}

	// �����������Ĳ���
	bool insert(const K& key)
	{
		return _insert(_root, key);
	}

	// �����������Ĳ���
	bool find(const K& key)
	{
		return _find(_root, key);
	}

	// ������������ɾ��
	bool erase(const K& key)
	{
		return _erase(_root, key);
	}

	// ���������������ӡ
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	// ���������Ӻ���
	Node* Copy(Node* root)
	{
		if (root == nullptr)
			return nullptr;
		Node* copyroot = new Node(root->_key);
		copyroot->_left = Copy(root->_left);
		copyroot->_right = Copy(root->_right);

		return copyroot;
	}

	// ���������������Ӻ���
	void Destroy(Node*& root)
	{
		if (root == nullptr)
			return;
		Destroy(root->_left);
		Destroy(root->_right);
		delete root;
		root = nullptr;
	}

	// ����������ɾ���Ӻ���
	bool _erase(Node*& root, const K& key)
	{
		// ����������Ϊ����
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
			// ������������������Ϊ��
			if (root->_left == nullptr)
			{
				root = root->_right;
			}
			// ������������������Ϊ��
			else if (root->_right == nullptr)
			{
				root = root->_right;
			}
			// ������������Ϊ��
			else
			{
				Node* leftMax = root->_left;
				// ���滻ֵ
				while (leftMax->_right)
				{
					leftMax = leftMax->_right;
				}
				// �����滻ֵ
				swap(root->_key, leftMax->_key);
				return _erase(root->_left, key);
			}
			delete del;
			return true;
		}
	}

	// ���������������Ӻ���
	bool _insert(Node*& root, const K& key)
	{
		if (root == nullptr)
		{
			// ����ֵ
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
			// �ҵ�����ȵ�ֵ�����ܲ���
			return false;
		}
	}

	// ���������������ӡ�Ӻ���
	void _InOrder(Node* root)
	{
		if (root == nullptr)  return;
		// �ȴ�ӡ������
		_InOrder(root->_left);
		cout << root->_key << " ";
		// ��ӡ������
		_InOrder(root->_right);
	}

	// ���������������Ӻ���
	bool _find(Node* root, const K& key)
	{
		// ����
		if (root == nullptr)  return false;
		// Ҫ�ҵ�ֵ���ڵ�ǰ����ֵ
		if (root->_key < key)
			return _find(root->_right, key);
		// Ҫ�ҵ�ֵС�ڵ�ǰ����ֵ
		else if (root->_key > key)
			return _find(root->_left, key);
		else
			return true;
		// û���ҵ�
		return false;
	}

	Node* _root;
};



// ��������������
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


// ��������������
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



// ��������������
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

