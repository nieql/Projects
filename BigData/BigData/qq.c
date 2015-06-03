
#define _CRT_SECURE_NO_WARNINGS
#include "qq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initQQ(PQQ* pqq, char *qq, char *name, int age, int sex, int auth, char *group)
{
	if (NULL == pqq)
	{
		return;
	}
	*pqq = (PQQ)malloc(sizeof(QQ));
	if (NULL != qq)
	{
		(*pqq)->qq = (char *)malloc(sizeof(char)*(strlen(qq) + 1));
		strcpy((*pqq)->qq, qq);
	}
	if (NULL != name)
	{
		(*pqq)->name = (char *)malloc(sizeof(char)*(strlen(name) + 1));
		strcpy((*pqq)->name, name);
	}
	(*pqq)->age = age;
	(*pqq)->sex = sex;
	(*pqq)->auth = auth;
	if (NULL != group)
	{
		(*pqq)->group = (char *)malloc(sizeof(char)*(strlen(group) + 1));
		strcpy((*pqq)->group, group);
	} 
}
//把文件的每一行转化为结构体对象
void * str2obj(char *line)
{
	PQQ pqq = NULL;
	if (NULL != NULL)
	{
		char qq[12] = { 0 };
		char name[25] = { 0 };
		int age = 0;
		int sex = 0;
		int auth = 0;
		char group[12] = { 0 };
		sscanf(line, "%*d%s%s%d%d%d%s", qq, name, &age, &sex, &auth, group);
		printf("%s,%s,%d,%d,%d,%s\n", qq, name, age, sex, auth, group);
		initQQ(&pqq, qq, name, age, sex, auth, group);
	}
	return pqq;
}


//把结构体对象转化为字符串
char* obj2str(void *pobj)
{
	if (NULL == pobj)
	{
		return NULL;
	}
	PQQ pqq = pobj;
	char *str = calloc(70, sizeof(char));
	sprintf(str, "%s %s %d %d %d %s", pqq->qq,pqq->name,pqq->age,pqq->sex,pqq->age,pqq->group);
	return str;
}


