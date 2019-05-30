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
	printf("\t    1.�����ϵ��     \n");
	printf("\t    2.ɾ����ϵ��     \n");
	printf("\t    3.������ϵ��     \n");
	printf("\t    4.�޸���ϵ��     \n");
	printf("\t    5.���浽�ļ�     \n");
	printf("\t    6.���ļ�����     \n");
	printf("\t    7.��ӡͨѶ¼     \n");
	printf("\t    0.��      ��     \n");
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
			printf("������������Ҫ��ӵ���ϵ�˵��������绰����ͥסַ������:\n");
			scanf("%s", con._name);
			scanf("%s", con._tel);
			scanf("%s", con._address);
			scanf("%d", &con._age);
			ContactBookAppend(&cb, &con);
		}
		else if (flag == 2)
		{
			const char name[24];
			printf("��������Ҫɾ������ϵ�˵�����:");
			scanf("%s", name);
			ContactBookDelete(&cb, name);
		}
		else if (flag == 3)
		{
			const char name[24];
			printf("��������Ҫ���ҵ���ϵ�˵�����:");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("û���ҵ�����ϵ��\n");
			}
			else
			{
				printf("����:%s,�绰:%s,��ͥסַ:%s,����:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
		}
		else if (flag == 4)
		{
			const char name[24];
			int input = 0;
			printf("��������Ҫ�޸ĵ���ϵ�����֣�");
			scanf("%s", name);
			Contact* pcon = ContactBookFind(&cb, name);
			if (pcon == NULL)
			{
				printf("û���ҵ���ϵ��\n");
			}
			else
			{
				printf("����:%s,�绰:%s,��ͥסַ:%s,����:%d\n", pcon->_name, pcon->_tel, pcon->_address, pcon->_age);
			}
			printf("�������Ƿ�Ҫ�޸ģ�  1����  2����\n");
			scanf("%d", &input);
			if (input == 1)
			{
				ContactBookDelete(&cb, name);
				printf("�����������������绰����ͥסַ������:\n");
				scanf("%s", con._name);
				scanf("%s", con._tel);
				scanf("%s", con._address);
				scanf("%d", &con._age);
				ContactBookAppend(&cb, &con);
			}
			else if (input == 2)
			{
				printf("ѡ���޸�\n");
			}
			else
			{
				printf("��������\n");
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