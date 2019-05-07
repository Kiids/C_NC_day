#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB

//����һ��
void left_move_1(char* str)
{
	char start = *str;
	char* cur = str;
	//�ַ���ǰ�ƶ�һ��λ��
	while (*(cur + 1))
	{
		*cur = *(cur + 1);
		++cur;
	}
	//��һ���ַ��ƶ������һ��λ��
	*cur = start;
}
void left_move(char* str, int k)
{
	k %= strlen(str);
	while (k--)
	{
		left_move_1(str);
	}
}
//�����㷨ʱ�临�Ӷ�O(kn)

//����ʱ�临�Ӷ�O(n)  ������ת
//n / 2  ~  O(n)
void  reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void  left_rotate(char * str, int k)
{
	int  len = strlen(str);
	//��תǰk���ַ�  ��һ�Σ�0 ~ k - 1
	reverse(str, str + k - 1);
	//��תʣ����ַ���  �ڶ��Σ�k ~ len - 1   ǰ���μ���������n/2 ѭ������n/2
	reverse(str + k, str + len - 1);
	//��ת����  �����Σ�0 ~ len - 1    ѭ������n/2
	reverse(str, str + len - 1);
}
int main()
{
	char string[30];
	scanf("%s", string);
	int k = 0;
	printf("��������Ҫ��ת���ַ�����:");
	scanf("%d", &k);
	if (k > (int)strlen(string)) {
		printf("��������\n");
	}
	left_rotate(string, k);
	printf("%s\n", string);
	system("pause");
	return 0;
}

#endif