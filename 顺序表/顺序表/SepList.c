#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"
#include <assert.h>

void SeqListInit(SeqList* ps)
{
	assert(ps);
	ps->_array = (DataType*)malloc(4 * sizeof(DataType));
	//ps->_array = NULL;
	ps->_capacity = 4;
	ps->_size = 0;
}

void SeqListDestory(SeqList* ps)
{
	assert(ps);
	free(ps->_array);
	ps->_capacity = 0;
	ps->_size = 0;
	ps->_array = NULL;
}

void CheckSeqListCapacity(SeqList* ps)
{
	assert(ps);
	if (ps->_capacity == 0)
	{
		ps->_array = (DataType*)malloc(4 * sizeof(DataType));
		ps->_capacity = 4;
	}
	else if (ps->_size == ps->_capacity)
	{
		DataType* arr = (DataType*)realloc(ps->_array, ps->_capacity * 2 * sizeof(DataType));
		ps->_array = arr;
		ps->_capacity *= 2;
	}
}

void SeqListPushBack(SeqList* ps, DataType x)
{
	assert(ps);
	CheckSeqListCapacity(ps);
	ps->_array[ps->_size] = x;
	ps->_size++;
}

void SeqListPushFront(SeqList* ps, DataType x)
{
	assert(ps);
	CheckSeqListCapacity(ps);
	for (size_t i = ps->_size; i > 0; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[0] = x;
	ps->_size++;
}

void SeqListPopBack(SeqList* ps)
{
	assert(ps);
	ps->_size--;
}

void SeqListPopFront(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

void SeqListInsert(SeqList* ps, size_t pos, DataType x)
{
	assert(ps && pos < ps->_size);
	CheckSeqListCapacity(ps);
	for (size_t i = ps->_size; i > pos; i--)
	{
		ps->_array[i] = ps->_array[i - 1];
	}
	ps->_array[pos] = x;
	ps->_size++;
}

void SeqListErase(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size);
	for (size_t i = pos; i < ps->_size - 1; i++)
	{
		ps->_array[i] = ps->_array[i + 1];
	}
	ps->_size--;
}

size_t SeqListSize(SeqList* ps)
{
	return ps->_size;
}

size_t SeqListFind(SeqList* ps, DataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
		if (x == ps->_array[i])
			return i;
	return -1;
}

DataType SeqListAt(SeqList* ps, size_t pos)
{
	assert(ps && pos < ps->_size);
	return ps->_array[pos];
}

void SeqListBubbleSort(SeqList* ps)
{
	assert(ps);
	int i = 0;
	int end = ps->_size - 1;
	while (end >= 0)
	{
		for (i = 0; i < end; i++)
		{
			if (ps->_array[i] > ps->_array[i + 1])
			{
				DataType tmp = ps->_array[i];
				ps->_array[i] = ps->_array[i + 1];
				ps->_array[i + 1] = tmp;
			}
		}
		end--;
	}
}

int SeqListBinaryFind(SeqList* ps, DataType x)\
{
	assert(ps);
	int start = 0;
	int end = ps->_size;
	int mid = 0;
	while (start <= end)
	{
		mid = start + (end - start) / 2;
		if (ps->_array[mid] == x)
			return mid;
		else if (ps->_array[mid] > x)
			end = mid - 1;
		else
			start = mid + 1;
	}
	return -1;
}

void SeqListRemoveAll(SeqList* ps, DataType x)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		if (ps->_array[i] == x)
		{
			SeqListErase(ps, x);
			i--;
		}
	}
}

void SeqListRemove(SeqList* psl, DataType x)
{
	assert(psl);
	int pos = SeqListFind(psl, x);
	if (pos != -1)
		SeqListErase(psl, pos);
}

void SeqListModify(SeqList* psl, size_t pos, DataType x)
{
	assert(psl && pos<psl->_size);
	psl->_array[pos] = x;
}

void SeqListPrint(SeqList* ps)
{
	assert(ps);
	for (size_t i = 0; i < ps->_size; i++)
	{
		printf("%d ", ps->_array[i]);
	}
	printf("\n");
}