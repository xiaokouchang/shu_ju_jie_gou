#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//��һ��д��
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//ָ��������ǽṹ��
	//SListNode* next;C���Բ���,C++����
	//STLnode* next;//�������Ĳ��ҹ���,ֻ�����ض���֮�����ʹ��
}STLNode;
//��2��д��
//typedef int SLTDataType;
//
//struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;//ָ��������ǽṹ��
//	//SListNode* next;C���Բ���,C++����
//	//STLnode* next;//�������Ĳ��ҹ���,ֻ�����ض���֮�����ʹ��
//};
//
//typedef struct SListNode STLNode;

void SLTPrint(STLNode* phead);
void SLPushBack(STLNode* phead, SLTDataType x);
