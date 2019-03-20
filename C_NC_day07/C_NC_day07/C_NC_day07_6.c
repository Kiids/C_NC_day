#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//递归和非递归分别实现求n的阶乘 
int Factorial(int n)
{
	if (n == 0)
		return 0;
	else if (n == 1)
		return 1;
	else
		return n * Factorial(n - 1);
}
int main()
{
	int n = 0;
	int i = 0, product = 1;
	scanf("%d", &n);
	printf("利用递归方式求得%d的阶乘为：%d\n", n, Factorial(n));
	for (i = 1; i <= n; i++)
		product *= i;
	printf("利用循环求得%d的阶乘为：%d\n", n, product);

	system("pause");
	return 0;
}

#endif