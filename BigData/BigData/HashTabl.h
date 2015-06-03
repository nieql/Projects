#pragma once

#include"Node.h"

#define HASHTABL_SIZE 100000

typedef struct {
	LinkNode *keys;
	int length;
}HashTable;

/*
	SDBM��ϣ�㷨
*/
unsigned int SDBMHash(char *str);
/*
	��ϣ�㷨
*/
unsigned int hash(char *str);
/*
	��ʼ����ϣ��
	tabl ��ϣ��
	len ��ϣ����
*/
void init(HashTable *tabl, int len);
/*
	���ٹ�ϣ��
*/
void destory(HashTable *tabl);
/*
	
*/
LinkNode get(HashTable *tabl, char *key);
/*
	
*/
LinkNode put(HashTable *tabl, char *key, void *buffer, int dtsize);

/*
	��ӡ��ϣ��
	tabl ��ϣ��
	void(*printBuf)(void*) ��ӡ����jie
*/
void printHashTable(HashTable tabl, void(*printBuf)(void*));