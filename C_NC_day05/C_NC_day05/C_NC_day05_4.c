#define _CRT_SECURE_NO_WARNINGS 1
#if 1
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

//编写一个程序，可以一直接收键盘字符，如果是小写字符就输出对应的大写字符，
//如果接收的是大写字符，就输出对应的小写字符，如果是数字不输出。
int main()
{
	int ch;
	printf("请输入字符：\n");
	while ((ch = getchar()) != EOF)
	{
		if (ch >= 'a' && ch <= 'z')
			//			printf("%c\n", ch-32);
			printf("%c\n", toupper(ch));
		else if (ch >= 'A'&&ch <= 'Z')
			//			printf("%c\n", ch+32);
			printf("%c\n", tolower(ch));
	}

	system("pause");
	return 0;
}

#endif
