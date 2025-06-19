#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"

//升序
void InsertSort(int* a, int n)
{
	//将tmp插入到[0, end]的区间中
	int i = 0;
	for (i = 1; i < n; i++)
	{
		int end = i - 1;
		int tmp = a[i];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				end--;
			}
			else
			{
				break;
			}
		}
		a[end + 1] = tmp;
	}
}

void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				int temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//gap大于1时是预排序,gap=1时是直接插入排序
void ShellSort(int* a, int n)
{
	int i = 0;
	int first = 0;
	int gap = n;
	while (gap > 1)
	{
		//gap /= 2;//gap最后是1,就是直接插入排序,log2(N)
		gap = gap / 3 + 1;//+1保证最后一次一定是1,log3(N)
		for (i = 0; i < n - gap; i++)//最开始gap很大
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)//刚开始次数少,一次跳跃n/2步
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
				{
					break;
				}
			}
			a[end + gap] = tmp;
		}
		PrintArray(a, n);
	} 
}
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
void SelectSort(int* a, int n)
{
	//最小的数放在左边,最大的数放在右边
	int i = 0;
	int left = 0;
	int right = n - 1;
	while (left < right)
	{
		int mini = left;
		int maxi = left;
		for (i = left + 1; i <= right; i++)
		{
			if (a[i] < a[mini])
			{
				mini = i;
			}
			if (a[i] > a[maxi])
			{
				maxi = i;
			}
		}
		Swap(&a[left], &a[mini]);
		//left和maxi重叠,交换后修正一下
		if (left == maxi)
		{
			maxi = mini;
		}
		Swap(&a[right], &a[maxi]);
		left++;
		right--;
	}
}


void PrintArray(int* a, int n)
{
	int i = 0;
	for (i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}