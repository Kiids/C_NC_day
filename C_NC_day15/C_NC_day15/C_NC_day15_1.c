#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//一个数组中只有两个数字是出现一次，
//其他所有数字都出现了两次。
//找出这两个只出现一次的数字，编程实现。
void Find(int arr[], int size){
	int i = 0;
	int ret = 0;  //记录所有值异或的结果
	int pos = 0;  //记录ret二进制为第一个为1的位置
	int x = 0;  //将一组值异或在x，得到1个没有相同数字的值
	int y = 0;  //将另一组值异或在y，得到另1个没有相同数字的值
	for (i = 0; i < size; i++)  //将数组的所有数字异或
	{
		ret ^= arr[i];
	}
	for (i = 0; i < 32; i++)  //找到ret二进制位第一个为1的位置
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < size; i++)  //分组异或
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
			y ^= arr[i];
	}
	printf("x=%d，y=%d\n", x, y);
}
//1.将所有值异或在一起，得到4和5异或的结果1
//2.找到异或结果1的二进制中第一个为1的位置
//3.按照这个位置分为两组，分别异或起来就得到最终的结果
int main()
{
	int arr[] = { 1, 2, 3, 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find(arr, sz);
	system("pause");
	return 0;
}

/*
int main()
{
	int arr[] = { 4, 8, 8, 4, 5, 9, 3, 5 };
	int count = 0;
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0, j = 0;
	for (i = 0; i<sz; i++)
	{
		count = 0;
		for (j = 0; j<sz + 1; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}

		}
		if (count == 1)
		{
			printf("%d ", arr[i]);
		}
	}
	system("pause");
	return 0;
}
*/

#endif