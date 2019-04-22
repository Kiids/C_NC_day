#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//模拟实现strcat
//将两个char类型连接
char* my_strcat(char* dest, char* src)
{
	char *ret = dest;
	assert(src && dest);
	while (*dest != '\0')
	{
		dest++;
	}
	while (*dest++ = *src++)
	{
		;
	}
	return ret;
}
int main()
{
	char str1[20] = "abcdefg";
	char str2[20] = "hijklm";
	printf("%s\n", my_strcat(str1, str2));
	system("pause");
	return 0;
}

#endif