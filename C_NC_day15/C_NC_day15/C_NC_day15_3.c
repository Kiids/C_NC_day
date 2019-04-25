#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//模拟实现strcpy 
//把含有'\0'结束符的字符串复制到另一个地址空间，返回值的类型为char*
char* my_strcpy(char* strdest, const char* strsrc)
{
	const char* ret = strsrc;
	assert(strsrc);
	while (*strdest++ = *strsrc++)
	{
		;
	}
	return ret;
}
int main()
{
	char arr1[] = "abcde";
	char arr2[10] = { 0 };
	my_strcpy(arr2, arr1);
	printf("%s\n", arr2);
	system("pause");
	return 0;
}

#endif