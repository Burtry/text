#define _CRT_SECURE_NO_WARNINGS 1
#pragma warning(disable:6031)
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<errno.h>

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n = 0, * arr = { 0 };int  i, num;

    printf("����Ҫ��������֣�����������ַ�ֹͣ):\n");

    // ѭ����ȡ�û����������
    while (scanf("%d", &num) == 1) {
        n++;
        arr = (int*)realloc(arr, n * sizeof(int)); // ��̬�����ڴ�
        arr[n - 1] = num;
    }

    bubbleSort(arr, n);

    printf("��С����> ");
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr); // �ͷŶ�̬������ڴ�
    return 0;
}
//	����ĳ��ĳ��ĳ�գ��ж���һ������һ��ĵڼ��죿

//int main()
//{
//	int year, month, day = 0;
//	int sum = 0;
//	int leap = 0;
//	printf("������������:>");
//	scanf("%d.%d.%d", &year, &month, &day);
//	switch (month)
//	{
//	case 1:sum = 0;	break;
//	case 2:sum = 31;	break;
//	case 3:sum = 59;	break;
//	case 4:sum = 90;	break;
//	case 5:sum = 120;	break;
//	case 6:sum = 151;	break;
//	case 7:sum = 181;	break;
//	case 8:sum = 212;	break;
//	case 9:sum = 243;	break;
//	case 10:sum = 273;	break;
//	case 11:sum = 304;	break;
//	case 12:sum = 334;	break;
//
//	default:printf("error\n");break;
//	}
//	sum = sum + day;
//	if (year % 400 == 0 || (year % 100 != 0 && year % 4 == 0)) {
//		leap = 1;
//	}
//	else {
//		leap = 0;
//	}
//	if (leap == 1 && month > 2) {
//		sum++;
//	}
//	printf("һ����%d", sum);
//	return 0;
//}
//


















////��1,2,3,4�����֣�����ɶ��ٸ�������ͬ�����ظ����ֵ���λ�������Ƕ��٣�
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

//��ҵ���ŵĽ������������ɡ�
//
//����(I)���ڻ����10��Ԫʱ���������10% ��
//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10% ��ɣ�����10��Ԫ�Ĳ��֣������7.5 % ��
//20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5 % ��
//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3 % ��
//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5 % ��
//����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1 % ��ɡ�
//�Ӽ������뵱������I����Ӧ���Ž���������
//<100000	//100000<I<200000	//200000<I<400000	//400000<I<600000	//600000<I<1000000
//int main()
//{
//    double i;
//    double bonus1, bonus2, bonus4, bonus6, bonus10, bonus;
//    printf("��ľ������ǣ�");
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
//    printf("���Ϊ��bonus=%0.2lf\n", bonus);
//
//	return 0;
//}
//�������10��Ԫ������20��Ԫʱ������10��Ԫ�Ĳ��ְ�10% ��ɣ�����10��Ԫ�Ĳ��֣������7.5 % ��
//20��40��֮��ʱ������20��Ԫ�Ĳ��֣������5 % ��
//40��60��֮��ʱ����40��Ԫ�Ĳ��֣������3 % ��
//60��100��֮��ʱ������60��Ԫ�Ĳ��֣������1.5 % ��
//����100��Ԫʱ������100��Ԫ�Ĳ��ְ�1 % ��ɡ�
//int main()
//{
//	double i = 0;
//	printf("�����뵱ǰ����:>");
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
//		printf("��Ľ���Ϊ:>%0.2lf", i1);
//	}
//	else if (100000 < i < 200000)
//	{
//		printf("��Ľ���Ϊ:>%0.2lf", i2);
//	}
//	else if (200000 < i < 400000)
//	{
//		printf("��Ľ���Ϊ:>%0.2lf", i3);
//	}
//	else if (400000 < i < 600000)
//	{
//		printf("��Ľ���Ϊ:>%0.2lf", i4);
//	}
//	else if (600000 < i < 1000000)
//	{
//		printf("��Ľ���Ϊ:>%0.2lf", i5);
//	}
//	else if (i>1000000)
//	{
//		printf("��Ľ���Ϊ:>%0.2lf", i6);
//	}
//	return 0;
//}
//	һ��������������100����һ����ȫƽ�������ټ���168����һ����ȫƽ���������ʸ����Ƕ��٣�
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
//	free(p);		//�������ڴ滹������ϵͳ
//
//	return 0;
//}

//int main()
//{
//	int* p = (int)calloc(10, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//	else
//	{
//		int i = 0;
//		for (i = 0; i < 10; i++)
//		{
//			printf("%d\n", *(p + i));
//		}
//		
//	}
//	realloc(p, 40);
//	free(p);
//	return 0;
//}
