#pragma once

//双向带头循环链表
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType data;
	struct ListNode* next;
	struct ListNode* prev;
}LTNode;

//初始化---设置哨兵位的头节点
LTNode* LTInit();

//销毁
void LTDestory(LTNode* phead);

//尾插
void LTPushBack(LTNode* phead, LTDataType x);

//头插
void LTPushFront(LTNode* phead, LTDataType x);

//尾删
void LTPopBack(LTNode* phead);

//头删
void LTPopFront(LTNode* phead);

//创建节点
LTNode* BuyListNode(LTDataType x);

//输出数据
void LTPrint(LTNode* phead);

//检查是否只有哨兵位的头节点
bool LTEmpty(LTNode* phead);

//pos位置之前插入一个节点
void LTInsertFront(LTNode* pos, LTDataType x);

//pos位置之后插入一个节点
void LTInsertAfter(LTNode* pos, LTDataType x);

//pos位置的前面删除一个节点
void LTEraseFront(LTNode* phead, LTNode* pos);

//pos位置删除一个节点
void LTErase(LTNode* phead, LTNode* pos);

//pos位置的后面删除一个节点
void LTEraseBack(LTNode* phead, LTNode* pos);

//查找
LTNode* LTFind(LTNode* phead, LTDataType x);

//加载链表
void LTLoad(LTNode* phead);

//保存链表
void LTSave(LTNode* phead);

//函数指针
void LTPushMiddle(void(*pf)(LTNode* phead, LTDataType x),LTNode* phead);

void LTMiddlePos(int(*pf)(LTNode* phead, LTDataType x), LTNode* phead, LTDataType num);

void LTMiddleErase(int(*pf)(LTNode* phead, LTNode* pos), LTNode* phead, LTDataType num);