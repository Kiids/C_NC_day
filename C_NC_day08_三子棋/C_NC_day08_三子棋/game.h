#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 3
#define COL 3

void game();
void InitBoard(char board[ROW][COL], int row, int col);  //初始化棋盘
void DisplatBoard(char board[ROW][COL], int row, int col);  //打印棋盘
void PlayMove(char board[ROW][COL], int row, int col);  //玩家下棋
void ComputerMove(char board[ROW][COL], int row, int col);  //电脑下棋
char IsWin(char board[ROW][COL], int row, int col);  //判断输赢 *玩家赢 #电脑赢 Q平局 C继续
void ComputerMovePlus(char board[ROW][COL], int row, int col);  //电脑机智一点的下棋
