#pragma once

//大堆
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;

//堆的初始化
void HeapInit(HP* php);

//堆的销毁
void HeapDestory(HP* php);

//堆的插入
void HeapPush(HP* php, HPDataType x);

//交换数据
void Swap(HPDataType* p1, HPDataType* p2);

//向上调整
void AdjustUP(HPDataType* a, int child);

//删除堆顶的数据
//挪动删除:
//效率低下
//父子兄弟关系全乱了
//间接删除
void HeapPop(HP* php);

//输出数据
void HeapPrint(HP* php);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//输出堆顶元素
HPDataType HeapTop(HP* php);

//堆的元素个数
int HeapSize(HP* php);

//堆是否为空
bool HeapEmpty(HP* php);

//将数据保存到文件中
void HeapSave(HP* php);

//从文件中读取数据
void HeapLoad(HP* php);

//函数指针
void HeapPushMiddle(void(*pf)(HP* php, HPDataType x), HP* php);

void HeapMiddle(HPDataType(*pf)(HP* php), HP* php, int num);

//使用数组初始化堆
void HeapInitArray(HP* php, int* a, int n);
