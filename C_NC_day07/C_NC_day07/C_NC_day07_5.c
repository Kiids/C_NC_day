#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//递归和非递归分别实现strlen
int my_strlen(char *str)
{
	if (*str == '\0') 
		return 0;
	else
		return 1 + my_strlen(str + 1);
}
int main()
{
	int i = 0, sum = 0;
	char s[] = "abcdefg";
	printf("利用递归方式求得字符串长度为：%d\n", my_strlen(s));
	for (i = 0; s[i] != '\0'; i++)
		sum++;
	printf("利用循环求得字符串长度为：%d\n", sum);

	system("pause");
	return 0;
}

#endif