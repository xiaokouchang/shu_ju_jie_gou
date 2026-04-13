#pragma once
//set判断在不在
//map的key_value
//高度平衡二叉搜索树(AVL树/红黑树),通过高度差来控制
//平衡因子:右子树的高度-左子树的高度(-1,0,1)左边高为-1,右边高为1
//增删查改:高度次O(log(N))
//满二叉树:2^h-1=N
//AVL树:2^h-x=N(1<=x<=2^(h-1)-1)-->[1,N/2]
//2^h-1=N-->左右两边除以2,2^(h-1)=(N+1)/2,约等于N/2

//多叉平衡搜索树(B树)
#include<iostream>
#include<assert.h>
using namespace std;
template<class K,class V>
class AVLTreeNode
{
public:
	pair<K, V> _kv;
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf;//平衡因子
	AVLTreeNode<K, V>(const pair<K, V>& kv)
		: _kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _bf(0)
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	AVLTree()
		:_root(nullptr)
	{ }
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* cur = _root;
		Node* parent = nullptr;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first < kv.first)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		cur->_parent = parent;
		//控制平衡因子
		//新增在左,parent的平衡因子--
		//新增在右,parent的平衡因子++
		//更新后,parent的平衡因子==0,parent所在子树的高度不变,不会再影响祖先,插入结束
		//更新后,parent的平衡因子==1/-1,parent所在子树的高度变化,会影响祖先,需要继续沿着root的路径往上更新
		//更新后,parent的平衡因子==2或者-2,说明parent所在子树的高度变化且不平衡,对parent所在的子树进行旋转,让它平衡
		//如果出现3/-3说明之前的操作有问题,最坏情况下更新到根结点
		while (parent)
		{
			if (cur == parent->_left)
			{
				parent->_bf--;
			}
			else//cur == parent->_right
			{
				parent->_bf++;
			}
			if (parent->_bf == 0)
			{
				//更新结束
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				//继续往上更新
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//子树不平衡,需要旋转
				//旋转时要注意的问题
				//1.保持它是搜索树
				//2.变成平衡树且降低这个子树的高度
				//核心条件:让parent往下降
				//parent->right=cur->left;
				//cur->left=parent;
				//左单旋,右边高往左边旋转
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
				//出现3/-3及以上
				assert(false);
			}
		}
		return true;
	}
	//左单旋(直线)
	//30 
	//  60 
	//    90
	void RotateL(Node* parent)
	{
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
		parent->_bf = cur->_bf = 0;//更改平衡因子
	}
	//右单旋(直线)
	//    30 
	//  60 
	//90
	void RotateR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		parent->_left = curright;
		if (curright)
		{
			curright->_parent = parent;
		}
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
		parent->_bf = cur->_bf = 0;
	}
	//先右单旋再左单旋(折线)
	//    30 
	//       60 
	//    90
	void RotateRL(Node* parent)
	{
		Node* cur = parent->_right;
		Node* curleft = cur->_left;
		int bf = curleft->_bf;
		RotateR(parent->_right);
		RotateL(parent);
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
	//先左单旋再右单旋(折线)
	//    90 
	//  30 
	//    60
	//60是新增
	//60的左边
	//60的右边
	void RotateLR(Node* parent)
	{
		Node* cur = parent->_left;
		Node* curright = cur->_right;
		int bf = curright->_bf;
		RotateL(parent->_left);
		RotateR(parent);
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
	int Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = Height(root->_left);
		int right = Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool IsBalance()
	{
		return _ISBalance(_root);
	}
	bool _ISBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		int leftHight = Height(root->_left);
		int rightHight = Height(root->_right);
		if (rightHight - leftHight != root->_bf)
		{
			cout << "平衡因子异常" << root->_kv.first << "->" << root->_bf << endl;
			return false;
		}
		return abs(rightHight - leftHight) < 2 && _ISBalance(root->_left) && _ISBalance(root->_right);
	}
	//删除
	//1.按搜索树的规则查找节点删除
	//2.更新平衡因子
	//3.出现异常,旋转
private:
	Node* _root = nullptr;
};