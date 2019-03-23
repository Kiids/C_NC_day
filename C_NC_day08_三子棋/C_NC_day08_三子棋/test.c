#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void menu()
{
	printf("****************************\n");
	printf("******    1. play     ******\n");
	printf("******    0. exit     ******\n");
	printf("****************************\n");
}
void test()
{
	int input = 0;
	do
	{
		menu();
		printf("请输入数字选择->");
		scanf("%d", &input);
		switch (input)
		{
		    case 1:
				game();
				break;
			case 0:
				break;
			default:
				printf("输入有误，请重新输入\n");
				break;
		}
	} while (input);
}
int main()
{
	test();

	system("pause");
	return 0;
}