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
	排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
	type 排序类型
*/
void sort(void *paray,int len, int elsize, int (*compare)(void *pa, void *pb), SORT_TYPE type, SORT sort);
/*
	选择排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void selectSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	插入排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void insertSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	冒泡排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void bubbleSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	快速排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void quickSort(void *paray, int start, int end, int elsize, int(*compare)(void *pa, void *pb), SORT sort);
/*
	堆排序
	paray 数组首地址
	len 数组长度
	elsize 元素大小
	compare 比较函数指针，1 a>b, 0 a==b, -1 a<b
*/
void heapSort(void *paray, int len, int elsize, int(*compare)(void *pa, void *pb), SORT sort);





