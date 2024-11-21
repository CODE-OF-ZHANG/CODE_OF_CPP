//#pragma once
//#include<iostream>
//using namespace std;
//
//// �������ɫö��
//enum Colour
//{
//	RED,  // ��ɫ���
//	BLACK  // ��ɫ���
//};
//
//// ����������
//template<class T>
//struct RBTreeNode
//{
//	// ���������
//	RBTreeNode<T>* _left;
//	// ���������
//	RBTreeNode<T>* _right;
//	// ��ǰ���ĸ����
//	RBTreeNode<T>* _parent;
//	// ����ǰ������ɫ
//	Colour _col;
//	// key value ģ��
//	T _data;
//
//	// ���������๹�캯��
//	RBTreeNode(const T& data)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _col(RED)
//		, _data(data)
//	{}
//};
//
//// �����������
//template<class T>
//struct __RBTreeIterator
//{
//	typedef RBTreeNode<T> Node;
//	typedef __RBTreeIterator<T> Self;
//	Node* _node;
//
//	__RBTreeIterator(Node* node)
//		:_node(node)
//	{}
//
//	// ���������
//	T& operator*()
//	{
//		return _node->_data;
//	}
//
//	T* operator->()
//	{
//		return &_node->_data;
//	}
//
//	Self& operator++()
//	{
//		if (_node->_right)
//		{
//			Node* subLeft = _node->_right;
//			while (subLeft->_left)
//				subLeft = subLeft->_left;
//			_node = subLeft;
//		}
//		else
//		{
//			Node* cur = _node;
//			Node* parent = cur->_parent;
//			// ���Һ����Ǹ�������Ǹ����Ƚ�㣬������һ��Ҫ���ʵĽ��
//			while (parent)
//			{
//				if (cur == parent->_left)
//					break;
//				else
//				{
//					cur = cur->_parent;
//					parent = parent->_parent;
//				}
//			}
//			_node = parent;
//		}
//		return *this;
//	}
//
//	bool operator!=(const Self& s)
//	{
//		return _node != s._node;
//	}
//};
//
//// �������
//template<class K, class T, class KeyOfT>
//class RBTree
//{
//	typedef RBTreeNode<T> Node;
//public:
//	// �����������
//	typedef __RBTreeIterator<T> iterator;
//
//	iterator begin()
//	{
//		Node* leftMin = _root;
//		while (leftMin && leftMin->_left)
//		{
//			leftMin = leftMin->_left;
//		}
//		return iterator(leftMin);
//	}
//
//	iterator end()
//	{
//		return iterator(nullptr);
//	}
//
//	// ��������Ҳ���
//	Node* find(const K& data)
//	{
//		// �º���
//		KeyOfT kot;
//		Node* cur = _root;
//		while (cur)
//		{
//			if (kot(cur->_data) < data)
//				cur = cur->_right;
//			else if (kot(cur->_data) > data)
//				cur = cur->_left;
//			else
//				return cur;
//		}
//		return nullptr;
//	}
//	
//	// ������������
//	bool insert(const T& data)
//	{
//		// ���Ϊ����
//		if (_root == nullptr)
//		{
//			_root = new Node(data);
//			_root->_col = BLACK;
//			return true;
//		}
//		// ��Ϊ����
//		Node* cur = _root;
//		Node* parent = nullptr;
//
//		KeyOfT kot;
//		while (cur)
//		{
//			// Ҫ�����ֵ�����������ֵ��
//			if (kot(cur->_data) < kot(data))
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			// Ҫ�����ֵ�����������ֵС
//			else if (kot(cur->_data) > kot(data))
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			// Ҫ�����ֵ�����������ֵ���
//			else
//				return false;
//
//			cur = new Node(data);
//			cur->_col = RED;
//			// �жϵ�ǰ�����Ҫ���ڸ��������������Ǹ�����������
//			if (kot(parent->_data) > kot(data))
//				parent->_left = cur;
//			else
//				parent->_right = cur;
//			// ���� cur �� _parent ��ָ��
//			cur->_parent = parent;
//			// ����²���Ľ��ĸ��״����Ҹ��׵���ɫΪ��ɫ����Ҫ����
//			while (parent && parent->_col == RED)
//			{
//				Node* grandfather = parent->_parent;
//				// �������游��������
//				if (parent == grandfather->_left)
//				{
//					Node* uncle = grandfather->_right;
//					// 1. ���������Ϊ��
//					if (uncle && uncle->_col == RED)
//					{
//						// ��ɫ --> ���׺��������ɫ��Ϊ��ɫ���游����ɫ��Ϊ��ɫ
//						parent->_col = uncle->_col = BLACK;
//						grandfather->_col = RED;
//						// �������ϴ���
//						cur = grandfather;
//						parent = cur->_parent;
//					}
//					// 2. ���岻���� ���� ������Ϊ��
//					else
//					{
//						if (cur == parent->_left)
//						{
//							RotateR(grandfather);
//							parent->_col = BLACK;
//							grandfather->_col = RED;
//						}
//						else
//						{
//							RotateL(parent);
//							RotateR(grandfather);
//							cur->_col = BLACK;
//							grandfather->_col = RED;
//						}
//						break;
//					}
//				}
//				else
//				{
//					Node* uncle = grandfather->_left;
//					// 1. ���������Ϊ��
//					if (uncle && uncle->_col == RED)
//					{
//						// ��ɫ --> ���׺��������ɫ��Ϊ��ɫ���游����ɫ��Ϊ��ɫ
//						parent->_col = uncle->_col = BLACK;
//						grandfather->_col = RED;
//						// �������ϴ���
//						cur = grandfather;
//						parent = cur->_parent;
//					}
//					// 2. ���岻���� ���� ������Ϊ��
//					else
//					{
//						if (cur == parent->_right)
//						{
//							RotateL(grandfather);
//							parent->_col = BLACK;
//							grandfather->_col = RED;
//						}
//						else
//						{
//							RotateR(parent);
//							RotateL(grandfather);
//							cur->_col = BLACK;
//							grandfather->_col = RED;
//						}
//						break;
//					}
//				}
//			}
//		}
//		_root->_col = BLACK;
//		return true;
//	}
//
//	// �������������
//	void RotateL(Node* parent)
//	{
//
//		Node* cur = parent->_right;
//		Node* curleft = cur->_left;
//		// ���Ĳ���
//		parent->_right = curleft;
//		// ���curleft��Ϊ�գ�����curleft��_parent��ָ��
//		if (curleft)
//			curleft->_parent = parent;
//		cur->_left = parent;
//		// ��¼ԭ��parent�ĸ���� --> ��תǰparent�����ڸ��������
//		Node* ppnode = parent->_parent;
//		// ����parent��_parent��ָ��
//		parent->_parent = cur;
//
//		if (parent == _root)
//		{
//			// ��ת֮ǰparent���Ǹ��������
//			_root = cur;
//			cur->_parent = nullptr;
//		}
//		// ��ת֮ǰparent��һ����������
//		else
//		{
//			// parent��ppnode��������
//			if (ppnode->_left == parent)
//				ppnode->_left = cur;
//			// parent��ppnode��������
//			else
//				ppnode->_right = cur;
//
//			cur->_parent = ppnode;
//		}
//	}
//
//	// �������������
//	void RotateR(Node* parent)
//	{
//		Node* cur = parent->_left;
//		Node* curright = cur->_right;
//		// ���Ĳ���
//		parent->_left = curright;
//		// �ж� curright �Ƿ�Ϊ��
//		if (curright)
//			curright->_parent = parent;
//		// ��¼ԭ��parent�ĸ���� --> ��תǰparent�����ڸ��������
//		Node* ppnode = parent->_parent;
//		cur->_right = parent;
//		parent->_parent = cur;
//
//		if (ppnode == nullptr)
//		{
//			_root = cur;
//			cur->_parent = nullptr;
//		}
//		else
//		{
//			// parent��ppnode��������
//			if (ppnode->_left == parent)
//				ppnode->_left = cur;
//			// parent��ppnode��������
//			else
//				ppnode->_right = cur;
//			cur->_parent = ppnode;
//		}
//	}
//
//private:
//	// �����
//	Node* _root = nullptr;
//};



#pragma once
#include<iostream>
using namespace std;

enum Colour
{
	RED,
	BLACK
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;

	T _data;
	Colour _col;

	RBTreeNode(const T& data)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _data(data)
		, _col(RED)
	{}
};

template<class T>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T> Self;
	Node* _node;

	__TreeIterator(Node* node)
		:_node(node)
	{}

	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}

	bool operator!=(const Self& s)
	{
		return _node != s._node;
	}

	Self& operator--();

	Self& operator++()
	{
		if (_node->_right)
		{
			// ����������ڵ�(��С�ڵ�)
			Node* subLeft = _node->_right;
			while (subLeft->_left)
			{
				subLeft = subLeft->_left;
			}

			_node = subLeft;
		}
		else
		{
			Node* cur = _node;
			Node* parent = cur->_parent;
			// �Һ����Ǹ�������Ǹ����Ƚڵ㣬������һ��Ҫ���ʵĽڵ�
			while (parent)
			{
				if (cur == parent->_left)
				{
					break;
				}
				else
				{
					cur = cur->_parent;
					parent = parent->_parent;
				}
			}

			_node = parent;
		}

		return *this;
	}
};

// set->RBTree<K, K, SetKeyOfT> _t;
// map->RBTree<K, pair<K, V>, MapKeyOfT> _t;

template<class K, class T, class KeyOfT>
struct RBTree
{
	typedef RBTreeNode<T> Node;
public:
	typedef __TreeIterator<T> iterator;
	// const_iterator

	iterator begin()
	{
		Node* leftMin = _root;
		while (leftMin && leftMin->_left)
		{
			leftMin = leftMin->_left;
		}

		return iterator(leftMin);
	}

	iterator end()
	{
		return iterator(nullptr);
	}


	Node* find(const K& key)
	{
		Node* cur = _root;
		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < key)
			{
				cur = cur->_right;
			}
			else if (kot(cur->_data) > key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}

		return nullptr;
	}

	bool insert(const T& data)
	{
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_col = BLACK;
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;

		KeyOfT kot;
		while (cur)
		{
			if (kot(cur->_data) < kot(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kot(cur->_data) > kot(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(data);
		cur->_col = RED;

		if (kot(parent->_data) < kot(data))
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}

		cur->_parent = parent;

		while (parent && parent->_col == RED)
		{
			Node* grandfather = parent->_parent;
			if (parent == grandfather->_left)
			{
				Node* uncle = grandfather->_right;
				// u������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else // u������ �� ������Ϊ��
				{
					if (cur == parent->_left)
					{
						//     g
						//   p
						// c
						RotateR(grandfather);
						parent->_col = BLACK;
						grandfather->_col = RED;
					}
					else
					{
						//     g
						//   p
						//		c
						RotateL(parent);
						RotateR(grandfather);

						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
			else // parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				// u������Ϊ��
				if (uncle && uncle->_col == RED)
				{
					// ��ɫ
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// �������ϴ���
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						// g
						//	  p
						//       c
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						// g
						//	  p
						// c
						RotateR(parent);
						RotateL(grandfather);
						cur->_col = BLACK;
						grandfather->_col = RED;
					}

					break;
				}
			}
		}

		_root->_col = BLACK;

		return true;
	}

	void RotateL(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_right;
		Node* curleft = cur->_left;

		parent->_right = curleft;
		if (curleft)
		{
			curleft->_parent = parent;
		}

		cur->_left = parent;

		Node* ppnode = parent->_parent;

		parent->_parent = cur;


		if (parent == _root)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;

			}

			cur->_parent = ppnode;
		}
	}


	void RotateR(Node* parent)
	{
		++_rotateCount;

		Node* cur = parent->_left;
		Node* curright = cur->_right;

		parent->_left = curright;
		if (curright)
			curright->_parent = parent;

		Node* ppnode = parent->_parent;
		cur->_right = parent;
		parent->_parent = cur;

		if (ppnode == nullptr)
		{
			_root = cur;
			cur->_parent = nullptr;
		}
		else
		{
			if (ppnode->_left == parent)
			{
				ppnode->_left = cur;
			}
			else
			{
				ppnode->_right = cur;
			}

			cur->_parent = ppnode;
		}
	}

	// 17:20����
	bool CheckColour(Node* root, int blacknum, int benchmark)
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
				return false;

			return true;
		}

		if (root->_col == BLACK)
		{
			++blacknum;
		}

		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "����������ɫ�ڵ�" << endl;
			return false;
		}

		return CheckColour(root->_left, blacknum, benchmark)
			&& CheckColour(root->_right, blacknum, benchmark);
	}

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		if (root->_col != BLACK)
		{
			return false;
		}

		// ��׼ֵ
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
				++benchmark;

			cur = cur->_left;
		}

		return CheckColour(root, 0, benchmark);
	}

	int Height()
	{
		return Height(_root);
	}

	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;

		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

private:
	Node* _root = nullptr;

public:
	int _rotateCount = 0;
};