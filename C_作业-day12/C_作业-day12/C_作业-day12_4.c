#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  //assert()检测传入的指针

//有一个字符数组的内容为:"student a am i",
//请你将数组的内容改为"i am a student".
//要求：
//不能使用库函数。
//只能开辟有限个空间（空间个数和字符串的长度无关）。
//student a am i
//i ma a tneduts
//i am a student
void reverse(char *start, char *end)  //翻转字符串
{
	assert(start);
	assert(end);
	while (start < end)
	{
		char t = *start;
		*start = *end;
		*end = t;
		start++;
		end--;
	}
}
void reverse_str(char *str, int sz)
{
	assert(str);
	char *str1 = str;
	char *left = str;
	char *right = str + sz - 1;
	reverse(left, right);  //整体字符串反转
	while (*str1)  //将单词逐个反转
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' '))  //找到单词，此处一定要加(*str1 != '\0')条件限制，因为找到最后一个单词的时候，*str1永远也不为空格
		{
			str1++;
		}
		right = str1 - 1;  //此时str1指向单词后方的空格，需要减一方能指向单词的最后一个字母
		reverse(left, right);  //继整体反转后再次反转单词，能使单词拼写顺序恢复过来
		if (*str1 == ' ')  //等于空格让指针后移一位否则无法参与下次循环。
		{
			str1++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	printf("原来的字符串为：%s\n", arr);
	reverse_str(arr, sz);
	printf("反转后的字符串为：%s", arr);
	system("pause");
	return 0;
}

#endif