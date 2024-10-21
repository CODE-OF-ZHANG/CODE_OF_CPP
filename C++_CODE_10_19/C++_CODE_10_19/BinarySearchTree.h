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

// ���װ�����������    �ǵݹ�ʵ��
template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	// ���캯��
	BSTree()
		:_root(nullptr)
	{}

	// ����
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
			// Ҫ�����ֵ���ڵ�ǰ����ֵ
			if (cur->_key < key)
			{
				parent = cur;
				cur = cur->_right;
			}
			// Ҫ�����ֵС�ڵ�ǰ�ڵ��ֵ
			else if (cur->_key > key) 
			{
				parent = cur;
				cur = cur->_left;
			}
			else 
				return false;
		}

		cur = new Node(key);
		// ���벢��������
		if (parent->_key < key)
			parent->_right = cur;
		else
			parent->_left = cur;
		return true;
	}

	// ��������������
	bool find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			// key �� cur �� _key ����������
			if (cur->_key < key)  cur = cur->_right;
			// key �� cur �� _key С����������
			else if (cur->_key > key)  cur = cur->_left;
			// ��ȣ��ҵ���
			else return true;
		}
		// û���ҵ�
		return false;
	}

	// ������������ɾ��
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		
		// ���ҵ�Ҫɾ���Ľ��
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
				// ��ǰ����������Ϊ��
				if (cur->_left == nullptr)
				{
					// Ҫɾ���Ľ����� _root ���
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						if (parent->_right == cur)  // ��ǰ���Ϊ������������
							parent->_right = cur->_right;
						else
							parent->_left = cur->_right;
					}
				}
				// ��ǰ����������Ϊ��
				else if (cur->_right == nullptr)
				{
					// Ҫɾ���Ľ����� _root ���
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						if (parent->_right == cur)  // ��ǰ���Ϊ������������
							parent->_right = cur->_left;
						else
							parent->_left = cur->_left;
					}
				}
				// ��ǰ����������������Ϊ��
				else
				{
					Node* parent = cur;
					// ���������㣬�����������ڵ�Ϊ��
					Node* leftMax = cur->_left;
					while (leftMax->_right)
					{
						parent = leftMax;
						leftMax = leftMax->_right;
					}
					// �����滻
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
		return false;  // û���ҵ�
	}

	// �����ӡ
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

private:
	// �����ӡ�Ӻ���
	void _InOrder(Node* root)
	{
		if (root == NULL)  return;
		// ������
		_InOrder(root->_left);
		cout << root->_key << " ";
		// ������
		_InOrder(root->_right);
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
	cout << endl;
	cout << t.find(1) << endl;

	// ɾ��Ԫ��
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




// ��������������
void TestBSTree2()
{
	int a[] = { 8,3,1,10,6,4,7,14,13 };
	BSTree<int> t;
	for (auto e : a)
	{
		t.insert(e);
	}

	// ɾ��Ԫ��
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