#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>

//��������

extern int rand_number(int);
extern void input_error();
//extern int* arr_put(int n);


int main()
{
	//srand((unsigned int)time(NULL));
	int num_to, n, i = 0, k, num_t = 0, num_w;
	int blue[16] = { 0 };
	int red[12] = { 0 };

	printf("������һ����������>");
	while (num_t = scanf("%d", &num_to) == 0 || num_t == EOF)
	{
		input_error();
	}

	srand(num_to);


	printf("\n���������������>");
	while (num_t = scanf("%d", &n) == 0 || num_t == EOF)
	{
		input_error();
	}


	printf("\n��������������>");
	while (num_t = scanf("%d", &k) == 0 || num_t == EOF)
	{
		input_error();
	}

	printf("\n���ԡ�%d���������ˡ�%d��������͡�%d��������", num_to, n, k);
	printf("\n\n������ѡ�Ĳ�ƱΪ��>");
	
	

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