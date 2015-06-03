#include "HashTabl.h"

unsigned int SDBMHash(char *str)
{
	unsigned int hash = 0;
	while (*str)
	{
		hash = (*str++) + (hash << 6) + (hash << 16) - hash;
	}
	return (hash & 0x7FFFFFFF);
}
unsigned int hash(char *str, int size)
{
	unsigned int hash = SDBMHash(str);
	return hash % size;
}
void init(HashTable *tabl, int len)
{
	assert(NULL != tabl);
	int hashSize = HASHTABL_SIZE;
	if (len > 0)
	{
		hashSize = len;
	}
	tabl->keys = malloc(sizeof(void*)*hashSize);
	memset(tabl->keys, 0, sizeof(void*)*hashSize);
	tabl->length = hashSize;
}

void destory(HashTable tabl)
{
	for (int i = 0; i < tabl.length; i++)
	{
		//destoryLNode(tabl.keys[i]);
	}
	free(tabl.keys);
	tabl.keys = NULL;
}

LinkNode get(HashTable *tabl, char *key)
{
	assert(NULL != tabl && NULL != key);
	unsigned int hashval = hash(key, tabl->length);
	return (tabl->keys)[hashval];
}
LinkNode put(HashTable *tabl, char *key, void *buffer, int dtsize)
{
	assert(NULL != tabl && NULL != key);
	unsigned int hashval = hash(key, tabl->length);
	LinkNode lnode = (tabl->keys)[hashval];

	addNode(&lnode, buffer, dtsize);
	(tabl->keys)[hashval] = lnode;

	return lnode;
}
void printHashTable(HashTable tabl, void(*printBuf)(void*)) {
	for (int i = 0; i < tabl.length; i++)
	{
		printf("%d\t:[", i);
		printLNode(tabl.keys[i], printBuf);
		printf("]\n");
	}
}