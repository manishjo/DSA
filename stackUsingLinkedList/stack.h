#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
	void* data;
	struct Node* next;
}node;

typedef struct {
	node* top;
	int length;
}stack;

typedef char string[50];
stack* create();
int push(stack*,void*data);
