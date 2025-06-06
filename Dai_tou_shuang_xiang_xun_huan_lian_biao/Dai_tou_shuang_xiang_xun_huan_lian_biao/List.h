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

//��ʼ��---�����ڱ�λ��ͷ�ڵ�
LTNode* LTInit();

//����
void LTDestory(LTNode* phead);

//β��
void LTPushBack(LTNode* phead, LTDataType x);

//ͷ��
void LTPushFront(LTNode* phead, LTDataType x);

//βɾ
void LTPopBack(LTNode* phead);

//ͷɾ
void LTPopFront(LTNode* phead);

//�����ڵ�
LTNode* BuyListNode(LTDataType x);

//�������
void LTPrint(LTNode* phead);

//����Ƿ�ֻ���ڱ�λ��ͷ�ڵ�
bool LTEmpty(LTNode* phead);

//posλ��֮ǰ����һ���ڵ�
void LTInsertFront(LTNode* pos, LTDataType x);

//posλ��֮�����һ���ڵ�
void LTInsertAfter(LTNode* pos, LTDataType x);

//posλ�õ�ǰ��ɾ��һ���ڵ�
void LTEraseFront(LTNode* phead, LTNode* pos);

//posλ��ɾ��һ���ڵ�
void LTErase(LTNode* phead, LTNode* pos);

//posλ�õĺ���ɾ��һ���ڵ�
void LTEraseBack(LTNode* phead, LTNode* pos);

//����
LTNode* LTFind(LTNode* phead, LTDataType x);

//��������
void LTLoad(LTNode* phead);

//��������
void LTSave(LTNode* phead);

//����ָ��
void LTPushMiddle(void(*pf)(LTNode* phead, LTDataType x),LTNode* phead);

void LTMiddlePos(int(*pf)(LTNode* phead, LTDataType x), LTNode* phead, LTDataType num);

void LTMiddleErase(int(*pf)(LTNode* phead, LTNode* pos), LTNode* phead, LTDataType num);