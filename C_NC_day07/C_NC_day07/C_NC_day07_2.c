#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//编写一个函数实现n^k，使用递归实现
int nk(int n, int k)
{
	if (k == 0 && n != 0)
		return  1;
	else if (k == 1)
		return n;
	else
		return n*nk(n, k - 1);
}
int main()
{
	int n = 0, k = 0;
	scanf("%d %d", &n, &k);
	printf("%d^%d = %d\n", n, k, nk(n, k));

	system("pause");
	return 0;
}

#endif