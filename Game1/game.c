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

//��ӡ���� --  ���ʾ��Ǵ�ӡ��ά����ÿ��Ԫ�ص����� �� �ָ���
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

//�����
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0, y = 0;
	while (1)
	{
		printf("�����-- >\n\n���������꣺>");
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
			printf("����Ƿ���������������ӣ����������룡����\n\n");
			DisplayBoard(board, ROW, COL);

		}
	}
}

//������
void ComputerMove(char board[ROW][COL], int row, int col)
{
	int ret = 0;

	char* Row = RowRule(board, row, col);
	char* Col = ColRule(board, row, col);
	char* Lol = LowerLeft(board, row, col);
	char* Lor = LowerRight(board, row, col);
	
	printf("������ -- >\n\n");

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
					if (board[i][j - 1] == ' ' && j !=0)//��
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
					if (board[i][j + 1] == ' ')//��
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
					if (board[i - 1][j] == ' ' && i != 0)//��
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
					if (board[i + 1][j] == ' ' && i < ROW - 1)//��
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
					if (board[i - 1][j + 1] == ' ' && i != 0 && j < COL - 1)//����
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
					if (board[i + 1][j - 1] == ' ' && i < ROW - 1 && j != 0)//����
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
					if (board[i - 1][j - 1] == ' ' && i != 0 && j != 0)//����
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
					if (board[i + 1][j + 1] == ' ' && i < ROW - 1 && j < COL -1)//����
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

//�ж���Ӯ '*' -> ���Ӯ  '#' -> ����Ӯ 'Q' -> ƽ��  'C' - > ����
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0, j = 0;

	//�ж�һ��
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//�ж�һ�� -- �����ұ���ÿһ��Ԫ��
			//1��һ�д����ҵ�һ��Ԫ�ز����ڿո�
			//2�������Ԫ�����������һ��Ԫ�ص�Ԫ�ظ���
			//   ��С����Ϸģʽ���Ӹ���
			//3�����Ԫ�غ��¸�Ԫ�����
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

	//�ж�һ��
	//�� i �� j ����  --  ���ϵ��±���ÿһ��Ԫ��
	//����ͬ��
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


	//�ж�һƲ  --  ˼· --> �����ϵ������ж�Ԫ��
	for (i = 0; i < ROW; i++)
	{
		for (j = TYPE - 1; j < COL; j++)//��ÿһ�еĵ�TYPE-1�п�ʼ
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
	//�ж�һ��  --  ˼· --> �����ϵ������ж�Ԫ��
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			//�ӵ�һ��Ԫ�ؿ�ʼ�ж�Ԫ�أ���� һ�еĵ�һ�����ǿո��Ԫ��
			//�����һ��Ԫ�صĲ� С����Ϸģʽ���Ӹ����򲻽����ж���
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

	//�ж��Ƿ�ƽ��
	if (IsDraw(board, ROW, COL))
	{
		return 'Q';
	}
	else
	{
		return 'C';
	}
}

//�ж��Ƿ�ƽ��
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

