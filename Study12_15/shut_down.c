#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1


#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <string.h>


int main()
{
	char put_t[64] = { 0 };

	printf("��ĵ��Խ��������Ӻ�ػ���������� ' ���Ǵ��� ' ��ȡ���ػ�!!!\n\n\n�����룺>");
	//system("shutdown -s -t 120");
	while (1)
	{
		scanf("%s", put_t);
		printf("%s", put_t);
		if (0 == strcmp(put_t, "���Ǵ���"))
		{
			goto hear;
		}
		printf("�����������������룺>");
	}



hear:
	system("shutdown -a");
	system("cls");
	printf("\n\n�ݰݣ�����!!!\n\n");
	return 0;
}