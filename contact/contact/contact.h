#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#define MAX 1000
#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30

#include<stdio.h>
#include<string.h>
struct Peoinfo
{
	char name[MAX_NAME];				//����
	char sex[MAX_SEX];					//�Ա�
	int age;							//����
	char tele[MAX_TELE];				//�绰	
	char addr[MAX_ADDR];				//��ַ
};
struct Contact
{
	struct Peoinfo data[MAX];
	int size;
};

enum Option
{
	EXIT, //0
	ADD,//1
	DEL,//2
	SHOW,//3
	MODIFY,//4
	SEARCH,//5
	SORT
};

//��������
//��ʼ��ͨѶ¼
void Initcontect(struct Contact* ps);
//������Ա��Ϣ
void Addpeople(struct Contact* ps);
//չʾ��Ա��Ϣ
void ShowContect(const struct Contact* ps);
//�޸���Ա��Ϣ
void ModifyContact(struct Contact* ps);
//ɾ����Ա��Ϣ
void Delpeople(struct Contact* ps);
//��ѯ��Ա��Ϣ
void SearchPepole(const struct Contact *ps);