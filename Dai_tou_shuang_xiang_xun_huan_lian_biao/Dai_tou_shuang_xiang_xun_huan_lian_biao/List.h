#pragma once

//双向带头循环链表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化
LTNode* LTInit();

//销毁
void LTDestory();

void LTPushBack(LTNode* phead, LTDataType x);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);

LTNode* BuyListNode(LTDataType x);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

//pos位置之前插入一个节点
void LTInsertFront(LTNode* pos, LTDataType x);

LTNode* LTFind(LTNode* phead);
