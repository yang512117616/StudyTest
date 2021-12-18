#define _CRT_SECURE_NO_WARNINGS 

//#include <conio.h>
//#include <stdio.h>
//#include <string.h>

//#pragma comment(lib,"xxx.lib")//导入静态库

//int main()
//{
//	/* Display message until key is pressed. */
//	while (1) {
//		_cputs("Hit me!! ");
//		if (_kbhit()) {
//			//在这里可以监听并处理点击的事件 处理完了以后 你可以选择继续计时或做其他操作
//			break;
//		}
//	}
//	/* Use _getch to throw key away. */
//		printf("\nKey struck was '%c'\n", _getch());
	//int len = strlen("abc");
	//printf("%d\n", len);

	//printf("%d\n", strlen("abc"));//链式访问

	//char arr1[20] = { 0 };
	//char arr2[] = "bit";
	//strcpy(arr1, arr2);

	//printf("%s\n", arr1);//等效于 = > printf("%s\n", strcpy(arr1, arr2));

	//printf("%d", printf("%d", printf("%d", 43)));//4321  经典链式访问

	//return 0;
//}

//递归实现打印参数部分数字的每一位。
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

//用递归函数实现不使用临时变量来计算一个字符串的长度

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
//	printf("请输入一个字符串：>");
//	scanf("%s", arr);
//
//	printf("你输入的字符串长度为:>%d\n\n", My_strlen(arr));
//
//	printf("使用strlen函数计算得到长度为：>%d\n\n", strlen(arr));
//	return 0;
//}




//用递归实现n的阶乘
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
//	printf("请输入‘n’的值：>");
//	int n = 0;
//	scanf("%d", &n);
//	printf("%d是的阶乘是：>%d\n\n", n, Fac(n));
//
//	return 0;
//}

//用递归实现求第N个斐波那契数
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


//用循环实现求第N个斐波那契数
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



//计算1-n 中含有几个数字N.
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
//		while (num > 100 && num % 10 != 2)//这个while 判断 大于100且个位不含2的数  如 2215 数字进来 出循环 num就等于22了  2220出循环就是222
//		{
//			num /= 10;
//
//		}
//		while (num % 10 == 2)//判断个位含2的数  223322
//		{
//			num /= 10;
//			ret++;
//		}
//		while (num / 10 == 2)//判断十位
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

//递归实现把一个字符串逆转（不是反向打印） 如 arr1[]="abcdef";调用函数后arr1[]="fedcba";
int my_strlen(char* str)
{
	if (*str != '\0')
	{

		return 1 + my_strlen(str + 1);
	}
	return 0;
}
//非递归方式
//void reverse_string(char* arr)
//{
//	char c = '0';
//	int i = strlen(arr) - 1, j = 0;
//	for (j = 0; j < i; j++)
//	{
//		c = arr[i];//arr[i]等效于 *(arr + i);
//		arr[i] = arr[j];
//		arr[j] = c;
//		i--;
//	}
//	
//}

//递归方式
//reverse_string(char* arr)
//{
//	char tmp = *arr;//把字符串第一个字符存入临时tmp里。
//	int len = my_strlen(arr);//测量字符串长度；
//	*arr = *(arr + len - 1);//把字符串最后一个字符赋值给第一个字符；
//	*(arr + len - 1) = '\0';//把最后一个字符地址赋值'\0';
//	if (my_strlen(arr + 1) >= 2)//递归条件：当剩下字符串长度在2个以上时再调用自己；
//	{
//		reverse_string(arr + 1);
//	}
//	
//	*(arr + len - 1) = tmp;//把字符串第一个字符赋值给字符串最后一个字符地址；
//}


//用递归实现输入一个正整数，返回这个整数所有位之和
//int DigitSum(int n)
//{
//	if (n > 9)
//	{
//		return n % 10 + DigitSum(n / 10);
//	}
//	return n ;
//}

//用递归实现n的k次方
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

//二维数组
int main()
{
	//创建
	//int arr[3][4];
	//char ch[3][4];

	//创建的同时赋值
	//int arr1[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };//完全初始化
	//int arr2[3][4] = { 1,2,3,4,5,6,7,8 };//不完全初始化
	//int arr3[3][4] = { {1,3},{3,4},{4,5} };//分行初始化
	//int arr4[][4] = { {1,3},{3,4},{4,5} };//分行初始化

	int arr5[3][4] = { 1,2,3,4,5,6,7,8,9,10,11,12 };
	int i = 0, j = 0;
	int* p = arr5;
	char arr2[] = "去给i看的";
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