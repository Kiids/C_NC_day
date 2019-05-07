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
//时间复杂度
//遍历a[m][n]-->O(mn)
//左下角，或者右上角m + n - 1 --> O(m + n)
//左下角起点
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
//递归写法，右上角
#define N 3
int find_r(int a[][N], int row, int col, int x, int y, int key)
{
	//终止
	if (x >= row || y < 0)
		return 0;
	if (a[x][y] == key)
		return 1;
	else if (key > a[x][y])
		return find_r(a, row, col, x + 1, y, key);
	else
		return find_r(a, row, col, x, y - 1, key);
}
//find_r(a[N][N], N, N, 0, N - 1, key)
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