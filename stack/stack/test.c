#define _CRT_SECURE_NO_WARNINGS 1 

#include "stack.h"
void menu()
{
	printf("***************************************\n");
	printf("*****   0. STExit     1. STPush   *****\n");
	printf("*****   2. STPop      3. STSize   *****\n");
	printf("*****   4. STEmpty    5. STTop    *****\n");
	printf("*****   6. STPrint                *****\n");
	printf("***************************************\n");
}
void test()
{
	int input = 0;
	ST st;
	STInit(&st);
	do
	{
		menu();
		printf("请输入你想要进行的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			STSave(&st);
			STDestroy(&st);
			break;
		case 1:
			STMiddle(STPush, &st);
			break;
		case 2:
			STPop(&st);
			STPrint(&st);
			break;
		case 3:
			printf("%d\n", STSize(&st));
			break;
		case 4:
			if (STEmpty(&st))
			{
				printf("栈为空\n");
			}
			else
			{
				printf("栈不为空\n");
			}
			break;
		case 5:
			printf("栈顶元素是:%d\n", STTop(&st));
			break;
		case 6:
			STPrint(&st);
			break;
		default:
			printf("输入无效,请重新输入\n");
			break;
		}
	} while (input);
}
void test1()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	//while(st.top != 0),不知道栈顶元素指向哪里
	//while (!STEmpty(&st))
	//{
	//	printf("%d ", STTop(&st));
	//	STPop(&st);
	//}
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	STPrint(&st);
	//int ret = STTop(&st);
	//printf("%d\n", ret);
	STPop(&st);
	STPrint(&st);
	STDestroy(&st);
}
int main()
{
	test();
	//test1();
	return 0;
}