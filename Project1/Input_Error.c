#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>	
#include <Windows.h>
#include <stdlib.h>

void input_error()
{
	int c = 0;
	printf("你输入的数字有误，请重新输入！！\n\n");
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
	printf("请输入：>");
	
	return;
}