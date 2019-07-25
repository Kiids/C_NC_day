#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int* a, int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", a[i]);
	printf("\n");
}

void Swap(int* a, int* b)
{
	int t = *a;
	*a = *b;
	*b = t;
}

// 升序
// 插入排序
// 直接插入排序
void InsertSort(int* a, int n)
{
	for (int i = 0; i < n - 1; ++i)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}

void TestInsertSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	InsertSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 希尔排序
void ShellSort(int* a, int n)
{
	int gap = n;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < n - gap; ++i)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

void TestShellSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	ShellSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 选择排序
// 直接选择排序
void SelectSort(int* a, int n)
{
	int begin = 0;
	int end = n - 1;
	int min_index = 0, max_index = 0;
	while (begin <= end)
	{
		min_index = max_index = begin;
		for (int i = begin + 1; i <= end; ++i)
		{
			if (a[i] < a[min_index])
				min_index = i;
			if (a[i] > a[max_index])
				max_index = i;
		}
		Swap(&a[begin], &a[min_index]);
		if (max_index == begin)
			max_index = min_index;
		Swap(&a[end], &a[max_index]);
		++begin;
		--end;
	}
}

void TestSelectSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	SelectSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 堆排序
void AdjustDown(int* a, int n, int parent)  // 向下调整，建立大顶堆
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		if (child + 1 < n && a[child] < a[child + 1])
			++child;
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapSort(int* a, int n)
{
	for (int i = n - 1; i >= 0; i--)  // for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(a, n, i);

	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void TestHeapSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	HeapSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 交换排序
// 冒泡排序
void BubbleSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
}

void TestBubbleSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void _BubbleSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
	{
		int flag = 1;
		for (int j = 0; j < n - i; j++)
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		if (flag == 1)
			break;
	}
}

void Test_BubbleSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	_BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// 快速排序
// 归并排序


void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a4[i] = a3[i] = a2[i] = a1[i];
	}

	//clock()函数返回的是程序运行过程中耗掉得process time，也就是CPU time。
	//clock() / CLOCKS_PER_SEC is a time in seconds.
	//CLOCKS_PER_SEC，它用来表示一秒钟会有多少个时钟计时单元，也就是硬件滴答数。
	//一个clock tick不是CPU的一个时钟周期，而是C / C++的一个基本计时单位，因此只与编译器有关。
	//在TC2.0中硬件每18.2个滴答是一秒，在VC中硬件每1000个滴答是一秒，在标准POSIX中定义为1000000个滴答为一秒。

	int begin1 = clock();
	InsertSort(a1, N);
	int end1 = clock();

	int begin2 = clock();
	ShellSort(a2, N);
	int end2 = clock();

	int begin3 = clock();
	SelectSort(a3, N);
	int end3 = clock();

	int begin4 = clock();
	HeapSort(a4, N);
	int end4 = clock();

	printf("Time of InsertSort: %d\n", end1 - begin1);
	printf("Time of ShellSort: %d\n", end2 - begin2);
	printf("Time of SelectSort: %d\n", end3 - begin3);
	printf("Time of HeapSort: %d\n", end4 - begin4);
}