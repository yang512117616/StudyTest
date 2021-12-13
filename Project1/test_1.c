#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//生成随机数字函数


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
	printf("请输入一个随机整数：>");
	scanf("%d", &num_to);
	srand(num_to);
	int n = 0;
	int k = 0;
	printf("请输入红球个数：>");
	scanf("%d", &n);
	printf("请输入蓝球个数：>");
	scanf("%d", &k);
	printf("\n\n给您机选的彩票为：>");
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