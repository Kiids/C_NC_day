#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#define ROW 3

//杨氏矩阵
//有一个二维数组.
//数组的每行从左到右是递增的，每列从上到下是递增的.
//在这样的数组中查找一个数字是否存在。
//时间复杂度小于O(N);
//
//数组：
//1 2 3
//2 3 4
//3 4 5
//
//1 3 4
//2 4 5
//4 5 6
//
//1 2 3
//4 5 6
//7 8 9
int find(int arr[ROW][ROW], int row, int k)
{
	int left = 0;
	int right = row - 1;
	while ((left < row) && (right >= 0))
	{
		if (arr[left][right] < k)
		{
			left++;
		}
		if (arr[left][right] > k)
		{
			right--;
		}
		if (arr[left][right] == k)
		{
			return 1;
		}
	}
	return 0;
}
int main()
{
	int arr[ROW][ROW] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int k = 0, ret = 0;
	printf("请输入想要查找的数字：");
	scanf("%d", &k);
	ret = find(arr, ROW, k);
	if (ret == 1)
		printf("找到了\n");
	else
		printf("未找到\n");
	system("pause");
	return 0;
}

#endif