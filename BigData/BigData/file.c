#define _CRT_SECURE_NO_WARNINGS
#include"qq.h"
#include<stdlib.h>
#include<stdio.h>
#include"Array.h"
#include"Sort.h"
#include<Windows.h>
//#pragma comment(lib,"Arrays.lib")



/*
   �Ƚ����������Ĵ�С
   *p1>*p2����1
   *p1>*p2����2
   *p1>*p2����0
 */
int compre(void *p1,void *p2)
{
	PQQ qq1 = (PQQ)p1;
	PQQ qq2 = (PQQ)p2;

	return strcmp(qq1->qq, qq2->qq);
}




/*

��ȡ�ļ�������

path �ļ���·��

�����ļ�������

*/
int getLins(char *path)
{
	FILE *pfr = fopen(path, "r");

	if (pfr==NULL)
	{
		printf("��ȡ��������ʧ��");
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
	�ָ��ļ�
	path �ָ��ļ���
	sortpath �����ļ���С
	getLine ��ȡ�ļ�ÿһ�У����������ݽṹ�׵�ַ��void * (*splitLine)(char *line)
	elsize �����ݽṹ��С
*/
void split(char *path, char *sortpath, void* (*str2obj)(char *line), char*(*obj2str)(void *pobj), int elsize, int(*compre)(void *pa, void *pb))
{
	if (NULL == path || NULL == sortpath || NULL == str2obj || elsize <= 0)
	{
		printf("��������");
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
			printf("û�гɹ���ȡ�ļ�");
			return;
		}
		List list;

		//�� �� �� ��
		initList(&list, 0, elsize);

		//���ļ������ڴ�
		for (int i = 0; i < allLength; i++)
		{
			char LineData[256] = { 0 };
			fgets(LineData, 256, pfr);

			void * pline = str2obj(LineData);

			insert(&list, pline);

		}
		//�Խṹ����������
		sort(&list, allLength, elsize, compre, 3, 1);

		//���źõ�����д���ļ�
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
         �ļ�ӳ������
path     Ҫӳ���ļ�ָ��
pathNew  �ź������ļ�ָ��
*/

void FileMapping(char *path,char * pathNew)
{

	

	//���ļ�
	HANDLE hfile = CreateFileA(path, GENERIC_WRITE | GENERIC_READ, 0, NULL,
		OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hfile==INVALID_HANDLE_VALUE)
	{
		abort();
		system("pause");

	}
	//ӳ���ļ�
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

	//��ȡ�ļ����׵�ַ
	PVOID pvfile = MapViewOfFile(fmap, FILE_MAP_READ | FILE_MAP_WRITE, 0, 0, 0);
	if (pvfile == NULL)
	{
		printf("ָ��ӳ��ʧ��");
		CloseHandle(hfile);
		CloseHandle(fmap);
		system("pause");

	}

	char *pstart = pvfile;
	char *pend = pstart + GetFileSize(hfile, NULL);

	




}

/*
�������ļ��ϲ�

path1 path2 ΪҪ�ϲ��������ļ�

path3        Ϊ�ϲ�����ļ�

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