#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>	
#include <Windows.h>
#include <stdlib.h>

void input_error()
{
	int c = 0;
	printf("������������������������룡��\n\n");
	system("pause");
	while ( 1 )
	{
		c = getchar();
		if (c == EOF || c == '\n')
		{
			break;
		}
	}
	system("cls");
	printf("�����룺>");
	
	return;
}