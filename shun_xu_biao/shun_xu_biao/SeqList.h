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
void SLInit(SL* s);
void SLDestory(SL* s);
void SLPrint(SL* s);
void SLPushBack(SL* s, SLDataType x);
void SLPopBack(SL* s, SLDataType x);
void SLPushFront(SL* s, SLDataType x);
void SLPopFront(SL* s, SLDataType x);