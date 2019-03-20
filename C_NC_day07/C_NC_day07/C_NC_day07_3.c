#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//写一个递归函数DigitSum(n)，输入一个非负整数，返回组成它的数字之和， 
//例如，调用DigitSum(1729)，则应该返回1 + 7 + 2 + 9，它的和是19
int DigitSum(int n)
{
	int sum = 0;
	int m = 0;
	if (n != 0)
	{
		m = n % 10;
		sum = m + DigitSum(n / 10);
	}
	return sum;
}
int main()
{
	int n = 0;
	scanf("%d", &n);
	printf("%d\n", DigitSum(n));

	system("pause");
	return 0;
}

#endif