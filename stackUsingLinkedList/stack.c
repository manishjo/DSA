#include "stack.h"

stack* create(){
	stack* stackPtr = (stack*)calloc(sizeof(stack),1);
	return stackPtr;
}

int push(stack* stackPtr,void* data){
	node* nodePtr = (node*)calloc(sizeof(node),1);
	if(stackPtr->length == 0){
		nodePtr->data = data;
		stackPtr->top = nodePtr;
		stackPtr->length += 1;
		return 1;	
	}
		nodePtr->data = data;
		nodePtr->next = stackPtr->top;
		stackPtr->top = nodePtr;
		stackPtr->length += 1;
		return 1;
}