#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	return phead;
}
void LTDestory();
LTNode* LTFind(LTNode* phead)
{

}
LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("newnode");
		return;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//一定不为空,空可能是传错了
	//方法1
	//LTNode* newnode = BuyListNode(x);
	//LTNode* tail = phead->prev;
	////phead         tail newnode
	//tail->next = newnode;
	//newnode->prev = tail;
	//newnode->next = phead;
	//phead->prev = newnode;
	//方法2
	//newnode phead    tail
	LTInsertFront(phead, x);
}
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	//方法1
	//if (phead->next == phead)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	//方法2
	return phead->next != phead;
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));
	//phead head tail
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);//一定不为空,空可能是传错了
	LTNode* newnode = BuyListNode(x);
	//phead newnode head
	//方法1---可以随便换顺序
	//LTNode* head = phead->next;
	//phead->next = newnode;
	//newnode->prev = phead;
	//newnode->next = head;
	//head->prev = newnode;
	//方法2---不能随便换顺序
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	//方法3
	LTInsertFront(phead->next, x);
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));
	LTNode* tail = phead->prev;
	LTNode* tailprev = tail->prev;
	tailprev->next = phead;
	phead->prev = tailprev;
	free(tail);
	tail = NULL;
}
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("<=head=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTInsertFront(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	//prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}
