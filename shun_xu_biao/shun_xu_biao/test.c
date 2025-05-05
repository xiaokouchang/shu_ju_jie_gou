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
	SLPrint(&s);
	SLDestory(&s);
}
int main()
{
	TestSeqList1();
}