#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1


#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>


int main()
{
	char put_t[64] = { 0 };

	printf("你的电脑将在两分钟后关机，如果输入 ' 我是大笨猪 ' 则取消关机!!!\n\n\n请输入：>");
	//system("shutdown -s -t 120");
	while (1)
	{
		scanf("%s", put_t);
		printf("%s", put_t);
		if (0 == strcmp(put_t, "我是大笨猪"))
		{
			goto hear;
		}
		printf("输入有误，请重新输入：>");
	}



hear:
	system("shutdown -a");
	system("cls");
	printf("\n\n拜拜，大笨猪!!!\n\n");
	return 0;
}