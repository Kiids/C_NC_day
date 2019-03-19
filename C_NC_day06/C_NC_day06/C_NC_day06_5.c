#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//实现一个函数，判断一个数是不是素数。
int is_prime(int x)
{
	int i = 0;
	for (i = 2; i <= sqrt(x); i++)
		if (x % i == 0)
			return 0;
	return 1;
}
int main()
{
	int n = 0;
	int ret = 0;
	scanf("%d", &n);
	ret = is_prime(n);
	if (ret == 1)
		printf("是素数\n");
	else
		printf("不是素数\n");

	system("pause");
	return 0;
}

#endif
