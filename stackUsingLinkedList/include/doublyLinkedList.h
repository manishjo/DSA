#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef char string[20];

typedef struct Node{
	void *data;
	struct Node* next;
	struct Node* pre;
}node;

typedef struct{
	node* head;
	int length;
}list;

list* create();
int insert(list* , int , void*);
int Remove(list* , int index);
int findIndex(list*, void*,int);
int length(list*);