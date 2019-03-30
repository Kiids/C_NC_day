#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>

//编程实现：两个int（32位）整数m和n的二进制表达中，有多少个位(bit)不同？ 
//输入例子: 
//1999 2299 
//输出例子:7	
int main()
{
	int a = 0, b = 0;
	int c = 0;
	int count = 0;
	int i = 0;
	scanf("%d%d", &a, &b);
	c = a^b;
	for (i = 0; i < 32; i++)  //求1的个数
	{
		if (((c >> i) & 1) == 1)
		{
			count++;
		}
	}
	printf("%d\n", count);

	system("pause");
	return 0;
}

#endif