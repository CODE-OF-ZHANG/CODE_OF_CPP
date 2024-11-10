#pragma once
#include<iostream>
using namespace std;

// �������ɫö��
enum Colour
{
	RED,  // ��ɫ���
	BLACK  // ��ɫ���
};

// ����������
template<class K, class V>
struct RBTreeNode
{
	// ���������
	RBTreeNode<K, V>* _left;
	// ���������
	RBTreeNode<K, V>* _right;
	// ��ǰ���ĸ����
	RBTreeNode<K, V>* _parent;
	// ����ǰ������ɫ
	Colour _col;
	// key value ģ��
	pair<K, V> _kv;

	// ���������๹�캯��
	RBTreeNode(const pair<K, V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_col(RED)
		,_kv(kv)
	{}
};

// �������
template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	// ������������
	bool insert(const pair<K, V>& kv)
	{
		// ���Ϊ����
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		// ��Ϊ����
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
			cur = new Node(kv);
			cur->_col = RED;
			// �жϵ�ǰ�����Ҫ���ڸ��������������Ǹ�����������
			if (parent->_kv.first > kv.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			// ���� cur �� _parent ��ָ��
			cur->_parent = parent;
			// ����²���Ľ��ĸ��״����Ҹ��׵���ɫΪ��ɫ����Ҫ����
			while (parent && parent->_col == RED)
			{
				Node* grandfather = parent->_parent;
				// �������游��������
				if (parent == grandfather->_left)
				{
					Node* uncle = grandfather->_right;
					// 1. ���������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						// ��ɫ --> ���׺��������ɫ��Ϊ��ɫ���游����ɫ��Ϊ��ɫ
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// �������ϴ���
						cur = grandfather;
						parent = cur->_parent;
					}
					// 2. ���岻���� ���� ������Ϊ��
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
					// 1. ���������Ϊ��
					if (uncle && uncle->_col == RED)
					{
						// ��ɫ --> ���׺��������ɫ��Ϊ��ɫ���游����ɫ��Ϊ��ɫ
						parent->_col = uncle->_col = BLACK;
						grandfather->_col = RED;
						// �������ϴ���
						cur = grandfather;
						parent = cur->_parent;
					}
					// 2. ���岻���� ���� ������Ϊ��
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

	// �������������
	void RotateL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		// ���Ĳ���
		parent->_right = curleft;
		// ���curleft��Ϊ�գ�����curleft��_parent��ָ��
		if (curleft)
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
	}

	// �������������
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
	}

private:
	// �����
	Node* _root = nullptr;
};




