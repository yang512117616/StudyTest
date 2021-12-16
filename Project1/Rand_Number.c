#define _CRT_SECURE_NO_WARNINGS 1


//生成随机数
int rand_number(int i)
{
	int ret = rand() % i;
	return ret;
}


//int* arr_put(int n,int k,int blue[])
//{
//	/*for (int l = 0; l < k; l++)
//	{
//		for (; i < n; i++)
//		{
//			blue[i] = rand_number(34);
//		}
//		red[l] = rand_number(17);
//	}
//	printf("\n\n");*/
//
//	for (int i = 0; i < n; i++)
//	{
//		blue[0] = rand_number(k);
//	}
//
//	return blue;
//
//}