#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//ð������ǵݹ�
void Bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 0;
		int j = 0;
		//һ��ð�ݹ���
		for (j = 0; j < sz - 1 - i; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				int tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				flag = 1;
			}
		}
		if (flag == 0)
		{
			break;
		}
	}
}

//ð�ݵݹ�
void bubble_sort(int arr[], int sz)
{
	int i = 0, flag = 0;
	for (i = 0; i < sz - 1; i++)
	{
		if (arr[i] > arr[i + 1])
		{
			int tmp = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = tmp;
			flag = 1;
		}
	}
	//�ж��Ƿ񽻻������û����˵���Ѿ��������
	if (flag == 0)
	{
		return;
	}
	bubble_sort(arr, sz - 1);//sz-1 ��˼��ÿ�������������������´�ֻ��Ҫ�������һ����ǰ�������
}
int main()
{
	int i = 0;
	int arr[] = { 4,3,5,1,2,9,8,6,7,14,11,12,10,13 };
	int sz = sizeof(arr) / sizeof(arr[1]);
	bubble_sort(arr, sz);
	for (i = 0; i < sz - 1; i++)
	{
		printf("arr[%d]\t= %d\n", i, arr[i]);
	}


	return 0;
}