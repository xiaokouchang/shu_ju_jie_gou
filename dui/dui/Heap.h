#pragma once

//���
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//�ѵĳ�ʼ��
void HeapInit(HP* php);

void HeapDestory(HP* php);

//�ѵĲ���
void HeapPush(HP* php, HPDataType x);

void Swap(HPDataType* p1, HPDataType* p2);

//���ϵ���
void AdjustUP(HPDataType* a, int child);

//ɾ���Ѷ�������
//Ų��ɾ��:
//Ч�ʵ���
//�����ֵܹ�ϵȫ����
//���ɾ��
void HeapPop(HP* php);

//���µ���
void AdjustDown(HPDataType* a, int n, int parent);

//����Ѷ�Ԫ��
HPDataType HeapTop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);

