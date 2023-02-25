#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
////有1,2,3,4个数字，能组成多少个互不相同且无重复数字的三位数？都是多少？
//int main()
//{
//	int i= 0, j = 0, k = 0;
//	int size = 0;
//	for ( i = 1; i < 5; i++)
//	{
//		for (j = 1; j < 5; j++)
//		{
//			for (k = 1; k < 5; k++)
//			{
//				if (i != k && i != j && j != k)
//				{
//					printf("%d%d%d\t", i, j, k);
//					size++;
//				}
//			}
//		}
//	}
//	printf("size = %d\n", size);
//	return 0;
//}

//企业发放的奖金根据利润提成。
//
//利润(I)低于或等于10万元时，奖金可提10% ；
//利润高于10万元，低于20万元时，低于10万元的部分按10% 提成，高于10万元的部分，可提成7.5 % ；
//20万到40万之间时，高于20万元的部分，可提成5 % ；
//40万到60万之间时高于40万元的部分，可提成3 % ；
//60万到100万之间时，高于60万元的部分，可提成1.5 % ；
//高于100万元时，超过100万元的部分按1 % 提成。
//从键盘输入当月利润I，求应发放奖金总数？
//<100000	//100000<I<200000	//200000<I<400000	//400000<I<600000	//600000<I<1000000
//int main()
//{
//    double i;
//    double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
//    printf("你的净利润是：");
//    scanf("%lf", &i);
//    bonus1 = 100000 * 0.1;
//    bonus2 = bonus1 + 100000 * 0.075;
//    bonus4 = bonus2 + 200000 * 0.05;
//    bonus6 = bonus4 + 200000 * 0.03;
//    bonus10 = bonus6 + 400000 * 0.015;
//    if (i <= 100000) {
//        bonus = i * 0.1;
//    }
//    else if (i <= 200000) {
//        bonus = bonus1 + (i - 100000) * 0.075;
//    }
//    else if (i <= 400000) {
//        bonus = bonus2 + (i - 200000) * 0.05;
//    }
//    else if (i <= 600000) {
//        bonus = bonus4 + (i - 400000) * 0.03;
//    }
//    else if (i <= 1000000) {
//        bonus = bonus6 + (i - 600000) * 0.015;
//    }
//    else if (i > 1000000) {
//        bonus = bonus10 + (i - 1000000) * 0.01;
//    }
//    printf("提成为：bonus=%0.2lf\n", bonus);
//
//	return 0;
//}
//利润高于10万元，低于20万元时，低于10万元的部分按10% 提成，高于10万元的部分，可提成7.5 % ；
//20万到40万之间时，高于20万元的部分，可提成5 % ；
//40万到60万之间时高于40万元的部分，可提成3 % ；
//60万到100万之间时，高于60万元的部分，可提成1.5 % ；
//高于100万元时，超过100万元的部分按1 % 提成。
//int main()
//{
//	double i = 0;
//	printf("请输入当前利润:>");
//	scanf("%lf", &i);
//	
//	double i1 = i * 0.1;
//	double i2 = 10000 + (i - 100000) * 0.075;
//	double i3 = 10000 + 7500 + (i - 200000) * 0.05;
//	double i4 = 10000 + 7500 + 5000 + (i - 400000) * 0.03;
//	double i5 = 10000 + 7500 + 5000 + 3000 + (i - 600000) * 0.015;
//	double i6 = 10000 + 7500 + 5000 + 3000 + 1500 + (i - 1000000) * 0.001;
//
//	
//	if (i<=100000)
//	{
//		printf("你的奖金为:>%0.2lf", i1);
//	}
//	else if (100000 < i < 200000)
//	{
//		printf("你的奖金为:>%0.2lf", i2);
//	}
//	else if (200000 < i < 400000)
//	{
//		printf("你的奖金为:>%0.2lf", i3);
//	}
//	else if (400000 < i < 600000)
//	{
//		printf("你的奖金为:>%0.2lf", i4);
//	}
//	else if (600000 < i < 1000000)
//	{
//		printf("你的奖金为:>%0.2lf", i5);
//	}
//	else if (i>1000000)
//	{
//		printf("你的奖金为:>%0.2lf", i6);
//	}
//	return 0;
//}
//	一个整数，它加上100后是一个完全平方数，再加上168又是一个完全平方数，请问该数是多少？
//int main()
//{
//    int  i, j, m, n, x;
//    for (i = 1; i < 168 / 2 + 1; i++)
//    {
//        if (168 % i == 0)
//        {
//            j = 168 / i;
//            if (i > j && (i + j) % 2 == 0 && (i - j) % 2 == 0)
//            {
//                m = (i + j) / 2;
//                n = (i - j) / 2;
//                x = n * n - 100;
//                printf("%d + 100 = %d * %d\n", x, n, n);
//                printf("%d + 268 = %d * %d\n", x, m, m);
//            }
//        }
//    }
//	return 0;
//}

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>
//int main()
//{
//	int* p = (int*)malloc(INT_MAX);
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		printf("dfd");
//	}
//	free(p);		//主动将内存还给操作系统
//
//	return 0;
//}

int main()
{
	int* p = (int)calloc(10, sizeof(int));
	if (p == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		int i = 0;
		for (i = 0; i < 10; i++)
		{
			printf("%d\n", *(p + i));
		}
		
	}
	realloc(p, 40);
	free(p);
	return 0;
}
