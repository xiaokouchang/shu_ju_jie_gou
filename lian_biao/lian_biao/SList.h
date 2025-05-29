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
STLNode* BuySLTNode(SLTDataType x);
void SLTPrint(STLNode* phead);
void SLTPushBack(STLNode** phead, SLTDataType x);
void SLTPushFront(STLNode** pphead, SLTDataType x);

void SLTPopBack(STLNode** phead);
void SLTPopFront(STLNode** pphead);

//���������
STLNode* SLTFind(STLNode* pphead, SLTDataType x);

//pos֮ǰ����
void SLTInsertFront(STLNode** pphead, STLNode* pos, SLTDataType x);

//posλ��ɾ��
void SLTErase(STLNode** pphead, STLNode* pos);

//pos�������
void SLTInsertAfter(STLNode* pos, SLTDataType x);

//posλ�ú���ɾ��
void SLTEraseAfter(STLNode* pos);

//��������
//����1
void SLTDestory1(STLNode* phead);

//����2
void SLTDestory2(STLNode** pphead);

void STLMiddlePos(int(*pf)(STLNode** pphead, SLTDataType x), STLNode** pphead, int num);


void STLMiddlePush(int(*pf)(STLNode** pphead, SLTDataType x), STLNode** pphead);

//���ļ��м���
void STLLoadSList(STLNode** pphead);

//�������浽�ļ�
void STLSaveSList(STLNode** pphead);


