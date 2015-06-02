#define  _CRT_SECURE_NO_WARNINGS
#include"Array.h"
#include<malloc.h>
#include<memory.h>

/*
	��ʼ����
	PList	Ŀ���
	unsigned int	����Ԫ�ش�С��sizeof(TYPE)>0
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
	��β������Ԫ��
	PList	Ŀ���
	void *	����Ԫ���׵�ַ
	return	true:�ɹ���false:ʧ��
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
	������λ�ò���
	PList	Ŀ���
	unsigned int		�����
	void*	����Ԫ���׵�ַ
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
	����һ������
	PList	Ŀ���
	unsigned int	�����
	void*	����Ԫ���׵�ַ
	unsigned int	����Ԫ�ظ���
	return	true:�ɹ���false:ʧ��
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
	��ӡ��Ԫ��
	PList	Ŀ���
	void(*)(void*)	����ָ�룬��ӡ��������Ԫ�أ�������Ԫ���׵�ַ
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
	��ǰ����ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	return	����Ԫ���±�
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
	�Ӻ���ǰ��ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	return	����Ԫ���±�
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
	initCsdn(&c1, 1, L"����", L"����123", L"����123321");

	insert(&list, &c1);
	
	insert(&list, &c1);

	insert(&list, &c1);

	char a[10] = { 'd','e','f','g','h','j','k','l','m','n' };
	return 0;
}