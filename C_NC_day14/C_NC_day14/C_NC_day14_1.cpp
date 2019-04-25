#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//ʵ��һ�����������������ַ����е�k���ַ���
//ABCD����һ���ַ��õ�BCDA
//ABCD���������ַ��õ�CDAB
void  reverse(char* start, char* end){
	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void  left_rotate(char * str, int k){
	int  len = strlen(str);
	//��תǰk���ַ�
	reverse(str, str + k - 1);
	//��תʣ����ַ���
	reverse(str + k, str + len - 1);
	//��ת����
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