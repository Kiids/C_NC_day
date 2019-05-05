#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// µœ÷strchr
const char * my_strchr(const char * str, int character)
{
	assert(str);
	while (*str != NULL)
	{
		if (*str == character)
		{
			return (char *)str;
		}
		*str++;
	}
	return NULL;
}
int main()
{
	char str1[] = "abcdefg";
	char str2 = 'c';
	char* ret = my_strchr(str1, str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}

#endif