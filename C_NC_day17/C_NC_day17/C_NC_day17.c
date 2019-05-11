#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int main()
{
	char *c[] = { "ENTER", "NEW", "POINT", "FIRST" };
	char**cp[] = { c + 3, c + 2, c + 1, c };
	char***cpp = cp;
	printf("%s\n", **++cpp);
	printf("%s\n", *--*++cpp + 3);
	printf("%s\n", *cpp[-2] + 3);
	printf("%s\n", cpp[-1][-1] + 1);

	int a[] = { 1, 2, 3 };
	int* p = a;
	printf("%d\n", *p++);
	printf("%d\n", *++p);
	printf("%d\n", *p);
	printf("%d\n", p[1]);

	char* str1 = "hello";
	printf("%d\n", strlen(str1)); // 5
	printf("%d\n", sizeof(str1)); // 4 / 8
	
	char str2[] = "hello";
	printf("%d\n", strlen(str2)); // 5
	printf("%d\n", sizeof(str2)); // 6
	
	char str3[] = "abcde\0gh\0";
	printf("%d\n", strlen(str3)); // 5
	printf("%d\n", sizeof(str3)); // 10
	
	char str4[] = "abcde\\0gh\\\0";
	printf("%d\n", strlen(str4)); // 10
	printf("%d\n", sizeof(str4)); // 12
	
	char str5[] = "abcde\\0gh\t\n\r";
	printf("%d\n", strlen(str5)); // 12
	printf("%d\n", sizeof(str5)); // 13
	
	printf("%s\n", "abc\nd\tef");

	system("pause");
	return 0;
}

int my_strlen1(const char* str)
{
	assert(str);

	size_t count = 0;
	while (*str != '\0')
	{
		++count;
		++str;
	}

	return count;
}

int my_strlen2(const char* str)
{
	assert(str);

	const char* end = str;
	while (*++end);

	return end-str;
}

// 递归方式 不建议采用
int my_strlen3(const char* str)
{
	assert(str);

	if (*str == '\0')
		return 0;

	// 分治算法

	return 1 + my_strlen3(str + 1);
}

char* my_strcpy(char* dst, const char* src)
{
	assert(src && dst);

	char* ret = dst;
	while (*dst++ = *src++);

	return ret;
}

char* my_strcat1(char* dst, const char* src)
{
	assert(dst && src);

	char* ret = dst;

	// 找到dst '\0' 的位置
	while (*dst++);
	--dst;

	// 将src追加到dst后面
	while (*dst++ = *src++);

	return dst;
}

char* my_strcat2(char* dst, const char* src)
{
	assert(dst && src);

	char* ret = dst;

	// 找到dst '\0' 的位置
	size_t count = 0;
	while (dst[count])
		count++;

	dst += count;

	// 将src追加到dst后面
	while (*dst++ = *src++);

	return dst;
}

int my_strcmp(const char* str1, const char* str2)
{
	assert(str1 && str2);

	while (*str1 && *str2)
	{
		if (*str1 < *str2)
		{
			return -1;
		}
		else if (*str1 > *str2)
		{
			return 1;
		}
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
