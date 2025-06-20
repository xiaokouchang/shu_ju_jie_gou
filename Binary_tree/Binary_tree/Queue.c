#define _CRT_SECURE_NO_WARNINGS 1 

#include "Queue.h"

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
	pq->size = 0;
	QueueLoad(pq);
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (newnode == NULL)
	{
		perror("newnode");
		return;
	}
	newnode->data = x;
	newnode->next = NULL;
	if (pq->head == NULL)
	{
		assert(pq->tail == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head != NULL);
	//方法1
	//QNode* next = pq->head->next;
	//free(pq->head);
	//pq->head = next;
	//if (pq->head == NULL)
	//{
	//	pq->tail = NULL;
	//}
	//方法2
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->tail = pq->head = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
	pq->size--;
}
int QueueSize(Queue* pq)
{
	assert(pq);
	return pq->size;
}
bool QueueEmpty(Queue* pq)
{
	assert(pq);
	//return pq->size == 0;
	return pq->head == NULL && pq->tail == NULL;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));
	return pq->tail->data;
}



void QueuePrint(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	if (QueueEmpty(pq))
	{
		printf("队列为空\n");
		return;
	}
	else
	{
		while (cur)
		{
			printf("%d ", cur->data);
			cur = cur->next;
		}
		printf("\n");
	}
}
void QueueMiddlePush(void(*pf)(Queue* pq, QDataType x), Queue* pq)
{
	int x = 0;
	printf("请输入你想要插入的元素:>");
	scanf("%d", &x);
	pf(pq, x);
	QueuePrint(pq);
}

void QueueMiddle(Queue* pq, int num)
{
	if (num == 2)
	{
		if (QueueEmpty(pq))
		{
			printf("队列已空,无法出队\n");
		}
		else
		{
			printf("出队元素:%d\n", QueueFront(pq));
			QueuePop(pq);
		}
	}
	else if (num == 4)
	{
		if (QueueEmpty(pq))
		{
			printf("队列已空,无队头元素\n");
		}
		else
		{
			printf("队头元素:%d\n", QueueFront(pq));
		}
	}
	else if (num == 5)
	{
		if (QueueEmpty(pq))
		{
			printf("队列已空,无队尾元素\n");
		}
		else
		{
			printf("队尾元素:%d\n", QueueBack(pq));
		}
	}
	else
	{
		if (QueueEmpty(pq))
		{
			printf("队列已空\n");
		}
		else
		{
			printf("队列不为空\n");
		}
	}
}

void QueueSave(Queue* pq)
{
	assert(pq);
	FILE* pf = fopen("queue.txt", "w");
	if (pf == NULL)
	{
		perror("无法打开文件");
		return;
	}
	QNode* cur = pq->head;
	while (cur)
	{
		fprintf(pf, "%d ", cur->data);
		cur = cur->next;
	}
	fclose(pf);
	pf = NULL;
	printf("保存文件成功\n");
}

void QueueLoad(Queue* pq)
{
	assert(pq);
	FILE* pf = fopen("queue.txt", "r");
	if (pf == NULL)
	{
		//文件不存在或无法打开,可能是第一次运行
		return;
	}
	int data = 0;
	while (fscanf(pf, "%d", &data) != EOF)
	{
		QueuePush(pq, data);
	}
	fclose(pf);
	pf = NULL;
}

void QueuePrintDestory(Queue* pq)
{
	assert(pq);
	while (!QueueEmpty(pq))
	{
		printf("%d ", QueueFront(pq));
		QueuePop(pq);
	}
	printf("\n");
}