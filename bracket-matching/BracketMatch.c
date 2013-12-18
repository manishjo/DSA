#include "BracketMatch.h"
#include <stdlib.h>
#include <memory.h>

int match(Stack* stack, int length, char* msg){
 	int i;
 	for (i=0;i<length;i++){
 		if(msg[i]=='{'||msg[i]=='('||msg[i]=='['){
 			push(stack,&msg[i]);
 		}
 		else if(msg[i] == ')'||msg[i] == ']'||msg[i] == '}'){
 			if(stack->top==-1){
 				return 0;	
 			}
 			else if(msg[i] == ')'){
 				if(*(char*)top(stack)!='(')
 					return 0;
 				pop(stack);
	 		}
	 		else if(msg[i] == ']'){
	 			if(*(char*)top(stack)!='[')
 					return 0;
 				pop(stack);
	 		}
	 		else if(msg[i] == '}'){
	 			if(*(char*)top(stack)!='{')
 					return 0;
 				pop(stack);
	 		}
 		}	
 	}
 	if(stack->top!=-1)
 		return 0;
 	return 1;
}
