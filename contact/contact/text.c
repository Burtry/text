#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>

#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
typedef struct Peoinfo
{
	char name[MAX_NAME];				//����
	char sex[MAX_SEX];					//�Ա�
	int age;							//����
	char tele[MAX_TELE];				//�绰	
	char addr[MAX_ADDR];				//��ַ
} Peoinfo;
typedef struct Contact
{
	 Peoinfo* data;
	 Contact* next;
} Contact;

int main()
{
	return 0;
}