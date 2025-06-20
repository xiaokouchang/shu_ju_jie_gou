#define _CRT_SECURE_NO_WARNINGS 1 
//顺序存储
//二叉树顺序存储在物理上是一个数组,在逻辑上是一颗二叉树。
//       0(A)
//  1(B)      2(C)
//3(D) 4(E) 5(F) 6(G)
//A B C D E F G
//0 1 2 3 4 5 6
//必须从0开始
//表示二叉树的值在数组位置中的父子下标关系:
//parent = (child-1)/2
//leftchild = parent*2+1
//rightchild = parent*2+2
//数组存储表示二叉树只适合完全二叉树


#include "Heap.h"

void HeapInit(HP* php)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = 0;
	php->capacity = 4;
	HeapLoad(php);
}

void HeapSave(HP* php)
{
	assert(php);
	FILE* pf = fopen("Heap.txt", "w");
	if (pf == NULL)
	{
		perror("fopen fail");
		return;
	}
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		fprintf(pf, "%d ", php->a[i]);
	}
	fclose(pf);
	pf = NULL;
	printf("保存文件成功\n");
}
void HeapLoad(HP* php)
{
	assert(php);
	FILE* pf = fopen("Heap.txt", "r");
	if (pf == NULL)
	{
		perror("Load fail");
		return;
	}
	int num = 0;
	int index = 0;
	while (fscanf(pf, "%d", &num) == 1)
	{
		HeapPush(php, num);
	}
	fclose(pf);
	pf = NULL;
}

//使用数组初始化建堆
void HeapInitArray(HP* php, int* a, int n)
{
	assert(php);
	php->a = (HPDataType*)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = n;
	php->capacity = n;
	//建堆
	int i = 0;
	for (i = (n - 2) / 2; i >= 0; i--)
	{
		AdjustDown(php->a, php->size, i);
	}
}


void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}


//除了child这个位置,前面的数据构成了堆
void AdjustUP(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
		{
			break;
		}
	}
}

void HeapPush(HP* php, HPDataType x)
{
	assert(php);
	if (php->capacity == php->size)
	{
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
		if (tmp == NULL)
		{
			perror("realloc fail");
			return;
		}
		php->a = tmp;
		php->capacity *= 2;
	}
	php->a[php->size] = x;
	php->size++;
	AdjustUP(php->a, php->size - 1);
}
////左右子树都是大堆/小堆
//void AdjustDown(HPDataType* a, int n, int parent)
//{
//	//最坏log2N(堆的高度)
//	int child = parent * 2 + 1;
//	while (child < n)
//	{
//		//选出左右孩子中大的那一个
//		if (child + 1 < n && a[child + 1] > a[child])
//		{
//			child++;
//		}
//		if (a[child] > a[parent])
//		{
//			Swap(&a[child], &a[parent]);
//			parent = child;
//			child = parent * 2 + 1;
//		}
//		else
//		{
//			break;
//		}
//	}
//}
//小根堆
void AdjustDown(HPDataType* a, int n, int parent)
{
	//最坏log2N(堆的高度)
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中小的那一个
		if (child + 1 < n && a[child + 1] < a[child])
		{
			child++;
		}
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			break;
		}
	}
}
void HeapPop(HP* php)
{
	assert(!HeapEmpty(php));
	assert(php);
	//删除数据
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(HP* php)
{
	assert(php);
	return php->a[0];
}

int HeapSize(HP* php)
{
	assert(php);
	return php->size;
}

bool HeapEmpty(HP* php)
{
	assert(php);
	return php->size == 0;
}
void HeapMiddle(HPDataType(*pf)(HP* php), HP* php, int num)
{
	assert(php);
	if (num == 4)
	{
		int ret = pf(php);
		printf("堆顶元素是:%d\n", ret);
	}
	else if (num == 5)
	{
		int ret = pf(php);
		printf("堆的元素个数是:%d\n", ret);
	}
	else
	{
		bool ret = pf(php);
		if (ret == true)
		{
			printf("堆是空\n");
		}
		else
		{
			printf("堆不是空\n");
		}
	}
}

void HeapDestory(HP* php)
{
	assert(php);
	free(php->a);
	php->a = NULL;
	php->capacity = 0;
	php->size = 0;
}

void HeapPushMiddle(void(*pf)(HP* php, HPDataType x), HP* php)
{
	assert(php);
	int x = 0;
	printf("请输入你想要插入的数字:>");
	scanf("%d", &x);
	pf(php, x);
	HeapPrint(php);
}

void HeapPrint(HP* php)
{
	assert(php);
	int i = 0;
	for (i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}


