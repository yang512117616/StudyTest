#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//����������ֺ���


int number_t()
{
	int ret_t = rand() % 17;
	return ret_t;
}
int number()
{
	int ret = rand() % 36;
	return ret;
}
int main()
{
	//srand((unsigned int)time(NULL));
	int num_to = 0;
	printf("������һ�����������>");
	scanf("%d", &num_to);
	srand(num_to);
	int n = 0;
	int k = 0;
	printf("��������������>");
	scanf("%d", &n);
	printf("���������������>");
	scanf("%d", &k);
	printf("\n\n������ѡ�Ĳ�ƱΪ��>");
	for (int i = 0; i < n; i++)
	{
		int n = number();
		Sleep(800);
		printf("%d\t", n);
	}
	Sleep(888);
	printf("+\t");
	for (int l = 0; l < k; l++)
	{
		int j = number_t();
		Sleep(888);
		printf("%d\t", j);
	}
	printf("\n\n");

	return 0;
}