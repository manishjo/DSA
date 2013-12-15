#include "scheduler.h"

list *create(){
	list* start = (list*)calloc(sizeof(list),1);
	return start;
};

process* createProcess(list* start,string name,int time,int priority){
	process *processPtr=(process*)calloc(1,sizeof(process));
	strcpy(processPtr->name,name);
	processPtr->priority = priority;
	processPtr->time = time;
	processPtr->attempts = 0;
	start->length += 1;
	return processPtr;
}

list* sortAndInsert(list * start, process* processPtr,process* temp){
	int i;
 	temp = start->head;
 	while(temp->next != NULL)
 		temp = temp->next;
 	for(i=start->length;i>=0;i--){
 		if(processPtr->priority,temp->priority,sizeof(int)))
 	}
}
list* insertProcess(list * start, process *processPtr){
	process* temp = (process*)calloc(sizeof(process),1);
	if(start->length == 0)
		return NULL;
	else if(start->length == 1){
		processPtr->next = NULL;
		start->head = processPtr;
	}
	else{
		temp= (process*)calloc(1,sizeof(process));
		temp = start->head;
		sortAndInsert(start,processPtr,temp);
	}
	return start;
}




