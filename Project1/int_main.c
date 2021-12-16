#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//函数申明

extern int rand_number(int);
extern void input_error();
//extern int* arr_put(int n);


int main()
{
	//srand((unsigned int)time(NULL));
	int num_to, n, i = 0, k, num_t = 0, num_w;
	int blue[16] = { 0 };
	int red[12] = { 0 };

	printf("请输入一个正整数：>");
	while (num_t = scanf("%d", &num_to) == 0 || num_t == EOF)
	{
		input_error();
	}

	srand(num_to);


	printf("\n请输入蓝球个数：>");
	while (num_t = scanf("%d", &n) == 0 || num_t == EOF)
	{
		input_error();
	}


	printf("\n请输入红球个数：>");
	while (num_t = scanf("%d", &k) == 0 || num_t == EOF)
	{
		input_error();
	}

	printf("\n您以‘%d’数生成了‘%d’个蓝球和‘%d’个红球。", num_to, n, k);
	printf("\n\n给您机选的彩票为：>");
	
	

	for (int l = 0; l < k; l++)
	{
		for (; i < n; i++)
		{
			blue[i] = rand_number(34);
		}
		red[l] = rand_number(17);
	}
	printf("\n\n");

	
	for (int i = 0; i < n; i++)
	{
		printf("%d\t", blue[i]);
	}

	return 0;
}