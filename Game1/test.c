#define _CRT_SECURE_NO_WARNINGS 1

#include "game.h"

void game()
{
	//�洢���� -- ��ά����
	char board[ROW][COL];
	//��ʼ������
	InitBoard(board, ROW, COL);
	//��ӡ����
	DisplayBoard(board, ROW, COL);

	char ret = 0;//��ȡ��Ϸ״̬��
	while (1)
	{
		//�����
		PlayerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
		//������
		ComputerMove(board, ROW, COL);
		ret = IsWin(board, ROW, COL);
		if (ret != 'C')
		{
			break;
		}
	}
	if (ret == '*')
	{
		printf("��ϲ��Ӯ������Ϸ������\n\n\n");
	}
	else if(ret == '#')
	{
		printf("��ʧ�ܣ���Ҳ���õ���Ӯ��Ϸ������\n\n\n");
	}
	else
	{
		printf("����������Դ����ƽ�֣�����\n\n\n");
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
	//ʹ��time�������������
	srand((unsigned int) time(NULL));
	do
	{
		menu();
		printf("��ѡ��>");
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
			printf("�������������ѡ�񣡣���\n\n");
		
			break;
		}
	} while (input);
	return 0;
}