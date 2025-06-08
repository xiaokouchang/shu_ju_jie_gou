#pragma once
//队列
//只允许在一端进行插入数据操作,在另一端进行删除数据操作的特殊线性表,
//队列具有先进先出
//入队列:进行插入操作的一端称为队尾
//出队列:进行删除操作的一端称为队头

#include<stdio.h>
#include<stdbool.h>
#include<assert.h>
#include<stdlib.h>

typedef int QDataType;
typedef struct QueueNode
{
	struct QueueNode* next;
	QDataType data;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;

//初始化队列
void QueueInit(Queue* pq);

//销毁队列
void QueueDestory(Queue* pq);

//队尾入队列
void QueuePush(Queue* pq,QDataType x);

//队头出队列
void QueuePop(Queue* pq);

//获取队列中有效元素个数
int QueueSize(Queue* pq);

//检查队列是否为空
bool QueueEmpty(Queue* pq);

//取出队头的数据
QDataType QueueFront(Queue* pq);

//取出队尾的数据
QDataType QueueBack(Queue* pq);