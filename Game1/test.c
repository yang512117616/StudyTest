#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

menu()
{
	printf("********************************************************\n\n");
	printf("********************************************************\n\n");
	printf("********    1 . < play >      0 . < exit >      ********\n\n");
	printf("********************************************************\n\n");
	printf("********************************************************\n\n");
}

int main()
{
	int input = 0;
	do
	{
		menu();
		printf("��ѡ��>");
		scanf("%d", &input);
	} while (input);
	return 0;
}