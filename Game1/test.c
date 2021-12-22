#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	//存储数据 -- 二维数组
	char board[ROW][COL];
	//初始化棋盘
	InitBoard(board, ROW, COL);
	//打印棋盘
	DisplayBoard(board, ROW, COL);

	char ret = 0;//获取游戏状态；
	while (1)
	{
		//玩家走
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//电脑走
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("恭喜您赢得了游戏！！！\n\n\n");
	}
	else if(ret == '#')
	{
		printf("真失败，这也能让电脑赢游戏？？？\n\n\n");
	}
	else
	{
		printf("不错嘛，跟电脑打成了平手！！！\n\n\n");
		DisplayBoard(board, ROW, COL);
	}

}

void menu()
{
	printf("********************************************************\n\n");
	printf("********************************************************\n\n");
	printf("****************      1 . < play >      ****************\n\n");
	printf("****************      0 . < exit >      ****************\n\n");
	printf("********************************************************\n\n");
	printf("********************************************************\n\n");
}

int main()
{
	int input = 0;
	//使用time函数生成随机数
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("请选择：>");
		scanf("%d", &input);
		switch (input)
		{
			case 1:
				game();
				break;
			case 0:
				break;
		
		default:
			system("cls");
			printf("输入错误，请重新选择！！！\n\n");
		
			break;
		}
	} while (input);
	return 0;
}