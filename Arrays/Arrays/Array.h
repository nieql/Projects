#pragma once
#include <assert.h>
#include<stdbool.h>
#include<stdarg.h>

#define LIST_ININT_SIZE 100	//��ʼ���ռ��С
#define LIST_INCREMENT 10	//�ռ�������

/*
	���Ա�
*/
typedef struct List
{
	void *buffer;	//�����׵�ַ	
	unsigned int elemsize;	//����Ԫ�ش�С,sizeof(TYPE)
	unsigned int length;	//���ϳ���
	unsigned int listsize;	//����
} List, *PList;

/*
	��ʼ����
	PList	Ŀ���
	unsigned int	����Ԫ�ش�С��sizeof(TYPE)>0
	return void
*/
void initList(PList, unsigned int);

/*
	��β������Ԫ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	return	true:�ɹ���false:ʧ��
*/
bool insert(PList, void *);
/*
	������λ�ò���
	PList	Ŀ���
	unsigned int	�����
	void*	����Ԫ���׵�ַ
	return	true:�ɹ���false:ʧ��
*/
bool insertByIndex(PList, unsigned int, void *);
/*
	����һ������
	PList	Ŀ���
	unsigned int	�����
	void*	����Ԫ���׵�ַ
	unsigned int	����Ԫ�ظ���
	return	true:�ɹ���false:ʧ��
*/
bool insertByArray(PList, unsigned int, void *, unsigned int);

/*
	��ӡ��Ԫ��
	PList	Ŀ���
	void (*)(void*)	����ָ�룬��ӡ��������Ԫ�أ�������Ԫ���׵�ַ
	return
*/
void printList(PList, void (*)(void*));
int compare(PList, );
/*
	��ǰ����ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	return	����Ԫ���±�
*/
int indexOf(PList, void *);

/*
	�Ӻ���ǰ��ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	return	����Ԫ���±�
*/
int indexLastIndexOf(PList, void *);
