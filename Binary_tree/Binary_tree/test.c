#define _CRT_SECURE_NO_WARNINGS 1 
//二叉搜索树
//左子树都比双亲节点小,右子树都比双亲节点大
//         1---根
//左子树 2    4  右子树
//     3    5  6
//前序遍历(前根遍历):根 左子树 右子树
//(1 2 3 NULL(3的左子树) NULL(3的右子树) NULL(2的右子树) 4 5 NULL(5的左子树) NULL(5的右子树) 6 NULL(6的左子树) NULL(6的右子树))
//中序遍历(中根遍历):左子树 根 右子树
//左树访问完成之后才能访问根
//(NULL(3的左子树) 3 NULL(3的右子树) 2 NULL(2的右子树) 1 NULL(5的左子树) 5 NULL(5的右子树) 4 NULL(6的左子树) 6 NULL(6的右子树))
//后序遍历:左子树 右子树 根
//(NULL(3的左子树) NULL(3的右子树) 3 NULL(2的右子树) 2 NULL(5的左子树) NULL(5的右子树) 5 NULL NULL 6 4 1 
//层序遍历
//1 2 4 3 5 6


//二叉树的增删查改没有意义
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include "Queue.h"
typedef int BTDataType;
typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;


BTNode* BuyNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (node == NULL)
	{
		perror("malloc fail");
		return NULL;
	}
	node->data = x;
	node->left = NULL;
	node->right = NULL;
	return node;
}
//     1
//  2     4 
//3     5   6
BTNode* CreatTree()
{
	BTNode* node1 = BuyNode(1);
	BTNode* node2 = BuyNode(1);
	BTNode* node3 = BuyNode(1);
	BTNode* node4 = BuyNode(1);
	BTNode* node5 = BuyNode(1);
	BTNode* node6 = BuyNode(1);
	BTNode* node7 = BuyNode(1);
	node1->left = node2;
	node1->right = node3;
	node2->left = node4;
	node2->right = node5;
	node3->right = node6;
	return node1;
}
//前序遍历
void PreOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	printf("%d ", root->data);
	PreOrder(root->left);
	PreOrder(root->right);
}
//中序遍历
void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
//后序遍历
void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}


//查找二叉树值为x的结点
//返回结点指针既有查找的功能,也有修改的功能
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->data == x)
	{
		return root;
	}
	BTNode* lret = BinaryTreeFind(root->left, x);
	if (lret)
	{
		return lret;
	}
	BTNode* rret = BinaryTreeFind(root->right, x);
	if (rret)
	{
		return rret;
	}
	return NULL;
}


//树的节点数目
//顺序影响执行逻辑
//方法1
//void Treesize(BTNode* root, int* size)
//{
//	if (root == NULL)
//	{
//		return;
//	}
//	Treesize(root->left, size);
//	Treesize(root->right, size);
//	(*size)++;
//}
//方法2
int Treesize(BTNode* root)
{
	return root == NULL ? 0 : Treesize(root->left) + Treesize(root->right) + 1;
}
int TreeHigh(BTNode* root)
{
	//方法1
	//时间复杂度:O(N)
	//return root == NULL ? 0 : (TreeHigh(root->left) > TreeHigh(root->right) ?
	//	TreeHigh(root->left) + 1 : TreeHigh(root->right) + 1);
	//方法2
	//时间复杂度:O(N^2)
	//if (root == NULL)
	//	return 0;
	//return TreeHigh(root->left) > TreeHigh(root->right)
	//	? TreeHigh(root->left) + 1 : TreeHigh(root->right) + 1;
	//方法3
	if (root == NULL)
		return 0;
	int leftHeight = TreeHigh(root->left);
	int rightHeight = TreeHigh(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
}
//第k层结点的个数
//根的第k层个数 = 左子树的k - 1层个数 + 右子树的k - 1层个数
int TreeLevel(BTNode* root, int k)
{
	assert(k > 0);
	if (root == NULL)
	{
		return 0;
	}
	if (k == 1)
	{
		return 1;
	}
	return TreeLevel(root->left, k - 1) +
		TreeLevel(root->right, k - 1);
}
//使用队列
//层序遍历
void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);//Pop的是队列的节点,front保存的是树的节点
		printf("%d ", front->data);
		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");
	QueueDestory(&q);
}
//判断完全二叉树
//通过层序遍历,空也入队列,如果是空,后面全是空
//按层序走,非空节点一定是连续的
bool IsCompleteTree(BTNode* root)
{
	Queue q;
	QueueInit(&q);
	if (root)
	{
		QueuePush(&q, root);
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		if (front == NULL)
		{
			break;
		}
		else
		{
			QueuePush(&q, front->left);
			QueuePush(&q, front->right);
		}
	}
	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		QueuePop(&q);
		//有非空,说明后面节点不是完全连续
		if (front)
		{
			QueueDestory(&q);
			return false;
		}
	}
	QueueDestory(&q);
	return true;
}
//后序遍历更好
//前序遍历:无法找到下一个节点
void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
	{
		return;
	}
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}
bool isUnivalTree(BTNode* root) {
	//A==B   B==C
	//A==C
	if (root == NULL)
	{
		return true;
	}
	if (root->left != NULL && root->left->data != root->data)
	{
		return false;
	}
	if (root->right != NULL && root->right->data != root->data)
	{
		return false;
	}
	return isUnivalTree(root->left) && isUnivalTree(root->right);
}
void test1()
{
	BTNode* root = CreatTree();
	printf("%d\n", isUnivalTree(root));
}
int main()
{
	test1();
	//BTNode* root = CreatTree();
	//PreOrder(root);
	//printf("\n");
	//InOrder(root);
	//printf("\n");
	//PostOrder(root);
	//printf("\n");
	//int size = 0;//调用两次会使size改变,全局变量
	//Treesize(root);
	//int ret1 = Treesize(root);
	//printf("Treesize:%d\n", ret1);
	//int ret2 = TreeHigh(root);
	//printf("Treesize:%d\n", ret2);
	//int ret3 = TreeLevel(root, 3);
	//printf("Treesize:%d\n", ret3);
	//LevelOrder(root);
	//BTNode* ret = BinaryTreeFind(root, 2);
	//printf("IsCompleteTree:%d\n", IsCompleteTree(root));
	//BinaryTreeDestory(root);
	//root = NULL;
	return 0;
}


//深度优先遍历(DFS):先往深处走,再往回退(递归)
//二叉树前序遍历
//广度优先遍历(BFS):队列
//一层一层往外扩
//二叉树层序遍历