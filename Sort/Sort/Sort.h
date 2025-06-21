#pragma once
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
typedef int HPDataType;
typedef struct Heap
{
	HPDataType* a;
	int size;
	int capacity;
}HP;
//ֱ�Ӳ�������
//Ԫ�ؼ���Խ�ӽ�����,ֱ�Ӳ��������㷨��ʱ��Ч��Խ��
//O(N^2)�����������
//ʱ�临�Ӷ�:�(����):O(N^2)   ���(����):O(n)
//�ռ临�Ӷ�:O(1),����һ���ȶ��������㷨
//�ȶ���:�ȶ�
void InsertSort(int* a, int n);

//ð������
//���ڼ������㷨,ԭ��ֱ�۵�Ч�ʽϵ�(ʱ�临�Ӷ�ΪO(n^2))
//�ȶ�����(��ͬԪ�ص����˳��������󱣳ֲ���)
void BubbleSort(int* a, int n);

//ϣ������(��С��������)
//ϣ�������ֳ���С������
//��ѡ��һ������,�Ѵ������ļ������м�¼�ֳɸ���,���о���Ϊgap�ļ�¼����ͬһ����,����ÿһ���ڵļ�¼��������
//Ȼ��ȡ�ظ��������������Ĺ���
//������=1ʱ,���м�¼��ͳһ�����ź���
//gapԽ��,����Խ��,Խ���ӽ�����
//gapԽС,����Խ��,Խ�ӽ�����
void ShellSort(int* a, int n);

//ѡ������
//��������O(N*N)
void SelectSort(int* a, int n);

//�������
void PrintArray(int* a, int n);

//���µ���
void AdjustDown(HPDataType* a, int n, int parent);

//���ϵ���
void AdjustUP(HPDataType* a, int child);

//������
void HeapSort(int* a, int n);

//��������
//��ȡ������Ԫ�������е�ĳԪ����Ϊ��׼ֵ,���ո������뽫�����򼯺Ϸָ����������,
//��������������Ԫ�ؾ�С�ڻ�׼ֵ,��������������Ԫ�ؾ����ڻ�׼ֵ,
//Ȼ���������������ظ��ù���,ֱ������Ԫ�ض���������Ӧλ����Ϊֹ��
//hoare�汾
void QuickSort1(int* a, int left, int right);

//�ڿӷ�
void QuickSort2(int* a, int left, int right);

//˫ָ��
void QuickSort3(int* a, int left, int right);