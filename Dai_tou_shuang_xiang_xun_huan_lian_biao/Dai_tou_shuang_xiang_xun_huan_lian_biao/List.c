#define _CRT_SECURE_NO_WARNINGS 1 

#include "List.h"

LTNode* LTInit()
{
	LTNode* phead = BuyListNode(-1);
	phead->next = phead;
	phead->prev = phead;
	LTLoad(phead);
	return phead;
}
void LTDestory(LTNode* phead)
{
	assert(phead);
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* curnext = cur->next;
		free(cur);
		cur = curnext;
	}
	free(phead);
}
LTNode* LTFind(LTNode* phead,LTDataType x)
{
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == x)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
LTNode* BuyListNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (newnode == NULL)
	{
		perror("newnode");
		return NULL;
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->data = x;
	return newnode;
}
void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);//一定不为空,空可能是传错了
	//方法1
	LTNode* newnode = BuyListNode(x);
	LTNode* tail = phead->prev;
	//phead         tail newnode
	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
	//方法2
	//newnode phead    tail
	//LTInsertFront(phead, x);
}
bool LTEmpty(LTNode* phead)
{
	assert(phead);
	//方法1
	//if (phead->next == phead)
	//{
	//	return true;
	//}
	//else
	//{
	//	return false;
	//}
	//方法2
	return phead->next != phead;
}
void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));
	//phead head tail
	//方法1
	//LTNode* tail = phead->prev;
	//LTNode* tailprev = tail->prev;
	//tailprev->next = phead;
	//phead->prev = tailprev;
	//free(tail);
	//tail = NULL;
	//方法2
	LTErase(phead, phead->prev);
}
void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);//一定不为空,空可能是传错了
	LTNode* newnode = BuyListNode(x);
	//phead newnode head
	//方法1---可以随便换顺序
	LTNode* head = phead->next;
	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = head;
	head->prev = newnode;
	//方法2---不能随便换顺序
	//newnode->next = phead->next;
	//phead->next->prev = newnode;
	//phead->next = newnode;
	//newnode->prev = phead;
	//方法3
	//LTInsertFront(phead->next, x);
}

//头删
void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(LTEmpty(phead));
	//phead head headnext
	//方法1
	//LTNode* head = phead->next;
	//phead->next = head->next;
	//head->prev = phead;
	//free(head);
	//head = NULL;
	//方法2
	LTErase(phead, phead->next);
}
void LTPrint(LTNode* phead)
{
	assert(phead);
	printf("<=head=>");
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d<=>", cur->data);
		cur = cur->next;
	}
	printf("\n");
}

void LTInsertFront(LTNode* pos, LTDataType x)
{
	assert(pos);
	LTNode* prev = pos->prev;
	LTNode* newnode = BuyListNode(x);
	//prev newnode pos
	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}


void LTInsertAfter(LTNode* pos, LTDataType x)
{
	assert(pos);
	//pos newnode posnext
	LTNode* posnext = pos->next;
	LTNode* newnode = BuyListNode(x);
	pos->next = newnode;
	newnode->prev = pos;
	newnode->next = posnext;
	posnext->prev = newnode;
}


void LTEraseFront(LTNode* phead, LTNode* pos)
{
	assert(pos);
	assert(pos->prev && pos != phead);
	// posprev pos
	LTNode* posprev = pos->prev;
	posprev->prev->next = pos;
	pos->prev = posprev->prev;
	free(posprev);
	posprev = NULL;
}

void LTErase(LTNode* phead, LTNode* pos)
{
	assert(pos);
	assert(pos != phead);
	// posprev pos 
	LTNode* posprev = pos->prev;
	posprev->next = pos->next;
	pos->next->prev = posprev;
	free(pos);
	pos = NULL;
}

void LTEraseBack(LTNode* phead, LTNode* pos)
{
	assert(pos);
	assert(pos->next && pos->next != phead);
	//pos posnext
	LTNode* posnext = pos->next;
	posnext->next->prev = pos;
	pos->next = posnext->next;
	free(posnext);
	posnext = NULL;
}

void LTLoad(LTNode* phead)
{
	FILE* pf = fopen("List.txt", "r");
	if (pf == NULL)
	{
		perror("pf");
		return;
	}
	int num = 0;
	while (fscanf(pf, "%d", &num) == 1)
	{
		LTPushBack(phead, num);
	}
	fclose(pf);
	pf = NULL;
}
void LTSave(LTNode* phead)
{
	FILE* pf = fopen("List.txt", "w");
	if (pf == NULL)
	{
		perror("pf");
		return;
	}
	LTNode* cur = phead->next;
	while (cur != phead)
	{
		fprintf(pf, "%d ", cur->data);
		cur = cur->next;
	}
	fclose(pf);
	pf = NULL;
	printf("保存双向循环链表成功\n");
}

void LTPushMiddle(void(*pf)(LTNode* phead, LTDataType x), LTNode* phead)
{
	LTDataType x = 0;
	printf("请输入你想要插入的数字:>\n");
	scanf("%d", &x);
	pf(phead, x);
	LTPrint(phead);
}

void LTMiddlePos(int(*pf)(LTNode* phead, LTDataType x), LTNode* phead,LTDataType num)
{
	LTDataType x = 0;
	LTDataType y = 0;
	if (num == 11)
	{
		printf("请输入你想要查找哪个数字:>");
		scanf("%d", &x);
		LTNode* ret = LTFind(phead, x);
		if (ret == NULL)
		{
			printf("找不到\n");
		}
		else
		{
			printf("%d\n", ret->data);
			return;
		}
	}
	LTPrint(phead);
	if (num == 5)
	{
		printf("请输入你想要插入哪个数字的前面:>");
		scanf("%d", &x);
		printf("请输入你想要插入的数字:>");
		scanf("%d", &y);
		LTNode* ret = LTFind(phead, x);
		pf(ret, y);
	}
	else
	{
		printf("请输入你想要插入哪个数字的后面:>");
		scanf("%d", &x);
		printf("请输入你想要插入的数字:>");
		scanf("%d", &y);
		LTNode* ret = LTFind(phead, x);
		pf(ret, y);
	}
	LTPrint(phead);
}


void LTMiddleErase(int(*pf)(LTNode* phead, LTNode* pos), LTNode* phead, LTDataType num)
{
	int x = 0;
	LTPrint(phead);
	if (num == 7)
	{
		printf("请输入你想要删除哪个数字前面的数字:>");
		scanf("%d", &x);
		LTNode* ret = LTFind(phead, x);
		pf(phead, ret);
	}
	else if (num == 8)
	{
		printf("请输入你想要删除哪个数字:>");
		scanf("%d", &x);
		LTNode* ret = LTFind(phead, x);
		pf(phead, ret);
	}
	else
	{
		printf("请输入你想要删除哪个数字后面的数字:>");
		scanf("%d", &x);
		LTNode* ret = LTFind(phead, x);
		pf(phead, ret);
	}
	LTPrint(phead);
}
