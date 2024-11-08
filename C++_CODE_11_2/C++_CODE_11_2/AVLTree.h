#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

// 二叉平衡搜索树结点类
template<class K, class V>
struct AVLTreeNode
{
	// key、value模型
	pair<K, V> _kv;
	// 左子树结点
	AVLTreeNode<K, V>* _left;
	// 右子树结点
	AVLTreeNode<K, V>* _right;
	// 父结点
	AVLTreeNode<K, V>* _parent;
	// 平衡因子
	int _bf;
	// 二叉平衡搜索树结点类构造函数
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

// 二叉平衡搜索树类  -->  AVL树
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	// 二叉平衡搜索树插入
	bool insert(const pair<K, V>& kv)
	{
		// 空树情况处理
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		// 非空树情况处理
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
		}
		cur = new Node(kv);
		// 判断当前结点是要插在父结点的右子树还是父结点的左子树
		if (parent->_kv.first < kv.first)
			parent->_right = cur;
		else
			parent->_left = cur;
		// 处理parent
		cur->_parent = parent;
		// 更新平衡因子
		while (parent)
		{
			// 插入到父结点的左边，平衡因子要减一
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			// 平衡因子等于零，说明子树的高度未变化，不需要更新
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// 继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			// 意外情况
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// 子树不平衡了，需要旋转
				if (parent->_bf == 2 && cur->_bf == 1)
				{
					RotateL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == -1)
				{
					RotateR(parent);
				}
				else if (parent->_bf == 2 && cur->_bf == -1)
				{
					RotateRL(parent);
				}
				else if (parent->_bf == -2 && cur->_bf == 1)
				{
					RotateLR(parent);
				}
				break;
			}
			else
			{
				assert(false);
			}
		}
		return true;
	}

	// 二叉平衡搜索树左旋操作
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		// 核心操作
		parent->_right = curleft;
		// 如果curleft不为空，更改curleft的_parent的指向
		if(curleft)
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
		// 更新平衡因子
		parent->_bf = cur->_bf = 0;
	}

	// 二叉平衡搜索树右旋操作
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
		// 更新平衡因子
		parent->_bf = cur->_bf = 0;
	}

	// 二叉平衡搜索树双旋操作
	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		// 更新平衡因子
		if (bf == 0)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else if (bf == 1)
		{
			cur->_bf = 0;
			curleft->_bf = 0;
			parent->_bf = -1;
		}
		else if (bf == -1)
		{
			cur->_bf = 1;
			curleft->_bf = 0;
			parent->_bf = 0;
		}
		else
		{
			assert(false);
		}
	}

	// 二叉平衡搜索树双旋操作
	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		// 更新平衡因子
		if (bf == 0)
		{
			parent->_bf = 0;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 1;
			cur->_bf = 0;
			curright->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			cur->_bf = -1;
			curright->_bf = 0;
		}
	}

	// 错误调试
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

	bool IsBalance()
	{
		return IsBalance(_root);
	}

	bool IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;

		int leftHight = Height(root->_left);
		int rightHight = Height(root->_right);

		if (rightHight - leftHight != root->_bf)
		{
			cout << "平衡因子异常:" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}

		return abs(rightHight - leftHight) < 2
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}

private:
	// 根结点
	Node* _root = nullptr;
};

