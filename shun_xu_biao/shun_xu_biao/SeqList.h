#pragma once

//#define N 10
//typedef int SLDataType;
////��̬˳���
////�����˲�����,�������˷�
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define INIT_CAPACITY 4         //��ʼ��������
typedef int SLDataType;
//��̬˳��� --- ��������
typedef struct SeqList
{
	SLDataType* a;
	int size;            //��Ч���ݸ���
	int capacity;        //�ռ�����
}SL;


//��ɾ���

//��ʼ��
void SLInit(SL* ps);

//�ͷſռ�
void SLDestory(SL* ps);

//���
void SLPrint(SL* ps);

//����
void SLCheckCapacity(SL* ps);

//β��
void SLPushBack(SL* ps, SLDataType x);

//βɾ
void SLPopBack(SL* ps);

//ͷ��
void SLPushFront(SL* ps, SLDataType x);

//ͷɾ
void SLPopFront(SL* ps);

//ĳ��λ�ò���
void SLInsert(SL* ps, int pos, SLDataType x);

//ĳ��λ��ɾ��
void SLErase(SL* ps, int pos);