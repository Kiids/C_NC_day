#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//Ä£ÄâÊµÏÖstrncpy
char* my_strncpy(char* dst, char* src, size_t num)
{
	assert(dst && src);
	size_t i = 0;
	for (i = 0; i < num; i++)
	{
		*(dst + i) = *(src + i);
	}
	*(dst + i) = '\0';
	return dst;
}
int main()
{
	char str1[10] = { 0 };
	char str2[] = "qwertyuiop";
	char* str3 = my_strncpy(str1, str2, 5 * sizeof(str2[0]));
	printf("%s\n", str3);
	system("pause");
	return 0;
}

#endif
