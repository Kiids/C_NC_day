#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//实现一个函数判断year是不是闰年
int is_leap_year(int year)
{
	return ((year%400 == 0) || (year%4 == 0 && year%100 != 0));
}
int main()
{
	int year = 0;
	int ret = 0;
	printf("请输入年份：\n");
	scanf("%d", &year);
	ret = is_leap_year(year);
	if (ret == 1)
		printf("是闰年\n");
	else
		printf("不是闰年\n");

	system("pause");
	return 0;
}

#endif