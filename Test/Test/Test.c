#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>

char * toLowerCase(char * str)
{
	char* ret = str;
	while (*str != '\0')
	{
		if (*str <= 'Z' && *str >= 'A')
			*str += 32;

		str++;
	}
	return ret;
}

int main()
{
	char str[] = "Hello";
	printf("%s\n", toLowerCase(str));
}