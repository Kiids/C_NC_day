#define _CRT_SECURE_NO_WARNINGS 1
#if 1
#include <stdio.h>
#include <stdlib.h>

//创建一个数组，实现函数init（）初始化数组、实现empty（）清空数组、实现reverse（）函数完成数组元素的逆置。
//要求：自己设计函数的参数，返回值。
void init(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
		arr[i] = 1;
}
void empty(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
		arr[i] = 0;
}
void reverse(int arr[], int sz)
{
	int i = 0, t = 0;
	for (i = 0; i < sz / 2; i++)
	{
		t = arr[i];
		arr[i] = arr[sz-1-i];
		arr[sz-1-i] = t;
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0, sz = 0;
	sz = sizeof(arr)/sizeof(arr[0]);
	printf("初始化数组全为1：\n");
	init(arr, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("清空数组全为0：\n");
	empty(arr, sz);
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");
	printf("请输入数组：\n");
	for (i = 0; i < sz; i++)
		scanf("%d", &arr[i]);
	reverse(arr, sz);
	printf("数组逆置后：\n");
	for (i = 0; i < sz; i++)
		printf("%d ", arr[i]);
	printf("\n");

	system("pause");
	return 0;
}

#endif