#define _CRT_SECURE_NO_WARNINGS 1 
#include"Queue.h"
void menu()
{
	printf("**********************************************\n");
	printf("*****   0. QueueExit    1.  QueuePush    *****\n");
	printf("*****   2. QueuePop     3.  QueueSize    *****\n");
	printf("*****   4. QueueFront   5.  QueueBack    *****\n");
	printf("*****   6. QueueEmpty   7.  QueuePrint   *****\n");
	printf("**********************************************\n");
}
void test()
{
	int input = 0;
	Queue q;
	QueueInit(&q);
	do
	{
		menu();
		printf("请输入你想要进行的操作:>");
		scanf("%d", &input);
		switch (input)
		{
		case 0:
			QueueSave(&q);
			QueueDestory(&q);
			break;
		case 1:
			QueueMiddlePush(QueuePush, &q);
			break;
		case 2:
			QueueMiddle(&q, 2);
			break;
		case 3:
			printf("队列元素个数:%d\n", QueueSize(&q));
			break;
		case 4:
			QueueMiddle(&q, 4);
			break;
		case 5:
			QueueMiddle(&q, 5);
			break;
		case 6:
			QueueMiddle(&q, 6);
			break;
		case 7:
			QueuePrint(&q);
			break;
		default:
			printf("输入无效,请重新输入\n");
			break;
		}
	} while (input);
}
void test1()
{
	Queue q;
	QueueInit(&q);
	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");
	QueueDestory(&q);
}
int main()
{
	test();
	//test1();
	return 0;
}
