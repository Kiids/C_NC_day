#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//实现strcmp
int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);
	while (*str1 && str2)
	{
		if (*str1 < *str2)
			return -1;
		else if (*str1 > *str2)
			return 1;
		else
		{
			++str1;
			++str2;
		}
	}
	if (*str1 != '\0')
		return 1;
	else if (*str2 != '\0')
		return -1;
	else
		return 0;
}
int main()
{
	char str1[] = "abc";
	char str2[] = "def";
	int ret = my_strcmp(str1, str2);
	if (ret == 1)
		printf("str1大\n");
	else if (ret == -1)
		printf("str2大\n");
	else
		printf("两个字符串一样大\n");
	system("pause");
	return 0;
}

#endif