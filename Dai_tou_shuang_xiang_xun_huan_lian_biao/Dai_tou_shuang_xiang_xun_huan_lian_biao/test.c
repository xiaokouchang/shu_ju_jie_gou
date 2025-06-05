#define _CRT_SECURE_NO_WARNINGS 1 
//尾的next指向哨兵位的头
//哨兵位的prev指向尾
#include "List.h"
void TestList()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTPushFront(plist, 5);
	LTPrint(plist);
}
int main()
{
	TestList();
	return 0;
}
