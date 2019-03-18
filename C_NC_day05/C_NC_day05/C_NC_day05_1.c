#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>

//完成猜数字游戏
void menu()
{
	printf("_________________________________\n");
	printf("__________   1. play    _________\n");
	printf("__________   0. exit    _________\n");
	printf("_________________________________\n");
}
void game()
{
	int num = rand() % 100 + 1;
	int a = 0;
	while (1)
	{
		printf("请输入猜的数字->");
		scanf("%d", &a);
		if (a > num)
			printf("猜大了\n");
		else if (a < num)
			printf("猜小了\n");
		else
		{
			printf("恭喜你，猜对了\n");
			break;
		}
	}
}
int main()
{
	int a = 0;
	srand((unsigned int)time(NULL));
	do {
		menu();
		printf("请输入你的选择：");
		scanf("%d", &a);
		switch (a)
		{
		case 1:
			game();
			break;
		case 0:
			break;
		default:
			printf("选择有误，请重新输入\n");
			break;
		}
	} while (a);

	system("pause");
	return 0;
}

#endif