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
STLNode* BuySLTNode(SLTDataType x);
void SLTPrint(STLNode* phead);
void SLTPushBack(STLNode** phead, SLTDataType x);
void SLTPushFront(STLNode** pphead, SLTDataType x);

void SLTPopBack(STLNode** phead);
void SLTPopFront(STLNode** pphead);

//单链表查找
STLNode* SLTFind(STLNode* pphead, SLTDataType x);

//pos之前插入
void SLTInsertFront(STLNode** pphead, STLNode* pos, SLTDataType x);

//pos位置删除
void SLTErase(STLNode** pphead, STLNode* pos);

//pos后面插入
void SLTInsertAfter(STLNode* pos, SLTDataType x);

//pos位置后面删除
void SLTEraseAfter(STLNode* pos);

//链表销毁
//方法1
void SLTDestory1(STLNode* phead);

//方法2
void SLTDestory2(STLNode** pphead);

void STLMiddlePos(int(*pf)(STLNode** pphead, SLTDataType x), STLNode** pphead, int num);


void STLMiddlePush(int(*pf)(STLNode** pphead, SLTDataType x), STLNode** pphead);

//从文件中加载
void STLLoadSList(STLNode** pphead);

//将链表保存到文件
void STLSaveSList(STLNode** pphead);


