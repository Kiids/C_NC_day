#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//实现一个函数，可以左旋字符串中的k个字符。
//ABCD左旋一个字符得到BCDA
//ABCD左旋两个字符得到CDAB
void  reverse(char* start, char* end){
	while (start < end){
		char temp = *start;
		*start = *end;
		*end = temp;
		start++;
		end--;
	}
}
void  left_rotate(char * str, int k){
	int  len = strlen(str);
	//旋转前k个字符
	reverse(str, str + k - 1);
	//旋转剩余的字符串
	reverse(str + k, str + len - 1);
	//旋转整体
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