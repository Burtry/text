#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include"contact.h"
void menu()
{
	printf("***************************************\n");
	printf("***1.add              2.del         ***\n");
	printf("***3.show             4.modify      ***\n");
	printf("***5.search           6.sort        ***\n");
	printf("***0.exit                           ***\n");
	printf("***************************************\n");

}
int main()
{
	int input = 0;
	struct Contact con;
	//��ʼ��ͨѶ¼
	Initcontect(&con);
	do
	{
		menu();
		printf("��ѡ��>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:	Addpeople(&con);	//������Ա��Ϣ
			break;
		case DEL:	 Delpeople(&con);	//ɾ����Ա��Ϣ
			break;
		case SHOW:	 ShowContect(&con);   //չʾ��Ϣ
			break;
		case MODIFY:	ModifyContact(&con);  //�޸���Ϣ
			break;
		case SEARCH: SearchPepole(&con);
			break;
		case SORT :
			break;
		case EXIT:
			printf("�˳�����\n");
			break;
		default:
			printf("�����������������\n");
			break;
		}
		
	} while (input);

	return 0;
}
