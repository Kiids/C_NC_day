#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//ģ��ʵ��strcpy 
//�Ѻ���'\0'���������ַ������Ƶ���һ����ַ�ռ䣬����ֵ������Ϊchar*
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