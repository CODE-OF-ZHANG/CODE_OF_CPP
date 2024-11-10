#pragma once
#include<iostream>
using namespace std;

// 红黑树颜色枚举
enum Colour
{
	RED,  // 红色结点
	BLACK  // 黑色结点
};

// 红黑树结点类
template<class K, class V>
struct RBTreeNode
{
	// 左子树结点
	RBTreeNode<K, V>* _left;
	// 右子树结点
	RBTreeNode<K, V>* _right;
	// 当前结点的父结点
	RBTreeNode<K, V>* _parent;
	// 代表当前结点的颜色
	Colour _col;
	// key value 模型
	pair<K, V> _kv;

	// 红黑树结点类构造函数
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
		,_kv(kv)
	{}
};

// 红黑树类
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	// 红黑树插入操作
	bool insert(const pair<K, V>& kv)
	{
		// 如果为空树
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		// 不为空树
		Node* cur = _root;
		Node* parent = nullptr;

		while (cur)
		{
			// 要插入的值比树里面结点的值大
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			// 要插入的值比树里面结点的值小
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			// 要插入的值和树里面结点的值相等
			else
			{
				return false;
			}
			cur = new Node(kv);
			cur->_col = RED;
			// 判断当前结点是要插在父结点的右子树还是父结点的左子树
			if (parent->_kv.first > kv.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			// 更改 cur 的 _parent 的指向
			cur->_parent = parent;
			// 如果新插入的结点的父亲存在且父亲的颜色为红色则需要处理
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				// 父亲是祖父的左子树
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					// 1. 叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						// 变色 --> 父亲和叔叔的颜色变为黑色，祖父的颜色变为红色
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// 继续向上处理
						cur = grandfather;
						parent = cur->_parent;
					}
					// 2. 叔叔不存在 或者 存在且为黑
					else
					{
						if (cur == parent->_left)
						{
							RotateR(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							RotateL(parent);
							RotateR(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
				else
				{
					Node* uncle = grandfather->_left;
					// 1. 叔叔存在且为红
					if (uncle && uncle->_col == RED)
					{
						// 变色 --> 父亲和叔叔的颜色变为黑色，祖父的颜色变为红色
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// 继续向上处理
						cur = grandfather;
						parent = cur->_parent;
					}
					// 2. 叔叔不存在 或者 存在且为黑
					else
					{
						if (cur == parent->_right)
						{
							RotateL(grandfather);
							parent->_col = BLACK;
							grandfather->_col = RED;
						}
						else
						{
							RotateR(parent);
							RotateL(grandfather);
							cur->_col = BLACK;
							grandfather->_col = RED;
						}
						break;
					}
				}
			}
		}
		_root->_col = BLACK;
		return true;
	}

	// 红黑树左旋操作
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		// 核心操作
		parent->_right = curleft;
		// 如果curleft不为空，更改curleft的_parent的指向
		if (curleft)
			curleft->_parent = parent;
		cur->_left = parent;
		// 记录原本parent的父结点 --> 旋转前parent不等于根结点的情况
		Node* ppnode = parent->_parent;
		// 更改parent的_parent的指向
		parent->_parent = cur;

		if (parent == _root)
		{
			// 旋转之前parent就是根结点的情况
			_root = cur;
			cur->_parent = nullptr;
		}
		// 旋转之前parent是一棵树的子树
		else
		{
			// parent是ppnode的左子树
			if (ppnode->_left == parent)
				ppnode->_left = cur;
			// parent是ppnode的右子树
			else
				ppnode->_right = cur;

			cur->_parent = ppnode;
		}
	}

	// 红黑树右旋操作
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		// 核心操作
		parent->_left = curright;
		// 判断 curright 是否为空
		if (curright)
			curright->_parent = parent;
		// 记录原本parent的父结点 --> 旋转前parent不等于根结点的情况
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
			// parent是ppnode的左子树
			if (ppnode->_left == parent)
				ppnode->_left = cur;
			// parent是ppnode的右子树
			else
				ppnode->_right = cur;
			cur->_parent = ppnode;
		}
	}

private:
	// 根结点
	Node* _root = nullptr;
};




