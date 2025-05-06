#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"
void SLInit(SL* ps)
{
	ps->a = (SLDataType*)malloc(sizeof(SLDataType) * INIT_CAPACITY);
	if (ps->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	ps->size = 0;
	ps->capacity = INIT_CAPACITY;
}


void SLDestory(SL* ps)
{
	//空间是野指针
	//数组指向的空间越界
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}


void SLPrint(SL* ps)
{
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLPushBack(SL* ps, SLDataType x)
{
	if (ps->size == ps->capacity)
	{
		//扩容
		SLDataType* tmp = (SLDataType*)realloc(ps->a, ps->capacity * 2 * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		ps->a = tmp;//不写这句代码的话是原地扩容,在原来的地址上增加
		ps->capacity *= 2;
	}
	ps->a[ps->size++] = x;
	/*ps->a[ps->size] = x;
	ps->size++;*/
}


//不释放空间,要释放空间只能一块一块释放
void SLPopBack(SL* ps)
{
	//方法1
	//assert(ps->size > 0);
	//方法2
	if (ps->size == 0)
	{
		return;
	}
	//ps->a[ps->size - 1] = 0;
	ps->size--;
}
void SLPushFront(SL* s, SLDataType x)
{

}
