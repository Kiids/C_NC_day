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

// ����
// ��������
// ֱ�Ӳ�������
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

// ϣ������
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

// ѡ������
// ֱ��ѡ������
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

// ������
void AdjustDown(int* a, int n, int parent)  // ���µ����������󶥶�
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

// ��������
// ð������
void _BubbleSort(int* a, int n)
{
	for (int i = 1; i < n; i++)
		for (int j = 0; j < n - i; j++)
			if (a[j] > a[j + 1])
				Swap(&a[j], &a[j + 1]);
}

void __BubbleSort(int* a, int n)
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
	__BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void BubbleSort(int* a, int n)
{
	int end = n;
	while (end > 0)
	{
		for (int i = 0; i < end; ++i)
			if (a[i - 1] > a[i])
				Swap(&a[i - 1], &a[i]);
		--end;
	}
}

void TestBubbleSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	BubbleSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

// ��������
int PartSort1(int* a, int left, int right)  // ����ָ�뷨
{
	int key = a[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
			++left;
		while (left < right && a[right] >= key)
			--right;

		if (left < right)
		{
			Swap(&a[left], &a[right]);
			++left;
			--right;
		}
	}

	Swap(&a[left], &a[key_index]);
	return left;
}

int GetMidIndex(int*a, int left, int right)  // ����ȡ�з��Ż�
{
	int mid = left + (right - left) / 2;
	if (a[left] < a[mid])
	{
		if (a[mid] < a[right])
			return mid;
		else if (a[left] > a[right])
			return left;
		else
			return right;
	}
	else
	{
		if (a[mid] > a[right])
			return mid;
		else if (a[left] < a[right])
			return left;
		else
			return right;
	}
}

int PartSort2(int* a, int left, int right)  // �ڿӷ�
{
	// ��������ȡ�з������㷨���Ż�
	// ����Ҫ�������������ʱ/����������ȡ�з��Ż���õ�������ȫ���ֵĵ�����������������
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int key = a[right];
	while (left < right)
	{
		while (left < right && a[left] <= key)
			++left;
		a[right] = a[left];

		while (left < right && a[right] >= key)
			--right;
		a[left] = a[right];
	}
	a[right] = key;
	return left;
}

void _QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;

	int keyindex = PartSort2(a, left, right);
	_QuickSort(a, left, keyindex - 1);
	_QuickSort(a, keyindex + 1, right);
}

void QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;

	// С�����Ż�������������Сʱ�ı������㷨��ʹ��ֱ�Ӳ���������򣬼��ٵ����������Ӷ��Ż��㷨
	// ���ٵ����������Ż���debug�汾��ʱ����ٸ����ԣ�����release�汾ʱ��仯���ܲ�����Ϊ����������release���Ѿ����й������������Ż�
	if (right - left + 1 > 10)
	{
		//int keyindex = PartSort1(a, left, right);
		int keyindex = PartSort2(a, left, right);
		QuickSort(a, left, keyindex - 1);
		QuickSort(a, keyindex + 1, right);
	}
	else
		InsertSort(a + left, right - left + 1);
}

void TestQuickSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

// �鲢����

// һ���㷨�����ܲ��Ի����release��ģ���Ϊ���շ����İ汾��release��
void TestOP()
{
	srand(time(0));
	const int N = 100000;
	int* a1 = (int*)malloc(sizeof(int)*N);
	int* a2 = (int*)malloc(sizeof(int)*N);
	int* a3 = (int*)malloc(sizeof(int)*N);
	int* a4 = (int*)malloc(sizeof(int)*N);
	int* a5 = (int*)malloc(sizeof(int)*N);
	int* a6 = (int*)malloc(sizeof(int)*N);

	for (int i = 0; i < N; i++)
	{
		a1[i] = rand();
		a6[i] = a5[i] = a4[i] = a3[i] = a2[i] = a1[i];
	}

	//clock()�������ص��ǳ������й����кĵ���process time��Ҳ����CPU time��
	//clock() / CLOCKS_PER_SEC is a time in seconds.
	//CLOCKS_PER_SEC����������ʾһ���ӻ��ж��ٸ�ʱ�Ӽ�ʱ��Ԫ��Ҳ����Ӳ���δ�����
	//һ��clock tick����CPU��һ��ʱ�����ڣ�����C / C++��һ��������ʱ��λ�����ֻ��������йء�
	//��TC2.0��Ӳ��ÿ18.2���δ���һ�룬��VC��Ӳ��ÿ1000���δ���һ�룬�ڱ�׼POSIX�ж���Ϊ1000000���δ�Ϊһ�롣

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

	int begin5 = clock();
	BubbleSort(a5, N);
	int end5 = clock();

	int begin6 = clock();
	_QuickSort(a6, 0, N - 1);
	int end6 = clock();

	int begin7 = clock();
	QuickSort(a6, 0, N - 1);
	int end7 = clock();

	printf("Time of InsertSort: %d\n", end1 - begin1);
	printf("Time of ShellSort: %d\n", end2 - begin2);
	printf("Time of SelectSort: %d\n", end3 - begin3);
	printf("Time of HeapSort: %d\n", end4 - begin4);
	printf("Time of BubbleSort: %d\n", end5 - begin5);
	printf("Time of _QuickSort: %d\n", end6 - begin6);
	printf("Time of QuickSort: %d\n", end7 - begin7);
}