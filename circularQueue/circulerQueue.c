#include "circulerQueue.h"

circulerQueue* create(int elementSize, int length){
	circulerQueue* cq = calloc(1,sizeof(circulerQueue));
	cq->base = calloc(length,elementSize);
	cq->elementSize = elementSize;
	cq->numberOfElements = length;
	cq->front = -1;
	cq->rear = -1;
	return cq;
}

int enqueue(circulerQueue* cq,void* element){
	int endLimit = cq->numberOfElements-1;
	if(cq->front==-1 && cq->rear ==-1){
		cq->front=0;
		cq->rear=0;
	}
	else{
	if(isFull(cq))
		return 0;
	else if(cq->rear == endLimit)
		cq->rear = 0;
	else
		++cq->rear;	
	}
	memmove(cq->base+cq->elementSize*cq->rear,element,cq->elementSize);
	return 1;
}

void* dequeue(circulerQueue* cq){
	if(isEmpty(cq) == 1)
		return NULL;
	else if(cq->front == cq->numberOfElements-1)
		cq->front = 0;
	else
		++cq->front;
	return cq->base+cq->elementSize*(cq->front-1);
}

int isEmpty(circulerQueue* cq){
	if(cq->front==-1 && cq->rear == -1)
		return 1;
	return 0;
}

int isFull(circulerQueue* cq){
	int endLimit = cq->numberOfElements-1;
	if((cq->front==0 && cq->rear==endLimit) || (cq->rear == cq->front-1))
		return 1;
	return 0;
}
