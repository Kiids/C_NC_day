#define _CRT_SECURE_NO_WARNINGS 1
#if 1

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>  //assert()��⴫���ָ��

//��һ���ַ����������Ϊ:"student a am i",
//���㽫��������ݸ�Ϊ"i am a student".
//Ҫ��
//����ʹ�ÿ⺯����
//ֻ�ܿ������޸��ռ䣨�ռ�������ַ����ĳ����޹أ���
//student a am i
//i ma a tneduts
//i am a student
void reverse(char *start, char *end)  //��ת�ַ���
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
	reverse(left, right);  //�����ַ�����ת
	while (*str1)  //�����������ת
	{
		left = str1;
		while ((*str1 != '\0') && (*str1 != ' '))  //�ҵ����ʣ��˴�һ��Ҫ��(*str1 != '\0')�������ƣ���Ϊ�ҵ����һ�����ʵ�ʱ��*str1��ԶҲ��Ϊ�ո�
		{
			str1++;
		}
		right = str1 - 1;  //��ʱstr1ָ�򵥴ʺ󷽵Ŀո���Ҫ��һ����ָ�򵥴ʵ����һ����ĸ
		reverse(left, right);  //�����巴ת���ٴη�ת���ʣ���ʹ����ƴд˳��ָ�����
		if (*str1 == ' ')  //���ڿո���ָ�����һλ�����޷������´�ѭ����
		{
			str1++;
		}
	}
}
int main()
{
	char arr[] = "student a am i";
	int sz = strlen(arr);
	printf("ԭ�����ַ���Ϊ��%s\n", arr);
	reverse_str(arr, sz);
	printf("��ת����ַ���Ϊ��%s", arr);
	system("pause");
	return 0;
}

#endif