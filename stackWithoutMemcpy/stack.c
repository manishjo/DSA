#include "stack.h"

stack* create(int length){
	stack* stackPtr = (stack*)calloc(1,sizeof(stack));
	stackPtr->data = calloc(sizeof(void*),length);
	stackPtr->numOfElements = length;
	stackPtr->top = -1;
	return stackPtr;
};

stack* resizeStack(stack* stackPtr){
	stackPtr->data = realloc(stackPtr->data, stackPtr->numOfElements*2*sizeof(void*));
	stackPtr->numOfElements=stackPtr->numOfElements*2;
	return stackPtr;
}

int push(stack* stackPtr,void* element){
	void *temp;
	if(isFull(stackPtr))
		resizeStack(stackPtr);
	*(stackPtr->data+(++stackPtr->top)) = element;
	return 1;
}

void* pop(stack* stackPtr){
	if(isEmpty(stackPtr)==1)
	return NULL;
    --stackPtr->top;
    return  *(stackPtr->data+(stackPtr->top+1));
}

int isFull(stack* stackPtr){
	if(stackPtr->top==(stackPtr->numOfElements-1))
		return 1;
	return 0;
}

int isEmpty(stack* stackPtr){
	if(stackPtr->top==-1)
		return 1;
	return 0;
}

void* top(stack* stackPtr){
	return  *(stackPtr->data+(stackPtr->top));
}