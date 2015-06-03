#include "Node.h"

/*
	��ʼ������
	plnode ����
	buffer ������ָ��
	dtsize �������С
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
	��������
	plnode Ŀ������
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
	������β����ӽڵ�
	lnode Ŀ������
	buffer Ԫ���׵�ַ
	dtsize �������С
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
	��������ڵ�
	lnode Ŀ������
	buffer Ԫ���׵�ַ
	int (*compre)(void *pa, void *pb) �Ƚ�Ԫ�ش�С��1 a>b,0 a==b, -1 a<b
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
	��ӡ����ڵ�
	lnode Ŀ������
	printBuf ��ӡ��������ָ��
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