#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//获取一个数二进制序列中所有的偶数位和奇数位，分别输出二进制序列。 
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	printf("奇数序列为：");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("偶数序列为：");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");

	system("pause");
	return 0;
}

#endif