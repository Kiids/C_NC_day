#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int QUDataType;
typedef struct QueueNode
{
	struct QueueNode* _next;
	QUDataType _data;
}QueueNode;
typedef struct Queue
{
	QueueNode* _front;  // ¶ÓÍ·
	QueueNode* _rear;   // ¶ÓÎ²
}Queue;

void QueueInit(Queue* pq);
void QueueDestory(Queue* pq);

QueueNode* BuyQueueNode(QUDataType x);
void QueuePush(Queue* pq, QUDataType x);
void QueuePop(Queue* pq);
QUDataType QueueFront(Queue* pq);
QUDataType QueueBack(Queue* pq);
int QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);

void TestQueue();

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->_front = pq->_rear = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QueueNode* cur = pq->_front;
	while (cur)
	{
		QueueNode* next = cur->_next;
		free(cur);
		cur = next;
	}
	pq->_front = pq->_rear = NULL;
}

QueueNode* BuyQueueNode(QUDataType x)
{
	QueueNode* node = (QueueNode*)malloc(sizeof(QueueNode));
	node->_data = x;
	node->_next = NULL;
	return node;
}

void QueuePush(Queue* pq, QUDataType x)
{
	assert(pq);
	QueueNode* node = BuyQueueNode(x);
	if (pq->_front == NULL)
	{
		pq->_front = pq->_rear = node;
	}
	else
	{
		pq->_rear->_next = node;
		pq->_rear = node;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	QueueNode* next = pq->_front->_next;
	free(pq->_front);
	pq->_front = next;
	if (pq->_front == NULL)
		pq->_rear = NULL;

	//assert(pq);
	//if (pq->_front == NULL)
	//{
	//	pq->_rear = NULL;
	//	return;
	//}
	//QueueNode* cur = pq->_front;
	//pq->_front = pq->_front->_next;
	//free(cur);
	//cur = NULL;
}

QUDataType QueueFront(Queue* pq)
{
	assert(pq && pq->_front != NULL);
	return pq->_front->_data;
}

QUDataType QueueBack(Queue* pq)
{
	assert(pq && pq->_rear != NULL);
	return pq->_rear->_data;
}

int QueueEmpty(Queue* pq)
{
	assert(pq);
	return pq->_front == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);
	int size = 0;
	QueueNode* cur = pq->_front;
	while (cur)
	{
		size++;
		cur = cur->_next;
	}
	return size;
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);

	QueuePush(&q, 1);
	QueuePush(&q, 2);
	QueuePush(&q, 3);
	QueuePush(&q, 4);
	QueuePush(&q, 5);

	while (!QueueEmpty(&q))
	{
		printf("%d,", QueueFront(&q));
		printf("%d  ", QueueBack(&q));
		QueuePop(&q);
	}
	printf("\n");

	QueueDestory(&q);
}