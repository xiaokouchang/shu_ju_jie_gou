#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <assert.h>
//静态栈
//#define N 10
//struct Stack
//{
//	int a[N];
//	int top;
//};

//动态栈
typedef int STDataType;
typedef struct Stack
{
	STDataType* a;
	int top;
	int capacity;   //容量
}ST;

//初始化
void STInit(ST* ps);

void STDestroy(ST* ps);

void STMiddle(void(*Pf)(ST* ps, STDataType x), ST* ps);

//只能在一端插入,即栈顶
void STPush(ST* ps,STDataType x);

void STPop(ST* ps);

int STSize(ST* ps);

bool STEmpty(ST* ps);

//访问栈顶元素
STDataType STTop(ST* ps);

void STPrint(ST* ps);

//保存栈中的元素到文件中
void STSave(ST* ps);

//从文件中加载
void STLoad(ST* ps);