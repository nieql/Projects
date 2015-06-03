#pragma once


typedef enum TYPE
{
	SELECT, INSERT, BUBBLE, QUICK, HEAP
}SORT_TYPE;
typedef enum SORT
{
	ASC = 1, DESC = -1
}SORT;

void swap(void *pa, void *pb, int elsize);
/*
	����
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
	type ��������
*/
void sort(void *paray,int len, int elsize, int (*compare)(void *pa, void *pb), SORT_TYPE type, SORT sort);
/*
	ѡ������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void selectSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	��������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void insertSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	ð������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void bubbleSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	��������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void quickSort(void *paray, int start, int end, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	������
	paray �����׵�ַ
	len ���鳤��
	elsize Ԫ�ش�С
	compare �ȽϺ���ָ�룬1 a>b, 0 a==b, -1 a<b
*/
void heapSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);





