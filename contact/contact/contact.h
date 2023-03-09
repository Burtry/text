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
	char name[MAX_NAME];				//姓名
	char sex[MAX_SEX];					//性别
	int age;							//年龄
	char tele[MAX_TELE];				//电话	
	char addr[MAX_ADDR];				//地址
} Peoinfo;
typedef struct Contact
{
	struct Peoinfo* data;
	int capacity; //当前最大容量
	int size;  //当前已有元素个数
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

//声明函数
//初始化通讯录
void Initcontect(struct Contact* ps);
//增加人员信息
void Addpeople(struct Contact* ps);
//展示人员信息
void ShowContect(const struct Contact* ps);
//修改人员信息
void ModifyContact(struct Contact* ps);
//删除人员信息
void Delpeople(struct Contact* ps);
//查询人员信息
void SearchPepole(const struct Contact *ps);
//按年龄排序排序
void SortPeople_age(const struct Contact *ps);
//销毁通讯录
void DestoryContact(Contact* ps);
//保存通讯录
void SaveContact(Contact* ps);
//加载文件中的信息到通讯录
void LoadContact(Contact*ps);
//检查容量
void CheckCapacity(Contact* ps);
//寻找人员姓名
static int FindPeopleName(const Contact* ps, char name[MAX_NAME]);
//插入人员
int PeopleInsert(Contact* ps);