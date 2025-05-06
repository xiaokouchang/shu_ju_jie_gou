#define _CRT_SECURE_NO_WARNINGS 1 

#include "SeqList.h"
void SLInit(SL* ps)
{
	assert(ps);
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
	assert(ps);
	//空间是野指针
	//数组指向的空间越界
	free(ps->a);
	ps->a = NULL;
	ps->capacity = 0;
	ps->size = 0;
}


void SLPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0;i < ps->size;i++)
	{
		printf("%d ", ps->a[i]);
	}
	printf("\n");
}

void SLCheckCapacity(SL* ps)
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

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLCheckCapacity(ps);
	}
	ps->a[ps->size++] = x;
	/*ps->a[ps->size] = x;
	ps->size++;*/
}


//不释放空间,要释放空间只能一块一块释放
void SLPopBack(SL* ps)
{
	assert(ps);
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
void SLPushFront(SL* ps, SLDataType x)
{
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLCheckCapacity(ps);
	}
	int end = ps->size - 1;
	while (end >= 0)
	{
		ps->a[end + 1] = ps->a[end];
		end--;
	}
	ps->a[0] = x;
	ps->size++;
}

void SLPopFront(SL* ps)
{
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
}


void SLInsert(SL* ps, int pos, SLDataType x)
{
	//memove
	//中间切开,创建1个空间,插入1个数据是不能的
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);//=0为头插,=size为尾插
	if (ps->size == ps->capacity)
	{
		SLCheckCapacity(ps);
	}
	int insert = ps->size - 1;//insert =ps->size对？
	while (pos <= insert)
	{
		ps->a[insert + 1] = ps->a[insert];
		insert--;
	}
	ps->a[pos] = x;
	ps->size++;
}


void SLErase(SL* ps, int pos)
{

}