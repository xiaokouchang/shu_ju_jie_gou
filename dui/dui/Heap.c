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
	php->a = (HPDataType)malloc(sizeof(HPDataType) * 4);
	if (php->a == NULL)
	{
		perror("malloc fail");
		return;
	}
	php->size = 0;
	php->capacity = 4;
}

void Swap(HPDataType* p1, HPDataType* p2)
{
	HPDataType tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustUP(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (parent >= 0)
	{
		if (a[child] > a[child])
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
		HPDataType* tmp = (HPDataType)realloc(php->a, sizeof(HPDataType) * php->capacity * 2);
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