#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// µœ÷memcpy
void * my_memcpy(void * destination, const void * source, size_t num)
{
	assert(destination && source);
	char* ret = destination;
	const char* dst = source;
	while (num)
	{
		*ret = *dst;
		ret++;
		dst++;
		num--;
	}
}
int main()
{
	char str1[] = "abcdefg";
	char str2[] = "hijklmn";
	my_memcpy(str1, str2, strlen(str1)+1);
	printf("%s\n", str1);
	system("pause");
	return 0;
}

#endif