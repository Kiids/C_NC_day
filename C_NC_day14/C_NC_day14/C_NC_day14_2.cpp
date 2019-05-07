#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//判断一个字符串是否为另外一个字符串旋转之后的字符串。 
//例如：给定s1 =AABCD和s2 = BCDAA，返回1 
//给定s1=abcd和s2=ACBD，返回0. 
//
//AABCD左旋一个字符得到ABCDA 
//AABCD左旋两个字符得到BCDAA 
//
//AABCD右旋一个字符得到DAABC

//解法1：利用_1的函数
int isRotate(char* dest, char* src)
{
	int len = strlen(src);
	while (len--)
	{
		left_move2(src, 1);
		if (!strcmp(dest, src))
			return 1;
	}
}
//解法2：判断是否为字串   两个源字符串拼接之后包含所有旋转字符串为其字串
int isRotate2(char* dest, char* src)
{
	//strcat(dest, dest);  //这个函数不能出现地址重叠，这样操作会使拼接时\0被覆盖，则这里程序会崩掉
	strncat(dest, dest, strlen(dest));
	if (strstr(dest, src) != NULL)
		return 1;
	return 0;
}
//模拟实现strstr
const char* strStr(const char* dest, char* src)
{
	while (*dest)
	{
		const char* dst = dest;
		const char* sc = src;
		while (*dst && *sc && dst == sc)
		{
			++dst;
			++sc;
		}
		if (*sc == '\0')
			return dest;
		dest++;
	}
	return NULL;
}

// 左旋 k 个字符
void LeftRotate(char* s, int k) {
	int len = strlen(s);
	char* p;
	char* q;
	for (p = s + k - 1; p >= s; --p) {
		for (q = p; q < p + len - k; ++q) {
			char tmp = *q;
			*q = *(q + 1);
			*(q + 1) = tmp;
		}
	}
}
//右旋 k 个字符    
void RightRotate(char* s, int k) {
	int len = strlen(s);
	char* p;
	char* q;
	for (p = s + len - k; p < s + len; ++p) {
		for (q = p; q > s; --q) {
			char tmp = *q;
			*q = *(q - 1);
			*(q - 1) = tmp;
		}
	}
}
//判断 s1 是否为 s2 旋转之后的字符串
int isRotate(char* s1, char* s2) {
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	if (len1 != len2) {
		return 0;
	}
	char* s;
	int i;
	for (i = 0; i <= len1; ++i) {
		s = s1;
		LeftRotate(s, i);
		if (strcmp(s, s2) == 0) {
			return 1;
		}
		s = s1;
		RightRotate(s, i);
		if (strcmp(s, s2) == 0) {
			return 1;
		}
	}
	return 0;
}
int main()
{
	char s1[] = "AABCD";
	char s2[] = "BCDAA";
	if (isRotate(s1, s2) == 1) {
		printf("是旋转之后的\n");
	}
	else {
		printf("不是旋转之后\n");
	}
	system("pause");
	return 0;
}

#endif