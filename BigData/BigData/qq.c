#include "qq.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initQQ(PQQ pqq, char *qq, char *name, int age, int sex, int auth, char *group)
{
	if (NULL == pqq)
	{
		abort();
	}
	else {
		pqq = (PQQ)malloc(sizeof(QQ));
		if (NULL != qq)
		{
			pqq->qq = (char *)malloc(sizeof(char)*(strlen(qq) + 1));
			strcpy(pqq->qq, qq);
		}
		if (NULL != name)
		{
			pqq->name = (char *)malloc(sizeof(char)*(strlen(name) + 1));
			strcpy(pqq->name, name);
		}
		pqq->age = age;
		pqq->sex = sex;
		pqq->auth = auth;
		if (NULL != group)
		{
			pqq->group = (char *)malloc(sizeof(char)*(strlen(group) + 1));
			strcpy(pqq->group, group);
		} 
	}
}