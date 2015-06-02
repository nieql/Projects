#pragma once
#include<stdbool.h>

#ifndef _INC_ARRAY
#define _INC_ARRAY 
#define LIST_ININT_SIZE 10000//初始化空间大小
#define LIST_INCREMENT 1000//空间增长量

/*
	线性表
*/
typedef struct List
{
	void *buffer;	//集合首地址	
	int elemsize;	//集合元素大小,sizeof(TYPE)
	int length;	//集合长度
	int listsize;	//表长度
} List, *PList;
/*
	初始化表
	PList	目标表 
	len 集合元素数量
	int	集合元素大小，sizeof(TYPE)>0
	return void
*/
void initList(PList, int len, int);
/*
	表尾部插入元素
	PList	目标表
	void*	   
	return	true:成功，false:失败
*/
bool insert(PList, void *);
/*
	表任意位置插入
	PList	目标表
	int	插入点
	void*	插入元素首地址
	return	true:成功，false:失败
*/
bool insertByIndex(PList, int, void *);
/*
	插入一个数组
	PList	目标表
	int	插入点
	void*	插入元素首地址
	int	数组元素个数
	return	true:成功，false:失败
*/
bool insertByArray(PList, int, void *, int);
/*
	打印表元素
	PList	目标表
	void (*)(void*)	函数指针，打印单个集合元素，参数是元素首地址
	return
*/
void printList(PList, void (*)(void*));
/*
	从前向后查询元素
	PList	目标表
	void*	搜索元素首地址
	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
	return	返回元素下标
*/
int indexOf(PList, void *, int (*compre)(void *pa, void *pb));
/*
	从后向前查询元素
	PList	目标表
	void*	搜索元素首地址
	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
	return	返回元素下标
*/
int indexLastIndexOf(PList, void *, int(*compre)(void *pa, void *pb));
/*
	删除单个元素
   Plist 目标表
   void *删除元素首地址
   	int (*compre)(void *pa, void *pb) 1 a>b, 0 a==b, -1 a<b
   int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)) 查找函数指针,实现行从前往后删,从后往前删
*/
bool delete(PList, void *, int(*compre)(void *pa, void *pb), int (*pfind)(PList pdst, void* pel, int(*compre)(void *pa, void *pb)));
/*
	删除所有匹配元素
   Plist 目标表
   void *删除元素首地址
*/
bool deletes(PList, void *, int(*compre)(void *pa, void *pb));

#endif  