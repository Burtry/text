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
//创建链表
 Node* createList()
{
	 Node* headNode = NULL;
	 headNode = (Node*)malloc(sizeof(Node));
	 if (headNode != NULL) {
		 headNode->next = NULL;
	}
	return headNode;

}
//创建结点
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
//打印链表
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

//插入结点,参数:插入的那个链表，插入的数据是多少
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
		printf("链表为空\n");
	else
	{
		while (posNode != NULL && posNode->data.num != num)
		{
			posNodeFront = posNode;
			posNode = posNodeFront->next;

			if (posNode == NULL)
			{
				printf("没有相关信息，无法删除\n");
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
	printf("**1.添加信息  2.删除信息*****\n");
	printf("**0.退出*********************\n");

}
int main()
{

	struct Node* list = createList();
	struct student info = { 0 };
	int input = 0;
	do
	{
		
		menu();
		printf("请选择:>");
		scanf("%d", &input);
		switch (input)
		{
		case 1:
			printf("请输入学生姓名 学号 成绩:>\n");
			scanf("%s%d%d", &info.name, &info.num, &info.math);
			insertNodeByhead(list, info);
			printList(list);
			break;
		case 2:
			printf("请输入要删除学生的学号:>");
			scanf("%d", &info.num);
			deleteNodeByAppinNum(list, info.num);
			printList(list);
			break;
		case 0:
			break;
		default:
			printf("错误\n");
			break;
		}
		
	} while (input);
	return 0;
}