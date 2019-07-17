#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void ListInit(List* plt)
{
	assert(plt);
	ListNode* head = (ListNode*)malloc(sizeof(ListNode));
	head->_next = head;
	head->_prev = head;
	plt->_head = head;

	//plt->_head = (ListNode*)malloc(sizeof(ListNode));
	//plt->_head->_next = plt->_head;
	//plt->_head->_prev = plt->_head;
}

ListNode* BuyListNode(LTDataType x)
{
	ListNode* newnode = (ListNode*)malloc(sizeof(ListNode));
	newnode->_data = x;
	newnode->_next = NULL;
	newnode->_prev = NULL;
	return newnode;
}

void ListPushBack(List* plt, LTDataType x)
{
	assert(plt);
	/*
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plt->_head;
	newnode->_next = head;
	newnode->_prev = head->_prev;
	head->_prev->_next = newnode;
	head->_prev = newnode;

	//ListNode* tail = head->_prev;
	//tail->_next = newnode;
	//newnode->_prev = tail;
	//newnode->_next = head;
	//head->_prev = newnode;
	*/

	ListInsert(plt->_head, x);
}

void ListPushFront(List* plt, LTDataType x)
{
	assert(plt);
	/*
	ListNode* newnode = BuyListNode(x);
	ListNode* head = plt->_head;
	newnode->_next = head->_next;
	newnode->_prev = head;
	head->_next->_prev = newnode;
	head->_next = newnode;
	*/

	ListInsert(plt->_head->_next, x);
}

void ListPopBack(List* plt)
{
	assert(plt);
	/*
	ListNode* head = plt->_head;
	ListNode* cur = head->_prev;
	cur->_prev->_next = head;
	head->_prev = cur->_prev;
	free(cur);
	*/

	ListErase(plt->_head->_prev);
}

void ListPopFront(List* plt)
{
	assert(plt);
	/*
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	cur->_next->_prev = head;
	head->_next = cur->_next;
	free(cur);
	*/

	ListErase(plt->_head->_next);
}

ListNode* ListFind(List* plt, LTDataType x)
{
	assert(plt);
	ListNode* head = plt->_head;
	assert(head && head->_next);
	ListNode* cur = head->_next;
	while (cur != head)
	{
		if (cur->_data == x)
			return cur;
		cur = cur->_next;
	}
	return NULL;
}

// 在pos的前面进行插入
void ListInsert(ListNode* pos, LTDataType x)
{
	assert(pos);
	ListNode* newnode = BuyListNode(x);
	ListNode* prev = pos->_prev;
	prev->_next = newnode;
	newnode->_prev = prev;
	newnode->_next = pos;
	pos->_prev = newnode;
}

// 删除pos位置的节点
void ListErase(ListNode* pos)
{
	assert(pos);
	// 保证不删除头结点，但需要此函数再传入参数List* plt
	// assert(pos != plt->_head);
	ListNode* next = pos->_next;
	ListNode* prev = pos->_prev;
	prev->_next = next;
	next->_prev = prev;
	free(pos);
	pos = NULL;
}

void ListPrint(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	printf("head<=>");
	while (cur != head)
	{
		printf("%d<=>", cur->_data);
		cur = cur->_next;
	}
	printf("\n");
}

void ListDestory(List* plt)
{
	assert(plt);
	ListNode* head = plt->_head;
	ListNode* cur = head->_next;
	while (cur != head)
	{
		ListNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	free(head);
	head = NULL;
}