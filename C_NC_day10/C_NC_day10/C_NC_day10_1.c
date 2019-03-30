#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//写一个函数返回参数二进制中 1 的个数 
//比如： 15 0000 1111 4 个 1
//程序原型：
//int count_one_bits(unsigned int value)
//{
//	// 返回 1的位数 
//}
int count_one_bits(unsigned int value)
{
	int count = 0;
	int i = 0;
	for (i = 0; i < 32; i++)  //32位平台
	{
		if ((value & 1) == 1)  //==优先于&
		{
			count++;
		}
		value = value >> 1;
	}
	return count;
}

int main()
{
	unsigned int value = 0;
	scanf("%d", &value);
	printf("%d\n", count_one_bits(value));

	system("pause");
	return 0;
}

#endif