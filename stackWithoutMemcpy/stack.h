#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];

typedef struct{
	void** data;
	int numOfElements;
	int top;
}stack;

stack* create( int length);
int push(stack* s,void* element);
void* pop(stack* s);
void* top(stack* s);
int isEmpty(stack* s);
int isFull(stack* s);