#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ÊµÏÖstrstr
const char * my_strstr(const char * str1, const char * str2)
{
	assert(str1 && str2);
	const char* ret = str1;
	while (*str1 != '\0' && *str2 != '\0')
	{

		if (*str1 == *str2)
		{
			str1++;
			str2++;
		}
		else
		{
			str1++;
			ret = str1;
		}
	}
	if (*str2 == '\0')
	{
		return ret;
	}
	return NULL;
}
int main()
{
	char str1[] = "abcdefg";
	char str2[] = "def";
	char* ret = my_strstr(str1, str2);
	printf("%s\n", ret);
	system("pause");
	return 0;
}

#endif