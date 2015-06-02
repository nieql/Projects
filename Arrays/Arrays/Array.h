#pragma once
#include <assert.h>
#include<stdbool.h>
#include<stdarg.h>

#define LIST_ININT_SIZE 100	//初始化空间大小
#define LIST_INCREMENT 10	//空间增长量

/*
	线性表
*/
typedef struct List
{
	void *buffer;	//集合首地址	
	unsigned int elemsize;	//集合元素大小,sizeof(TYPE)
	unsigned int length;	//集合长度
	unsigned int listsize;	//表长度
} List, *PList;

/*
	初始化表
	PList	目标表
	unsigned int	集合元素大小，sizeof(TYPE)>0
	return void
*/
void initList(PList, unsigned int);

/*
	表尾部插入元素
	PList	目标表
	void*	插入元素首地址
	return	true:成功，false:失败
*/
bool insert(PList, void *);
/*
	表任意位置插入
	PList	目标表
	unsigned int	插入点
	void*	插入元素首地址
	return	true:成功，false:失败
*/
bool insertByIndex(PList, unsigned int, void *);
/*
	插入一个数组
	PList	目标表
	unsigned int	插入点
	void*	插入元素首地址
	unsigned int	数组元素个数
	return	true:成功，false:失败
*/
bool insertByArray(PList, unsigned int, void *, unsigned int);

/*
	打印表元素
	PList	目标表
	void (*)(void*)	函数指针，打印单个集合元素，参数是元素首地址
	return
*/
void printList(PList, void (*)(void*));
int compare(PList, );
/*
	从前向后查询元素
	PList	目标表
	void*	搜索元素首地址
	return	返回元素下标
*/
int indexOf(PList, void *);

/*
	从后向前查询元素
	PList	目标表
	void*	搜索元素首地址
	return	返回元素下标
*/
int indexLastIndexOf(PList, void *);
