#include "scheduler.h"
        
int insertProcess(list *start ,int priority ,void *data){
        Process *processPtr;int Time;
        enqueue(start,priority,data);
        return 1;
};

void finishProcess(node* temp,list* start){
	int processFinished = 0;
	int index = 0;
	Process* ongoingProcess;
	while(processFinished <= start->length){
		if(temp->next == NULL){
			temp = start->head;
			index = 0;			
		}
		ongoingProcess = temp->data;
		if(ongoingProcess->Time <= 10){
			processFinished++;
			ongoingProcess->lifeCycle +=1;	
			index++;
		}
		ongoingProcess->Time -= 10;
		ongoingProcess->lifeCycle += 1;
		index++;
		temp = temp->next;
	}
}
int excuteProcess(list* start){
	node* temp;
	temp = start->head;
	if(start->length == 0)
		return 0;
	finishProcess(temp,start);
	return 1;
}