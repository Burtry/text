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
	//��������ͨѶ¼
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
	//��ȡ�ļ��������ͨѶ¼��
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
	{	//����
		Peoinfo*ptr = realloc(ps->data, (ps->capacity + 2) * sizeof(Peoinfo));
		if (ptr != NULL)
		{
			ps->data = ptr;
			ps->capacity += 2;
			printf("���ݳɹ�\n");
		}
		else 
		{
			printf( "����ʧ��\n" );
		}

	}
}
void Addpeople( Contact* ps)
{
	//�������
	CheckCapacity(ps);
	//��������
	printf("���������֣�");
	scanf("%s", ps->data[ps->size].name);
	printf("�������Ա�");
	scanf("%s", ps->data[ps->size].sex);
	printf("���������䣺");
	scanf("%d", &(ps->data[ps->size].age));
	printf("������绰��");
	scanf("%s", ps->data[ps->size].tele);
	printf("�������ַ��");
	scanf("%s", ps->data[ps->size].addr);

	ps->size++;
	printf("��ӳɹ�\n");

}


void ShowContect(const  Contact* ps)
{
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("�����Ҫ�޸��˵�����:");
	scanf("%s", name);
	int pos = FindPeopleName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ�޸ĵ��˲�����\n");
	}
	else
	{
		printf("���������֣�");
		scanf("%s", ps->data[pos].name);
		printf("�������Ա�");
		scanf("%s", ps->data[pos].sex);
		printf("���������䣺");
		scanf("%d", &(ps->data[pos].age));
		printf("������绰��");
		scanf("%s", ps->data[pos].tele);
		printf("�������ַ��");
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
	return -1;   //�Ҳ��������
}
void Delpeople( Contact* ps)
{
	char name[MAX_NAME];
	printf("������ɾ����Ա������:");
	scanf("%s", name);

	//������Աλ��
	//�ҵ��˷���Ԫ�����ڵ��±�
	//�Ҳ�������-1
	int pos = FindPeopleName(ps,name);  
	
	if (pos == -1)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = pos; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchPepole(const  Contact* ps)
{
	char name[MAX_NAME];
	printf("�����Ҫ�����˵�����:");
	scanf("%s",name );
	int pos = FindPeopleName(ps, name);
	if (pos == -1)
	{
		printf("Ҫ���ҵ��˲�����\n");
	}
	else
	{
		printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	printf("%-20s\t%-4s\t%-5s\t%-12s\t%-30s\n", "����", "�Ա�", "����", "�绰", "��ַ");
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
	//д���ݵ�ͨѶ¼��

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
	printf("������Ҫ�����λ��:>");
	scanf("%d", &i);
	if (i<1 || i>ps->size)
	{
		printf("����λ�ò��Ϸ�\n");
		return -1;
	}
	else
	{
		CheckCapacity(ps);
		Peoinfo pos = { 0 };
		printf("������������");
		scanf("%s", pos.name);
		printf("�������Ա�");
		scanf("%s", pos.sex);
		printf("���������䣺");
		scanf("%d", &pos.age);
		printf("������绰��");
		scanf("%s", pos.tele);
		printf("�������ַ��");
		scanf("%s", pos.addr);
		for (j = ps->size - 1; j > i - 1; j--)
		{
			ps->data[j + 1] = ps->data[j];	
		}
		
		ps->data[i - 1] = pos;
		ps->size++;
		printf("����ɹ���\n");
	}
	return 0;
}