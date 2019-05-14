#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//https://baike.baidu.com/item/qsort/4747970?fr=aladdin
//qsort�ٶȰٿ�
//ģ��qsort�Ĺ���ʵ��һ��ͨ�õ�ð������
int comp(const void* m, const void* n)  //�Ƚ����������Ĵ�С
{
	return *(char* )m - *(char* )n;
}
void swap(char* p1, char* p2, int width)  //����ָ�룬һ�������ֽڿ�ȣ��������ֽڽ��н���
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
void my_qsort(void* base, int size, int width)  //������������򣬴����������׵�ַ�������д�����Ԫ����������Ԫ�ص�ռ�ÿռ��С
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
