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
	LoadSeqList(ps);
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
	printf("销毁成功\n");
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
	printf("尾插\n");
	//方法1
	assert(ps);
	if (ps->size == ps->capacity)
	{
		SLCheckCapacity(ps);
	}
	ps->a[ps->size++] = x;
	//ps->a[ps->size] = x;
	//ps->size++;
	//方法2
	//SLBackInsert(ps, ps->size, x);
}


//不释放空间,要释放空间只能一块一块释放
void SLPopBack(SL* ps)
{
	assert(ps);
	printf("尾删\n");
	//方法1
	//assert(ps->size > 0);
	//方法2
	if (ps->size == 0)
	{
		return;
	}
	//ps->a[ps->size - 1] = 0;
	ps->size--;
	//方法2
	//SLErase(ps, ps->size);
}
void SLPushFront(SL* ps, SLDataType x)
{
	printf("头插\n");
	//方法1
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
	//方法2
	//SLBackInsert(ps, 0, x);
}

void SLPopFront(SL* ps)
{
	printf("头删\n");
	//方法1
	assert(ps);
	assert(ps->size > 0);
	int begin = 1;
	while (begin < ps->size)
	{
		ps->a[begin - 1] = ps->a[begin];
		begin++;
	}
	ps->size--;
	//方法2
	//SLErase(ps, 0);
}


void SLErase(SL* ps, int pos)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	int erase = pos - 1;
	while (erase <= ps->size - 1)
	{
		ps->a[erase] = ps->a[erase + 1];
		erase++;
	}
	ps->size--;
	printf("消除成功\n");
}


int SLFind(SL* ps, SLDataType x)
{
	assert(ps);
	printf("查找\n");
	int i = 0;
	int flag = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (ps->a[i] == x)
		{
			return i;
		}
	}
	return -1;
}


void SeqListValue(int(*pf)(SL* ps, SLDataType x), SL* ps)
{
	int x = 0;
	printf("请输入1个操作数:>\n");
	scanf("%d", &x);
	pf(ps, x);
	SLPrint(ps);
}

void SLFrontInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	if (ps->capacity == ps->size)
	{
		SLCheckCapacity(ps);
	}
	int tmp = ps->size - 1;
	while (tmp >= pos - 1)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[pos - 1] = x;
	ps->size++;
}
void SLBackInsert(SL* ps, int pos, SLDataType x)
{
	assert(ps);
	assert(pos >= 0 && pos <= ps->size);
	if (ps->capacity == ps->size)
	{
		SLCheckCapacity(ps);
	}
	int tmp = ps->size - 1;
	while (tmp >= pos)
	{
		ps->a[tmp + 1] = ps->a[tmp];
		tmp--;
	}
	ps->a[pos] = x;
	ps->size++;
}
void SeqListInsert(int(*pf)(SL* ps, SLDataType x), SL* ps, int num)
{
	int x = 0;
	int y = 0;
	if (num == 5)
	{
		printf("请输入你要插入数的位置:>\n");
		scanf("%d", &x);
		printf("请输入你要插入的数字:>\n");
		scanf("%d", &y);
		SLBackInsert(ps, x, y);
		SLPrint(ps);
	}
	else if (num == 6)
	{
		printf("请输入你要插入的数字:>\n");
		scanf("%d", &x);
		printf("请输入你要插入的数字的位置:>\n");
		scanf("%d", &y);
		SLFrontInsert(ps, y, x);
		SLPrint(ps);
	}
	else if (num == 7)
	{
		printf("请输入你要擦除数的位置:>\n");
		scanf("%d", &x);
		pf(ps, x);
		SLPrint(ps);
	}
	else
	{
		printf("请输入你要查找的数字:>\n");
		scanf("%d", &x);
		int ret = pf(ps, x);
		if (ret != -1)
		{
			printf("下标是:%d\n", ret);
		}
		else
		{
			printf("查找的数字不存在\n");
		}
	}
}


void SaveSeqList(SL* ps)
{
	FILE* pf = fopen("SeqList.txt", "wb");
	if (pf == NULL)
	{
		perror("SaveSeqList");
		return;
	}
	else
	{
		int i = 0;
		for (i = 0; i < ps->size; i++)
		{
			fwrite(ps->a + i, sizeof(SLDataType), 1, pf);
		}
		fclose(pf);
		pf = NULL;
		printf("保存文件成功\n");
	}
}


void LoadSeqList(SL* ps)
{
	//打开文件
	FILE* pf = fopen("SeqList.txt", "rb");
	if (NULL == pf)
	{
		perror("LoadSeqList");
		return;
	}
	else
	{
		//读数据
		SLDataType tmp = 0;
		int i = 0;
		while (fread(&tmp, sizeof(SLDataType), 1, pf))
		{
			if (ps->size == ps->capacity)
			{
				SLCheckCapacity(ps);
			}
			ps->a[i] = tmp;
			ps->size++;
			i++;
		}
		fclose(pf);
		pf = NULL;
	}
}