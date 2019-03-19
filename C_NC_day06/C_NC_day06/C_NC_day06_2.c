#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//使用函数实现两个数的交换
void swap(int *a, int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}
int main()
{
	int a = 10, b = 20;
	printf("交换前a=%d,b=%d\n", a, b);
	swap(&a, &b);
	printf("交换后a=%d,b=%d\n", a, b);

	system("pause");
	return 0;
}

#endif