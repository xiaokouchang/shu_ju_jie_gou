#pragma once

//���
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php);

//�ѵĲ���
void HeapPush(HP* php, HPDataType x);

//���ϵ���
void AdjustUP(HPDataType* a, int child);