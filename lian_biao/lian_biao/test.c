#define _CRT_SECURE_NO_WARNINGS 1
//顺序表
//中间/头部的插入删除,时间复杂度为O(N)
//增容需要申请新空间,拷贝数据,释放旧空间,会有不小的消耗。
//增容一般是呈2倍的增长,势必会有一定的空间浪费。
//例如当前容量为100,满了以后增容到200,我们再继续插入了5个数据,
//后面没有数据插入了,那么就浪费了95个数据空间。
//链表
//链表是一种物理存储结构上非连续、非顺序的存储结构
//数据元素的逻辑顺序是通过链表中的指针链接次序实现的
#include "SList.h"
void menu()
{
	printf("****************************************************\n");
	printf("*****   0. STLExit          1. SLTPrint        *****\n");
	printf("*****   2. STLPushBack      3. STLPopBack      *****\n");
	printf("*****   4. STLPushFront     5. STLPopFront     *****\n");
	printf("*****   6. SLTInsertFront   7. SLTErase        *****\n");
	printf("*****   8. SLTInsertAfter   9. SLTEraseAfter   *****\n");
	printf("****************************************************\n");
}
void test()
{
	int input = 0;
	STLNode* plist = NULL;
	STLLoadSList(&plist);
	do
	{
		menu();
		printf("请输入你想要进行的操作:>\n");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			STLSaveSList(&plist);
			SLTDestory2(&plist);
			break;
		case 1:
			SLTPrint(plist);
			break;
		case 2:
			STLMiddlePush(SLTPushBack, &plist);
			break;
		case 3:
			SLTPopBack(&plist);
			SLTPrint(plist);
			break;
		case 4:
			STLMiddlePush(SLTPushFront, &plist);
			break;
		case 5:
			SLTPopFront(&plist);
			SLTPrint(plist);
			break;
		case 6:
			STLMiddlePos(SLTInsertFront, &plist, 6);
			break;
		case 7:
			STLMiddlePos(SLTErase, &plist, 7);
			break;
		case 8:
			STLMiddlePos(SLTInsertAfter, &plist, 8);
			break;
		case 9:
			STLMiddlePos(SLTEraseAfter, &plist, 9);
			break;
		default:
			printf("无效输入,请重新输入\n");
			break;
		}
	} while (input);
}
void TestSList1()
{
	STLNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	//removeElements(plist, 2);
	SLTPrint(plist);
}

int main()
{
	//TestSList1();
	test();
	return 0;
}

//void Func1(int* y)
//{
//	*y = 1;
//}
//void Func2(int** ptr)
//{
//	*ptr = (int*)malloc(sizeof(int));
//}
//int main()
//{
//	int x = 0;
//	Func1(&x);
//	printf("%d\n", x);
//	int* px = NULL;
//	//改变int*,使用int*的地址,int**指针
//	//改变int,使用int的地址,int*指针
//	Func2(&px);
//	free(px);
//	px = NULL;
//	return 0;
//}