#pragma once
#include<stdbool.h>

#ifndef _INC_ARRAY
#define _INC_ARRAY 
#define LIST_ININT_SIZE 10000//��ʼ���ռ��С
#define LIST_INCREMENT 1000//�ռ�������

/*
	���Ա�
*/
typedef struct List
{
	void *buffer;	//�����׵�ַ	
	int elemsize;	//����Ԫ�ش�С,sizeof(TYPE)
	int length;	//���ϳ���
	int listsize;	//����
} List, *PList;
/*
	��ʼ����
	PList	Ŀ��� 
	len ����Ԫ������
	int	����Ԫ�ش�С��sizeof(TYPE)>0
	return void
*/
void initList(PList, int len, int);
/*
	��β������Ԫ��
	PList	Ŀ���
	void*	   
	return	true:�ɹ���false:ʧ��
*/
bool insert(PList, void *);
/*
	������λ�ò���
	PList	Ŀ���
	int	�����
	void*	����Ԫ���׵�ַ
	return	true:�ɹ���false:ʧ��
*/
bool insertByIndex(PList, int, void *);
/*
	����һ������
	PList	Ŀ���
	int	�����
	void*	����Ԫ���׵�ַ
	int	����Ԫ�ظ���
	return	true:�ɹ���false:ʧ��
*/
bool insertByArray(PList, int, void *, int);
/*
	��ӡ��Ԫ��
	PList	Ŀ���
	void (*)(void*)	����ָ�룬��ӡ��������Ԫ�أ�������Ԫ���׵�ַ
	return
*/
void printList(PList, void (*)(void*));
/*
	��ǰ����ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
	return	����Ԫ���±�
*/
int indexOf(PList, void *, int (*compre)(void *pa, void *pb));
/*
	�Ӻ���ǰ��ѯԪ��
	PList	Ŀ���
	void*	����Ԫ���׵�ַ
	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
	return	����Ԫ���±�
*/
int indexLastIndexOf(PList, void *, int(*compre)(void *pa, void *pb));
/*
	ɾ������Ԫ��
   Plist Ŀ���
   void *ɾ��Ԫ���׵�ַ
   	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
   int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)) ���Һ���ָ��,ʵ���д�ǰ����ɾ,�Ӻ���ǰɾ
*/
bool delete(PList, void *, int(*compre)(void *pa, void *pb), int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)));
/*
	ɾ������ƥ��Ԫ��
   Plist Ŀ���
   void *ɾ��Ԫ���׵�ַ
*/
bool deletes(PList, void *, int(*compre)(void *pa, void *pb));

#endif  