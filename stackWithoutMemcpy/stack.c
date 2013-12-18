#include "stack.h"
#include <stdlib.h>
#include <string.h>

Stack* create(int length){
	Stack* stackPtr = (Stack*)calloc(1,sizeof(Stack));
	stackPtr->data = calloc(sizeof(void*),length);
	stackPtr->numOfElements = length;
	stackPtr->top = -1;
	return stackPtr;
};

Stack* resizeStack(Stack* stackPtr){
	stackPtr->data = realloc(stackPtr->data, stackPtr->numOfElements*2*sizeof(void*));
	stackPtr->numOfElements=stackPtr->numOfElements*2;
	return stackPtr;
}

int push(Stack* stackPtr,void* element){
	void *temp;
	if(isFull(stackPtr))
		resizeStack(stackPtr);
	*(stackPtr->data+(++stackPtr->top)) = element;
	return 1;
}

void* pop(Stack* stackPtr){
	if(isEmpty(stackPtr)==1)
	return NULL;
    --stackPtr->top;
    return  *(stackPtr->data+(stackPtr->top+1));
}

int isFull(Stack* stackPtr){
	if(stackPtr->top==(stackPtr->numOfElements-1))
		return 1;
	return 0;
}

int isEmpty(Stack* stackPtr){
	if(stackPtr->top==-1)
		return 1;
	return 0;
}

void* top(Stack* stackPtr){
	return  *(stackPtr->data+(stackPtr->top));
}