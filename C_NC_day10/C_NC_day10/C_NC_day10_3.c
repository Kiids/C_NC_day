#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//输出一个整数的每一位。
void print(int n)
{
	if (n > 9)
		print(n / 10);
	printf("%d ", n % 10);
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	print(n);
	printf("\n");

	system("pause");
	return 0;
}

#endif
