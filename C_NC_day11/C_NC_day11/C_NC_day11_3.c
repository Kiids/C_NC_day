#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//在屏幕上打印杨辉三角。 
//1 
//1 1 
//1 2 1 
//1 3 3 1 
int main()
{
	int i = 0, j = 0, n = 0;
	int a[100][100] = { 0 };
	printf("请输入打印行数：");
	scanf("%d", &n);
	for (i = 0; i < n; i++)  //每行左右两端的1
	{
		a[i][0] = a[i][i] = 1;
	}
	//第i行有i个元素
	for (i = 2; i < n; i++)  //行数，从第三行开始算
	{
		for (j = 1; j < i; j++)  //每行个数，从第二列开始算
		{
			a[i][j] = a[i - 1][j - 1] + a[i - 1][j];
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j <= i; j++)
			printf("%d ", a[i][j]);
		printf("\n");
	}
	printf("\n");

	system("pause");
	return 0;
}

#endif
