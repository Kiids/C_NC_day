#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Ä£ÄâÊµÏÖstrncat
char* my_strncat(char* dst, const char* src, size_t num)
{
	assert(dst && src);
	char* ret = dst;
	while (*dst++);
	dst--;
	while ((*dst = *src) && num)
	{
		dst++;
		src++;
		num--;
	}
	*dst = '\0';
	return ret;
}
int main()
{
	char str1[20] = "asdfghjkl";
	char str2[] = "qwertyuiop";
	char* str3 = my_strncat(str1, str2, 5 * sizeof(str2[0]));
	printf("%s\n", str3);
	system("pause");
	return 0;
}

#endif
