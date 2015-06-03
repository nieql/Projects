#define  _CRT_SECURE_NO_WARNINGS
#include"Array.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<memory.h>

/*
	初始化表
	PList	目标表
	 int	集合元素大小，sizeof(TYPE)>0
	return void
*/
void initList(PList pdst, int len, int elemsize)//初始化结构体
{
	if (pdst == NULL || elemsize<=0)
	{
		printf("pdst不等于null且elemsize必须大于零");
		abort();
	}
	else
	{
		int listsize = LIST_ININT_SIZE;
		if (len>0)
		{
			listsize = len;
		}
		pdst->buffer = malloc(elemsize * listsize);//开辟内存,首先开辟100字节
		if (NULL == pdst->buffer)//开辟内存失败
		{
			printf("集合的首地址不能为空");
			abort();
		}
		pdst->length = 0;//刚开始的时候,没有任何元素,此时为0
		pdst->listsize = listsize;//开辟元素的个数
		pdst->elemsize = elemsize;//每个元素的字节
	}
}
   
/*
	表尾部插入元素
	PList	目标表
	void *	插入元素首地址
	return	true:成功，false:失败
*/
bool insert(PList pdst, void * pelem) //结构体数组尾部插入元素
{
	if (NULL == pdst) //这个数组为空时
	{
		printf("数组不能为空");
		abort();
	}
	if (NULL == pelem) 
	{
		printf("插入元素的地址不能为空");
		abort();
	}
	insertByIndex(pdst, pdst->length + 1, pelem);
	
	return true;
}

/*
	表任意位置插入
	PList	目标表
	 int		插入点
	void*	插入元素首地址
*/
bool insertByIndex(PList pdst,  int index, void * pelem)
{
	if (NULL == pdst)
	{
		printf("数组不能为空");
		abort();
	}
	if (index < 1 || index > pdst->length + 1)
	{
		printf("插入的数据必须连续and必须在数组的范围内插入");
		abort();
	}
	if (NULL == pelem)
	{
		printf("插入元素的地址不能为空");
		abort();
	}
	if (pdst->length >= pdst->listsize)//当这个数组实际元素个数大于总共的结构体元素个数时
	{
		//重新开辟内存
		pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + LIST_INCREMENT) * pdst->elemsize);
		if (NULL == pdst->buffer)
		{
			printf("数组不能为空");
			abort(); 
		}
		pdst->listsize += LIST_INCREMENT;
	}
	for (int i = pdst->length; i >= index; i--)
	{
		//将前一个元素拷贝到后面的内存中,幅度为一个元素的大小,为elemsize
		memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (i - 1) * pdst->elemsize, pdst->elemsize);
	}
	//将要插入的数据插到该位置上
	memcpy(((char*)pdst->buffer) + (index - 1) * pdst->elemsize, pelem, pdst->elemsize);
	pdst->length++;
	return true;
}

/*
	插入一个数组
	PList	目标表
	 int	插入点
	void*	插入元素首地址
	 int	数组元素个数
	return	true:成功，false:失败
*/
bool insertByArray(PList pdst,  int index, void *pelem,  int size) 
{
		if (NULL == pdst)
		{
			printf("数组不能为空");
			abort();
		}
		if (index < 1 || index > pdst->length + 1) 
		{
			printf("插入的数据必须连续and必须在数组的范围内插入");
			abort();
		}
		if (NULL == pelem)
		{
			printf("插入元素的地址不能为空");
			abort();
		}
		if (size) 
		{
			if (pdst->length + size >= pdst->listsize)
			{
				pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + size + LIST_INCREMENT) * pdst->elemsize);
				if (NULL == pdst->buffer)
				{
					printf("数组不能为空");
					abort();
				}
				//整个数组的元素个数容量增加
				pdst->listsize += size + LIST_INCREMENT;//增加(数组个数+10)个元素
			}
			//将元素往后移动
			for (int i = pdst->length - 1 + size, j = pdst->length; j >= index; i--, j--)
			{
				memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (j - 1) * pdst->elemsize, pdst->elemsize);
			}
			//将要插入的数组元素插入到目标数组中
			for (int i = 0; i < size; i++)
			{
				memcpy((char*)pdst->buffer + (index - 1 + i) * pdst->elemsize, (char*)pelem + i * pdst->elemsize, pdst->elemsize);
			}
			//数组元素实际个数增加
			pdst->length += size;
		}
	return true;
}

/*
	打印表元素
	PList	目标表
	void(*)(void*)	函数指针，打印单个集合元素，参数是元素首地址
	return
*/
void printList(PList pdst, void (*pel)(void*))//传递的是函数指针
{
	if (NULL == pdst)
	{
		printf("数组不能为空");
		abort();
	}
	if (NULL == pel) 
	{
		printf("函数指针不能为空");
		abort();
	}
	for ( int i = 0; i < pdst->length; i++)
	{
		pel((char*)pdst->buffer + pdst->elemsize * i);
	}
}

/*
	从前向后查询元素
	PList	目标表
	void*	搜索元素首地址
	compre 比较元素大小，1 a>b, 0 a==b, -1 a<b
	return	返回元素下标
*/
int indexOf(PList pdst, void* pel, int(*compre)(void *pa, void *pb))
{
	if (NULL == pdst)
	{
		printf("数组不能为空");
		abort();
	}
	if (NULL == pel)
	{
		printf("查找元素的地址不能为空");
		abort();
	}
	for ( int i = 0; i < pdst->length; i++)
	{
		if (0 == compre((char*)pdst->buffer + i * pdst->elemsize, pel))
		{
			return i;
		}
	}
	return -1;
}

/*
	从后向前查询元素
	PList	目标表
	void*	搜索元素首地址
	compre 比较元素大小，1 a>b, 0 a==b, -1 a<b
	return	返回元素下标
*/
int indexLastIndexOf(PList pdst, void* pel, int(*compre)(void *pa, void *pb))
{
	if (NULL == pdst)
	{
		printf("数组不能为空");
		abort();
	}
	if (NULL == pel)
	{
		printf("查找元素的地址不能为空");
		abort();
	}
	for (int i = pdst->length - 1; i >= 0;i--)
	{
		if (0 == compre((char*)pdst->buffer + i * pdst->elemsize, pel))
		{
			return i;
		}
	}
	return -1;
}

/*
	Plist 整个数组
	void *删除元素的首地址
	int(*compre)(void *pa, void *pb)----->是一个函数指针,可以实现行从前往后删,从后往前删
*/
bool delete(PList pdst, void* pel, int(*compre)(void *pa, void *pb),int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)))
{
	if (NULL == pdst)
	{
		printf("数组不能为空");
		abort();
	}
	if (NULL == pel)
	{
		printf("查找元素的地址不能为空");
		abort();
	}
	if (NULL == pfind)
	{
		pfind = indexOf;
	}
	int index = pfind(pdst, pel, compre);
	if (-1 != index)
	{
		//从前开始,让其之后的数往前移动
		for (int i = index; i < pdst->length; i++)//其中flag是找到元素的下标
		{
			memcpy((char *)pdst->buffer + i*pdst->elemsize, (char *)pdst->buffer + (i + 1)*pdst->elemsize, pdst->elemsize);
		}
		pdst->length--;
	}
	return true;
}

bool deletes(PList pdst, void *pel, int(*compre)(void *pa, void *pb))
{
	int i = 0;
	int j = 0;
	if (pdst==NULL||pel==NULL)
	{
		printf("是空的,无法删除");
		return false;
	} 
	else
	{
		int len = pdst->length;
		if (0 != len)
		{
			int i = 0;
			int j = 0;
			while (len--)
			{
				memcpy((char*)pdst->buffer + i*pdst->elemsize, (char*)pdst->buffer + j*pdst->elemsize, pdst->elemsize);
				if (0 == compre((char*)pdst->buffer + j*pdst->elemsize, pel))
				{
					j++;
					pdst->length--;
				} 
				else
				{
					i++;
					j++;
				}
			}
		}
	} 
	return true;
}

/*
	销毁数组
	pdst 目标
*/
void destroylist(PList  pdst)
{
	if (NULL == pdst)
	{
		return;
	}
	free(pdst->buffer);
	pdst->buffer = NULL;
}