#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//��ȡһ�������������������е�ż��λ������λ���ֱ�������������С� 
int main()
{
	int n = 0;
	int i = 0;
	scanf("%d", &n);
	printf("��������Ϊ��");
	for (i = 31; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");
	printf("ż������Ϊ��");
	for (i = 30; i >= 0; i -= 2)
	{
		printf("%d ", (n >> i) & 1);
	}
	printf("\n");

	system("pause");
	return 0;
}

#endif