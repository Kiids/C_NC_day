#define _CRT_SECURE_NO_WARNINGS 1
#include "Heap.h"

void HeapInit(Heap* hp, HPDataType* a, int n)
{
	hp->_a = malloc(sizeof(HPDataType)*n);
	memcpy(hp->_a, a, sizeof(HPDataType)*n);
	hp->_size = n;
	hp->_capacity = n;

	// 构建成堆，n-1为最后一个节点，(n-1)/2为该节点的父节点，时间复杂度为O(n)
	for (int i = (n - 1 - 1) / 2; i >= 0; --i)
		AdjustDown(hp->_a, hp->_size, i);
}

void Swap(HPDataType* a, HPDataType* b)
{
	HPDataType t = *a;
	*a = *b;
	*b = t;
}

// 向下调整
void AdjustDown(HPDataType* a, size_t n, size_t parent)
{
	int child = parent * 2 + 1;
	while (child < n)
	{
		// 选出小的那个孩纸
		if (child + 1 < n && a[child + 1] < a[child])
			++child;
		// 孩纸小于父亲，则交换
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapDestory(Heap* hp)
{
	//if (!HeapEmpty(&hp))
	//	free(hp->_a);
	hp->_capacity = hp->_size = 0;
}

// 时间复杂度logn
void HeapPush(Heap* hp, HPDataType x)
{
	if (hp->_capacity == hp->_size)
	{
		hp->_capacity = (hp->_capacity == 0) ? 2 : hp->_capacity * 2;
		hp->_a = realloc(hp->_a, sizeof(HPDataType)*hp->_capacity);
	}
	hp->_a[hp->_size] = x;
	hp->_size++;
	AdjustUp(hp->_a, hp->_size - 1);
}

// 向上调整
void AdjustUp(HPDataType* a, int child)
{
	size_t parent = (child - 1) / 2;
	while (child)
	{
		if (a[child] < a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPop(Heap* hp)
{
	assert(hp->_size > 0);
	Swap(&hp->_a[0], &hp->_a[hp->_size - 1]);
	hp->_size--;
	AdjustDown(hp->_a, hp->_size, 0);
}

HPDataType HeapTop(Heap* hp)
{
	return hp->_a[0];
}

int HeapSize(Heap* hp)
{
	return hp->_size;
}

int HeapEmpty(Heap* hp)
{
	return hp->_size == 0;
}

// 堆排序
// 降序排列数组，建立小顶堆，每次将取到的最大数字与数组最后一个元素交换，然后逻辑堆不计最后这个交换到后面的目前最大的元素
void HeapSort(int* a, int n)
{
	// 以下时间复杂度O(n)
	for (int i = (n - 2) / 2; i >= 0; i--)
		AdjustDown(a, n, i);

	// 以下时间复杂度O(nlogn)
	int end = n - 1;
	while (end)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

void HeapPrint(Heap* hp)
{
	for (int i = 0; i < hp->_size; i++)
		printf("%d ", hp->_a[i]);
	printf("\n");
}

void TestHeap1()
{
	int a[] = { 2, 4, 0, 7, 6, 1, 8, 3, 9 };
	Heap hp;
	HeapInit(&hp, a, sizeof(a) / sizeof(int));
	
	printf("HeapEmpty: %d\n", HeapEmpty(&hp));
	printf("HeapSize: %d\n", HeapSize(&hp));

	HeapPrint(&hp);

	HeapPush(&hp, 5);
	HeapPrint(&hp);
	HeapPush(&hp, -1);
	HeapPrint(&hp);
	HeapPush(&hp, 10);
	HeapPrint(&hp);

	HeapTop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("HeapTop: %d\n", HeapTop(&hp));

	HeapTop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("HeapTop: %d\n", HeapTop(&hp));

	HeapTop(&hp);
	HeapPop(&hp);
	HeapPrint(&hp);
	printf("HeapTop: %d\n", HeapTop(&hp));

	printf("HeapSize: %d\n", HeapSize(&hp));

	int num = hp._size;
	for (int i = 0; i < num; i++)
		HeapPop(&hp);
	printf("HeapEmpty: %d\n", HeapEmpty(&hp));

	HeapDestory(&hp);
}

void TestHeap2()
{
	int a[] = { 2, 4, 0, 7, 6, 1, 8, 3, 9, 5 };
	HeapSort(a, sizeof(a) / sizeof(int));

	for (int i = 0; i < sizeof(a) / sizeof(int); i++)
		printf("%d ", a[i]);
	printf("\n");
}