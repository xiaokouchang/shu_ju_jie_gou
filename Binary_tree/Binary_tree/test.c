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
	BTNode* node2 = BuyNode(2);
	BTNode* node3 = BuyNode(3);
	BTNode* node4 = BuyNode(4);
	BTNode* node5 = BuyNode(5);
	BTNode* node6 = BuyNode(6);
	BTNode* node7 = BuyNode(7);
	node1->left = node2;
	node1->right = node4;
	node2->left = node3;
	node4->left = node5;
	node4->right = node6;
	node3->left = node7;
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
void LeverIOrder(BTNode* root)
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
	QueueDestory(&q);
}
//判断完全二叉树
int BinaryTreeComplete(BTNode* root)
{

}
int main()
{
	BTNode* root = CreatTree();
	PreOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	int size = 0;//调用两次会使size改变,全局变量
	//Treesize(root, &size);
	//int ret = Treesize(root);
	//printf("Treesize:%d\n", ret);
	//int ret = TreeHigh(root);
	//printf("Treesize:%d\n", ret);
	int ret = TreeLevel(root, 3);
	printf("Treesize:%d\n", ret);
	//BTNode* ret = BinaryTreeFind(root, 2);

	return 0;
}