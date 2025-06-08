#pragma once
//����
//ֻ������һ�˽��в������ݲ���,����һ�˽���ɾ�����ݲ������������Ա�,
//���о����Ƚ��ȳ�
//�����:���в��������һ�˳�Ϊ��β
//������:����ɾ��������һ�˳�Ϊ��ͷ

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

//��ʼ������
void QueueInit(Queue* pq);

//���ٶ���
void QueueDestory(Queue* pq);

//��β�����
void QueuePush(Queue* pq,QDataType x);

//��ͷ������
void QueuePop(Queue* pq);

//��ȡ��������ЧԪ�ظ���
int QueueSize(Queue* pq);

//�������Ƿ�Ϊ��
bool QueueEmpty(Queue* pq);

//ȡ����ͷ������
QDataType QueueFront(Queue* pq);

//ȡ����β������
QDataType QueueBack(Queue* pq);