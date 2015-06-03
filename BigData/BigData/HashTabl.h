#pragma once

#include"Node.h"

#define HASHTABL_SIZE 100000

typedef struct {
	LinkNode *keys;
	int length;
}HashTable;

/*
	SDBM哈希算法
*/
unsigned int SDBMHash(char *str);
/*
	哈希算法
*/
unsigned int hash(char *str);
/*
	初始化哈希表
	tabl 哈希表
	len 哈希表长度
*/
void init(HashTable *tabl, int len);
/*
	销毁哈希表
*/
void destory(HashTable *tabl);
/*
	
*/
LinkNode get(HashTable *tabl, char *key);
/*
	
*/
LinkNode put(HashTable *tabl, char *key, void *buffer, int dtsize);

/*
	打印哈希表
	tabl 哈希表
	void(*printBuf)(void*) 打印链表jie
*/
void printHashTable(HashTable tabl, void(*printBuf)(void*));