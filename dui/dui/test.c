#define _CRT_SECURE_NO_WARNINGS 1 
//堆的性质
//1、堆中某个结点的值总是不大于或不小于其父结点的值
//2、堆总是一棵完全二叉树
//没有限制左孩子和右孩子之间的关系,所以堆不是有序的
//根结点最大的堆叫做最大堆或大根堆
//根结点最小的堆叫做最小堆或小根堆
//小根堆:树中所有的父亲都小于或等于孩子
//大根堆:树中所有的父亲都大于或等于孩子
//#include "Heap.h"
//void test()
//{
//	HP hp;
//	HeapInit(&hp);
//	HeapPush(&hp, 4);
//	HeapPush(&hp, 18);
//	HeapPush(&hp, 42);
//	HeapPush(&hp, 12);
//	HeapPush(&hp, 2);
//	HeapPush(&hp, 3);
//	int k = 0;
//	scanf("%d", &k);
//	while (!HeapEmpty(&hp) && k--)//走k次
//	{
//		printf("%d ", HeapTop(&hp));
//		HeapPop(&hp);
//	}
//	printf("\n");
//}
////堆排序:O(N*long2(N))
////冒泡排序:O(N*N)
//void HeapSort(int* a, int n)
//{
//	//最后一层有二叉树一半的节点
//	//堆排序
//	//方法1 --- 向上调整建堆
//	//时间复杂度:O(N*log2(N))
//	//2*T(N)=		2^2*1+2^3*2+...+2^(h-2)*(h-3)+2^(h-1)*(h-2)+2^(h)*(h-1)
//	//T(N)  = 2^1*1+2^2*2+...+2^(h-2)*(h-2)+2^(h-1)*(h-1)
//	//T(N)  = -2^1-2^2-2^3-....-2^(h-2)-2^(h-1)+2^h*(h-1)
//	//T(N)  = -2^0-2^1-2^2-2^3-....-2^(h-2)-2^(h-1)+2^0-2^h+2^h*h
//	//T(N)  = -2^h+2+2^h*h-2^h
//	//N=2^h-1
//	int i = 0;
//	for (i = 1; i < n; i++)
//	{
//		AdjustUP(a, i);
//	}
//	//建堆 --- 向下调整建堆
//	//时间复杂度:O(N-log2(N)) = O(N)
//	for (i = (n - 1 - 1) / 2; i >= 0; i--)//n-1是下标
//	{
//		AdjustDown(a, n, i);
//	}
//	//排升序 --- 建大堆
//	//时间复杂度:O(N*log2(N))
//	int end = n - 1;
//	while (end > 0)
//	{
//		Swap(&a[end], &a[0]);
//		AdjustDown(a, end, 0);
//		end--;
//	}
//	//排降序 --- 建小堆
//}
//void test1()
//{
//	int a[10] = { 1,3,5,7,6,4,9,2,8,0 };//对数组排序
//	HeapSort(a, 10);
//}
//int main()
//{
//	//test();
//	//test1();
//	TestTopk();
//	return 0;
//}


//Top-k问题
//找出N个数里面最大的前k个
//1.建大堆---建N个的大堆
//2.再pop k次
//1G=1024MB=1024*1024*1024Byte --- 大约10亿Byte
//100亿个整数占40G的内存
//内存存不下,数据是在磁盘文件中


//遍历剩下的数据,如果这个数据比堆顶的数据大,就代替它进堆(向下调整)
//最后这个小堆的数据就是最大的前k个
//1.建小堆---用a中前k个元素建堆
//2.将剩余n-k个元素依次与堆顶元素交换,不满则替换
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>
#include <time.h>
void Swap(int* p1, int* p2)
{
	int tmp = *p1;
	*p1 = *p2;
	*p2 = tmp;
}
void AdjustDown(int* a, int n, int parent)
{
	//最坏log2N(堆的高度)
	int child = parent * 2 + 1;
	while (child < n)
	{
		//选出左右孩子中大的那一个
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
void PrintTopK(const char* file, int k)
{
	//1. 建堆 --- 用a中前k个元素建堆
	int* topk = (int*)malloc(sizeof(int) * k);
	if (topk == NULL)
	{
		perror("malloc fail");
		return;
	}
	FILE* fout = fopen(file, "r");
	if (fout == NULL)
	{
		perror("fopen fail");
		return;
	}
	//读取文件中的前k个数据建小堆
	int i = 0;
	for (i = 0; i < k; i++)
	{
		fscanf(fout, "%d", &topk[i]);
	}
	//建堆
	for (i = (k - 2) / 2; i >= 0; i--)
	{
		AdjustDown(topk, k, i);
	}
	//2. 将剩余n-k个元素依次与堆顶元素交换,不满则则替换
	int val = 0;
	int ret = fscanf(fout, "%d", &val);
	while (ret != EOF)
	{
		if (val > topk[0])
		{
			topk[0] = val;
			AdjustDown(topk, k, 0);
		}
		ret = fscanf(fout, "%d", &val);
	}
	for (i = 0; i < k; i++)
	{
		printf("%d ", topk[i]);
	}
	printf("\n");
	free(topk);
	fclose(fout);
	fout = NULL;
}
void CreateNData()
{
	int n = 10000;
	srand(time(0));
	const char* file = "num.txt";
	FILE* fin = fopen(file, "w");
	if (fin == NULL)
	{
		perror("file fail");
		return;
	}
	for (size_t i = 0; i < n; ++i)
	{
		int x = rand() % 10000;
		fprintf(fin, "%d\n", x);
	}
	PrintTopK(file, 10);
	fclose(fin);
	fin = NULL;
}
int main()
{
	//CreateNData();
	PrintTopK("num.txt", 10);
	return 0;
}