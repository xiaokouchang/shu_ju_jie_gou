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

//初始化
void SLInit(SL* ps);

//释放空间
void SLDestory(SL* ps);

//输出
void SLPrint(SL* ps);

//扩容
void SLCheckCapacity(SL* ps);

//尾插
void SLPushBack(SL* ps, SLDataType x);

//尾删
void SLPopBack(SL* ps);

//头插
void SLPushFront(SL* ps, SLDataType x);

//头删
void SLPopFront(SL* ps);

//某个数的后面插入
void SLBackInsert(SL* ps, int pos, SLDataType x);

//某个数的前面插入
void SLFrontInsert(SL* ps, int pos, SLDataType x);

//某个位置删除
void SLErase(SL* ps, int pos);

//查找
int SLFind(SL* ps, SLDataType x);

//函数指针数组
void SeqListValue(int(*pf)(SL* ps, SLDataType x), SL* ps);

void SeqListInsert(int(*pf)(SL* ps, SLDataType x), SL* ps, int num);

//保存数据到文件中
void SaveSeqList(SL* ps);

//加载数据到文件中
void LoadSeqList(SL* ps);