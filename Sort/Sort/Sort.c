#define _CRT_SECURE_NO_WARNINGS 1

#include "Sort.h"
void Swap(int* a, int* b)
{
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
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

//最坏:O(N^2)
//最好:O(N)
void BubbleSort(int* a, int n)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < n - 1; i++)
	{
		bool exchange = false;
		for (j = 0; j < n - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				exchange = true;
			}
		}
		if (exchange == false)
		{
			break;
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
	} 
}
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
//堆排序每次需要调log2(N)次
void HeapSort(int* a, int n)
{
	int i = 0;
	//for (i = 1; i < n; i++)
	//{
	//	AdjustUP(a, i);
	//}
	////堆排序
	//int end = n - 1;
	//while (end > 0)
	//{
	//	Swap(&a[end], &a[0]);
	//	AdjustDown(a, end, 0);
	//	end--;
	//}
	for (i = (n - 1 - 1) / 2; i >= 0; i--)//n-1是最后数字的下标
	{
		AdjustDown(a, n, i);
	}
	int end = n - 1;
	while (end > 0)
	{
		Swap(&a[end], &a[0]);
		AdjustDown(a, end, 0);
		end--;
	}
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
int PartSort1(int* a, int left, int right)
{
	//随机选keyi
	//int randi = left + (rand() % (right - left));
	//Swap(&a[left], &a[randi]);
	//三数取中(有序)---开始中间最后三个数中选不是最小也不是最大的数
	int midi = GetMidNumi(a, left, right);
	if (midi != left)
	{
		Swap(&a[midi], &a[left]);
	}
	int keyi = left;
	while (left < right)
	{
		//右边找小
		while (left < right && a[right] >= a[keyi])
		{
			right--;
		}
		//左边找大
		while (left < right && a[left] <= a[keyi])
		{
			left++;
		}
		Swap(&a[left], &a[right]);
	}
	Swap(&a[keyi], &a[left]);
	keyi = left;
	return keyi;
}
int PartSort2(int* a, int left, int right)
{
	int key = a[left];
	int hole = left;
	while (left < right)
	{
		while (left < right && a[right] >= key)
		{
			right--;
		}
		a[hole] = a[right];
		hole = right;
		while (left < right && a[left] <= key)
		{
			left++;
		}
		a[hole] = a[left];
		hole = left;
	}
	a[hole] = key;
	return hole;
}
int PartSort3(int* a, int left, int right)
{
	//左闭右闭
	int keyi = left;
	int prev = left;
	int cur = left + 1;
	while (cur <= right)
	{
		if (a[cur] <= a[keyi] && ++prev != cur)
		{
			Swap(&a[prev], &a[cur]);
		}
		cur++;
	}
	Swap(&a[prev], &a[keyi]);
	keyi = prev;
	return prev;
}
//有序都很坏
//keyi越接近中间值,效率越高
int GetMidNumi(int* a, int left, int right)
{
	//三目操作符可读性差
	int mid = (left + right) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
		{
			return mid;
		}
		else if(a[left] > a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
	else  //(a[left] > a[mid])
	{
		if (a[mid] > a[right])
		{
			return mid;
		}
		else if (a[left] < a[right])
		{
			return left;
		}
		else
		{
			return right;
		}
	}
}
//时间复杂度:O(N*log2(N))
//左边做keyi,右边先走,保证相遇位置比keyi要小或者就是key的位置
//相遇:
//R找小,L没有找到大,L遇到R
//R找小,找不到,直接跟L相遇了,要么就是一个比key小的位置或者直接到keyi
//R找小,L没有找到大,L遇到R
//类似道理,右边做key,左边先走,相遇位置就比key要大
//hoare版本
void QuickSort1(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	//按照基准值对array数组的[left, right)区间中的元素进行划分
	int div = PartSort1(a, left, right);
	//划分成功后以div为边界形成了左右两部分[left, div)和[div+1, right)
	//类似于倒立的二叉树
	//递归排[left, div)
	QuickSort1(a, left, div - 1);
	//递归排[div+1, right)
	QuickSort1(a, div + 1, right);
}
void QuickSort2(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort2(a, left, right);
	QuickSort2(a, left, div - 1);
	QuickSort2(a, div + 1, right);
}
//双指针
//cur找到比key小的值,++prev,cur和prev的位置的值交换，++cur
//cur找到比key大的值,++cur
//说明
//prev要么紧跟着cur(prev下一个就是cur)
//prev跟cur中间间隔着比key大的一段值区间
//把比key大的值往右翻,把比key小的值翻到左边
void QuickSort3(int* a, int left, int right)
{
	if (left >= right)
	{
		return;
	}
	int div = PartSort3(a, left, right);
	QuickSort3(a, left, div - 1);
	QuickSort3(a, div + 1, right);
}
//如果去掉最后一层,递归减少1/2,倒数第2层减少1/4
void QuickSort4(int* a, int left, int right)
{
	//小区间优化
	if (left >= right)
	{
		return;
	}
	if ((right - left + 1) > 10)//插入的效率高于递归
	{
		int div = PartSort3(a, left, right);
		QuickSort4(a, left, div - 1);
		QuickSort4(a, div + 1, right);
	}
	else
	{
		InsertSort(a + left, right - left + 1);
	}
}
//递归的问题
//1.效率
//2.深度太深会溢出
//栈溢出:栈区域的空间不够了
//递归改成非递归
//1.直接改循环
//2.使用栈辅助改循环
//栈里面取一段区间,单趟排序
//单趟分割子区间入栈
//子区间只有一个值或者不存在就不入栈
void QuickSortNone(int* a, int left, int right)
{
	ST st;
	STInit(&st);
	STPush(&st, right);
	STPush(&st, left);
	while (!STEmpty(&st))
	{
		int begin = STTop(&st);
		STPop(&st);
		int end = STTop(&st);
		STPop(&st);
		int keyi = PartSort3(a, begin, end);
		//[begin, keyi - 1] keyi [keyi + 1, end]
		if (keyi + 1 < end)
		{
			STPush(&st, end);
			STPush(&st, keyi + 1);
		}
		if (begin < keyi - 1)
		{
			STPush(&st, keyi - 1);
			STPush(&st, begin);
		}
	}
	STDestroy(&st);
}
void _MergeSort(int* a, int begin, int end, int* tmp)
{
	if (begin >= end)
	{
		return;
	}
	int mid = (begin + end) / 2;
	//[begin, mid][mid + 1, end]  子区间递归排序
	_MergeSort(a, begin, mid, tmp);
	_MergeSort(a, mid + 1, end, tmp);
	//[begin, mid][mid + 1, end]  归并
	int begin1 = begin;
	int end1 = mid;
	int begin2 = mid + 1;
	int end2 = end;
	int i = begin;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] < a[begin2])
		{
			//谁小谁尾插
			tmp[i++] = a[begin1++];
		}
		else
		{
			tmp[i++] = a[begin2++];
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1++];
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2++];
	}
	memcpy(a + begin, tmp + begin, sizeof(int) * (end - begin + 1));
}
void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}


//end1越界了,不归并
//end1没有越界,begin2越界,和1一样处理
//end1,begin1没有越界,end2越界,继续归并,修正到end2
//方法1---直接拷贝
void MergeSortNone1(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;//gap是归并过程中每组的数据个数
	int i = 0;
	while (gap < n)
	{
		for (i = 0; i < n; i += 2 * gap)
		{
			//[begin1, end1][begin2, end2]
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = gap + i;//begin2 = end + 1;
			int end2 = i + 2 * gap - 1;
			//修正路线(不归并)
			if (end1 >= n)
			{
				//第2个区间不存在
				end1 = n - 1;
				begin2 = n;
				end2 = n - 1;
			}
			if (begin2 >= n)
			{
				begin2 = n;
				end2 = n - 1;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			//printf("[%d, %d][%d, %d] ", begin1, end1, begin2, end2);
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					//谁小谁尾插
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
		}
		memcpy(a, tmp, sizeof(int) * n);
		gap *= 2;
	}
	free(tmp);
}
//方法2---分别拷贝两个区间
void MergeSortNone2(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int) * n);
	if (tmp == NULL)
	{
		perror("malloc fail");
		return;
	}
	int gap = 1;//gap是归并过程中每组的数据个数
	int i = 0;
	while (gap < n)
	{
		for (i = 0; i < n; i += 2 * gap)
		{
			//[begin1, end1][begin2, end2]
			int begin1 = i;
			int end1 = i + gap - 1;
			int begin2 = gap + i;//begin2 = end + 1;
			int end2 = i + 2 * gap - 1;
			//修正路线(不归并)
			if (end1 >= n || begin2 >= n)
			{
				break;
			}
			if (end2 >= n)
			{
				end2 = n - 1;
			}
			//printf("[%d, %d][%d, %d] ", begin1, end1, begin2, end2);
			int j = i;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] < a[begin2])
				{
					//谁小谁尾插
					tmp[j++] = a[begin1++];
				}
				else
				{
					tmp[j++] = a[begin2++];
				}
			}
			while (begin1 <= end1)
			{
				tmp[j++] = a[begin1++];
			}
			while (begin2 <= end2)
			{
				tmp[j++] = a[begin2++];
			}
			//归并一部分拷贝一部分
			memcpy(a + i, tmp + i, sizeof(int) * (end2 - i + 1));
		}
		gap *= 2;
	}
	free(tmp);
}

//时间复杂度:O(N+range)
//空间复杂度:O(range)
void CountSort(int* a, int n)
{
	int max = a[0], min = a[0];
	int i = 0;
	for (i = 0;i < n;i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
		if (a[i] < min)
		{
			min = a[i];
		}
	}
	//左闭右闭
	int range = max - min + 1;
	int* countA = (int*)malloc(sizeof(int) * range);
	if (countA == NULL)
	{
		perror("malloc fail");
		return;
	}
	memset(countA, 0, sizeof(int) * range);
	//计数
	for (i = 0;i < n;i++)
	{
		countA[a[i] - min]++;
	}
	//排序
	//n--循环走n次
	//--n循环走n-1次
	int j = 0;
	for (i = 0;i < range;i++)
	{
		while (countA[i]--)
		{
			a[j++] = i + min;
		}
	}
	free(countA);
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


