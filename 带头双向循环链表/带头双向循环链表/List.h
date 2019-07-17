#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int LTDataType;
typedef struct ListNode
{
	LTDataType _data;
	struct ListNode* _next;
	struct ListNode* _prev;
}ListNode;
typedef struct List
{
	ListNode* _head;
}List;

void ListInit(List* plt);
void ListDestory(List* plt);

void ListPushBack(List* plt, LTDataType x);
void ListPopBack(List* plt);
void ListPushFront(List* plt, LTDataType x);
void ListPopFront(List* plt);

ListNode* ListFind(List* plt, LTDataType x);
// ��pos��ǰ����в���
void ListInsert(ListNode* pos, LTDataType x);
// ɾ��posλ�õĽڵ�
void ListErase(ListNode* pos);

void ListPrint(List* plt);
