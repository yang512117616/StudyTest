#define _CRT_SECURE_NO_WARNINGS 

//#include <conio.h>
//#include <stdio.h>
//#include <string.h>

//#pragma comment(lib,"xxx.lib")//���뾲̬��

//int main()
//{
//	/* Display message until key is pressed. */
//	while (1) {
//		_cputs("Hit me!! ");
//		if (_kbhit()) {
//			//��������Լ��������������¼� ���������Ժ� �����ѡ�������ʱ������������
//			break;
//		}
//	}
//	/* Use _getch to throw key away. */
//		printf("\nKey struck was '%c'\n", _getch());
	//int len = strlen("abc");
	//printf("%d\n", len);

	//printf("%d\n", strlen("abc"));//��ʽ����

	//char arr1[20] = { 0 };
	//char arr2[] = "bit";
	//strcpy(arr1, arr2);

	//printf("%s\n", arr1);//��Ч�� = > printf("%s\n", strcpy(arr1, arr2));

	//printf("%d", printf("%d", printf("%d", 43)));//4321  ������ʽ����

	//return 0;
//}

//�ݹ�ʵ�ִ�ӡ�����������ֵ�ÿһλ��
//#include <stdio.h>
//
//void print(unsigned int n)
//{
//	
//	if (n > 9)
//	{
//		print(n / 10);
//	}
//	printf("%d", n % 10);
//	return;
//}
//
//int main()
//{
//	unsigned int num = 0;
//	scanf("%u", &num);
//	print(num);
//	return 0;
//}
#include <stdio.h>
#include <string.h>

//�õݹ麯��ʵ�ֲ�ʹ����ʱ����������һ���ַ����ĳ���

//int My_strlen(char* arr)
//{
//	if (*arr != '\0')
//	{
//		return 1 + My_strlen(arr + 1);
//
//	}
//	else
//	{
//		return 0;
//	}
//}
//
//int main()
//{
//	/*char arr[] = "hello world!!!";*/
//	char arr[] = "0";
//
//	printf("������һ���ַ�����>");
//	scanf("%s", arr);
//
//	printf("��������ַ�������Ϊ:>%d\n\n", My_strlen(arr));
//
//	printf("ʹ��strlen��������õ�����Ϊ��>%d\n\n", strlen(arr));
//	return 0;
//}




//�õݹ�ʵ��n�Ľ׳�
//int Fac(int n)
//{
//	if (n <= 1)
//	{
//		return 1;
//	}
//	else
//	{
//
//		return n * Fac(n - 1);
//	}
//}
//
//int main()
//{
//	printf("�����롮n����ֵ��>");
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d�ǵĽ׳��ǣ�>%d\n\n", n, Fac(n));
//
//	return 0;
//}

//�õݹ�ʵ�����N��쳲�������
//int Fib(int n)
//{
//	if (n <= 2)
//	{
//		return 1;
//	}
//	else
//	{
//		return Fib(n - 1) + Fib(n - 2);
//	}
//}


//��ѭ��ʵ�����N��쳲�������
//int Fib(int n)
//{
//	int a = 1, b = 1, c = 0;
//	while (n > 2)
//	{
//		c = a + b;
//		a = b;
//		b = c;
//		n--;
//	}
//	return c;
//}



//����1-n �к��м�������N.
//int func(int num)
//{
//
//	int ret = 0;
//	if (num <= 100)
//	{
//
//		if (num % 10 == 2)
//		{
//			ret++;
//		}
//		if (num / 10 == 2)
//		{
//			ret++;
//		}
//	}
//	while (num > 100)
//	{
//
//		while (num > 100 && num % 10 != 2)//���while �ж� ����100�Ҹ�λ����2����  �� 2215 ���ֽ��� ��ѭ�� num�͵���22��  2220��ѭ������222
//		{
//			num /= 10;
//
//		}
//		while (num % 10 == 2)//�жϸ�λ��2����  223322
//		{
//			num /= 10;
//			ret++;
//		}
//		while (num / 10 == 2)//�ж�ʮλ
//		{
//			num /= 10;
//			ret++;
//		}
//		
//	}
//	return ret;
//}
//
//int main()
//{
//	int num = 0, i = 0, sum = 0;
//	for (i = 1; i <= 100; i++)//2 12 20 21 22 23 24 25 26 27 28 29
//	{
//		num += func(i);
//		//sum += num;
//	}
//	printf("%d", num);
//	return 0;
//}

//�ݹ�ʵ�ְ�һ���ַ�����ת�����Ƿ����ӡ�� �� arr1[]="abcdef";���ú�����arr1[]="fedcba";
int my_strlen(char* str)
{
	if (*str != '\0')
	{

		return 1 + my_strlen(str + 1);
	}
	return 0;
}
//�ǵݹ鷽ʽ
//void reverse_string(char* arr)
//{
//	char c = '0';
//	int i = strlen(arr) - 1, j = 0;
//	for (j = 0; j < i; j++)
//	{
//		c = arr[i];//arr[i]��Ч�� *(arr + i);
//		arr[i] = arr[j];
//		arr[j] = c;
//		i--;
//	}
//	
//}

//�ݹ鷽ʽ
//reverse_string(char* arr)
//{
//	char tmp = *arr;//���ַ�����һ���ַ�������ʱtmp�
//	int len = my_strlen(arr);//�����ַ������ȣ�
//	*arr = *(arr + len - 1);//���ַ������һ���ַ���ֵ����һ���ַ���
//	*(arr + len - 1) = '\0';//�����һ���ַ���ַ��ֵ'\0';
//	if (my_strlen(arr + 1) >= 2)//�ݹ���������ʣ���ַ���������2������ʱ�ٵ����Լ���
//	{
//		reverse_string(arr + 1);
//	}
//	
//	*(arr + len - 1) = tmp;//���ַ�����һ���ַ���ֵ���ַ������һ���ַ���ַ��
//}


//�õݹ�ʵ������һ�������������������������λ֮��
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	return n ;
//}

//�õݹ�ʵ��n��k�η�
//double sqrt_t(int n, int k)
//{
//	if (k == 0)
//	{
//		return 1;
//	}
//	else if (k > 0)
//	{
//		return n * sqrt_t(n, k - 1);
//	}
//	else
//	{
//		return 1 / sqrt_t(n, -k);
//	}
//}

//int main()
//
//{
//	int ch[] = "about";
//	int ch1[] = { 'a','b','o','u','t' };
//	printf("%s\n\n%s\n", ch, ch1);
//	printf("%d\t%d\t%d\t%d\n", sizeof(ch), strlen(ch), sizeof(ch1), strlen(ch1));
//	return 0;
//}

//��ά����
int main()
{
	//����
	//int arr[3][4];
	//char ch[3][4];

	//������ͬʱ��ֵ
	//int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };//��ȫ��ʼ��
	//int arr2[3][4] = { 1,2,3,4,5,6,7,8 };//����ȫ��ʼ��
	//int arr3[3][4] = { {1,3},{3,4},{4,5} };//���г�ʼ��
	//int arr4[][4] = { {1,3},{3,4},{4,5} };//���г�ʼ��

	int arr5[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int i = 0, j = 0;
	int* p = arr5;
	char arr2[] = "ȥ��i����";
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 4; j++)
		{
			//printf("&arr5[%d][%d] = %p\t", i, j, &arr5[i][j]);
			printf("%s %d\t", arr2, *p);
			p++;
		}
		printf("\n\n");
	}

	return 0;
}