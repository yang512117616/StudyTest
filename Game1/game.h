#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//符号的定义
#define ROW 40
#define COL 40
#define TYPE 5

//函数声明

//初始化棋盘 -- 初始化空格
void InitBoard(char board[ROW][COL], int row, int col);//行可以省略，列不可以省略board[][COL]

//打印棋盘  --  打印数组的内容
void DisplayBoard(char board[ROW][COL], int row, int col);

//玩家走
void PlayerMove(char board[ROW][COL], int row, int col);

//电脑走
void ComputerMove(char board[ROW][COL], int row, int col);

//判断输赢 '*' -> 玩家赢  '#' -> 电脑赢 'Q' -> 平局  'C' - > 继续
char IsWin(char board[ROW][COL], int row, int col);

//判断是否平局
int IsDraw(char board[ROW][COL], int row, int col);

//判断规则
int IsRule(char board[ROW][COL], int row, int col);

//行
char* RowRule(char board[ROW][COL], int row, int col);

//列
char* ColRule(char board[ROW][COL], int row, int col);

//撇
char* LowerLeft(char board[ROW][COL], int row, int col);

//捺
char* LowerRight(char board[ROW][COL], int row, int col);

