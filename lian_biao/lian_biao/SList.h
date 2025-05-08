#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
//第一种写法
typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType data;
	struct SListNode* next;//指针的类型是结构体
	//SListNode* next;C语言不行,C++可以
	//STLnode* next;//编译器的查找规则,只能在重定义之后才能使用
}STLNode;
//第2种写法
//typedef int SLTDataType;
//
//struct SListNode
//{
//	SLTDataType data;
//	struct SListNode* next;//指针的类型是结构体
//	//SListNode* next;C语言不行,C++可以
//	//STLnode* next;//编译器的查找规则,只能在重定义之后才能使用
//};
//
//typedef struct SListNode STLNode;

void SLTPrint(STLNode* phead);
void SLPushBack(STLNode* phead, SLTDataType x);
