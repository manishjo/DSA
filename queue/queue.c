#include "queue.h"
#include <stdlib.h>
#include <memory.h>

Queue* create(int elementSize, int length){
	Queue* myqueue = calloc(1,sizeof(Queue));
	myqueue->base = calloc(length,sizeof(elementSize));
	myqueue->elementSize = elementSize;
	myqueue->numberOfElements = length;
	myqueue->front = myqueue->rear = -1;
	return myqueue;
}

int enqueue(Queue* myQueue,void* element){
	if(isFull(myQueue)==1)
		return 0;
	memmove(myQueue->base+myQueue->elementSize*++myQueue->rear,element, myQueue->elementSize);
	if(myQueue->rear == 0)
		myQueue->front = 0;
	return 1;
}

void* dequeue(Queue* myQueue){
	int i;
	void *deletedElement;
	if(isEmpty(myQueue)==1)
		return NULL;
	--myQueue->rear;
	deletedElement = calloc(1,myQueue->elementSize);
	memmove(deletedElement,myQueue->base,myQueue->elementSize);
	for(i=0;i<myQueue->numberOfElements;i++){
	  memmove(myQueue->base+myQueue->elementSize*i,myQueue->base+myQueue->elementSize*(i+1),myQueue->elementSize);
	};
	return deletedElement;
}

int isEmpty(Queue* myQueue){
	if(myQueue->front==-1 || myQueue->rear == -1)
		return 1;
	return 0;
}

int isFull(Queue* myQueue){
	if(myQueue->front==0 && myQueue->rear == myQueue->numberOfElements-1)
		return 1;
	return 0;
}


