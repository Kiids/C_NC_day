#define _CRT_SECURE_NO_WARNINGS 1
#include "List.h"

void Test1()
{
	List plt;
	ListInit(&plt);

	ListPushBack(&plt, 1);
	ListPushBack(&plt, 2);
	ListPushBack(&plt, 3);
	ListPushBack(&plt, 4);
	ListPushBack(&plt, 5);
	ListPrint(&plt);

	ListPopBack(&plt);
	ListPrint(&plt);

	ListPopBack(&plt);
	ListPrint(&plt);

	ListPopBack(&plt);
	ListPrint(&plt);
}

void Test2()
{
	List plt;
	ListInit(&plt);

	ListPushFront(&plt, 1);
	ListPushFront(&plt, 2);
	ListPushFront(&plt, 3);
	ListPushFront(&plt, 4);
	ListPushFront(&plt, 5);
	ListPrint(&plt);

	ListPopFront(&plt);
	ListPrint(&plt);

	ListPopFront(&plt);
	ListPrint(&plt);
}

int main()
{
	Test1();
	Test2();

	system("pause");
	return 0;
}