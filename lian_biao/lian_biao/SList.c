#define _CRT_SECURE_NO_WARNINGS 1 

#include "SList.h"
void SLTPrint(STLNode* phead)
{
	//空的顺序表可以打印,只是数据为空
	//assert(phead);//不能
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

STLNode* BuySTLNode(SLTDataType x)
{
	STLNode* newnode = (STLNode*)malloc(sizeof(STLNode));
	if (newnode == NULL)
	{
		perror("SLPushBack");
		return NULL;
	}
	newnode->data = x;
	newnode->next = NULL;
	return newnode;
}
//上一个节点链接下一个节点的地址
//不为空链表的尾插,尾插的本质是原尾节点要存储新的尾节点的地址
void SLTPushBack(STLNode** pphead, SLTDataType x)
{
	assert(pphead);//*pphead为地址一定不为空,值可以为空
	STLNode* newnode = BuySTLNode(x);
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		STLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			tail = tail->next;
		}
		tail->next = newnode;
		//错误
		//while (tail != NULL)
		//{
		//	tail = tail->next;
		//}
		//tail = newnode;
	}
}


void SLTPushFront(STLNode** pphead, SLTDataType x)
{
	assert(pphead);
	STLNode* newnode = BuySTLNode(x);
	newnode->next = *pphead;
	*pphead = newnode;
}


//一定不能为空,要断言
//pphead
void SLTPopBack(STLNode** pphead)
{
	//必须有数据才能删除
	//检查
	assert(pphead);
	assert(*pphead);
	//if (*pphead == NULL)
	//{
	//	return;
	//}
	//只有一个节点
	//有多个节点
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//方法1
		//找尾
		STLNode* prev = NULL;
		STLNode* tail = *pphead;
		while (tail->next != NULL)
		{
			prev = tail;
			tail = tail->next;
		}
		free(tail);
		tail = NULL;
		prev->next = NULL;
		//方法2
		//STLNode* tail = *pphead;
		//while (tail->next->next != NULL)
		//{
		//	tail = tail->next;
		//}
		//free(tail->next);
		//tail->next = NULL;
	}
}
void SLTPopFront(STLNode** pphead)
{
	//检查
	assert(*pphead != NULL);
	//if (*pphead == NULL)
	//{
	//	return;
	//}
	STLNode* first = *pphead;
	*pphead = first->next;
	free(first);
	first = NULL;
}

STLNode* SLTFind(STLNode* pphead, SLTDataType x)
{
	STLNode* cur = pphead;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void SLTInsert(STLNode** pphead, STLNode* pos, SLTDataType x)
{
	//不能实现尾插
	assert(pos);
	assert(pphead);
	if (pos == *pphead)
	{
		SLTPushFront(pphead, x);
	}
	else
	{
		//找到pos的前一个位置
		STLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		STLNode* newnode = BuySTLNode(x);
		prev->next = newnode;
		newnode->next = pos;
	}
}


void SLTErase(STLNode** pphead, STLNode* pos)
{
	assert(pphead);
	assert(pos);
	assert(*pphead);
	if (pphead == NULL)
	{
		SLTPopBack(pphead);
	}
	else
	{
		STLNode* prev = *pphead;
		while (prev->next != pos)
		{
			prev = prev->next;
		}
		prev->next = pos->next;
		free(pos);
		pos = NULL;//可以不写,因为pos为形参
	}
}