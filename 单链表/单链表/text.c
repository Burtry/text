#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)
#include <stdio.h>
#include<stdlib.h>
#include<Windows.h>
struct student
{
	char name[20];
	int num;
	int math;
};
typedef struct Node
{
	struct student data ;
	struct Node* next;
}Node;
//��������
 Node* createList()
{
	 Node* headNode = NULL;
	 headNode = (Node*)malloc(sizeof(Node));
	 if (headNode != NULL) {
		 headNode->next = NULL;
	}
	return headNode;

}
//�������
 Node* createNode(struct student data)
{
	 Node* newNode = NULL;
	newNode = (Node*)malloc(sizeof(Node));
	if (newNode != NULL) {
		newNode->data = data;
		newNode->next = NULL;
	}
	return newNode;

}
//��ӡ����
void printList(Node* headNode)
{
	Node* pMove = headNode->next;
	printf("name\tnum\tmath\n");
	while (pMove)
	{
		printf("%s\t%d\t%d\n", pMove->data.name,pMove->data.num,pMove->data.math);
		pMove = pMove->next;
	}
	printf("\n");
}

//������,����:������Ǹ���������������Ƕ���
void insertNodeByhead(Node* headNode, struct student data)
{
	Node* newNode = createNode(data);
	newNode->next = headNode->next;
	headNode->next = newNode;

}
void deleteNodeByAppinNum(Node* headNode, int num)
{
	Node* posNode = headNode->next;
	Node* posNodeFront = headNode;
	if (posNode == NULL)
		printf("����Ϊ��\n");
	else
	{
		while (posNode != NULL && posNode->data.num != num)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;

			if (posNode == NULL)
			{
				printf("û�������Ϣ���޷�ɾ��\n");
				return;
			}
		}
		posNodeFront->next = posNode->next;
		free(posNode);
	}


}

void menu()
{

	printf("*****************************\n");
	printf("**1.�����Ϣ  2.ɾ����Ϣ*****\n");
	printf("**0.�˳�*********************\n");

}
int main()
{

	struct Node* list = createList();
	struct student info = { 0 };
	int input = 0;
	do
	{
		
		menu();
		printf("��ѡ��:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("������ѧ������ ѧ�� �ɼ�:>\n");
			scanf("%s%d%d", &info.name, &info.num, &info.math);
			insertNodeByhead(list, info);
			printList(list);
			break;
		case 2:
			printf("������Ҫɾ��ѧ����ѧ��:>");
			scanf("%d", &info.num);
			deleteNodeByAppinNum(list, info.num);
			printList(list);
			break;
		case 0:
			break;
		default:
			printf("����\n");
			break;
		}
		
	} while (input);
	return 0;
}