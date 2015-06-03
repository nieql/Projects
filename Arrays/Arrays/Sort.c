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
		printf("数组中没有元素，不需要排序");
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
	冒泡排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void bubbleSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("数组中没有元素，不需要排序");
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
	插入排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void insertSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("数组中没有元素，不需要排序");
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
	选择排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void selectSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || len < 1 || elsize < 1 || NULL == compare)
	{
		printf("数组中没有元素，不需要排序");
		abort();
	}
	else
	{
		for (int i = 0; i < len - 1; i++)
		{
			int max = i;//保存最值下标，假设下标0是最值
			for (int j = i + 1; j < 10; j++)//用较大数和剩下的数相比
			{
				if (compare((char*)paray + j * elsize, (char*)paray + max * elsize) == -1 * sort)
				{
					max = j;//第1个大于第二个就用max保存第一个的下标
				}
			}
			if (max != i)
			{//说明最值下标被更改，说明最值被更新
				swap((char*)paray + i * elsize, (char*)paray + max * elsize, elsize);
			}
		}
	}
}
/*
	快速排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/

void quickSort(void *paray, int start, int end, int elsize, int(*compare)(void *pa, void *pb), SORT sort)
{
	if (NULL == paray || elsize < 1 || NULL == compare)
	{
		printf("数组中没有元素，不需要排序");
		abort();
	}
	else
	{
		if (start < end)
		{
			int i = start;
			for (int j = i + 1; j <= end; j++)
			{
				if (compare((char*)paray + j * elsize, (char*)paray + start * elsize) == -1 * sort)//第一个元素
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
