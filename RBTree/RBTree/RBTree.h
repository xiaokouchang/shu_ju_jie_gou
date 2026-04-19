#pragma once

//红黑树
//没有一条路径会比其他路径长出俩倍
//规则
//每个结点不是红色就是黑色
//根节点是黑色的
//如果一个节点是红色的,则它的两个孩子结点是黑色的(任何路径没有连续的红色节点)
//对于每个结点,从该结点到其所有后代叶结点的简单路径上,均包含相同数目的黑色结点(每条路径上黑色节点的数量相等)
//每个叶子结点都是黑色的(此处的叶子结点指的是空结点)(空节点也被称为NIL节点)


//路径:根到空节点算一条路径
//为什么满足上面的性质,红黑树就能保证:其最长路径中节点个数不会超过最短路径节点个数的两倍?
//最短:全黑
//最长:一黑一红相同的路径


//AVL树(logN)和红黑树(2logN)
//性能是同一量级的,CPU的速度非常快
//但是AVL树,控制严格平衡是付出代价的,插入和删除需要进行大量的旋转
//红黑树不需要旋转,效率比AVL树的效率低

#include<iostream>
using namespace std;
enum Colour
{
	RED,
	BLACK
};
template<class K,class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;
	pair<K, V> _kv;
	Colour _col;
	RBTreeNode(const pair<K, V>& kv)
		:_kv(kv)
		, _left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _col(RED)
	{ }
};

template<class K, class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
public:
	RBTree()
		:_root(nullptr)
		,_rotateCount(0)
	{
	}
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
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
			else if (cur->_kv.first > kv.first)
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
		cur->_col = RED;//违反规则3,规则3容易控制
		//变红之后,parent一定为黑
		//继续向上处理:
		//grandfather没有父亲,就是根,grandfather变黑即可
		//grandfather有父亲,父亲是黑色,结束了
		//grandfather有父亲,父亲是红色
		
		//插入关键是uncle
		//uncle存在且为红,变色+继续向上更新
		//uncle存在且为黑
		//uncle不存在,uncle存在且为黑,旋转+变色
		if (parent->_kv.first < kv.first)
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
				//uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					//局部变色
					//红黑节点的数量不变,暂时解决了连续的红节点
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;
					
					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else//uncle不存在或者存在且为黑
				{
					//  g(black)
					// p(red)
					//c(red)
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
			else//parent == grandfather->_right
			{
				Node* uncle = grandfather->_left;
				//uncle存在且为红
				if (uncle && uncle->_col == RED)
				{
					//变色
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					//继续向上处理
					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_right)
					{
						//g 
						//  p
						//    c
						RotateL(grandfather);
						grandfather->_col = RED;
						parent->_col = BLACK;
					}
					else
					{
						// g 
						//p
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
		_rotateCount++;
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
	//右单旋(直线)
	//    30 
	//  60 
	//90
	void RotateR(Node* parent)
	{
		_rotateCount++;
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
	}
	bool CheckColour(Node* root, int blacknum, int benchmark)//使用引用算整颗树的黑色节点的数量
	{
		if (root == nullptr)
		{
			if (blacknum != benchmark)
			{
				return false;
			}
			return true;
		}
		if (root->_col == BLACK)
		{
			blacknum++;
		}
		if (root->_col == RED && root->_parent && root->_parent->_col == RED)
		{
			cout << root->_kv.first << "出现连续红色节点" << endl;
			return false;
		}
		return CheckColour(root->_left, blacknum, benchmark) && CheckColour(root->_right, blacknum, benchmark);
	}
	bool IsBalance()
	{
		return _IsBalance(_root);
	}
	int Height()
	{
		return _Height(_root);
	}
	int _Height(Node* root)
	{
		if (root == nullptr)
		{
			return 0;
		}
		int left = _Height(root->_left);
		int right = _Height(root->_right);
		return left > right ? left + 1 : right + 1;
	}
	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
		{
			return true;
		}
		if (root->_col != BLACK)
		{
			return false;
		}
		//基准值
		int benchmark = 0;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_col == BLACK)
			{
				benchmark++;
			}
			cur = cur->_left;
		}
		return CheckColour(root, 0, benchmark);
	}
private:
	Node* _root;
public:
	int _rotateCount = 0;//旋转次数
};

