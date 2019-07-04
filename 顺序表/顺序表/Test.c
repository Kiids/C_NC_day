#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <stdlib.h>

void Test1()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushFront(&s, 0);
	SeqListPopBack(&s);
	SeqListPopFront(&s);

	for (size_t i = 0; i < s._size; i++)
	{
		printf("%d ", s._array[i]);
	}
	printf("\n");

	SeqListDestory(&s);
}

void Test2()
{
	SeqList s;
	SeqListInit(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);

	SeqListInsert(&s, 1, 10);
	SeqListErase(&s, 0);

	for (size_t i = 0; i < s._size; i++)
	{
		printf("%d ", s._array[i]);
	}
	printf("\n");

	SeqListDestory(&s);
}

int main()
{
	//Test1();
	Test2();

	system("pause");
	return 0;
}