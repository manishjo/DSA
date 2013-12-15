#include "stack.h"

int push(list* top, void* element){
	int index = 1;
	return insert(top,index,element);	
}

int pop(list* top){
	int index = 1;
	return Remove(top,index);
}

int isEmpty(list* top){
	if(top->head == NULL)
		return 1;
	return 0;
}

