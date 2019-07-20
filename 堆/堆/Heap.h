#define _CRT_SECURE_NO_WARNINGS 1
#pragma once
#include <stdio.h>
#include <assert.h>
#include <string.h>
#include <stdbool.h>
#include <malloc.h>

typedef int HPDataType;
typedef struct Heap
{
	HPDataType* _a;
	int _size;
	int _capacity;
}Heap;

void AdjustDown(HPDataType* a, size_t n, size_t parent);
void AdjustUp(HPDataType* a, int child);

void HeapInit(Heap* hp, HPDataType* a, int n);
void HeapDestory(Heap* hp);
void HeapPush(Heap* hp, HPDataType x);
void HeapPop(Heap* hp);
HPDataType HeapTop(Heap* hp);
int HeapSize(Heap* hp);
int HeapEmpty(Heap* hp);

// ∂—≈≈–Ú
void HeapSort(int* a, int n);

void TestHeap1();
void TestHeap2();