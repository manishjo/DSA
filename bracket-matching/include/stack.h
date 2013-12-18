#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

typedef struct{
	void *base;
	int numberOfElements;
	int elementSize;
	int top;
}Stack;

typedef char String[256];
Stack* create(int elementSize, int length);
void push(Stack* s,void* element);
void* pop(Stack* s);
void* top(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);