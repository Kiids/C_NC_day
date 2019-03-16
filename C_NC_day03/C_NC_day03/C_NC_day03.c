#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int i = 0, t = 0;
	int A[10] = { 0 };
	int B[10] = { 0 };
	double sum = 0.0;
	int count = 0;
	//将数组A中的内容和数组B中的内容进行交换。（数组一样大）
	printf("请输入数组A: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &A[i]);
	}
	printf("请输入数组B: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &B[i]);
	}
	for (i = 0; i < 10; i++)
	{
		t = A[i];
		A[i] = B[i];
		B[i] = t;
	}
	for (i = 0; i <10; i++)
	{
		printf("%d ", A[i]);
	}
	printf("\n");
	for (i = 0; i <10; i++)
	{
		printf("%d ", B[i]);
	}
	printf("\n");

	//计算1/1-1/2+1/3-1/4+1/5 …… + 1/99 - 1/100 的值。
	for (i = 1; i <= 100; i++)
	{
		if (i % 2 == 0)
			sum -= 1.0 / i;
		else
			sum += 1.0 / i;
	}
	printf("%lf\n", sum);

	//编写程序数一下 1到 100 的所有整数中出现多少次数字9。
	for (i = 1; i <= 100; i++)
	{
		if (i % 10 == 9)
			count++;
		if (i / 10 == 9)
			count++;
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}

