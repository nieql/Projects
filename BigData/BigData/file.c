#define _CRT_SECURE_NO_WARNINGS
#include"qq.h"
#include<stdlib.h>
#include<stdio.h>

/*
	分割文件
	path 分割文件名
	sortpath 排序文件大小
	getLine 获取文件每一行，返回行数据结构首地址，void * (*splitLine)(char *line)
	elsize 行数据结构大小
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
		1.获取文件行数
		2.创建动态数组
		3.排序
		4.写出文件
	*/
}
