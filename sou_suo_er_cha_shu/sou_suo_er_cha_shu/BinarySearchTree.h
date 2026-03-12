#pragma once
#include<iostream>
using namespace std;
//普通二叉树的增删查改没有意义
//搜索二叉树的增删查改有意义
//搜索二叉树的查找排序插入删除效率都不错
namespace key
{
	template<class K>
	//BinarySearchTreeNode  --->   BSTreeNode
	class BSTreeNode
	{
	public:
		BSTreeNode<K>* _left;
		BSTreeNode<K>* _right;
		K _key;
		BSTreeNode(const K& key)
			:_left(nullptr)
			, _right(nullptr)
			, _key(key)
		{}
	};

	template<class K>
	class BSTree
	{
		typedef BSTreeNode<K> Node;
	public:
		BSTree()
			:_root(nullptr)
		{
		}
		BSTree(const BSTree<K>& t)
		{
			_root = Copy(t._root);
		}
		BSTree<K>& operator=(BSTree<K> t)
		{
			swap(_root, t._root);
			return *this;
		}
		~BSTree()
		{
			Destory(_root);
		}
		bool Insert(const K& key)
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
				else//cur->_key == key
				{
					return false;
				}
			}
			cur = new Node(key);
			if (parent->_key < key)
			{
				parent->_right = cur;
			}
			else//parent->_key>key
			{
				parent->_left = cur;
			}
			return true;
		}
		//查找
		bool Find(const K& key)
		{
			Node* cur = _root;
			while (cur)
			{
				if (cur->_key < key)
				{
					cur = cur->_right;
				}
				else if (cur->_key > key)
				{
					cur = cur->_left;
				}
				else//cur->_key == key
				{
					return true;
				}
			}
			return false;
		}
		//删除
		//没有孩子
		//1个孩子
		//2个孩子(替换法:左子树的最大节点(最右节点)或者右子树的最小节点(最左节点))

		bool Erase(const K& key)
		{
			Node* parent = nullptr;
			Node* cur = _root;
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
				else//找到了 cur->_key == key
				{
					//左为空
					if (cur->_left == nullptr)
					{
						//根节点
						if (cur == _root)
						{
							_root = cur->_right;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_right;
							}
						}
					}//右为空
					else if (cur->_right == nullptr)
					{
						if (cur == _root)
						{
							_root = cur->_left;
						}
						else
						{
							if (parent->_right == cur)
							{
								parent->_right = cur->_right;
							}
							else
							{
								parent->_left = cur->_left;
							}
						}
					}
					else//左右都不为空
					{
						//找替代节点
						//Node* parent = nullptr;
						Node* parent = cur;
						Node* leftMax = cur->_left;
						while (leftMax->_right)
						{
							parent = leftMax;
							leftMax = leftMax->_right;
						}
						swap(cur->_key, leftMax->_key);
						if (parent->_left == leftMax)
						{
							parent->_left = leftMax->_left;
						}
						else
						{
							parent->_right = leftMax->_left;
						}
						cur = leftMax;
					}
					delete cur;
					return true;
				}
			}
			return false;
		}
		//中序遍历
		void InOrder()
		{
			_InOrder(_root);
			cout << endl;
		}
		//递归
		bool FindR(const K& key)
		{
			return _FindR(_root, key);
		}
		bool InsertR(const K& key,const V& value)
		{
			return _InsertR(_root, key);
		}
		bool EreaseR(const K& key)
		{
			return _EreaseR(_root, key);
		}
	private:
		Node* Copy(Node* root)
		{
			if (root == nullptr)
				return nullptr;
			Node* copyroot = new Node(root->_key);
			copyroot->_left = Copy(root->_left);
			copyroot->_right = Copy(root->_right);
			return copyroot;
		}
		void Destory(Node*& root)
		{
			if (root == nullptr)
			{
				return;
			}
			Destory(root->_left);
			Destory(root->_right);
			delete root;
			root = nullptr;
		}

		//引用不能改变指向,循环中不能使用,递归每次会产生新的引用
		//C++不能缺少指针
		bool _EreaseR(Node*& root, const K& key)
		{
			if (root == nullptr)
			{
				return false;
			}
			if (root->_key < key)
			{
				return _EreaseR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _EreaseR(root->_left, key);
			}
			else
			{
				//左为空
				//右为空
				//左右都不为空
				Node* del = root;
				if (root->_left == nullptr)
				{
					root = root->_right;
				}
				else if (root->_right == nullptr)
				{
					root = root->_left;
				}
				else
				{
					Node* leftMax = root->_left;
					while (leftMax->_right)
					{
						leftMax = leftMax->_right;
					}
					swap(root->_key, leftMax->_key);
					return _EreaseR(root->_left, key);
					//return _EreaseR(leftMax, key);
				}
				delete del;
				return true;
			}
		}
		//可以将parent传递,这里使用传引用
		bool _InsertR(Node*& root, const K& key)
		{
			if (root == NULL)
			{
				root = new Node(key);
				return true;
			}
			if (root->_key < key)
			{
				return _InsertR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _InsertR(root->_left, key);
			}
			else
			{
				return true;
			}
		}
		bool _FindR(Node* root, const K& key)
		{
			if (root == NULL)
			{
				return NULL;
			}
			if (root->_key < key)
			{
				return _FindR(root->_right, key);
			}
			else if (root->_key > key)
			{
				return _FindR(root->_left, key);
			}
			else
			{
				return true;
			}
		}

		//中序遍历
		void _InOrder(Node* root)
		{
			if (root == NULL)
			{
				printf("NULL ");
				return;
			}
			cout << root->_key << " ";
			_InOrder(root->_left);
			_InOrder(root->_right);
		}
	private:
		Node* _root;
	};
}


//namespace key_value
//{
//	template<class K,class V>
//	//BinarySearchTreeNode  --->   BSTreeNode
//	class BSTreeNode
//	{
//	public:
//		BSTreeNode<K, V>* _left;
//		BSTreeNode<K, V>* _right;
//		K _key;
//		V _value;
//		BSTreeNode(const K& key, const V& value)
//			: _left(nullptr)
//			, _right(nullptr)
//			, _key(key)
//			, _value(value)
//		{}
//	};
//
//
//	template<class K, class V>
//	class BSTree
//	{
//		typedef BSTreeNode<K, V> Node;
//	public:
//		BSTree()
//			:_root(nullptr)
//		{}
//		//中序遍历
//		void InOrder()
//		{
//			_InOrder(_root);
//			cout << endl;
//		}
//		//递归
//		Node* FindR(const K& key)
//		{
//			return _FindR(_root, key);
//		}
//		bool InsertR(const K& key,const V& value)
//		{
//			return _InsertR(_root, key, value);
//		}
//		bool EreaseR(const K& key)
//		{
//			return _EreaseR(_root, key);
//		}
//	private:
//		//引用不能改变指向,循环中不能使用,递归每次会产生新的引用
//		//C++不能缺少指针
//		bool _EreaseR(Node*& root, const K& key)
//		{
//			if (root == nullptr)
//			{
//				return false;
//			}
//			if (root->_key < key)
//			{
//				return _EreaseR(root->_right, key);
//			}
//			else if (root->_key > key)
//			{
//				return _EreaseR(root->_left, key);
//			}
//			else
//			{
//				//左为空
//				//右为空
//				//左右都不为空
//				Node* del = root;
//				if (root->_left == nullptr)
//				{
//					root = root->_right;
//				}
//				else if (root->_right == nullptr)
//				{
//					root = root->_left;
//				}
//				else
//				{
//					Node* leftMax = root->_left;
//					while (leftMax->_right)
//					{
//						leftMax = leftMax->_right;
//					}
//					swap(root->_key, leftMax->_key);
//					return _EreaseR(root->_left, key);
//					//return _EreaseR(leftMax, key);
//				}
//				delete del;
//				return true;
//			}
//		}
//		//可以将parent传递,这里使用传引用
//		//value不参与这个过程
//		bool _InsertR(Node*& root, const K& key, const V& value)
//		{
//			if (root == NULL)
//			{
//				root = new Node(key, value);
//				return true;
//			}
//			if (root->_key < key)
//			{
//				return _InsertR(root->_right, key, value);
//			}
//			else if (root->_key > key)
//			{
//				return _InsertR(root->_left, key, value);
//			}
//			else
//			{
//				return true;
//			}
//		}
//		Node* _FindR(Node* root, const K& key)//key不能改变,value可以改变
//		{
//			if (root == NULL)
//			{
//				return nullptr;
//			}
//			if (root->_key < key)
//			{
//				return _FindR(root->_right, key);
//			}
//			else if (root->_key > key)
//			{
//				return _FindR(root->_left, key);
//			}
//			else
//			{
//				return root;
//			}
//		}
//
//		//中序遍历
//		void _InOrder(Node* root)
//		{
//			if (root == NULL)
//			{
//				//printf("NULL ");
//				return;
//			}
//			cout << root->_key << ":" << root->_value << endl;
//			_InOrder(root->_left);
//			_InOrder(root->_right);
//		}
//	private:
//		Node* _root;
//	};
//}
//搜索二叉树的应用
//key的搜索模型 
//快速判断在不在的场景,门禁系统,小车辆出入系统
//通过1个值找另外一个值
//商场的车辆出入系统
//高铁实名制车票系统
//检查英文文章单词是否正确

//key/value的搜索模型 
