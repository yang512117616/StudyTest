#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

int main()
{
	int k;
	scanf("%d", &k);

	for (int i = 1;i < k; i++)
	{
		if(1==i%2)
		printf("%d\t", i);
	}
	return 0;
 }