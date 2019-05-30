#define _CRT_SECURE_NO_WARNINGS 1
#pragma once  //一个比较常用的C/C++预处理指令，在头文件的最开始加入这条预处理指令，保证头文件只被编译一次
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct Contact
{
	char _name[24];
	char _tel[16];
	char _address[64];
	int _age;
}Contact;

typedef struct ContactBook
{
	Contact* _con_array;
	size_t _size;
	size_t _capacity;
}ContactBook;

void ContactBookInit(ContactBook* pbook);
void ContactBookDestory(ContactBook* pbook);
void ContactBookAppend(ContactBook* pbook, Contact* con);
void ContactBookDelete(ContactBook* pbook, const char* name);
Contact* ContactBookFind(ContactBook* pbook, const char* name);
void ContactBookSave(ContactBook* pbook, const char* file);
void ContactBookLoad(ContactBook* pbook, const char* file);
void ContactPrint(ContactBook* pbook);
