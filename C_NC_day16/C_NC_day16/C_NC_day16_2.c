#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// µœ÷strcat
char* my_strcat(char* dst, const char* src)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++);
	--dst;
	while (*dst++ = *src++);
	return ret;
}
int main()
{
	char str1[] = "abc";
	char str2[] = "def";
	my_strcat(str1, str2);
	printf("%s\n", str1);
	system("pause");
	return 0;
}

#endif