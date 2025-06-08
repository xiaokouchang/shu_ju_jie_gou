#define _CRT_SECURE_NO_WARNINGS 1 

#include "stack.h"
int main()
{
	ST st;
	STInit(&st);
	STPush(&st, 1);
	STPush(&st, 2);
	STPush(&st, 3);
	STPush(&st, 4);
	//while(st.top != 0),不知道栈顶元素指向哪里
	while (!STEmpty(&st))
	{
		printf("%d ", STTop(&st));
		STPop(&st);
	}
	STDestroy(&st);
	return 0;
}