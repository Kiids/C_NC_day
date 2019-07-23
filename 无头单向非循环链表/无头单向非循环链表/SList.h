#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

typedef int SLTDataType;

typedef struct SListNode
{
	SLTDataType	_data;
	struct SListNode* _next;
}SListNode;

typedef struct SList
{
	SListNode* _head;
}SList;

void SListInit(SList* plt);
void SListDestory(SList* plist);

SListNode* BuySListNode(SLTDataType x);
void SListPushFront(SList* plt, SLTDataType x);
void SListPopFront(SList* plt);
SListNode* SListFind(SList* plt, SLTDataType x);
// 在pos的后面进行插入 
void SListInsertAfter(SListNode* pos, SLTDataType x);
// 在pos的前面进行插入 
void SListEraseAfter(SListNode* pos);
void SListRemove(SList* plt, SLTDataType x);

void SListPrint(SList* plt);

void TestSList1();
void TestSList2();