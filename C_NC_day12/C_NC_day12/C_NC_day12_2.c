#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//��ʹ�ã�a+b��/2���ַ�ʽ������������ƽ��ֵ�� 
int main()
{
	int a = 0, b = 0, average = 0;
	printf("����������������\n");
	scanf("%d%d", &a, &b);
	average = (a + b) >> 1;
	printf("a��b��ƽ��ֵΪ��%d\n", average);
	system("pause");
	return 0;
}

#endif