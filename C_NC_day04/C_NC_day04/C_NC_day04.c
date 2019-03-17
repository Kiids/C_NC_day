#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int sum = 0, k = 0;
	int a = 0, b = 0, c = 0;
	//在屏幕上输出以下图案 
	int i = 0, j = 0, n = 6;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= n - i; j++)
			printf(" ");
		for (j = 1; j <= 2 * i - 1; j++)
			printf("*");
		printf("\n");
	}
	for (i = n - 1; i > 0; i--)
	{
		for (j = n - i - 1; j >= 0; j--)
			printf(" ");
		for (j = 2 * i - 2; j >= 0; j--)
			printf("*");
		printf("\n");
	}

	/*求出0～999之间的所有“水仙花数”并输出。
	“水仙花数”是指一个三位数，其各位数字的立方和确好等于该数本身，如；153＝1＋5＋3?，则153是一个“水仙花数”。
	在数论中，水仙花数（Narcissistic number）也称为自恋数、自幂数、阿姆斯壮数或阿姆斯特朗数（Armstrong number），
	是指一N位数，其各个数之N次方和等于该数。
	例如153、370、371及407就是三位数的水仙花数，其各个数之立方和等于该数：
	153 = 1^3 + 5^3 + 3^3。
	370 = 3^3 + 7^3 + 0^3。
	371 = 3^3 + 7^3 + 1^3。
	407 = 4^3 + 0^3 + 7^3。 */
	for (a = 1; a <= 9; a++)
		for (b = 0; b <= 9; b++)
			for (c = 0; c <= 9; c++)
				if (100 * a + 10 * b + c == a*a*a + b*b*b + c*c*c)
					printf("%d%d%d\n", a, b, c);

	//求Sn=a+aa+aaa+aaaa+aaaaa的前5项之和，其中a是一个数字，例如：2+22+222+2222+22222 
	scanf("%d", &a);
	for (i = 0; i < 5; i++)
	{
		k = k * 10 + a;
		sum = sum + k;
	}
	printf("%d\n", sum);

	system("pause");
	return 0;
}
