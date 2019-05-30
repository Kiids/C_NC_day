#define _CRT_SECURE_NO_WARNINGS 1
#include "contact.h"

/*
int main()
{
	ContactBook cb;
	ContactBookInit(&cb);

	Contact con1;
	strcpy(con1._name, "Peter");
	strcpy(con1._tel, "186123498745");
	strcpy(con1._address, "xxx");
	con1._age = 20;
	ContactBookAppend(&cb, &con1);

	Contact con2;
	strcpy(con2._name, "Tom");
	strcpy(con2._tel, "186123498321");
	strcpy(con2._address, "xxxxxx");
	con2._age = 20;
	ContactBookAppend(&cb, &con2);

	ContactPrint(&cb);
	ContactBookSave(&cb, "ContactBookBin.txt");

	ContactBookDestory(&cb);

	system("pause");
	return 0;
}
*/
/*
int main()
{
	ContactBook cb;
	ContactBookInit(&cb);
	ContactBookLoad(&cb, "ContactBookBin.txt");
	ContactPrint(&cb);
	ContactBookDestory(&cb);
	system("pause");
	return 0;
}
*/

void menu()
{
	printf("\t*********************\n");
	printf("\t    1.添加联系人     \n");
	printf("\t    2.删除联系人     \n");
	printf("\t    3.查找联系人     \n");
	printf("\t    4.修改联系人     \n");
	printf("\t    5.保存到文件     \n");
	printf("\t    6.从文件加载     \n");
	printf("\t    7.打印通讯录     \n");
	printf("\t    0.退      出     \n");
	printf("\t*********************\n");
}

int main()
{
	ContactBook cb;
	ContactBookInit(&cb);
	Contact con;
	ContactBookLoad(&cb, "ContactBookBin.txt");
	int flag = -1;
	while (flag != 0)
	{
		menu();
		scanf("%d", &flag);
		if (flag == 1)
		{
			printf("请依次输入需要添加的联系人的姓名、电话、家庭住址、年龄:\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
		}
		else if (flag == 2)
		{
			const char name[24];
			printf("请输入需要删除的联系人的名字:");
			scanf("%s", name);
			ContactBookDelete(&cb, name);
		}
		else if (flag == 3)
		{
			const char name[24];
			printf("请输入需要查找的联系人的名字:");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("没有找到该联系人\n");
			}
			else
			{
				printf("姓名:%s,电话:%s,家庭住址:%s,年龄:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
		}
		else if (flag == 4)
		{
			const char name[24];
			int input = 0;
			printf("请输入需要修改的联系人名字：");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("没有找到联系人\n");
			}
			else
			{
				printf("姓名:%s,电话:%s,家庭住址:%s,年龄:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
			printf("请输入是否要修改？  1、是  2、否\n");
			scanf("%d", &input);
			if (input == 1)
			{
				ContactBookDelete(&cb, name);
				printf("请依次输入姓名，电话，家庭住址，年龄:\n");
				scanf("%s", con._name);
				scanf("%s", con._tel);
				scanf("%s", con._address);
				scanf("%d", &con._age);
				ContactBookAppend(&cb, &con);
			}
			else if (input == 2)
			{
				printf("选择不修改\n");
			}
			else
			{
				printf("输入有误\n");
			}
		}
		else if (flag == 5)
		{
			ContactBookSave(&cb, "ContactBookBin.txt");
		}
		else if (flag == 6)
		{
			ContactBookLoad(&cb, "ContactBookBin.txt");
		}
		else if (flag == 7)
		{
			ContactPrint(&cb);
		}
		else if (flag == 0)
		{
			break;
		}
	}

	ContactBookDestory(&cb);

	return 0;
}