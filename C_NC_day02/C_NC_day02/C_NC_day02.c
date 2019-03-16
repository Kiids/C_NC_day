#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float arr2[3];
	int i = 0;
	int arr[10] = { 0 };
	//给定两个整形变量的值，将两个值的内容进行交换 
	int a = 10;
	int b = 20;
	int c = 0;
	printf("交换前a=%d,b=%d\n", a, b);
	c = a;
	a = b;
	b = a;
	printf("交换后a=%d,b=%d\n\n", a, b);
	//不允许创建临时变量，交换两个数的内容（附加题）
	printf("交换前a=%d,b=%d\n", a, b);
	a = a^b;
	b = a^b;
	a = a^b;
	printf("交换后a=%d,b=%d\n\n", a, b);
	//求10个整数中最大值 
	printf("请输入10个整数: ");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
		if (arr[i] > c)
			c = arr[i];
	}
	printf("最大值为: %d\n\n", c);
	//将三个数按从大到小输出 
	printf("请输入三个数: ");
	scanf("%d%d%d", &a, &b, &c);
	if (a < b)
	{
		i = a;
		a = b;
		b = i;
	}
	if (a < c)
	{
		i = a;
		a = c;
		c = i;
	}
	if (b < c)
	{
		i = b;
		b = c;
		c = i;
	}
	printf("从大到小的顺序是: %d %d %d\n\n", a, b, c);
	//求两个数的最大公约数 
	printf("请输入两个数: ");
	scanf("%d%d", &a, &b);
	while (b != 0)
	{
		c = a%b;
		a = b;
		b = c;
	}
	printf("最大公约数为: %d\n", a);

	system("pause");
	return 0;
}
