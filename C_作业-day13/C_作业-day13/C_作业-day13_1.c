#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//��������ʹ����ȫ����λ��ż��ǰ�档
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿�֡�
void move(int arr[], int sz)
{
	int *left = arr;
	int *right = arr + sz - 1;
	int tmp = 0;
	while (left < right)
	{
		while ((left < right) && (*left) % 2 != 0)  //����
			left++;
		while ((left < right) && (*right) % 2 == 0)  //ż��
			right--;
		if (left < right)
		{
			tmp = *left;
			*left = *right;
			*right = tmp;
		}
	}
}
int main()
{
	int arr[10] = { 0 };
	int i = 0, sz = 0;
	printf("������10�����֣�\n");
	for (i = 0; i < 10; i++)
	{
		scanf("%d", &arr[i]);
	}
	sz = sizeof(arr) / sizeof(arr[0]);
	move(arr, sz);
	for (i = 0; i < sz; i++)
	{
		printf("%d ", arr[i]);
	}
	system("pause");
	return 0;
}

#endif