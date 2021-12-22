#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 8
#define COL 8
#define TYPE 5

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* func(int board[ROW][COL], int row, int col)
{
	int* p = board;
	//printf("此时P指向了%d行%d列的%d\n\n", i, j, board[i][j]);
				

	while (1)
	{
		printf("此时P指向了%d\t下一个值是%d\n", *p,*(p + 1));
		if (*p == *(p + 1) && *p == *(p + 2) && *p != 0)
		{
			return p - 1;
		}
		p++;
	}
}

int* func1(int board[ROW][COL],int row,int col)
{
	return &board[row][col];
}

int main()
{

	int i = 0, j = 0;
	int board[ROW][COL] = 
	{
		{8,0,0,5,1,1,1,0},
		{0,0,1,1,1,1,1,0},
		{0,1,0,0,0,2,2,2},
		{0,0,1,0,0,0,0,0},
		{0,0,0,1,0,0,1,0},
		{0,0,0,0,1,0,1,0},
		{0,0,0,0,0,1,1,0},
		{0,0,0,0,0,0,1,9}
	};

	/*for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d\t", board[i][j]);
		}
		printf("\n\n");
	}

	printf("\n\n------------------------------------------------------------------------\n\n");*/

	//int* p = func(board, ROW, COL);
	int* p = &board[0][0];
	int* p1 = p + (ROW * COL - 1);
	if (p1 > p)
	{
		printf("hehe\n");
	}
	printf("%d\n\n", *p);
	printf("%d\n\n", *p1);
	//printf("%d\n\n", );


	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			printf("%d\t",board[i][j] );
		}
		printf("\n\n");
	}
		
	
	return 0;
}
