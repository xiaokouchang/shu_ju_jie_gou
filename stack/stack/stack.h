#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//��̬ջ
//#define N 10
//struct Stack
//{
//	int a[N];
//	int top;
//};

//��̬ջ
typedef int STDataType;
typedef struct Stack
{
	int* a;
	int top;
	int capacity;   //����
}ST;

//��ʼ��
void STInit(ST* ps);

void STDestroy(ST* ps);

//ֻ����һ�˲���,��ջ��
void STPush(ST* ps,STDataType x);

void STPop(ST* ps);

int STSize(ST* ps);

bool STEmpty(ST* ps);

//����ջ��Ԫ��
STDataType STTop(ST* ps);