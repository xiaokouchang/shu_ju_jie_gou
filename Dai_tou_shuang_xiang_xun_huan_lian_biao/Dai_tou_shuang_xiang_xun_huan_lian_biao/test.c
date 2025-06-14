#define _CRT_SECURE_NO_WARNINGS 1 
//尾的next指向哨兵位的头
//哨兵位的prev指向尾
#include "List.h"
void menu()
{
	printf("*******************************************************\n");
	printf("*****   0. LTExit            1. LTPushBack       ******\n");
	printf("*****   2. LTPopBack         3. LTPushFront      ******\n");
	printf("*****   4. LTPopFront        5. LTInsertFront    ******\n");
	printf("*****   6. LTInsertAfter     7. LTEraseFront     ******\n");
	printf("*****   8. LTErase           9. LTEraseBack      ******\n");
	printf("*****   10. LTPrint          11. LTFind          ******\n");
	printf("*******************************************************\n");
}
void test()
{
	int input = 0;
	LTNode* plist = LTInit();
	do
	{
		menu();
		printf("请输入你想要进行的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			LTSave(plist);
			LTDestory(plist);
			break;
		case 1:
			LTPushMiddle(LTPushBack, plist);
			break;
		case 2:
			LTPopBack(plist);
			LTPrint(plist);
			break;
		case 3:
			LTPushMiddle(LTPushFront, plist);
			break;
		case 4:
			LTPopFront(plist);
			LTPrint(plist);
			break;
		case 5:
			LTMiddlePos(LTInsertFront, plist, 5);
			break;
		case 6:
			LTMiddlePos(LTInsertAfter, plist, 6);
			break;
		case 7:
			LTMiddleErase(LTEraseFront, plist, 7);
			break;
		case 8:
			LTMiddleErase(LTErase, plist, 8);
			break;
		case 9:
			LTMiddleErase(LTEraseBack, plist, 9);
			break;
		case 10:
			LTPrint(plist);
			break;
		case 11:
			LTMiddlePos(LTFind, plist, 11);
			break;
		default:
			printf("输入错误,请重新输入\n");
			break;
		}
	} while (input);
}
void TestList()
{
	LTNode* plist = LTInit();
	LTPushBack(plist, 1);
	LTPushBack(plist, 2);
	LTPushBack(plist, 3);
	LTPushBack(plist, 4);
	LTNode* ret = LTFind(plist, 3);
	LTEraseFront(plist, ret);
	LTPrint(plist);
}
int main()
{
	test();
	//TestList();
	return 0;
}
