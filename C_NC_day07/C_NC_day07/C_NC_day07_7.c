#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//递归方式实现打印一个整数的每一位
int print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d ", n % 10);
}
int main()
{
	int a = 0;
	scanf("%d", &a);
	print(a);

	system("pause");
	return 0;
}

#endif