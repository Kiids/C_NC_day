#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
int main()
{
	//打印100~200之间的素数 	
	int i = 0, prime = 0, j = 0, year = 0;
	for (i = 100; i <= 200; i++){
		for (prime = 2; prime < i; prime++)
			if (i % prime == 0) break;
		if (i == prime)
			printf("%d ", i);
	}
	printf("\n\n");
	//输出乘法口诀表 
	for (i = 1; i <= 10; i++)
	{
		for (j = 1; j <= i; j++)
			printf("%d*%d=%d ", i, j, i*j);
		printf("\n");
	}
	printf("\n\n");
	//判断1000年---2000年之间的闰年 
	printf("请输入年份：\n");
	scanf("%d", &year);
	if (year % 400 == 0 || year % 4 == 0 && year % 100 != 0)
	{
		printf("是闰年。\n");
	}
	else{
		printf("不是闰年。\n");
	}

	system("pause");
	return 0;
}
