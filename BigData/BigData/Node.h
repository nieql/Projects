#pragma once

#ifndef _INC_NODE
#define _INC_NODE
#include "include.h"

typedef struct Node Node, *LinkNode;

struct Node
{
	void* buffer;//����������
	int dtsize;//�����������С
	LinkNode prev;//ǰһ��
	LinkNode next;//��һ��

	//LinkNode up;//��һ��
	//LinkNode down;
};

/*
	��ʼ������
	plnode Ŀ������
	buffer ������ָ��
	dtsize �������С
*/
void initNode(LinkNode* plnode, void *buffer, int dtsize);
/*
	��������
	lnode Ŀ������
*/
void destoryLNode(LinkNode lnode);
/*
	������β����ӽڵ�
	plnode Ŀ������
	buffer Ԫ���׵�ַ
	dtsize �������С
*/
void addNode(LinkNode* plnode, void *buffer, int dtsize);

/*
	��������ڵ�
	lnode Ŀ������
	buffer Ԫ���׵�ַ
	int (*compre)(void *pa, void *pb) �Ƚ�Ԫ�ش�С��1 a>b,0 a==b, -1 a<b
*/
LinkNode indexOf(LinkNode lnode, void *buffer, int(*compre)(void *pa, void *pb));

/*
	��ӡ����ڵ�
	lnode Ŀ������
	printBuf ��ӡ��������ָ��
*/
void printLNode(LinkNode lnode, void(*printBuf)(void*));


#endif