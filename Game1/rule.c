#define _CRT_SECURE_NO_WARNINGS 1
#include "game.h"

int IsRule(char board[ROW][COL], int row, int col)
{
	
}

//��
char* RowRule(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[i][j] == board[i][j + 1] && board[i][j + 2] == board[i][j] && j + TYPE - 2 < COL)
			{
				if (j > 0 && board[i][j - 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i][j - 1];
				}
				else if (board[i][j] != ' ' && board[i][j + 3] == ' ')
				{
					return &board[i][j + 3];
				}
				else if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 3] && board[i][j + 2] == ' ' && j + TYPE - 2 < COL && board[i][j] != ' ')
				{
					return &board[i][j + 2];
				}
				else if (board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j + 1] == ' ' && j + TYPE - 2 < COL && board[i][j] != ' ')
				{
					return &board[i][j + 1];
				}
			}
		}
	}
	return NULL;
}

//��
char* ColRule(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (j = 0; j < ROW; j++)
	{
		for (i = 0; i < COL; i++)
		{
			if (board[i][j] == board[i + 1][j] && board[i + 2][j] == board[i][j] && i + TYPE - 2 < ROW)
			{
				if (board[i - 1][j] == ' ' && board[i][j] != ' ' && i > 0)
				{
					return &board[i - 1][j];
				}
				else if (board[i][j] != ' ' && board[i + 3][j] == ' ')
				{
					return &board[i + 3][j];
				}
				else if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 3][j] && board[i + 2][j] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 2][j];
				}
				else if (board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i + 1][j] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 1][j];
				}
			}
		}
	}

	return NULL;
}

//Ʋ
char* LowerLeft(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = TYPE - 1; j < COL; j++)//��ÿһ�еĵ�TYPE-1�п�ʼ
		{
			if (board[i][j] == board[i + 1][j - 1] && board[i + 2][j - 2] == board[i][j] && j + TYPE - 2 <= COL && i + TYPE - 2 < ROW)
			{
				if (j >= 3 && board[i + 3][j - 3] == ' ' && board[i][j] != ' ')
				{
					return &board[i + 3][j + 3];
				}
				else if (board[i][j] != ' ' && board[i - 1][j + 1] == ' ' && i > 0)
				{
					return &board[i - 1][j + 1];
				}
				else if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 3][j - 3] && board[i + 2][j - 2] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 2][j - 2];
				}
				else if (board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i + 1][j - 1] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 1][j - 1];
				}
			}
		}
	}

	return NULL;
}

//��
char* LowerRight(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//�ӵ�һ��Ԫ�ؿ�ʼ�ж�Ԫ�أ���� һ�еĵ�һ�����ǿո��Ԫ��
			//�����һ��Ԫ�صĲ� С����Ϸģʽ���Ӹ����򲻽����ж���
			if (board[i][j] == board[i + 1][j + 1] && board[i + 2][j + 2] == board[i][j] && i + TYPE - 2 < ROW)
			{
				if (i + j > 1 && board[i - 1][j - 1] == ' ' && board[i][j] != ' ')
				{
					return &board[i - 1][j - 1];
				}
				else if (board[i][j] != ' ' && board[i + 3][j + 3] == ' ')
				{
					return &board[i + 3][j + 3];
				}
				else if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 3][j + 3] && board[i + 2][j + 2] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 2][j + 2];
				}
				else if (board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i + 1][j + 1] == ' ' && i + TYPE - 2 < ROW && board[i][j] != ' ')
				{
					return &board[i + 1][j + 1];
				}
			}
		}
	}

	return NULL;
}