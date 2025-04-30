#define _CRT_SECURE_NO_WARNINGS 1
//数据结构是计算机存储、组织数据的方式
//指相互之间存在一种或多种特定关系的数据元素的集合

//算法
//定义良好的计算过程,他取一个或一组的值为输入,并产生出一个或一组值作为输出
//算法就是一系列的计算步骤,用来将输入数据转化成输出结果
//算法在编写成可执行程序后,运行时需要耗费时间资源和空间(内存)资源
//因此衡量一个算法的好坏,一般是从时间和空间两个维度来衡量的
//时间复杂度和空间复杂度
//时间复杂度主要衡量一个算法的运行快慢,即程序的运行次数,是数学中的函数式
//空间复杂度主要衡量一个算法运行所需要的额外空间

//#include <stdio.h>
//void Func1(int N)
//{
//	int count = 0;
//	for (int i = 0; i < N; ++i)
//	{
//		for (int j = 0; j < N; ++j)
//		{
//			++count;
//		}
//	}
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//int main()
//{
//	int num = 10;
//	Func1(num);
//	return 0;
//}
//函数执行N*N+2*N+10次
//N*N影响最大,大概次数
//N = 10   F(N) = 130
//N = 100  F(N) = 10210
//N = 1000 F(N) = 1002010


//大O的渐进表示法
//大O符号:是用于描述函数渐进行为的数学符号
//推导大O阶方法:
//用常数1取代运行时间中的所有加法常数
//在修改后的运行次数函数中,只保留最高阶项
//如果最高阶项存在且不是1,则去除与这个项目相乘的常数
//得到的结果就是大O阶
//大O的渐进表示法去掉了那些对结果影响不大的项,简洁明了的表示出了执行次数


//#include <stdio.h>
//void Func2(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 2 * N; ++k)
//	{
//		++count;
//	}
//	int M = 10;
//	while (M--)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//int main()
//{
//	int num = 10;
//	Func2(num);
//	return 0;
//}
//时间复杂度:2*N+10
//O(N)
//N无限大,2.......1000000可以忽略不计


//Func3的时间复杂度
//O(M + N)无法识别M、N哪个大
//M=N时,O(M+N)=O(2*M)=O(M)
//m>N,O(M+N)=O(N)
//m<N,O(M+N)=O(M)
//void Func3(int N, int M)
//{
//	int count = 0;
//	for (int k = 0; k < M; ++k)
//	{
//		++count;
//	}
//	for (int k = 0; k < N; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}


//Func4的时间复杂度
//void Func4(int N)
//{
//	int count = 0;
//	for (int k = 0; k < 100; ++k)
//	{
//		++count;
//	}
//	printf("%d\n", count);
//}
//时间复杂度:O(1),不是代表1次,而是常数次
//基本操作执行最好1次,最坏N次,时间复杂度一般看最坏,时间复杂度为O(N)
//最坏情况:任意输入规模的最大运行次数(上界)
//​平均情况:任意输入规模的期望运行次数
//​最好情况:任意输入规模的最小运行次数(下界)
//在一个长度为N数组中搜索一个数据x
//​最好情况:1次找到
//​最坏情况:N次找到
//​平均情况:N/2次找到
//一般情况关注的是算法的最坏运行情况
//数组中搜索数据时间复杂度为O(N)
//函数strchr的时间复杂度
//查找字符串中的某一个字符
//const char* strchr(const char* str, int character)
//{
//	while (*str)
//	{
//		if (*str == character)
//		{
//			return str;
//		}
//		else
//		{
//			++str;
//		}
//	}
//}


//计算BubbleSort的时间复杂度
//冒泡排序
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for(size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}
//最好:O(N),最少比较内层循环的数目
//最坏:O(N*N)
//等差数列,不能数循环,N(N-1)/2使用大O的渐进表示法表示为O(N^2) 
//如果去掉exchange,最好和最坏都是O(N^2)


//计算BinarySearch的时间复杂度
//经典的二分查找
//二分查找也叫折半查找
//查找N/2/2/2/2/2/2/2.......折半查找x次,除以多少个2
//2^x=N ---- x=log2(N)
//最好:O(1)
//最坏:O(log2(N))
//有序
//效率高但是如果遇到数组更改,减少元素会很麻烦
//int BinarySearch(int* a, int n, int x)
//{
//	assert(a);
//	int begin = 0;
//	int end = n - 1;
//	//[begin, end]:begin和end是左闭右闭区间,因此有=号
//	while(begin <= end)
//	{
//		int mid = begin + ((end - begin) >> 1);
//		if (a[mid] < x)
//			begin = mid + 1;
//		else if (a[mid] > x)
//			end = mid - 1;
//		else
//			return mid;
//	}
//	return -1;
//}
//n                      1000          100W          10亿
//最好:O(1)               1000          100w          10亿
//最坏:O(log2(N))          10           20            30
//2^10 = 1024
//2^20 = 1024 * 1024 
//2^30 = 1024 * 1024 * 1024


//阶乘
//0的阶乘是1
//5*4*3*2*1
//long long Fac(size_t N)
//{
//	if (0 == N || 1 == N)//特殊值1、0
//		return N;
//	return Fac(N - 1) * N;
//}
//时间复杂度:O(N + 1) == O(N)


//斐波那契数列
//时间复杂度:O(2^(N-1))=O(2^N)
//#include<stdio.h>
//long long Fib(size_t N)
//{
//	if (N < 3)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}
//int main()
//{
//	printf("%lld\n", Fib(50));
//	return 0;
//}


//排序
//O(1)    --- 常数阶
//O(logN) --- 对数阶
//O(N)    --- 
//O(N*log(N))
//O(N^2)
//O(N^3)
//O(2^N)


//空间复杂度
//空间复杂度也是一个数学表达式,是对一个算法在运行过程中,临时占用存储空间大小的量度
//空间复杂度不是程序占用了多少bytes的空间,因为这个也没太大意义,所以空间复杂度算的是变量的个数
//空间复杂度计算规则基本跟时间复杂度类似,也使用大O渐进表示法。
//注意:函数运行时所需要的栈空间(存储参数、局部变量、一些寄存器信息等)在编译期间已经确定好了
//因此空间复杂度主要通过函数在运行时候显式申请的额外空间来确定
//BubbleSort的空间复杂度为O(1),3个变量
//#include <stdio.h>
//#include <assert.h>
//void BubbleSort(int* a, int n)
//{
//	assert(a);
//	for (size_t end = n; end > 0; --end)
//	{
//		int exchange = 0;
//		for (size_t i = 1; i < end; ++i)
//		{
//			if (a[i - 1] > a[i])
//			{
//				Swap(&a[i - 1], &a[i]);
//				exchange = 1;
//			}
//		}
//		if (exchange == 0)
//			break;
//	}
//}


//额外的空间
//Fibonacci的空间复杂度O(N)
//返回斐波那契数列的前n项
//n+1的原因从0开始到第n个数总共有n+1个数
//#include <stdio.h>
//long long* Fibonacci(size_t n)
//{
//	if (n == 0)
//		return NULL;
//	long long* fibArray = (long long*)malloc((n + 1) * sizeof(long long));
//	fibArray[0] = 0;
//	fibArray[1] = 1;
//	for (int i = 2; i <= n; ++i)
//	{
//		fibArray[i] = fibArray[i - 1] + fibArray[i - 2];
//	}
//	return fibArray;
//}


//80%的空间复杂度是O(1)或者O(N)
//空间复杂度是O(N)
//#include<stdio.h>
//long long Fac(size_t N)
//{
//	if (N == 0)
//		return 1;
//	return Fac(N - 1) * N;
//}


//空间复杂度是O(N)
//#include <stdio.h>
//long long Fib(size_t N)
//{
//	if (N < 13)
//		return 1;
//	return Fib(N - 1) + Fib(N - 2);
//}


//同1份空间
//#include<stdio.h>
//void F1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//}
//void F2()
//{
//	int b = 0;
//	printf("%p\n", &b);
//}
//int main()
//{
//	F1();
//	F2();
//	return 0;
//}


//不同的空间
//#include<stdio.h>
//void F2()
//{
//	int b = 0;
//	printf("%p\n", &b);
//}
//void F1()
//{
//	int a = 0;
//	printf("%p\n", &a);
//	F2();
//}
//int main()
//{
//	F1();
//	return 0;
//}