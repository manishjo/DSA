#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	void *base;
	int numberOfElements;
	int elementSize;
	int front;
	int rear;
}circulerQueue;

typedef char string[256];
circulerQueue* create(int elementSize, int length);
int enqueue(circulerQueue* q,void* element);
void* dequeue(circulerQueue* q);
int isEmpty(circulerQueue* q);
int isFull(circulerQueue* q);