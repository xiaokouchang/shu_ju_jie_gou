#define _CRT_SECURE_NO_WARNINGS 1 
//堆的性质
//1、堆中某个结点的值总是不大于或不小于其父结点的值
//2、堆总是一棵完全二叉树
//没有限制左孩子和右孩子之间的关系,所以堆不是有序的
//根结点最大的堆叫做最大堆或大根堆
//根结点最小的堆叫做最小堆或小根堆
//小根堆:树中所有的父亲都小于或等于孩子
//大根堆:树中所有的父亲都大于或等于孩子
#include "Heap.h"
void test()
{
	HP hp;
	HeapInit(&hp);
	HeapPush(&hp, 4);
	HeapPush(&hp, 18);
	HeapPush(&hp, 42);
	HeapPush(&hp, 12);
	HeapPush(&hp, 2);
	HeapPush(&hp, 3);
	int k = 0;
	scanf("%d", &k);
	while (!HeapEmpty(&hp) && k--)//走k次
	{
		printf("%d ", HeapTop(&hp));
		HeapPop(&hp);
	}
	printf("\n");
}
//堆排序:O(N*long2(N))
//冒泡排序:O(N*N)
void HeapSort(int* a, int n)
{
	//堆排序
	//方法1 --- 向上调整建堆
	//时间复杂度:O(Nlog2(N))
	int i = 0;
	for (i = 1; i < n; i++)
	{
		AdjustUP(a, i);
	}
	//方法2 --- 向下调整建堆 
	//排升序 --- 建大堆
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		end--;
	}
	//排降序 --- 建小堆
}
void test1()
{
	int a[10] = { 1,3,5,7,6,4,9,2,8,0 };//对数组排序
	HeapSort(a, 10);
}
int main()
{
	//test();
	test1();
	return 0;
}