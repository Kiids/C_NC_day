#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//����ˮ��1ƿ��ˮ1Ԫ��2����ƿ���Ի�һƿ��ˮ��
//��20Ԫ�����Զ�����ˮ��
//���ʵ�֡�
int Num(int n)
{
	if (n != 0)
	{
		if (n != 1)
		{
			if (n % 2 == 0)
			{
				return n + Num(n / 2);//ż��ֱ�ӷ��ص�n�еĸ����ӵ�n-1�еĸ���
			}
			else
			{
				return (n - 1) + Num((n / 2) + 1);//����ʱ�ɵ�n�����µ�һ��Ų����n-1�У���n-1�еĽ��м���
			}
		}
		else
		{
			return 1;
		}
	}
	else
	{
		return 0;
	}
}
int main()
{
	int n = 0;
	printf("�������\n");
	scanf("%d", &n);
	printf("%dԪ���Ժ�%dƿ��ˮ\n", n, 2 * n - 1);  //����һ���ҹ��ɣ����ɸպ���nԪǮ�ܺ�2*n-1ƿˮ��
	printf("%dԪ���Ժ�%dƿ��ˮ\n", n, Num(n));  //���������õݹ�ķ������㣻
	system("pause");
	return 0;
}

#endif