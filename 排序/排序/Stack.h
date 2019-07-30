#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;  // arrayÊý×é
	int _top;        // Õ»¶¥
	int _capacity;   // ÈÝÁ¿
}Stack;

void StackInit(Stack* s);
void StackDestory(Stack* s);

void StackPush(Stack* s, STDataType x);
void StackPop(Stack* s);
STDataType StackTop(Stack* s);
bool StackEmpty(Stack* s);
int StackSize(Stack* s);

void TestStack();

void StackInit(Stack* s)
{
	assert(s);
	s->_a = NULL;
	s->_top = s->_capacity = 0;
}

void StackDestory(Stack* s)
{
	assert(s);
	//s->_top = s->_capacity = 0;
	//free(s->_a);
	if (s->_a != NULL)
	{
		free(s->_a);
		s->_a = NULL;
		s->_top = s->_capacity = 0;
	}
}

void StackPush(Stack* s, STDataType x)
{
	assert(s);
	if (s->_top == s->_capacity)
	{
		s->_capacity = (s->_capacity == 0) ? 2 : 2 * s->_capacity;
		s->_a = (STDataType*)realloc(s->_a, sizeof(STDataType)*s->_capacity);
	}
	s->_a[s->_top] = x;
	s->_top++;
}

void StackPop(Stack* s)
{
	assert(s && s->_top > 0);
	s->_top--;
}

STDataType StackTop(Stack* s)
{
	assert(s && s->_top > 0);
	return s->_a[s->_top - 1];
}

bool StackEmpty(Stack* s)
{
	assert(s);
	return s->_top == 0;
}

int StackSize(Stack* s)
{
	assert(s);
	return s->_top;
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 1);
	StackPush(&s, 2);
	StackPush(&s, 3);
	StackPush(&s, 4);
	StackPush(&s, 5);

	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");

	StackDestory(&s);
}