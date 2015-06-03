#define _CRT_SECURE_NO_WARNINGS
#include"qq.h"
#include<stdlib.h>
#include<stdio.h>
#include"Array.h"
#include"Sort.h"
#include<Windows.h>
//#pragma comment(lib,"Arrays.lib")



/*
   比较两个变量的大小
   *p1>*p2返回1
   *p1>*p2返回2
   *p1>*p2返回0
 */
int compre(void *p1,void *p2)
{
	PQQ qq1 = (PQQ)p1;
	PQQ qq2 = (PQQ)p2;

	return strcmp(qq1->qq, qq2->qq);
}




/*

获取文件的行数

path 文件的路径

返回文件的行数

*/
int getLins(char *path)
{
	FILE *pfr = fopen(path, "r");

	if (pfr==NULL)
	{
		printf("获取行数函数失败");
		abort();
		return;
	}
	else
	{
		int length = 0;

		while (!feof(pfr))
		{
			char str[256] = { 0 };
			fgets(str, 256, pfr);
			length++;
		}

		fclose(pfr);
		return length;
	}

}
/*
	分割文件
	path 分割文件名
	sortpath 排序文件大小
	getLine 获取文件每一行，返回行数据结构首地址，void * (*splitLine)(char *line)
	elsize 行数据结构大小
*/
void split(char *path, char *sortpath, void* (*str2obj)(char *line), char*(*obj2str)(void *pobj), int elsize, int(*compre)(void *pa, void *pb))
{
	if (NULL == path || NULL == sortpath || NULL == str2obj || elsize <= 0)
	{
		printf("参数不对");
		abort();
	}
	else
	{
		int allLength = getLins(path);
		FILE *pfr = fopen(path, "r");
		FILE *pfw = fopen(sortpath, "w");
		if (pfr == NULL || pfw == NULL)
		{
			fclose(pfr);
			fclose(pfw);
			printf("没有成功读取文件");
			return;
		}
		List list;

		//开 辟 数 组
		initList(&list, 0, elsize);

		//将文件读入内存
		for (int i = 0; i < allLength; i++)
		{
			char LineData[256] = { 0 };
			fgets(LineData, 256, pfr);

			void * pline = str2obj(LineData);

			insert(&list, pline);

		}
		//对结构体数组排序
		sort(&list, allLength, elsize, compre, 3, 1);

		//将排好的数组写入文件
		for (int i = 0; i < allLength; i++)
		{

			char *str = obj2str((char*)list.buffer + i * elsize);

			fputs(str, pfw);
			free(str);

		}

		fclose(pfw);
		fclose(pfr);

	}

}

/*
         文件映射排序
path     要映射文件指针
pathNew  排好序后的文件指针
*/

void FileMapping(char *path,char * pathNew)
{

	

	//打开文件
	HANDLE hfile = CreateFileA(path, GENERIC_WRITE | GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile==INVALID_HANDLE_VALUE)
	{
		abort();
		system("pause");

	}
	//映射文件
	HANDLE fmap = CreateFileMappingA(hfile, NULL,
		PAGE_READWRITE | SEC_COMMIT,
		0,
		GetFileSize(hfile, NULL) + 1,
		NULL
		);
	if (fmap==NULL)
	{
		abort();
		CloseHandle(hfile);
		system("pause");

	}

	//获取文件的首地址
	PVOID pvfile = MapViewOfFile(fmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (pvfile == NULL)
	{
		printf("指针映射失败");
		CloseHandle(hfile);
		CloseHandle(fmap);
		system("pause");

	}

	char *pstart = pvfile;
	char *pend = pstart + GetFileSize(hfile, NULL);

	




}

/*
把两个文件合并

path1 path2 为要合并的两个文件

path3        为合并后的文件

*/
void MergeFile(char * path1, char *path2,char *path3)
{
		if (path1==NULL||path2==NULL||path3==NULL)
		{
			abort();
			
		}
		FILE * pfr1 = fopen(path1, "r");
		FILE * pfr2 = fopen(path2, "r");
		FILE * pfw = fopen(path3, "w");

		if (pfr1==NULL||pfr2==NULL||pfw==NULL)
		{
			abort();
		}
		else
		{
			
			while (!feof(pfr1))
			{
				char str[256] = { 0 };
				fgets(str, 256, pfr1);
				fputs(str, 256, pfw);
			}
			while (!feof(pfr2))
			{
				char str[256] = { 0 };
				fgets(str, 256, pfr2);
				fputs(str, 256, pfw);
			}

			fclose(pfr2);
			fclose(pfr1);
			fclose(pfw);
		}
}