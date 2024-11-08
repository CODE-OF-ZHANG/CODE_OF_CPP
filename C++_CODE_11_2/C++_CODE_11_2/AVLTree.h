#pragma once
#include<iostream>
#include<assert.h>
using namespace std;

// ����ƽ�������������
template<class K, class V>
struct AVLTreeNode
{
	// key��valueģ��
	pair<K, V> _kv;
	// ���������
	AVLTreeNode<K, V>* _left;
	// ���������
	AVLTreeNode<K, V>* _right;
	// �����
	AVLTreeNode<K, V>* _parent;
	// ƽ������
	int _bf;
	// ����ƽ������������๹�캯��
	AVLTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		,_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_bf(0)
	{}
};

// ����ƽ����������  -->  AVL��
template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	// ����ƽ������������
	bool insert(const pair<K, V>& kv)
	{
		// �����������
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		// �ǿ����������
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			// Ҫ�����ֵ�����������ֵ��
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			// Ҫ�����ֵ�����������ֵС
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			// Ҫ�����ֵ�����������ֵ���
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		// �жϵ�ǰ�����Ҫ���ڸ��������������Ǹ�����������
		if (parent->_kv.first < kv.first)
			parent->_right = cur;
		else
			parent->_left = cur;
		// ����parent
		cur->_parent = parent;
		// ����ƽ������
		while (parent)
		{
			// ���뵽��������ߣ�ƽ������Ҫ��һ
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;
			// ƽ�����ӵ����㣬˵�������ĸ߶�δ�仯������Ҫ����
			if (parent->_bf == 0)
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				// �������ϸ���
				cur = parent;
				parent = parent->_parent;
			}
			// �������
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				// ������ƽ���ˣ���Ҫ��ת
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

	// ����ƽ����������������
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		// ���Ĳ���
		parent->_right = curleft;
		// ���curleft��Ϊ�գ�����curleft��_parent��ָ��
		if(curleft)
			curleft->_parent = parent;
		cur->_left = parent;
		// ��¼ԭ��parent�ĸ���� --> ��תǰparent�����ڸ��������
		Node* ppnode = parent->_parent;
		// ����parent��_parent��ָ��
		parent->_parent = cur;
		
		if (parent == _root)
		{
			// ��ת֮ǰparent���Ǹ��������
			_root = cur;
			cur->_parent = nullptr;
		}
		// ��ת֮ǰparent��һ����������
		else
		{
			// parent��ppnode��������
			if (ppnode->_left == parent)
				ppnode->_left = cur;
			// parent��ppnode��������
			else
				ppnode->_right = cur;
			
			cur->_parent = ppnode;
		}
		// ����ƽ������
		parent->_bf = cur->_bf = 0;
	}

	// ����ƽ����������������
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		// ���Ĳ���
		parent->_left = curright;
		// �ж� curright �Ƿ�Ϊ��
		if (curright)
			curright->_parent = parent;
		// ��¼ԭ��parent�ĸ���� --> ��תǰparent�����ڸ��������
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
			// parent��ppnode��������
			if (ppnode->_left == parent)
				ppnode->_left = cur;
			// parent��ppnode��������
			else
				ppnode->_right = cur;
			cur->_parent = ppnode;
		}
		// ����ƽ������
		parent->_bf = cur->_bf = 0;
	}

	// ����ƽ��������˫������
	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;
		RotateR(parent->_right);
		RotateL(parent);

		// ����ƽ������
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

	// ����ƽ��������˫������
	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		// ����ƽ������
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

	// �������
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
			cout << "ƽ�������쳣:" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}

		return abs(rightHight - leftHight) < 2
			&& IsBalance(root->_left)
			&& IsBalance(root->_right);
	}

private:
	// �����
	Node* _root = nullptr;
};

