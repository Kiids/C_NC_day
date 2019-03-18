#define _CRT_SECURE_NO_WARNINGS 1
#if 0
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//编写代码模拟三次密码输入的场景。最多能输入三次密码，密码正确，提示“登录成功”,密码错误，
//可以重新输入，最多输入三次。三次均错，则提示退出程序。
int main()
{
	char c[] = "123456";
	int i = 0;
	int j = 0;
	for (i = 0; i < 3; i++)
	{
		printf("请输入密码：");
		scanf("%s", c);
		if (strcmp(c, "123456") == 0)
			break;
		else
			printf("密码错误，请重新输入\n");
	}
	if (i == 3)
		printf("三次密码错误，程序退出\n");
	else
		printf("登陆成功\n");

	system("pause");
	return 0;
}

#endif
