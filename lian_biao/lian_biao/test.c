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
void TestSList1()
{
	STLNode* plist = NULL;
	SLTPushBack(&plist, 1);
	SLTPushBack(&plist, 2);
	SLTPushBack(&plist, 3);
	SLTPushBack(&plist, 4);
	SLTPrint(plist);
	STLNode* ret = SLTFind(plist, 2);
	SLTInsert(&plist, ret, 20);
	SLTPrint(plist);
	SLTDestory(&plist);
}
void Func1(int* y)
{
	*y = 1;
}
void Func2(int** ptr)
{
	*ptr = (int*)malloc(sizeof(int));
}
int main()
{
	TestSList1();
	int x = 0;
	Func1(&x);
	printf("%d\n", x);
	int* px = NULL;
	//改变的int*,使用int*的地址,int**指针
	Func2(&px);
	free(px);
	px = NULL;
	return 0;
}