#pragma once

//˫���ͷѭ������
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

//��ʼ��
LTNode* LTInit();

//����
void LTDestory();

void LTPushBack(LTNode* phead, LTDataType x);
void LTPushFront(LTNode* phead, LTDataType x);
void LTPopBack(LTNode* phead);
void LTPopFront(LTNode* phead);

LTNode* BuyListNode(LTDataType x);
void LTPrint(LTNode* phead);
bool LTEmpty(LTNode* phead);

//posλ��֮ǰ����һ���ڵ�
void LTInsertFront(LTNode* pos, LTDataType x);

LTNode* LTFind(LTNode* phead);
