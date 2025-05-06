#pragma once

//#define N 10
//typedef int SLDataType;
////静态顺序表
////开少了不够用,开多了浪费
//struct SeqList
//{
//	SLDataType a[N];
//	int size;
//};


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#define INIT_CAPACITY 4         //初始化的容量
typedef int SLDataType;
//动态顺序表 --- 按需申请
typedef struct SeqList
{
	SLDataType* a;
	int size;            //有效数据个数
	int capacity;        //空间容量
}SL;


//增删查改
void SLInit(SL* s);
void SLDestory(SL* s);
void SLPrint(SL* s);
void SLPushBack(SL* s, SLDataType x);
void SLPopBack(SL* s);
void SLPushFront(SL* s, SLDataType x);
void SLPopFront(SL* s);