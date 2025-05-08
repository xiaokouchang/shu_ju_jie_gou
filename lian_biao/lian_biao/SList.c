#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"
void SLTPrint(STLNode* phead)
{
	//空的顺序表可以打印,只是数据为空
	//assert(phead);不能
	//物理结构:实实在在数据在内存中的变化
	//逻辑结构:为了方便理解,形象化画出来的
	STLNode* cur = phead;
	//while(cur)
	while (cur != NULL)//cur->next != NULL最后一个数据没有输出,可以写成
	{
		printf("%d->", cur->data);
		cur = cur->next;//cur的地址不断覆盖,不能++,不能保证空间是连续的
		//一块空间的初始地址和结束地址不一样,一块空间的结束地址和下一块空间的起始地址一样
	}
	printf("NULL\n");
}


//上一个节点链接下一个节点的地址
//原尾节点要存储新的尾节点的地址
void SLPushBack(STLNode* phead, SLTDataType x)
{
	STLNode* newnode = (STLNode*)malloc(sizeof(STLNode));
	if (newnode == NULL)
	{
		perror("SLPushBack");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	//找尾
	STLNode* tail = phead;
	//错误
	//while (tail != NULL)
	//{
	//	tail = tail->next;
	//}
	//tail = newnode;
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;
}