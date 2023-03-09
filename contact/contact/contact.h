#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
//#define MAX 100
#define MAX_NAME 20
#define MAX_SEX 5 
#define MAX_TELE 12
#define MAX_ADDR 30
#define DEFAULT_SZ 3
#include<stdlib.h>
#include<errno.h>
#include<stdio.h>
#include<string.h>
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
	struct Peoinfo* data;
	int capacity; //��ǰ�������
	int size;  //��ǰ����Ԫ�ظ���
} Contact;

enum Option
{
	EXIT, //0
	ADD,//1
	DEL,//2
	SHOW,//3
	MODIFY,//4
	SEARCH,//5
	SORT,	//6
	SAVE,	//7
	Insert	//8
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
//��������������
void SortPeople_age(const struct Contact *ps);
//����ͨѶ¼
void DestoryContact(Contact* ps);
//����ͨѶ¼
void SaveContact(Contact* ps);
//�����ļ��е���Ϣ��ͨѶ¼
void LoadContact(Contact*ps);
//�������
void CheckCapacity(Contact* ps);
//Ѱ����Ա����
static int FindPeopleName(const Contact* ps, char name[MAX_NAME]);
//������Ա
int PeopleInsert(Contact* ps);