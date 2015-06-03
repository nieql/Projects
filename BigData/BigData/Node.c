#include "Node.h"

/*
	初始化链表
	plnode 链表
	buffer 数据域指针
	dtsize 数据域大小
*/
void initNode(LinkNode* plnode, void *buffer, int dtsize)
{
	if (NULL == plnode || NULL == buffer || dtsize <= 0) {
		return;
	}
	*plnode = (LinkNode)malloc(sizeof(Node));
	(*plnode)->buffer = malloc(sizeof(char) * dtsize);
	memcpy((*plnode)->buffer, buffer, dtsize);
	(*plnode)->dtsize = dtsize;
	(*plnode)->prev = NULL;
	(*plnode)->next = NULL;
	//(*plnode)->up = NULL;
	//(*plnode)->down = NULL;
}

/*
	销毁链表
	plnode 目标连表
*/
void destoryNode(LinkNode lnode)
{
	if (NULL == lnode)
	{
		return;
	}
	else {
		destoryNode(lnode->next);
		free(lnode->buffer);
		free(lnode);
	}
}

/*
	在链表尾部添加节点
	lnode 目标链表
	buffer 元素首地址
	dtsize 数据域大小
*/
void addNode(LinkNode* plnode, void *buffer, int dtsize)
{
	if (NULL == plnode || NULL == buffer || dtsize <= 0) {
		return;
	}
	LinkNode lnode = NULL;
	initNode(&lnode, buffer, dtsize);
	if (NULL == *plnode)
	{
		*plnode = lnode;
	}
	else {
		LinkNode p = *plnode;
		while (NULL != p->next)
		{
			p = p->next;
		}
		p->next = lnode;
	}
}

/*
	查找链表节点
	lnode 目标链表
	buffer 元素首地址
	int (*compre)(void *pa, void *pb) 比较元素大小，1 a>b,0 a==b, -1 a<b
*/
LinkNode indexOf(LinkNode lnode, void *buffer, int (*compre)(void *pa, void *pb))
{
	if (NULL == lnode || NULL == lnode->next || NULL == buffer) {
		return NULL;
	}
	while (lnode = lnode->next) {
		if (0 == compre(lnode->buffer, buffer)) {
			return lnode;
		}
	}
	return NULL;
}

/*
	打印链表节点
	lnode 目标链表
	printBuf 打印数据域函数指针
*/
void printLNode(LinkNode lnode, void(*printBuf)(void*))
{
	if (NULL == lnode)
	{
		return;
	}
	else {
		while (lnode)
		{
			printBuf(lnode->buffer);
			lnode = lnode->next;
		}
	}
}