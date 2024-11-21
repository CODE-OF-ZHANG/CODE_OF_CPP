//#pragma once
//#include<iostream>
//using namespace std;
//
//// 红黑树颜色枚举
//enum Colour
//{
//	RED,  // 红色结点
//	BLACK  // 黑色结点
//};
//
//// 红黑树结点类
//template<class T>
//struct RBTreeNode
//{
//	// 左子树结点
//	RBTreeNode<T>* _left;
//	// 右子树结点
//	RBTreeNode<T>* _right;
//	// 当前结点的父结点
//	RBTreeNode<T>* _parent;
//	// 代表当前结点的颜色
//	Colour _col;
//	// key value 模型
//	T _data;
//
//	// 红黑树结点类构造函数
//	RBTreeNode(const T& data)
//		:_left(nullptr)
//		, _right(nullptr)
//		, _parent(nullptr)
//		, _col(RED)
//		, _data(data)
//	{}
//};
//
//// 红黑树迭代器
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
//	// 运算符重载
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
//			// 先找孩子是父亲左的那个祖先结点，就是下一个要访问的结点
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
//// 红黑树类
//template<class K, class T, class KeyOfT>
//class RBTree
//{
//	typedef RBTreeNode<T> Node;
//public:
//	// 红黑树迭代器
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
//	// 红黑树查找操作
//	Node* find(const K& data)
//	{
//		// 仿函数
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
//	// 红黑树插入操作
//	bool insert(const T& data)
//	{
//		// 如果为空树
//		if (_root == nullptr)
//		{
//			_root = new Node(data);
//			_root->_col = BLACK;
//			return true;
//		}
//		// 不为空树
//		Node* cur = _root;
//		Node* parent = nullptr;
//
//		KeyOfT kot;
//		while (cur)
//		{
//			// 要插入的值比树里面结点的值大
//			if (kot(cur->_data) < kot(data))
//			{
//				parent = cur;
//				cur = cur->_right;
//			}
//			// 要插入的值比树里面结点的值小
//			else if (kot(cur->_data) > kot(data))
//			{
//				parent = cur;
//				cur = cur->_left;
//			}
//			// 要插入的值和树里面结点的值相等
//			else
//				return false;
//
//			cur = new Node(data);
//			cur->_col = RED;
//			// 判断当前结点是要插在父结点的右子树还是父结点的左子树
//			if (kot(parent->_data) > kot(data))
//				parent->_left = cur;
//			else
//				parent->_right = cur;
//			// 更改 cur 的 _parent 的指向
//			cur->_parent = parent;
//			// 如果新插入的结点的父亲存在且父亲的颜色为红色则需要处理
//			while (parent && parent->_col == RED)
//			{
//				Node* grandfather = parent->_parent;
//				// 父亲是祖父的左子树
//				if (parent == grandfather->_left)
//				{
//					Node* uncle = grandfather->_right;
//					// 1. 叔叔存在且为红
//					if (uncle && uncle->_col == RED)
//					{
//						// 变色 --> 父亲和叔叔的颜色变为黑色，祖父的颜色变为红色
//						parent->_col = uncle->_col = BLACK;
//						grandfather->_col = RED;
//						// 继续向上处理
//						cur = grandfather;
//						parent = cur->_parent;
//					}
//					// 2. 叔叔不存在 或者 存在且为黑
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
//					// 1. 叔叔存在且为红
//					if (uncle && uncle->_col == RED)
//					{
//						// 变色 --> 父亲和叔叔的颜色变为黑色，祖父的颜色变为红色
//						parent->_col = uncle->_col = BLACK;
//						grandfather->_col = RED;
//						// 继续向上处理
//						cur = grandfather;
//						parent = cur->_parent;
//					}
//					// 2. 叔叔不存在 或者 存在且为黑
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
//	// 红黑树左旋操作
//	void RotateL(Node* parent)
//	{
//
//		Node* cur = parent->_right;
//		Node* curleft = cur->_left;
//		// 核心操作
//		parent->_right = curleft;
//		// 如果curleft不为空，更改curleft的_parent的指向
//		if (curleft)
//			curleft->_parent = parent;
//		cur->_left = parent;
//		// 记录原本parent的父结点 --> 旋转前parent不等于根结点的情况
//		Node* ppnode = parent->_parent;
//		// 更改parent的_parent的指向
//		parent->_parent = cur;
//
//		if (parent == _root)
//		{
//			// 旋转之前parent就是根结点的情况
//			_root = cur;
//			cur->_parent = nullptr;
//		}
//		// 旋转之前parent是一棵树的子树
//		else
//		{
//			// parent是ppnode的左子树
//			if (ppnode->_left == parent)
//				ppnode->_left = cur;
//			// parent是ppnode的右子树
//			else
//				ppnode->_right = cur;
//
//			cur->_parent = ppnode;
//		}
//	}
//
//	// 红黑树右旋操作
//	void RotateR(Node* parent)
//	{
//		Node* cur = parent->_left;
//		Node* curright = cur->_right;
//		// 核心操作
//		parent->_left = curright;
//		// 判断 curright 是否为空
//		if (curright)
//			curright->_parent = parent;
//		// 记录原本parent的父结点 --> 旋转前parent不等于根结点的情况
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
//			// parent是ppnode的左子树
//			if (ppnode->_left == parent)
//				ppnode->_left = cur;
//			// parent是ppnode的右子树
//			else
//				ppnode->_right = cur;
//			cur->_parent = ppnode;
//		}
//	}
//
//private:
//	// 根结点
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
			// 右树的最左节点(最小节点)
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
			// 找孩子是父亲左的那个祖先节点，就是下一个要访问的节点
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
				// u存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else // u不存在 或 存在且为黑
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
				// u存在且为红
				if (uncle && uncle->_col == RED)
				{
					// 变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					// 继续向上处理
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

	// 17:20继续
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
			cout << root->_kv.first << "出现连续红色节点" << endl;
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

		// 基准值
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