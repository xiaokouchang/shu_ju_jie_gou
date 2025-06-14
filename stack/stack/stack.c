#define _CRT_SECURE_NO_WARNINGS 1 

#include "stack.h"

void STInit(ST* ps)
{
	assert(ps);
	ps->a = (STDataType*)malloc(sizeof(STDataType) * 4);
	if (ps->a == NULL)
	{
		perror("ps->a");
		return;
	}
	ps->capacity = 4;
	ps->top = 0;          //top是栈顶元素的下一个位置
	//ps->top = -1;         //top是栈顶元素
	STLoad(ps);
}

void STDestroy(ST* ps)
{
	assert(ps);
	free(ps->a);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
}
void STPush(ST* ps, STDataType x)
{
	assert(ps);
	if (ps->top == ps->capacity)
	{
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * ps->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;
		ps->capacity *= 2;
	}
	ps->a[ps->top] = x;
	ps->top++;
}

void STPop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	ps->top--;
}

int STSize(ST* ps)
{
	assert(ps);
	return ps->top;
}

bool STEmpty(ST* ps)
{
	assert(ps);
	return ps->top == 0;
}

STDataType STTop(ST* ps)
{
	assert(ps);
	assert(!STEmpty(ps));
	return ps->a[ps->top - 1];
}


void STPrint(ST* ps)
{
	assert(ps);
	int i = 0;
	while (i < ps->top)
	{
		printf("%d ", ps->a[i]);
		i++;
	}
	printf("\n");
}


void STSave(ST* ps)
{
	assert(ps);
	FILE* pf = fopen("stack.txt", "w");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}
	int i = 0;
	for (i = 0;i < ps->top;i++)
	{
		fprintf(pf, "%d ", ps->a[i]);
	}
	fclose(pf);
	pf = NULL;
	printf("保存数据成功\n");
}

void STLoad(ST* ps)
{
	assert(ps);
	FILE* pf = fopen("stack.txt", "r");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}
	int data = 0;
	while (fscanf(pf, "%d", &data) == 1)
	{
		STPush(ps, data);
	}
	fclose(pf);
	pf = NULL;
}


void STMiddle(void(*pf)(ST* ps, STDataType x),ST* ps)
{
	assert(ps);
	int x = 0;
	printf("请输入你想要插入的数字:>");
	scanf("%d", &x);
	pf(ps, x);
	STPrint(ps);
}