#define  _CRT_SECURE_NO_WARNINGS
#include"Node.h"
#include "HashTabl.h"

void printNode(void *p)
{
	int *pi = p;
	printf("%3d", *pi);
}
int compre(void *pa, void *pb)
{
	int *a = pa;
	int *b = pb;
	if (*a > *b)
	{
		return 1;
	}
	else if (*a < *b)
	{
		return -1;
	}
	else {
		return 0;
	}
}
int main()
{
	/*LinkNode lnode = NULL;
	for (int i = 0; i < 10; i++)
	{
		addNode(&lnode, &i, sizeof(int));
	}
	printLNode(lnode, printNode);
	int i = 50;
	LinkNode ln = indexOf(lnode, &i, compre);
	printf("\n%d\n", *((int*)ln->buffer));*/

	HashTable tabl;
	init(&tabl, 10);
	for (int i = 0; i < 100; i++)
	{
		char str[100] = { 0 };
		_itoa(i, str, 10);
		put(&tabl, str, &i, sizeof(int));
	}
	printHashTable(tabl, printNode);


	system("pause");
	return 0;
}