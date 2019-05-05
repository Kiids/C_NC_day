#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// µœ÷strcpy
char* my_strcpy(char* dst, const char* src)
{
	assert(src && dst);
	char* ret = dst;
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char str1[] = "abc";
	char str2[] = "def";
	my_strcpy(str1, str2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}

#endif