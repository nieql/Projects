#define  _CRT_SECURE_NO_WARNINGS
#include"Array.h"
#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<memory.h>

/*
	��ʼ����
	PList	Ŀ���
	 int	����Ԫ�ش�С��sizeof(TYPE)>0
	return void
*/
void initList(PList pdst, int len, int elemsize)//��ʼ���ṹ��
{
	if (pdst == NULL || elemsize<=0)
	{
		printf("pdst������null��elemsize���������");
		abort();
	}
	else
	{
		int listsize = LIST_ININT_SIZE;
		if (len>0)
		{
			listsize = len;
		}
		pdst->buffer = malloc(elemsize * listsize);//�����ڴ�,���ȿ���100�ֽ�
		if (NULL == pdst->buffer)//�����ڴ�ʧ��
		{
			printf("���ϵ��׵�ַ����Ϊ��");
			abort();
		}
		pdst->length = 0;//�տ�ʼ��ʱ��,û���κ�Ԫ��,��ʱΪ0
		pdst->listsize = listsize;//����Ԫ�صĸ���
		pdst->elemsize = elemsize;//ÿ��Ԫ�ص��ֽ�
	}
}
   
/*
	��β������Ԫ��
	PList	Ŀ���
	void *	����Ԫ���׵�ַ
	return	true:�ɹ���false:ʧ��
*/
bool insert(PList pdst, void * pelem) //�ṹ������β������Ԫ��
{
	if (NULL == pdst) //�������Ϊ��ʱ
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (NULL == pelem) 
	{
		printf("����Ԫ�صĵ�ַ����Ϊ��");
		abort();
	}
	insertByIndex(pdst, pdst->length + 1, pelem);
	
	return true;
}

/*
	������λ�ò���
	PList	Ŀ���
	 int		�����
	void*	����Ԫ���׵�ַ
*/
bool insertByIndex(PList pdst,  int index, void * pelem)
{
	if (NULL == pdst)
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (index < 1 || index > pdst->length + 1)
	{
		printf("��������ݱ�������and����������ķ�Χ�ڲ���");
		abort();
	}
	if (NULL == pelem)
	{
		printf("����Ԫ�صĵ�ַ����Ϊ��");
		abort();
	}
	if (pdst->length >= pdst->listsize)//���������ʵ��Ԫ�ظ��������ܹ��Ľṹ��Ԫ�ظ���ʱ
	{
		//���¿����ڴ�
		pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + LIST_INCREMENT) * pdst->elemsize);
		if (NULL == pdst->buffer)
		{
			printf("���鲻��Ϊ��");
			abort(); 
		}
		pdst->listsize += LIST_INCREMENT;
	}
	for (int i = pdst->length; i >= index; i--)
	{
		//��ǰһ��Ԫ�ؿ�����������ڴ���,����Ϊһ��Ԫ�صĴ�С,Ϊelemsize
		memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (i - 1) * pdst->elemsize, pdst->elemsize);
	}
	//��Ҫ��������ݲ嵽��λ����
	memcpy(((char*)pdst->buffer) + (index - 1) * pdst->elemsize, pelem, pdst->elemsize);
	pdst->length++;
	return true;
}

/*
	����һ������
	PList	Ŀ���
	 int	�����
	void*	����Ԫ���׵�ַ
	 int	����Ԫ�ظ���
	return	true:�ɹ���false:ʧ��
*/
bool insertByArray(PList pdst,  int index, void *pelem,  int size) 
{
		if (NULL == pdst)
		{
			printf("���鲻��Ϊ��");
			abort();
		}
		if (index < 1 || index > pdst->length + 1) 
		{
			printf("��������ݱ�������and����������ķ�Χ�ڲ���");
			abort();
		}
		if (NULL == pelem)
		{
			printf("����Ԫ�صĵ�ַ����Ϊ��");
			abort();
		}
		if (size) 
		{
			if (pdst->length + size >= pdst->listsize)
			{
				pdst->buffer = (void *)realloc(pdst->buffer, (pdst->listsize + size + LIST_INCREMENT) * pdst->elemsize);
				if (NULL == pdst->buffer)
				{
					printf("���鲻��Ϊ��");
					abort();
				}
				//���������Ԫ�ظ�����������
				pdst->listsize += size + LIST_INCREMENT;//����(�������+10)��Ԫ��
			}
			//��Ԫ�������ƶ�
			for (int i = pdst->length - 1 + size, j = pdst->length; j >= index; i--, j--)
			{
				memcpy((char*)pdst->buffer + i * pdst->elemsize, (char*)pdst->buffer + (j - 1) * pdst->elemsize, pdst->elemsize);
			}
			//��Ҫ���������Ԫ�ز��뵽Ŀ��������
			for (int i = 0; i < size; i++)
			{
				memcpy((char*)pdst->buffer + (index - 1 + i) * pdst->elemsize, (char*)pelem + i * pdst->elemsize, pdst->elemsize);
			}
			//����Ԫ��ʵ�ʸ�������
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
void printList(PList pdst, void (*pel)(void*))//���ݵ��Ǻ���ָ��
{
	if (NULL == pdst)
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (NULL == pel) 
	{
		printf("����ָ�벻��Ϊ��");
		abort();
	}
	for ( int i = 0; i < pdst->length; i++)
	{
		pel((char*)pdst->buffer + pdst->elemsize * i);
	}
}

/*
	��ǰ����ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	compre �Ƚ�Ԫ�ش�С��1 a>b, 0 a==b, -1 a<b
	return	����Ԫ���±�
*/
int indexOf(PList pdst, void* pel, int(*compre)(void *pa, void *pb))
{
	if (NULL == pdst)
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (NULL == pel)
	{
		printf("����Ԫ�صĵ�ַ����Ϊ��");
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
	�Ӻ���ǰ��ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	compre �Ƚ�Ԫ�ش�С��1 a>b, 0 a==b, -1 a<b
	return	����Ԫ���±�
*/
int indexLastIndexOf(PList pdst, void* pel, int(*compre)(void *pa, void *pb))
{
	if (NULL == pdst)
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (NULL == pel)
	{
		printf("����Ԫ�صĵ�ַ����Ϊ��");
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
	Plist ��������
	void *ɾ��Ԫ�ص��׵�ַ
	int(*compre)(void *pa, void *pb)----->��һ������ָ��,����ʵ���д�ǰ����ɾ,�Ӻ���ǰɾ
*/
bool delete(PList pdst, void* pel, int(*compre)(void *pa, void *pb),int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)))
{
	if (NULL == pdst)
	{
		printf("���鲻��Ϊ��");
		abort();
	}
	if (NULL == pel)
	{
		printf("����Ԫ�صĵ�ַ����Ϊ��");
		abort();
	}
	if (NULL == pfind)
	{
		pfind = indexOf;
	}
	int index = pfind(pdst, pel, compre);
	if (-1 != index)
	{
		//��ǰ��ʼ,����֮�������ǰ�ƶ�
		for (int i = index; i < pdst->length; i++)//����flag���ҵ�Ԫ�ص��±�
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
		printf("�ǿյ�,�޷�ɾ��");
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
	��������
	pdst Ŀ��
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