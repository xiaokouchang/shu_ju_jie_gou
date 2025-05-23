#define _CRT_SECURE_NO_WARNINGS 1 
//OJ题
//I/O型  --- scanf拿输入条件 结果printf 写完整的程序
//接口型 --- 输入条件 参数 结果 返回值返回 写实现一个函数 部分程序

//线性表
//线性表是n个具有相同特性的数据元素的有限序列 
//线性表是一种在实际中广泛使用的数据结构,常见的线性表:顺序表、链表、栈、队列、字符串...
//线性表在逻辑上是线性结构,也就说是连续的一条直线。
//但是在物理结构上并不一定是连续的,线性表在物理上存储时,通常以数组和链式结构的形式存储

//顺序表是用一段物理地址连续的存储单元依次存储数据元素的线性结构
//一般情况下采用数组存储,在数组上完成数据的增删查改
//静态顺序表:使用定长数组存储元素

#include "SeqList.h"

void TestSeqList1()
{
	SL s;
	SLInit(&s);
	SLPushBack(&s, 1);
	SLPushBack(&s, 2);
	SLPushBack(&s, 3);
	SLPushBack(&s, 4);
	SLPushBack(&s, 5);
	//头插N个数据的时间复杂度:O(N^2)
	//尾插N个数据的时间复杂度:O(N)
	SLPrint(&s);
	SLErase(&s, 3);
	SLPrint(&s);
	int ret = SLFind(&s, 4);
	if (ret != -1)
	{
		printf("下标是:%d\n", ret);
	}
	else
	{
		printf("查找的数字不存在\n");
	}
	SLDestory(&s);
}
void menu()
{
	printf("*************************************************\n");
	printf("*****  1. SLPushBack     2. SLPopBack       *****\n");
	printf("*****  3. SLPushFront    4. SLPopFront      *****\n");
	printf("*****  5. SLBackInsert   6. SLFrontInsert   *****\n");
	printf("*****  7. SLErase        8. SLFind          *****\n");
	printf("*****  9. SLPrint        0. exit            *****\n");
	printf("*************************************************\n");
}
void TestSeqList2()
{
	SL* s = NULL;
	SLInit(&s);
}
void test()
{
	SL s;
	SLInit(&s);
	int input = 0;
	do
	{
		menu();
		printf("请输入你想要的操作:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			SaveSeqList(&s);
			SLDestory(&s);
			break;
		case 1:
			SeqListValue(SLPushBack, &s);
			break;
		case 2:
			SLPopBack(&s);
			SLPrint(&s);
			break;
		case 3:
			SeqListValue(SLPushFront, &s);
			break;
		case 4:
			SLPopFront(&s);
			SLPrint(&s);
			break;
		case 5:
			SeqListInsert(SLBackInsert, &s, 5);
			break;
		case 6:
			SeqListInsert(SLFrontInsert, &s, 6);
			break;
		case 7:
			SeqListInsert(SLErase, &s, 7);
			break;
		case 8:
			SeqListInsert(SLFind, &s, 8);
			break;
		case 9:
			SLPrint(&s);
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (input);
}
int main()
{
	//TestSeqList1();
	//TestSeqList2();
	test();
	return 0;
}


//realloc
//#include<stdio.h>
//#include<stdlib.h>
//int main()
//{
//	void* ptr1 = malloc(4);
//	printf("%p\n", ptr1);
//	void* ptr2 = realloc(ptr1, 2);
//	printf("%p\n", ptr2);
//	return 0;
//}