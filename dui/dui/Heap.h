#pragma once

//大堆
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

//堆的初始化
void HeapInit(HP* php);

void HeapDestory(HP* php);

//堆的插入
void HeapPush(HP* php, HPDataType x);

void Swap(HPDataType* p1, HPDataType* p2);

//向上调整
void AdjustUP(HPDataType* a, int child);

//删除堆顶的数据
//挪动删除:
//效率低下
//父子兄弟关系全乱了
//间接删除
void HeapPop(HP* php);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//输出堆顶元素
HPDataType HeapTop(HP* php);

int HeapSize(HP* php);

bool HeapEmpty(HP* php);

