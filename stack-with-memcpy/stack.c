#include "stack.h"
#include <stdlib.h>
#include <memory.h>

Stack* create(int elementSize, int length){
	Stack* stack = calloc(1,sizeof(Stack));
	stack->base = calloc(length, elementSize);
	stack->numberOfElements = length;	
	stack->top = -1;
	stack->elementSize=elementSize;
	return stack;	
}

Stack* resizeStack(Stack* stack){
	stack->base = realloc(stack->base, stack->numberOfElements*2*stack->elementSize);
	stack->numberOfElements=stack->numberOfElements*2;
	return stack;
}

int push(Stack* stack,void* element){
	if(isFull(stack)==1)
		resizeStack(stack);
    memcpy(stack->base+stack->elementSize*++stack->top,element,stack->elementSize);
    return 1;
}

void* pop(Stack* stack){
	if(isEmpty(stack)==1)
		return NULL;
    --stack->top;
    return  stack->base+stack->elementSize*(stack->top+1);
}

void *top(Stack* stack){
	return stack->base+stack->elementSize*stack->top;
}

int isEmpty(Stack* stack){
	if(stack->top==-1)
		return 1;
	return 0;
}

int isFull(Stack* stack){
	if(stack->top==(stack->numberOfElements-1))
		return 1;
	return 0;
}

