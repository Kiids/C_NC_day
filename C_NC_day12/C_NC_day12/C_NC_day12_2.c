#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//不使用（a+b）/2这种方式，求两个数的平均值。 
int main()
{
	int a = 0, b = 0, average = 0;
	printf("请输入两个整数：\n");
	scanf("%d%d", &a, &b);
	average = (a + b) >> 1;
	printf("a、b的平均值为：%d\n", average);
	system("pause");
	return 0;
}

#endif