#define _CRT_SECURE_NO_WARNINGS 1

#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

// ��̬˳���
//#define N 100
//typedef int DataType;
//struct SeqList
//{
//	DataType _array[N];
//	size_t _size;
//};

typedef int DataType;
//˳���Ķ�̬�洢
typedef struct SeqList
{
	DataType* _array;  //ָ��̬���ٵ�����
	size_t _size;      //��Ч���ݸ���
	size_t _capacity;  //�����ռ�Ĵ�С
}SeqList;

void SeqListInit(SeqList* ps);
void SeqListDestory(SeqList* ps);

void SeqListPushBack(SeqList* ps, DataType x);
void SeqListPushFront(SeqList* ps, DataType x);
void SeqListPopBack(SeqList* ps);
void SeqListPopFront(SeqList* ps);

void SeqListInsert(SeqList* ps, size_t pos, DataType x);
void SeqListErase(SeqList* ps, size_t pos);

size_t SeqListSize(SeqList* ps);
size_t SeqListFind(SeqList* ps, DataType x);
DataType SeqListAt(SeqList* ps, size_t pos);

void SeqListBubbleSort(SeqList* ps);
int SeqListBinaryFind(SeqList* ps, DataType x);

void SeqListRemoveAll(SeqList* ps, DataType x);


void SeqListRemove(SeqList* psl, DataType x);
void SeqListModify(SeqList* psl, size_t pos, DataType x);
void SeqListPrint(SeqList* psl);