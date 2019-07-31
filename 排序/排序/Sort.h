#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

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

// �Ż�Ϊ���ַ���������
void BinInsertSort(int* a, int n)
{
	for (int i = 1; i < n; ++i)
	{
		int tmp = a[i];
		int left = 0, right = i - 1;
		while (left <= right)
		{
			int mid = left + (right - left) / 2;
			if (tmp > a[mid])
				left = mid + 1;
			else
				right = mid - 1;
		}
		int j = 0;
		for (j = i - 1; j >= left; j--)
			a[j + 1] = a[j];
		a[j + 1] = tmp;
	}
}

void TestBinInsertSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	BinInsertSort(a, sizeof(a) / sizeof(int));
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
	//_BubbleSort(a, sizeof(a) / sizeof(int));
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

int PartSort1(int* a, int left, int right)  // ����ָ�뷨
{
	// ����ȡ�з��Ż�
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int key = a[right];
	int key_index = right;
	while (left < right)
	{
		while (left < right && a[left] <= key)
			++left;
		while (left < right && a[right] >= key)
			--right;

		Swap(&a[left], &a[right]);
	}

	Swap(&a[left], &a[key_index]);
	return left;
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

int PartSort3(int* a, int left, int right)  // ǰ��ָ�뷨
{
	// ����ȡ�з��Ż�
	int mid = GetMidIndex(a, left, right);
	Swap(&a[mid], &a[right]);

	int key = a[right];
	int prev = left - 1, cur = left;

	while (cur < right)
	{
		if (a[cur] < key && ++prev != cur)
			Swap(&a[prev], &a[cur]);;

		++cur;
	}
	++prev;
	Swap(&a[prev], &a[cur]);

	return prev;
}

void _QuickSort(int *a, int left, int right)
{
	if (left >= right)
		return;

	int keyindex = PartSort1(a, left, right);
	//int keyindex = PartSort2(a, left, right);
	//int keyindex = PartSort3(a, left, right);
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
	//int a[] = { 1, 5, 9, 7, 6, 8 };
	_QuickSort(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

#include "Stack.h"
void QuickSortNonR(int* a, int left, int right)  // ����ջʵ�ַǵݹ��������
{
	Stack s;
	StackInit(&s);
	StackPush(&s, left);
	StackPush(&s, right);

	while (!StackEmpty(&s))
	{
		int end = StackTop(&s);
		StackPop(&s);
		int begin = StackTop(&s);
		StackPop(&s);

		int keyindex = PartSort3(a, begin, end);
		if (begin < keyindex - 1)
		{
			StackPush(&s, begin);
			StackPush(&s, keyindex - 1);
		}
		if (keyindex + 1 < end)
		{
			StackPush(&s, keyindex + 1);
			StackPush(&s, end);
		}
	}
}

void TestQuickSortNonR()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	//int a[] = { 1, 5, 9, 7, 6, 8 };
	QuickSortNonR(a, 0, sizeof(a) / sizeof(int) - 1);
	PrintArray(a, sizeof(a) / sizeof(int));
}

// �鲢����
void _MergeSort(int* a, int left, int right, int* tmp)
{
	if (left == right)
		return;

	int mid = left + (right - left) / 2;
	// [left, mid] [mid + 1, right] �ֱ�����
	_MergeSort(a, left, mid, tmp);
	_MergeSort(a, mid + 1, right, tmp);

	// [left, mid] [mid + 1, right] �鲢��tmp[left, right]
	int begin1 = left, end1 = mid;
	int begin2 = mid + 1, end2 = right;
	int i = left;
	while (begin1 <= end1 && begin2 <= end2)
	{
		if (a[begin1] <= a[begin2])
		{
			tmp[i++] = a[begin1];
			++begin1;
		}
		else
		{
			tmp[i++] = a[begin2];
			++begin2;
		}
	}
	while (begin1 <= end1)
	{
		tmp[i++] = a[begin1];
		++begin1;
	}
	while (begin2 <= end2)
	{
		tmp[i++] = a[begin2];
		++begin2;
	}

	memcpy(a + left, tmp + left, sizeof(int)*(i - left));
}

void MergeSort(int* a, int n)
{
	int* tmp = (int*)malloc(sizeof(int)*n);
	_MergeSort(a, 0, n - 1, tmp);
	free(tmp);
}

void TestMergeSort()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	//int a[] = { 1, 5, 9, 7, 6, 8 };
	MergeSort(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

void MergeSortNonR(int* a, int n)  // �鲢����ǵݹ�
{
	int* tmp = (int*)malloc(sizeof(int)*n);

	int gap = 1;
	while (gap < n)
	{
		// [begin, end]
		for (int begin = 0; begin < n; begin += 2 * gap)
		{
			// [begin, begin+gap-1] [begin+gap, begin+2*gap-1]
			int begin1 = begin, end1 = begin + gap - 1;
			if (end1 >= n)
				end1 = n - 1;

			int begin2 = begin + gap, end2 = begin + 2 * gap - 1;
			if (end2 >= n)
				end2 = n - 1;

			int index = begin1;
			while (begin1 <= end1 && begin2 <= end2)
			{
				if (a[begin1] <= a[begin2])
					tmp[index++] = a[begin1++];
				else
					tmp[index++] = a[begin2++];
			}

			while (begin1 <= end1)
				tmp[index++] = a[begin1++];
			while (begin2 <= end2)
				tmp[index++] = a[begin2++];
		}
		memcpy(a, tmp, sizeof(int)*n);

		gap *= 2;
	}
	free(tmp);
}

void TestMergeSortNonR()
{
	int a[] = { 0, 1, 5, 9, 6, 7, 8, 2, 4, 3 };
	//int a[] = { 1, 5, 9, 7, 6, 8 };
	MergeSortNonR(a, sizeof(a) / sizeof(int));
	PrintArray(a, sizeof(a) / sizeof(int));
}

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