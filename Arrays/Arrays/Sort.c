#define _CRT_SECURE_NO_WARNINGS
#include "Sort.h"
#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

void swap(void *pa, void *pb, int elsize)
{
	void *ptemp = malloc(elsize);
	memcpy(ptemp, pa, elsize);
	memcpy(pa, pb, elsize);
	memcpy(pb, ptemp, elsize);
	free(ptemp);
}
void sort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT_TYPE type, SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("������û��Ԫ�أ�����Ҫ����");
	}
	else 
	{
		switch (type)
		{
		case SELECT:
			selectSort(paray, len, elsize, compare, sort);
			break;
		case INSERT:
			insertSort(paray, len, elsize, compare, sort);
			break;
		case BUBBLE:
			bubbleSort(paray, len, elsize, compare, sort);
			break;
		case QUICK:
			//quickSort(paray, start, end, elsize, compare)
			break;
		case HEAP:
			//selectSort();
			break;
		default:

			break;
		}
	}
}

/*
	ð������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void bubbleSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("������û��Ԫ�أ�����Ҫ����");
	}
	else
	{
		for (int i = 0; i < len - 1; i++)
		{
			for (int j = 0; j < len - i -1; j++)
			{
				if (compare((char*)paray + j * elsize, (char*)paray + (j + 1) * elsize) == -1 * sort)
				{
					swap((char*)paray + j * elsize, (char*)paray + (j + 1) * elsize, elsize);
				}
			}
		}
	}
}
/*
	��������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void insertSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("������û��Ԫ�أ�����Ҫ����");
		abort();
	}
	else
	{
		void *ptemp = malloc(sizeof(char)*elsize);
		for (int i = 1; i < len; i++)
		{
			memcpy(ptemp, (char*)paray + i * elsize, elsize);
			int j = i;
			while (j > 0 && compare((char*)paray + (j - 1) * elsize, ptemp) == 1 * sort)
			{
				memcpy((char*)paray + j * elsize, (char*)paray + (j - 1) * elsize, elsize);
				j--;
			}
			memcpy((char*)paray + j * elsize, ptemp, elsize);
		}
		free(ptemp);
	}
}
/*
	ѡ������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void selectSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("������û��Ԫ�أ�����Ҫ����");
		abort();
	}
	else
	{
		for (int i = 0; i < len - 1; i++)
		{
			int max = i;//������ֵ�±꣬�����±�0����ֵ
			for (int j = i + 1; j < 10; j++)//�ýϴ�����ʣ�µ������
			{
				if (compare((char*)paray + j * elsize, (char*)paray + max * elsize) == -1 * sort)
				{
					max = j;//��1�����ڵڶ�������max�����һ�����±�
				}
			}
			if (max != i)
			{//˵����ֵ�±걻���ģ�˵����ֵ������
				swap((char*)paray + i * elsize, (char*)paray + max * elsize, elsize);
			}
		}
	}
}
/*
	��������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/

void quickSort(void *paray, int start, int end, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || elsize < 1 || NULL == compare)
	{
		printf("������û��Ԫ�أ�����Ҫ����");
		abort();
	}
	else
	{
		if (start < end)
		{
			int i = start;
			for (int j = i + 1; j <= end; j++)
			{
				if (compare((char*)paray + j * elsize, (char*)paray + start * elsize) == -1 * sort)//��һ��Ԫ��
				{
					i++;
					swap((char*)paray + i * elsize, (char*)paray + j * elsize, elsize);
				}
			}
			swap((char*)paray + i * elsize, (char*)paray + start * elsize, elsize);
			quickSort(paray, start, i - 1, elsize, compare, sort);
			quickSort(paray, i + 1, end, elsize, compare, sort);
		}
	}
}
