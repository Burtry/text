#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include"contact.h"
void Initcontect(struct Contact* ps)
{
	memset(ps->data, 0, sizeof(ps->data));
	ps->size = 0;
}
void Addpeople(struct Contact* ps)
{
	if (ps->size == 1000)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
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
		printf("���ӳɹ�\n");
	}
}
void ShowContect(const struct Contact* ps)
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
void ModifyContact(struct Contact* ps)
{


}
void Delpeople(struct Contact* ps)
{
	char name[MAX_NAME];
	printf("������ɾ����Ա������:");
	scanf("%s", name);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(ps->data[i].name,name))
		{
			break;
		}
	}
	if (i == ps->size)
	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		//ɾ������
		int j = 0;
		for (j = i; j < ps->size - 1; j++)
		{
			ps->data[j] = ps->data[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
}

void SearchPepole(const struct Contact* ps)
{


}