#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	char mine[ROWS][COLS] = { 0 };
	char show[ROWS][COLS] = { 0 };
	InitBoard(mine, ROWS, COLS, '0');
	InitBoard(show, ROWS, COLS, '*');
	DisplayBoard(show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);
	SetMine(mine, ROW, COL);
	//DisplayBoard(mine, ROW, COL);  //布置雷后的显示
	SafeFirst(mine, show, ROW, COL);
	//DisplayBoard(mine, ROW, COL);  //第一次保护后的雷区显示
	//FindMine(mine, show, ROW, COL);
	FindMinePlus(mine, show, ROW, COL);
}

void InitBoard(char board[ROWS][COLS], int rows, int cols, char set)
{
	memset(board, set, rows*cols);
}

void DisplayBoard(char board[ROWS][COLS], int row, int col)
{
	int i = 0, j = 0;
	printf("____________________________\n");
	for (i = 0; i <= row; i++)
		printf("%d ", i);
	printf("\n");
	for (i = 1; i <= row; i++)
	{
		printf("%d ", i);
		for (j = 1; j <= col; j++)
			printf("%c ", board[i][j]);
		printf("\n");
	}
	printf("----------------------------\n");
}

void SetMine(char board[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int count = EASY_COUNT;
	while (count)
	{
		x = rand() % 9 + 1;
		y = rand() % 9 + 1;
		if (board[x][y] == '0')
		{
			board[x][y] = '1';
			count--;
		}
	}
}

static int GetMineCount(char mine[ROWS][COLS], int x, int y)
{
	return mine[x - 1][y] + mine[x - 1][y - 1] + mine[x][y - 1] + mine[x + 1][y - 1] + mine[x + 1][y] + mine[x + 1][y + 1] +
		mine[x][y + 1] + mine[x - 1][y + 1] - 8 * '0';
}

//有了展开函数之后，以下这个函数循环控制变量win的计算无法正确计算出已经排除的无雷个数
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int win = 0;
	while (win < row*col - EASY_COUNT - 1)  //有第一次的新手保护，额外再减1
	{
		printf("请输入你认为没有雷的坐标：");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，该位置有雷，游戏失败。\n雷区标识如下（有雷为1，无则为0）：\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int minecount = GetMineCount(mine, x, y);
				show[x][y] = minecount + '0';
				OpenMine(mine, show, ROW, COL, x, y);
				DisplayBoard(show, ROW, COL);
				win++;
			}
		}
		else
			printf("输入的坐标非法，请重新输入。\n");
	}
	if (win >= row*col - EASY_COUNT - 1)
	{
		printf("恭喜您，游戏成功！\n");
		DisplayBoard(mine, ROW, COL);
	}
}

//返回未知位置的个数
static int IsWin(char show[ROWS][COLS], int row, int col)
{
	int count = 0;
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (show[i][j] == '*')
			{
				count++;
			}
		}
	}
	return count;
}

void FindMinePlus(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	if (IsWin(show, ROW, COL) == EASY_COUNT)
	{
		printf("恭喜您，游戏成功！\n");
		//DisplayBoard(mine, ROW, COL);
		goto end;
	}
	while (1)
	{
		printf("请输入你认为没有雷的坐标：");
		scanf("%d%d", &x, &y);
		if (x > 0 && x <= row && y > 0 && y <= col)
		{
			if (mine[x][y] == '1')
			{
				printf("很遗憾，该位置有雷，游戏失败。\n雷区标识如下（有雷为1，无则为0）：\n");
				DisplayBoard(mine, ROW, COL);
				break;
			}
			else
			{
				int minecount = GetMineCount(mine, x, y);
				show[x][y] = minecount + '0';
				OpenMine(mine, show, ROW, COL, x, y);
				DisplayBoard(show, ROW, COL);
				if (IsWin(show, ROW, COL) == EASY_COUNT)
				{
					printf("恭喜您，游戏成功！\n");
					//DisplayBoard(mine, ROW, COL);
					break;
				}
			}
		}
		else
			printf("输入的坐标非法，请重新输入。\n");
	}
    end:
	    ;
}

void SafeFirst(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	int x = 0, y = 0;
	int x1 = 0, y1 = 0;
	printf("请输入你认为没有雷的坐标：");
	scanf("%d%d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
	{
		if (mine[x][y] == '1')
		{
			mine[x][y] = '0';
			while (1)  //在其余有空的地方设置这个雷
			{
				x1 = rand() % 9 + 1;
				y1 = rand() % 9 + 1;
				if (mine[x1][y1] == '0')
				{
					mine[x1][y1] = '1';
					break;
				}
			}
			int minecount = GetMineCount(mine, x, y);
			show[x][y] = minecount + '0';
			OpenMine(mine, show, ROW, COL, x, y);
			DisplayBoard(show, ROW, COL);
			if (IsWin(show, ROW, COL) == EASY_COUNT)
			{
				printf("恭喜您，游戏成功！\n");
				//DisplayBoard(mine, ROW, COL);
			}
		}
		else
		{
			int minecount = GetMineCount(mine, x, y);
			show[x][y] = minecount + '0';
			OpenMine(mine, show, ROW, COL, x, y);
			DisplayBoard(show, ROW, COL);
			if (IsWin(show, ROW, COL) == EASY_COUNT)
			{
				printf("恭喜您，游戏成功！\n");
				//DisplayBoard(mine, ROW, COL);
			}
		}
	}
	else
		printf("输入的坐标非法，请重新输入。\n");
}

void OpenMine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col, int x, int y)
{
	if (x > 0 && x <= row && y > 0 && y <= col) // 递归防止越界
	{
		if (mine[x][y] == '0')
		{
			int count = GetMineCount(mine, x, y);
			if (count == 0)
			{
				board[x][y] = ' ';
				if (board[x - 1][y - 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x - 1, y - 1);
				}
				if (board[x - 1][y] == '*')
				{
					OpenMine(mine, board, ROW, COL, x - 1, y);
				}
				if (board[x - 1][y + 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x - 1, y + 1);
				}
				if (board[x][y - 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x, y - 1);
				}
				if (board[x][y + 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x, y + 1);
				}
				if (board[x + 1][y - 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x + 1, y - 1);
				}
				if (board[x + 1][y] == '*')
				{
					OpenMine(mine, board, ROW, COL, x + 1, y);
				}
				if (board[x + 1][y + 1] == '*')
				{
					OpenMine(mine, board, ROW, COL, x + 1, y + 1);
				}
			}
			else
			{
				board[x][y] = count + '0';
			}
		}
	}
}
