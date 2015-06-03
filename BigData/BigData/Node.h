#pragma once

#ifndef _INC_NODE
#define _INC_NODE
#include "include.h"

typedef struct Node Node, *LinkNode;

struct Node
{
	void* buffer;//链表数据域
	int dtsize;//链表数据域大小
	LinkNode prev;//前一个
	LinkNode next;//后一个

	//LinkNode up;//上一个
	//LinkNode down;
};

/*
	初始化链表
	plnode 目标链表
	buffer 数据域指针
	dtsize 数据域大小
*/
void initNode(LinkNode* plnode, void *buffer, int dtsize);
/*
	销毁链表
	lnode 目标连表
*/
void destoryLNode(LinkNode lnode);
/*
	在链表尾部添加节点
	plnode 目标链表
	buffer 元素首地址
	dtsize 数据域大小
*/
void addNode(LinkNode* plnode, void *buffer, int dtsize);

/*
	查找链表节点
	lnode 目标链表
	buffer 元素首地址
	int (*compre)(void *pa, void *pb) 比较元素大小，1 a>b,0 a==b, -1 a<b
*/
LinkNode indexOf(LinkNode lnode, void *buffer, int(*compre)(void *pa, void *pb));

/*
	打印链表节点
	lnode 目标链表
	printBuf 打印数据域函数指针
*/
void printLNode(LinkNode lnode, void(*printBuf)(void*));


#endif