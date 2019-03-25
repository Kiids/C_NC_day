#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	int choice = 0;
	int row = ROW, col = COL;
	char board[ROW][COL] = { 0 };
	char ret = 0;
	srand((unsigned int)time(NULL));
	InitBoard(board, row, col);
	DisplatBoard(board, row, col);
	do
	{
		printf("请输入1玩家先手，或2电脑先手进行选择：");
		scanf("%d", &choice);
		if (choice == 1 || choice == 2)
			break;
		else
			printf("输入错误，请重新选择。\n");
	} while (1);
	while (choice == 1)
	{
		PlayMove(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		//ComputerMove(board, row, col);
		ComputerMovePlus(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	while (choice == 2)
	{
		ComputerMovePlus(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		PlayMove(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
	}
	if (ret == '*')
		printf("恭喜玩家胜利！\n");
	else if (ret == '#')
		printf("电脑胜利！\n");
	else
		printf("平局！\n");
}

void InitBoard(char board[ROW][COL], int row, int col)
{
	//int i = 0, j = 0;
	//for (i = 0; i < row; i++)
	//{
	//	for (j = 0; j < col; j++)
	//	{
	//		board[i][j] = ' ';
	//	}
	//}
	memset(board, ' ', col*row);  //将棋盘初始化为‘ ’空格符号，效率更高
}

void DisplatBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf(" %c |", board[i][j]);
			else
				printf(" %c \n", board[i][j]);
		}
		for (j = 0; j < col; j++)
		{
			if (j < col - 1)
				printf("---|", board[i][j]);
			else
				printf("---\n", board[i][j]);
		}
	}
}

void PlayMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("玩家下棋：\n");
	while (1)
	{
		printf("请输入下棋的位置：");
		scanf("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else 
				printf("坐标已被占用，请重新输入。\n");
		}
		else 
			printf("坐标非法，请重新输入。\n");
	}
}

void ComputerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	printf("电脑下棋：\n");
	while (1)
	{
		x = rand() % row;
		y = rand() % col;
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//先手：正中间，对面如果走边中间位置，就落子在紧贴对方棋子的角位置。对方必定堵你，然后你就落子在刚才自己角位置棋子的旁边，必赢。
//      如果对方也会玩，就会先落子在角位置，基本最后就是和棋。
//后手：对方中间，你就在角位置，然后堵对方就行，就是和棋。
//以下嵌套循环时，电脑落子之后直接goto跳出所有循环，防止电脑落子不止一个
void ComputerMovePlus(char board[ROW][COL], int row, int col)  //电脑后手井字棋和棋
{
	int i = 0, j = 0;
	char win = 0;
	printf("电脑下棋：\n");
	while (1)
	{
		//如果可以则先占据中心点
		if (board[1][1] == ' ')
		{
			board[1][1] = '#';
			break;
		}
		//遍历检测空位，判断下#是否能赢，能赢则下
		for (i = 0; i < row; i++)
		{
			for (j = 0; j < col; j++)
			{
				if (board[i][j] == ' ')
				{
					board[i][j] = '#';
					win = IsWin(board, row, col);
					if (win != '#')
						board[i][j] = ' ';
					else
						goto end;
				}
			}
		}
		//遍历检测空位，判断下*玩家是否能赢，能则堵住该位置
		if (win != '#')
		{
			for (i = 0; i < row; i++)
			{
				for (j = 0; j < col; j++)
				{
					if (board[i][j] == ' ')
					{
						board[i][j] = '*';
						win = IsWin(board, row, col);
						if (win != '*')
							board[i][j] = ' ';
						else
						{
							board[i][j] = '#';
							goto end;
						}
					}
				}
			}
		}
		//若以上均不达到，则优先下在角位置（第一次对手占据中心则下在一个角）
		if (board[0][0] == ' ')
		{
			board[0][0] = '#';
			break;
		}
		else if (board[0][3] == ' ')
		{
			board[0][3] = '#';
			break;
		}
		else if (board[3][0] == ' ')
		{
			board[3][0] = '#';
			break;
		}
		else if (board[3][3] == ' ')
		{
			board[3][3] = '#';
			break;
		}
		//以上除外则随机寻找位置
		while (1)
		{
			i = rand() % row;
			j = rand() % col;
			if (board[i][j] == ' ')
			{
				board[i][j] = '#';
				goto end;
			}
		}
	}
    end:
	    ;
}

static int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == ' ')
				return 0;
		}
	}
	return 1;
}

char IsWin(char board[ROW][COL], int row, int col)
{
	/*
	int i;
	for (i = 0; i < row; i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
			return board[i][1];
	}
	for (i = 0; i < col; i++)
	{
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
			return board[1][i];
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
		return board[1][1];
	else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
		return board[1][1];
	else if (IsFull(board, row, col))
		return 'Q';
	return 'C';
	*/

	int i = 0, j = 0;
	int flag = 0;
	//一行相等
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}

	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[i][j] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	
	//一列相等
	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '*')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '*';
	}

	for (i = 0; i < row; i++)
	{
		flag = 0;
		for (j = 0; j < col; j++)
		{
			if (board[j][i] == '#')
				;
			else
			{
				flag = 1;
				break;
			}
		}
		if (flag != 1)
			return '#';
	}
	
	//主对角线相等
	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '*')
			;
		else
		{
			flag = 1;
			break;
		}
		
	}
	if (flag != 1)
		return '*';

	flag = 0;
	for (i = 0; i < row; i++)
	{
		if (board[i][i] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';

	//副对角线相等
	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '*')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '*';

	flag = 0;
	for (i = 0, j = col - 1; i < row, j >= 0; i++, j--)
	{
		if (board[i][j] == '#')
			;
		else
		{
			flag = 1;
			break;
		}

	}
	if (flag != 1)
		return '#';

	//均不相等
	if (flag)
	{
		if (IsFull(board, row, col))
			return 'Q';
		else
			return 'C';
	}

	//解决不是所有控件路径都返回值的警告
	else
	{
		return 'C';
	}
}