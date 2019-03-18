#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//写代码可以在整型有序数组中查找想要的数字，找到了返回下标，找不到返回-1.（折半查找）
int BinarySearch(int arr[], int k, int left, int right)
{
	int mid = 0;
	while (left <= right)
	{
		mid = left + (right - left) / 2;
		if (arr[mid] < k)
			left = mid + 1;
		else if (arr[mid] > k)
			right = mid - 1;
		else
			return mid;
	}
	return -1;
}
int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, k = 7;
	int left = 0;
	int right = sizeof(arr) / sizeof(arr[0]) - 1;
	int ret = BinarySearch(arr, k, left, right);
	if (ret == -1)
		printf("未找到\n");
	else
		printf("找到了，下标为%d\n", ret);

	system("pause");
	return 0;
}

#endif
