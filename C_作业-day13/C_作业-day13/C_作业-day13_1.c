#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//调整数组使奇数全部都位于偶数前面。
//题目：
//输入一个整数数组，实现一个函数，
//来调整该数组中数字的顺序使得数组中所有的奇数位于数组的前半部分，
//所有偶数位于数组的后半部分。
void move(int arr[], int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	int tmp = 0;
	while (left < right)
	{
		while ((left < right) && (*left) % 2 != 0)  //奇数
			left++;
		while ((left < right) && (*right) % 2 == 0)  //偶数
			right--;
		if (left < right)
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0, sz = 0;
	printf("请输入10个数字：\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}

#endif