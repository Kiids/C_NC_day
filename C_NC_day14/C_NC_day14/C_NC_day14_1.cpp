#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB

//左旋一次
void left_move_1(char* str)
{
	char start = *str;
	char* cur = str;
	//字符向前移动一个位置
	while (*(cur + 1))
	{
		*cur = *(cur + 1);
		++cur;
	}
	//第一个字符移动到最后一个位置
	*cur = start;
}
void left_move(char* str, int k)
{
	k %= strlen(str);
	while (k--)
	{
		left_move_1(str);
	}
}
//以上算法时间复杂度O(kn)

//以下时间复杂度O(n)  三次逆转
//n / 2  ~  O(n)
void  reverse(char* start, char* end)
{
	while (start < end)
	{
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void  left_rotate(char * str, int k)
{
	int  len = strlen(str);
	//旋转前k个字符  第一次：0 ~ k - 1
	reverse(str, str + k - 1);
	//旋转剩余的字符串  第二次：k ~ len - 1   前两次加起来走了n/2 循环次数n/2
	reverse(str + k, str + len - 1);
	//旋转整体  第三次：0 ~ len - 1    循环次数n/2
	reverse(str, str + len - 1);
}
int main()
{
	char string[30];
	scanf("%s", string);
	int k = 0;
	printf("请输入你要旋转的字符个数:");
	scanf("%d", &k);
	if (k > (int)strlen(string)) {
		printf("输入有误\n");
	}
	left_rotate(string, k);
	printf("%s\n", string);
	system("pause");
	return 0;
}

#endif