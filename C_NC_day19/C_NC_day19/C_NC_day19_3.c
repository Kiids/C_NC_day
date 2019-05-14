#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//模拟实现strncmp
int my_strncmp(const char* str1, const char* str2, size_t num)
{
	assert(str1 && str2);
	while ((*str1 == *str2) && num)
	{
		if (*str1 == '\0')
		{
			return 0;
		}
		str1++;
		str2++;
		num--;
	}
	return *str1 - *str2;
}
int main()
{
	char str1[] = "asdfghjkl";
	char str2[] = "qwertyuiop";
	int n = 5;
	int ret = my_strncmp(str1, str2, n);
	if (ret == 0)
		printf("str1的前%d位与str2一样\n", n);
	else if (ret < 0)
		printf("str1的前%d位小于str2\n", n);
	else
		printf("str1的前%d位大于str2\n", n);
	system("pause");
	return 0;
}

#endif
