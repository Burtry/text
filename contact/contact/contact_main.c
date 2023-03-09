#define _CRT_SECURE_NO_WARNINGS  1
#pragma warning(disable:6031)

#include"contact.h"
void menu()
{
	printf("***************************************\n");
	printf("***1.add              2.del         ***\n");
	printf("***3.show             4.modify      ***\n");
	printf("***5.search           6.sort        ***\n");
	printf("***7.save            8.Insert       ***\n");
	printf("***0.exit******************************\n");

}
int main()
{
	int input = 0;
	struct Contact con;  //date size capacity
	//初始化通讯录
	Initcontect(&con);
	do
	{
		menu();
		printf("请选择>:");
		scanf("%d", &input);
		switch (input)
		{
		case ADD:	Addpeople(&con);	//增加人员信息
			break;
		case DEL:	 Delpeople(&con);	//删除人员信息
			break;
		case SHOW:	 ShowContect(&con);   //展示信息
			break;
		case MODIFY:  ModifyContact(&con);  //修改信息
			break;
		case SEARCH: SearchPepole(&con);	//查找信息
			break;
		case SORT:	SortPeople_age(&con);  //排序
			break;
		case EXIT:
			//销毁通讯录，释放动态开辟的内存
			DestoryContact(&con);
			printf("退出程序\n");
			break;
		case SAVE:
			SaveContact(&con);
			break;
		case Insert:
			PeopleInsert(&con);
			break;
		default:
			printf("输入错误，请重新输入\n");
			break;
		}
		
	} while (input);

	return 0;
}
