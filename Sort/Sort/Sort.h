#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <string.h>
#include "stack.h"
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//直接插入排序
//元素集合越接近有序,直接插入排序算法的时间效率越高
//O(N^2)的排序里最好
//时间复杂度:最坏(逆序):O(N^2)   最好(有序):O(n)
//空间复杂度:O(1),它是一种稳定的排序算法
//稳定性:稳定
void InsertSort(int* a, int n);

//冒泡排序
//属于简单排序算法,原理直观但效率较低(时间复杂度为O(n^2))
//稳定排序(相同元素的相对顺序在排序后保持不变)
void BubbleSort(int* a, int n);

//希尔排序(缩小增量排序)
//希尔排序法又称缩小增量法
//先选定一个整数,把待排序文件中所有记录分成个组,所有距离为gap的记录分在同一组内,并对每一组内的记录进行排序
//然后取重复上述分组和排序的工作
//当到达=1时,所有记录在统一组内排好序
//gap越大,跳的越快,越不接近有序
//gap越小,跳的越慢,越接近有序
void ShellSort(int* a, int n);

//选择排序
//最好最坏都是O(N*N)
void SelectSort(int* a, int n);

//输出数组
void PrintArray(int* a, int n);

//向下调整
void AdjustDown(HPDataType* a, int n, int parent);

//向上调整
void AdjustUP(HPDataType* a, int child);

//堆排序
void HeapSort(int* a, int n);

//快速排序
//任取待排序元素序列中的某元素作为基准值,按照该排序码将待排序集合分割成两子序列,
//左子序列中所有元素均小于基准值,右子序列中所有元素均大于基准值,
//然后最左右子序列重复该过程,直到所有元素都排列在相应位置上为止。
//hoare版本
void QuickSort1(int* a, int left, int right);

//挖坑法
void QuickSort2(int* a, int left, int right);

//双指针
void QuickSort3(int* a, int left, int right);

//小区间优化
void QuickSort4(int* a, int left, int right);

//快速排序非递归
void QuickSortNone(int* a, int left, int right);

//归并排序(后序遍历)
//可以用作外排序,即在磁盘中排序
//两个有序空间归并:
//依次比较,小的尾插到新空间
void MergeSort(int* a, int n);

//子函数
void _MergeSort(int* a, int begin, int end, int* tmp);

//归并排序非递归
void MergeSortNone1(int* a, int n);

void MergeSortNone2(int* a, int n);

//非比较排序
//适用于一些特殊情况
//计数排序
//适合范围集中,且范围不大的整型数组排序
//不适合范围分散,或者非整形的排序
//1.统计相同元素出现次数(提高效率)
//2.根据统计的结果将序列回收到原来的序列中
void CountSort(int* a, int n);

//基数排序(实际中没什么应用)

//桶排序(实际中没什么应用)