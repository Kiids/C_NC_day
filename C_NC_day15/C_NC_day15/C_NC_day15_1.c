#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//һ��������ֻ�����������ǳ���һ�Σ�
//�����������ֶ����������Ρ�
//�ҳ�������ֻ����һ�ε����֣����ʵ�֡�
void Find(int arr[], int size){
	int i = 0;
	int ret = 0;  //��¼����ֵ���Ľ��
	int pos = 0;  //��¼ret������Ϊ��һ��Ϊ1��λ��
	int x = 0;  //��һ��ֵ�����x���õ�1��û����ͬ���ֵ�ֵ
	int y = 0;  //����һ��ֵ�����y���õ���1��û����ͬ���ֵ�ֵ
	for (i = 0; i < size; i++)  //������������������
	{
		ret ^= arr[i];
	}
	for (i = 0; i < 32; i++)  //�ҵ�ret������λ��һ��Ϊ1��λ��
	{
		if (1 == ((ret >> i) & 1))
		{
			pos = i;
			break;
		}
	}
	for (i = 0; i < size; i++)  //�������
	{
		if (1 == ((arr[i] >> pos) & 1))
		{
			x ^= arr[i];
		}
		else
			y ^= arr[i];
	}
	printf("x=%d��y=%d\n", x, y);
}
//1.������ֵ�����һ�𣬵õ�4��5���Ľ��1
//2.�ҵ������1�Ķ������е�һ��Ϊ1��λ��
//3.�������λ�÷�Ϊ���飬�ֱ���������͵õ����յĽ��
int main()
{
	int arr[] = { 1, 2, 3, 1, 2, 3, 4, 5 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	Find(arr, sz);
	system("pause");
	return 0;
}

/*
int main()
{
	int arr[] = { 4, 8, 8, 4, 5, 9, 3, 5 };
	int count = 0;
	int sz = sizeof(arr) / sizeof(arr[0]) - 1;
	int i = 0, j = 0;
	for (i = 0; i<sz; i++)
	{
		count = 0;
		for (j = 0; j<sz + 1; j++)
		{
			if (arr[i] == arr[j])
			{
				count++;
			}

		}
		if (count == 1)
		{
			printf("%d ", arr[i]);
		}
	}
	system("pause");
	return 0;
}
*/

#endif