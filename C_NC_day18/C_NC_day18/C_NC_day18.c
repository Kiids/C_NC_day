#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://baike.baidu.com/item/qsort/4747970?fr=aladdin
//qsort百度百科
//模仿qsort的功能实现一个通用的冒泡排序
int comp(const void* m, const void* n)  //比较两个变量的大小
{
	return *(char* )m - *(char* )n;
}
void swap(char* p1, char* p2, int width)  //两个指针，一个类型字节宽度，变量按字节进行交换
{
	int i = 0;
	char t = 0;
	for (i = 0; i < width; i++)
	{
		t = *p1;
		*p1 = *p2;
		*p2 = t;
		*p1++;
		*p2++;
	}
}
void my_qsort(void* base, int size, int width)  //按升序进行排序，待排序数组首地址，数组中待排序元素数量，各元素的占用空间大小
{
	int i = 0, j = 0, ret = 0;
	for (i = 0; i < size; i++)
	{
		j = 0;
		for (j = 0; j < size - i - 1; j++)
		{
			ret = comp((char* )base + j * width, (char* )base + (j + 1) * width);
			if (ret > 0)
			{
				swap((char* )base + j * width, (char* )base + (j + 1) * width, width);
			}
		}
	}
}
int comp1(const void* a, const void* b)
{
	return *(int* )a - *(int* )b;
}
int comp2(const void* p1, const void* p2)
{
	return strcmp((char* )p2, (char* )p1);
}
int main()
{
	int i = 0;
	int a[] = { 6, 8, 1, 2, 5 };
	char b[] = { 'm', 't', 'x', 'a', 'z' };

	qsort(a, 5, sizeof(int), comp1);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	my_qsort(a, 5, 4);
	for (i = 0; i < 5; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");

	qsort(b, 5, sizeof(char), comp2);
	for (i = 0; i < 5; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");

	my_qsort(b, 5, 1);
	for (i = 0; i < 5; i++)
	{
		printf("%c ", b[i]);
	}
	printf("\n");

	system("pause");
	return 0;
}
