#define _CRT_SECURE_NO_WARNINGS 1
#if 0

#include <stdio.h>
#include <stdlib.h>

//日本某地发生了一件谋杀案，警察通过排查确定杀人凶手必为4个 
//嫌疑犯的一个。以下为4个嫌疑犯的供词。 
//A说：不是我。 
//B说：是C。 
//C说：是D。 
//D说：C在胡说 
//已知3个人说了真话，1个人说的是假话。 
//现在请根据这些信息，写一个程序来确定到底谁是凶手。 

void predict()
{
	int killer = 0;
	// a, b, c, d --> 1, 2, 3, 4
	for (killer = 1; killer <= 4; killer++)
	{
		if ((killer != 1) + (killer == 3) + (killer == 4) + (killer != 4) == 3)
		{
			printf("凶手是：%c\n", killer + 'A' - 1);
		}
	}
}
void predict2()
{
	char killer = 0;
	for (killer = 'A'; killer <= 'D'; killer++)
	{
		if ((killer != 'A') + (killer == 'C') + (killer == 'D') + (killer != 'D') == 3)
		{
			printf("凶手是：%c\n", killer);
		}
	}
}

int main()
{
	int murder = 0;
	for (murder = 'A'; murder <= 'D'; murder++)
	{
		if (((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D')) == 3)  //三真一假，在if语句的，括号里为真结果为1，要是假结果为0。因此if括号  后面若成立，必定为三真一假，即必定等于3.  
		{
			printf("Murder is %c\n", murder);
		}
	}

	system("pause");
	return 0;
}

#endif