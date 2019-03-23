#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	int row = ROW, col = COL;
	char board[ROW][COL] = { 0 };
	char ret = 0;
	srand((unsigned int)time(NULL));
	InitBoard(board, row, col);
	DisplatBoard(board, row, col);
	while (1)
	{
		PlayMove(board, row, col);
		DisplatBoard(board, row, col);
		ret = IsWin(board, row, col);
		if (ret != 'C')
			break;
		ComputerMove(board, row, col);
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
	//int i;
	//for (i = 0; i < row; i++)
	//{
	//	if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ')
	//		return board[i][1];
	//}
	//for (i = 0; i < col; i++)
	//{
	//	if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ')
	//		return board[1][i];
	//}
	//if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ')
	//	return board[1][1];
	//else if (board[2][0] == board[1][1] && board[1][1] == board[0][2] && board[1][1] != ' ')
	//	return board[1][1];
	//else if (IsFull(board, row, col))
	//	return 'Q';
	//return 'C';
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

	//不相等
	if (flag)
	{
		if (IsFull(board, row, col))
			return 'Q';
		else
			return 'C';
	}
}