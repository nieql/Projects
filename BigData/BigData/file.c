#define _CRT_SECURE_NO_WARNINGS
#include"qq.h"
#include<stdlib.h>
#include<stdio.h>

/*
	�ָ��ļ�
	path �ָ��ļ���
	sortpath �����ļ���С
	getLine ��ȡ�ļ�ÿһ�У����������ݽṹ�׵�ַ��void * (*splitLine)(char *line)
	elsize �����ݽṹ��С
*/
void split(char *path, char *sortpath, void* (*str2obj)(char *line), char*(*obj2str)(void *pobj),int elsize, int(*compre)(void *pa, void *pb))
{	
	if (NULL == path || NULL == sortpath || NULL == str2obj || elsize <= 0)
	{
		abort();
	}
	else
	{
		FILE *pfr = fopen(path, "r");
		//List list = NULL;
		//initList(&list, elsize );
		for (int i = 0; i < elsize; i++)
		{
			char LineData[256] = { 0 };
			fgets(LineData, 256, pfr);
			
			void *pline = str2obj(LineData);
			//insert(&list, pline);

		}
		//sort(&list,len, elsize, compre );
	

		fclose(pfr);
	}




	//FILE *pr = fopen();
	/*
		1.��ȡ�ļ�����
		2.������̬����
		3.����
		4.д���ļ�
	*/
}
