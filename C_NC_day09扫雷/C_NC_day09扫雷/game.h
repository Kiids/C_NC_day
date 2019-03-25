#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define ROW 9
#define COL 9
#define ROWS 11
#define COLS 11
#define EASY_COUNT 10

void game();
void InitBoard(char board[ROWS][COLS], int rows, int cols, char set);  //初始化棋盘
void DisplayBoard(char board[ROWS][COLS], int row, int col);  //打印棋盘
void SetMine(char board[ROWS][COLS], int row, int col);  //布置雷
void FindMine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //玩家寻找是否有雷
void SafeFirst(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //避免玩家第一次被炸死
void OpenMine(char mine[ROWS][COLS], char board[ROWS][COLS], int row, int col, int x, int y);  //若坐标周围没雷则实现展开
void FindMinePlus(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col);  //利用剩余未打开位置个数与设置的雷个数判断输赢