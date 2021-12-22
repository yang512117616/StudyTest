#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


//���ŵĶ���
#define ROW 40
#define COL 40
#define TYPE 5

//��������

//��ʼ������ -- ��ʼ���ո�
void InitBoard(char board[ROW][COL], int row, int col);//�п���ʡ�ԣ��в�����ʡ��board[][COL]

//��ӡ����  --  ��ӡ���������
void DisplayBoard(char board[ROW][COL], int row, int col);

//�����
void PlayerMove(char board[ROW][COL], int row, int col);

//������
void ComputerMove(char board[ROW][COL], int row, int col);

//�ж���Ӯ '*' -> ���Ӯ  '#' -> ����Ӯ 'Q' -> ƽ��  'C' - > ����
char IsWin(char board[ROW][COL], int row, int col);

//�ж��Ƿ�ƽ��
int IsDraw(char board[ROW][COL], int row, int col);

//�жϹ���
int IsRule(char board[ROW][COL], int row, int col);

//��
char* RowRule(char board[ROW][COL], int row, int col);

//��
char* ColRule(char board[ROW][COL], int row, int col);

//Ʋ
char* LowerLeft(char board[ROW][COL], int row, int col);

//��
char* LowerRight(char board[ROW][COL], int row, int col);

