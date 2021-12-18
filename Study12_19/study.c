#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

//冒泡排序非递归
void Bubble_sort(int arr[], int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		int flag = 0;
		int j = 0;
		//一趟冒泡过程
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

//冒泡递归
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
	//判断是否交换，如果没交换说明已经排序完成
	if (flag == 0)
	{
		return;
	}
	bubble_sort(arr, sz - 1);//sz-1 意思是每次排序会把最大数放最后，下次只需要排序最后一个数前面的数；
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