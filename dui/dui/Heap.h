#pragma once

//大堆
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

//堆的初始化
void HeapInit(HP* php);

//堆的插入
void HeapPush(HP* php, HPDataType x);

//向上调整
void AdjustUP(HPDataType* a, int child);