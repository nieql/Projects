#pragma once

typedef struct QQ
{
	char *qq;
	char *name;
	int age;
	int sex;
	int auth;
	char *group;
}QQ, *PQQ;

void initQQ(PQQ* pqq, char *qq, char *name, int age, int sex, int auth,char *group);

void * str2obj(char *line);

char* obj2str(void *pobj);