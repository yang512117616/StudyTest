#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void InitBoard(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘 --  本质就是打印二维数组每个元素的内容 和 分割线
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0; i < row; i++)
	{
		int j = 0;
		if (i == 0)
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					printf("\t    %d  ", j + 1);
				}
				else if (j > 9)
				{
					printf("%d  ", j + 1);
				}
				else
				{
					printf(" %d  ", j + 1);
				}
			}
			printf("\n\n");
		}
		for (j = 0; j < col; j++)
		{
			if (j == 0 && i < 9)
			{
				printf("\t%d   %c ",i + 1,board[i][j]);
			}
			else if(i >= 9 && j == 0)
			{
				printf("\t%d  %c ", i + 1, board[i][j]);
			}
			else
			{
				printf(" %c ", board[i][j]);
			}
			if (j < col - 1)
			{
				printf("|");
			}
		}
		printf("\n");
		if (i < row - 1)
		{
			for (j = 0; j < col; j++)
			{
				if (j == 0)
				{
					printf("\t   ---");
				}
				else
				{

					printf("---");
				}
				if (j < col - 1)
				{
					printf("|");
				}
			}
		}
		printf("\n");
	}
}

//玩家走
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("玩家走-- >\n\n请输入坐标：>");
		scanf("%d.%d", &x, &y);
		if (x <= row && x >= 1 && y <= col && y >= 1 && board[x - 1][y - 1] == ' ')
		{
			board[x - 1][y - 1] = '*';
			DisplayBoard(board, ROW, COL);
			break;
		}
		else
		{
			system("cls");
			getchar();
			printf("输入非法或该坐标已有棋子，请重新输入！！！\n\n");
			DisplayBoard(board, ROW, COL);

		}
	}
}

//电脑走
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int ret = 0;

	char* Row = RowRule(board, row, col);
	char* Col = ColRule(board, row, col);
	char* Lol = LowerLeft(board, row, col);
	char* Lor = LowerRight(board, row, col);
	
	printf("电脑走 -- >\n\n");

	if (NULL == Row && NULL == Col && NULL == Lol && NULL == Lor)
	{
		goto hear;
	}
	else if (NULL != Row)
	{
		*Row = '#';
		DisplayBoard(board, row, col);
		return;
	}
	else if (NULL != Col)
	{
		*Col = '#';
		DisplayBoard(board, row, col);
		return;
	}
	else if (NULL != Lol)
	{
		*Lol = '#';
		DisplayBoard(board, row, col);
		return;
	}
	else if (NULL != Lor)
	{
		*Lor = '#';
		DisplayBoard(board, row, col);
		return;
	}


	int i = 0, j = 0;
hear:
	for (j = 0; j < ROW; j++)
	{
		for (i = 0; i < COL; i++)
		{
			if (board[i][j] == '*')
			{
				switch (rand() % 8 + 1)
				{
				case 1:
					if (board[i][j - 1] == ' ' && j !=0)//左
					{
						board[i][j - 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 2:
					if (board[i][j + 1] == ' ')//右
					{
						board[i][j + 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 3:
					if (board[i - 1][j] == ' ' && i != 0)//上
					{
						board[i - 1][j] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 4:
					if (board[i + 1][j] == ' ' && i < ROW - 1)//下
					{
						board[i + 1][j] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 5:
					if (board[i - 1][j + 1] == ' ' && i != 0 && j < COL - 1)//右上
					{
						board[i - 1][j + 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 6:
					if (board[i + 1][j - 1] == ' ' && i < ROW - 1 && j != 0)//左下
					{
						board[i + 1][j - 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 7:
					if (board[i - 1][j - 1] == ' ' && i != 0 && j != 0)//左上
					{
						board[i -1][j - 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				case 8:
					if (board[i + 1][j + 1] == ' ' && i < ROW - 1 && j < COL -1)//右下
					{
						board[i + 1][j + 1] = '#';
						DisplayBoard(board, ROW, COL);
						return;
					}
					else
					{
						goto hear;
					}
				default:

					break;
				}
			}
		}
	}
}

//判断输赢 '*' -> 玩家赢  '#' -> 电脑赢 'Q' -> 平局  'C' - > 继续
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;

	//判断一行
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//判断一行 -- 从左到右遍历每一行元素
			//1、一行从左到右第一个元素不等于空格
			//2、从这个元素起到这行最后一个元素的元素个数
			//   不小于游戏模式棋子个数
			//3、这个元素和下个元素相等
			if (board[i][j] != ' ' && j + TYPE - 1 < COL)
			{

				int k = 1;
				int ret = TYPE - 1;

				while (ret)
				{
					if (board[i][j] == board[i][j + k])
					{
						ret--;
						k++;
					}
					else
					{
						break;
					}
				}
				if (ret == 0)
				{
					return board[i][j];
				}
			}
		}
	}

	//判断一列
	//把 i 和 j 交换  --  从上到下遍历每一列元素
	//条件同上
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (board[j][i] != ' ' && j + TYPE - 1 < COL)
			{

				int k = 1;
				int ret = TYPE - 1;

				while (ret)
				{
					if (board[j][i] == board[j + k][i])
					{
						ret--;
						k++;
					}
					else
					{
						break;
					}
				}
				if (ret == 0)
				{
					return board[j][i];
				}
			}
		}
	}


	//判断一撇  --  思路 --> 从右上到左下判断元素
	for (i = 0; i < ROW; i++)
	{
		for (j = TYPE - 1; j < COL; j++)//从每一行的第TYPE-1列开始
		{
			if (board[i][j] != ' ')
			{
				int k = 1;
				int ret = TYPE - 1;

				while (ret)
				{
					if (board[i][j] == board[i + k][j - k])
					{
						ret--;
						k++;
					}
					else
					{
						break;
					}
				}
				 if (ret == 0)
				{
					return board[i][j];
				}
			}
		}
	}
	//判断一捺  --  思路 --> 从左上到右下判断元素
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//从第一个元素开始判断元素，如果 一行的第一个不是空格的元素
			//到最后一列元素的差 小于游戏模式棋子个数则不进行判断了
			if (board[i][j] != ' ' && COL - j > TYPE - 1)
			{
				int k = 1;
				int ret = TYPE - 1;

				while (ret)
				{
					if (board[i][j] == board[i + k][j + k])
					{
						ret--;
						k++;
					}
					else
					{
						break;
					}
				}
				if (ret == 0)
				{
					return board[i][j];
				}
			}
		}
	}

	//判断是否平局
	if (IsDraw(board, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}

//判断是否平局
int IsDraw(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0, ret = 0;
	for (i = 0; i < row; i++)
	{
		for (j = 0; j < col; j++)
		{
			if (board[i][j] != ' ')
			{
				ret++;
			}
		}
	}
	if (ret == ROW * COL)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

