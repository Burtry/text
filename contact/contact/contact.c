#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include"contact.h"
void Initcontect(Contact* ps)
{ 
	ps->data = (Peoinfo*)malloc(DEFAULT_SZ * sizeof(Peoinfo));
	if (ps->data == NULL){
		return;
	}
	ps->size = 0;
	ps->capacity = DEFAULT_SZ;

	/*memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;*/
	//加载已有通讯录
	LoadContact(ps);
}
void LoadContact(Contact* ps)
{
	Peoinfo tmp = { 0 };
	FILE* pfRead = fopen("contat.dat", "rb");
	if (pfRead == NULL)
	{
		printf("LoadContact:%s\n", strerror(errno));
		return;
	}
	//读取文件，存放在通讯录中
	while (fread(&tmp, sizeof(Peoinfo), 1, pfRead))
	{
		CheckCapacity(ps);
		ps->data[ps->size] = tmp;
		ps->size++;
	}


	fclose(pfRead);
	pfRead = NULL;
}

void CheckCapacity(Contact* ps)
{

	if (ps->size == ps->capacity) 
	{	//增容
		Peoinfo*ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("增容成功\n");
		}
		else 
		{
			printf( "增容失败\n" );
		}

	}
}
void Addpeople( Contact* ps)
{
	//检测容量
	CheckCapacity(ps);
	//增加数据
	printf("请输入名字：");
	scanf("%s", ps->data[ps->size].name);
	printf("请输入性别：");
	scanf("%s", ps->data[ps->size].sex);
	printf("请输入年龄：");
	scanf("%d", &(ps->data[ps->size].age));
	printf("请输入电话：");
	scanf("%s", ps->data[ps->size].tele);
	printf("请输入地址：");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("添加成功\n");

}


void ShowContect(const  Contact* ps)
{
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
		for (i = 0; i<(ps->size); i++)
		{
			printf("%-20s\t%-4s\t%-5d\t%-12s\t%-30s\n",
				ps->data[i].name,
				ps->data[i].sex,
				ps->data[i].age,
				ps->data[i].tele,
				ps->data[i].addr);

		}
	}
}
void ModifyContact( Contact* ps)
{
	char name[MAX_NAME];
	printf("请输出要修改人的名字:");
	scanf("%s", name);
	int pos = FindPeopleName(ps, name);
	if (pos == -1)
	{
		printf("要修改的人不存在\n");
	}
	else
	{
		printf("请输入名字：");
		scanf("%s", ps->data[pos].name);
		printf("请输入性别：");
		scanf("%s", ps->data[pos].sex);
		printf("请输入年龄：");
		scanf("%d", &(ps->data[pos].age));
		printf("请输入电话：");
		scanf("%s", ps->data[pos].tele);
		printf("请输入地址：");
		scanf("%s", ps->data[pos].addr);

	}
}
 static int FindPeopleName(const Contact* ps, char name[MAX_NAME])

{
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name, name))
		{
			return i;
		}
	}
	return -1;   //找不到的情况
}
void Delpeople( Contact* ps)
{
	char name[MAX_NAME];
	printf("请输入删除人员的名字:");
	scanf("%s", name);

	//查找人员位置
	//找到了返回元素所在的下标
	//找不到返回-1
	int pos = FindPeopleName(ps,name);  
	
	if (pos == -1)
	{
		printf("要删除的人不存在\n");
	}
	else
	{
		//删除数据
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
}

void SearchPepole(const  Contact* ps)
{
	char name[MAX_NAME];
	printf("请输出要搜索人的名字:");
	scanf("%s",name );
	int pos = FindPeopleName(ps, name);
	if (pos == -1)
	{
		printf("要查找的人不存在\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
		printf("%-20s\t%-4s\t%-5d\t%-12s\t%-30s\n",
				ps->data[pos].name,
				ps->data[pos].sex,
				ps->data[pos].age,
				ps->data[pos].tele,
				ps->data[pos].addr);

	}
}

void SortPeople_age(Contact* ps)
{
	int i = 0; int j = 0; 
	 Peoinfo tmp;
	for (i = 0; i < (ps->size)- 1; i++)
	{
		for (j = 0; j < ps->size-1-i; j++)
		{
			if (ps->data[j].age > ps->data[j + 1].age)
			{
				tmp =  ps->data[j];
				ps->data[j] = ps->data[j + 1];
				ps->data[j + 1] = tmp;
			}
		}

	}
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "名字", "性别", "年龄", "电话", "地址");
	for ( i = 0; i < ps->size; i++)
	{
		
		printf("%-20s\t%-4s\t%-5d\t%-12s\t%-30s\n",
			ps->data[i].name,
			ps->data[i].sex,
			ps->data[i].age,
			ps->data[i].tele,
			ps->data[i].addr);
	}
	
}
void DestoryContact(Contact* ps)
{
	free(ps->data);
	ps->data = NULL;
}
void SaveContact(Contact* ps)
{
	FILE* pfWrite = fopen("contat.dat", "wb");
	if (pfWrite == NULL)
	{
		printf("SaveContact:%s\n", strerror( errno ));
		return;
	}
	//写数据到通讯录中

	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		fwrite(&(ps->data[i]),sizeof(Peoinfo),1,pfWrite);
		
	}
	fclose(pfWrite );
}


int  PeopleInsert(Contact* ps)
{
	int i = 0;
	int j = 0;
	printf("请输入要插入的位置:>");
	scanf("%d", &i);
	if (i<1 || i>ps->size)
	{
		printf("插入位置不合法\n");
		return -1;
	}
	else
	{
		CheckCapacity(ps);
		Peoinfo pos = { 0 };
		printf("请输入姓名：");
		scanf("%s", pos.name);
		printf("请输入性别：");
		scanf("%s", pos.sex);
		printf("请输入年龄：");
		scanf("%d", &pos.age);
		printf("请输入电话：");
		scanf("%s", pos.tele);
		printf("请输入地址：");
		scanf("%s", pos.addr);
		for (j = ps->size - 1; j > i - 1; j--)
		{
			ps->data[j + 1] = ps->data[j];	
		}
		
		ps->data[i - 1] = pos;
		ps->size++;
		printf("插入成功！\n");
	}
	return 0;
}