#define  _CRT_SECURE_NO_WARNINGS
#include"Array.h"
#include<malloc.h>
#include<memory.h>

/*
	初始化表
	PList	目标表
	unsigned int	集合元素大小，sizeof(TYPE)>0
	return void
*/
void initList(PList pdst, unsigned int elemsize)
{
	assert(pdst != NULL&&elemsize>0);
	if (NULL != pdst && 0 < elemsize)
	{
		pdst->buffer = malloc(elemsize * LIST_ININT_SIZE);
		if (NULL == pdst->buffer)
		{
			assert(pdst->buffer!= NULL);
		}
		pdst->length = 0;
		pdst->listsize = LIST_ININT_SIZE;
		pdst->elemsize = elemsize;
	}
}



/*
	表尾部插入元素
	PList	目标表
	void *	插入元素首地址
	return	true:成功，false:失败
*/
bool insert(PList pdst, void * pelem) 
{
	
	if (NULL == pdst) 
	{
		assert(pdst != NULL);
	}
	if (NULL == pelem) 
	{
		assert(pelem != NULL);
	}
	insertByIndex(pdst, pdst->length + 1, pelem);
	
	return true;
}

/*
	表任意位置插入
	PList	目标表
	unsigned int		插入点
	void*	插入元素首地址
*/
bool insertByIndex(PList pdst, unsigned int index, void * pelem)
{
	if (NULL == pdst)
	{
		assert(pdst != NULL);
	}
	if (index < 1 || index > pdst->length + 1)
	{
		assert(index >= 1 && index < pdst->length + 1);
	}
	if (NULL == pelem)
	{
		assert(pelem != NULL);
	}
	if (pdst->length >= pdst->listsize)
	{
		pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + LIST_INCREMENT) * pdst->elemsize);
		if (NULL == pdst->buffer)
		{
			assert(pdst->buffer != NULL);
		}
		pdst->listsize += LIST_INCREMENT;
	}
	for (int i = pdst->length; i >= index; i--)
	{
		memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (i - 1) * pdst->elemsize, pdst->elemsize);
	}
	memcpy(((char*)pdst->buffer) + (index - 1) * pdst->elemsize, pelem, pdst->elemsize);
	pdst->length++;
	return true;
}
/*
	插入一个数组
	PList	目标表
	unsigned int	插入点
	void*	插入元素首地址
	unsigned int	数组元素个数
	return	true:成功，false:失败
*/
bool insertByArray(PList pdst, unsigned int index, void *pelem, unsigned int size) {
	
	
		if (NULL == pdst)
		{
			assert(pdst != NULL);
		}
		if (index < 1 || index > pdst->length + 1) 
		{
			assert(index >= 1 && index < pdst->length + 1);
		}
		if (NULL == pelem)
		{
			assert(pelem != NULL);
		}
		if (size) 
		{
			if (pdst->length + size >= pdst->listsize)
			{
				pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + size + LIST_INCREMENT) * pdst->elemsize);
				if (NULL == pdst->buffer)
				{
					assert(pdst->buffer != NULL);
				}
				pdst->listsize += size + LIST_INCREMENT;
			}
			for (int i = pdst->length - 1 + size, j = pdst->length; j >= index; i--, j--)
			{
				memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (j - 1) * pdst->elemsize, pdst->elemsize);
			}
			for (int i = 0; i < size; i++)
			{
				memcpy((char*)pdst->buffer + (index - 1 + i) * pdst->elemsize, (char*)pelem + i * pdst->elemsize, pdst->elemsize);
			}
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
void printList(PList pdst, void (* pel)(void*)) {
	
		if (NULL == pdst)
		{
			assert(pdst != NULL);
		}
		if (NULL == pel) 
		{
			assert(pel != NULL);
		}
		for (unsigned int i = 0; i < pdst->length; i++)
		{
			pel((char*)pdst->buffer + pdst->elemsize * i);
		}
	
}

/*
	从前向后查询元素
	PList	目标表
	void*	搜索元素首地址
	return	返回元素下标
*/
int indexOf(PList pdst, void * pel)
{
	if (NULL == pdst)
	{
		assert(pdst != NULL);
	}
	if (NULL == pel)
	{
		assert(pel != NULL);
	}
	for (unsigned int i = 0; i < pdst->length; i++)
	{
		/*	if (0 == compare())
			{
			return i;
			}*/
		//pel((char*)pdst->buffer + pdst->elemsize * i);
	}
	return -1;
}


/*
	从后向前查询元素
	PList	目标表
	void*	搜索元素首地址
	return	返回元素下标
*/
//int indexLastIndexOf(PList  , void *) 
//{
//
//}


#include<locale.h>

int main() {
	setlocale(LC_ALL, "zh-CN");
	List list;
	initList(&list, sizeof(csdn));
	csdn c1;
	initCsdn(&c1, 1, L"王芳", L"王芳123", L"王芳123321");

	insert(&list, &c1);
	
	insert(&list, &c1);

	insert(&list, &c1);

	char a[10] = { 'd','e','f','g','h','j','k','l','m','n' };
	return 0;
}