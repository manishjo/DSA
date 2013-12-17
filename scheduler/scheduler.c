
#include "scheduler.h"
        
int insertProcess(list *start ,int priority ,void *data){
        process *processPtr;int Time;
        enqueue(start,priority,data);
        return 1;
};

int excuteProcess(list* start){
	int processFinished = 0;
	node* temp;
	process* ongoingProcess;
	temp = start->head;
	while(processFinished != start->length){
    	printf("\n helloooo \n");
		ongoingProcess = temp->data;
		printf("\n-----------%d",ongoingProcess->Time);
		if(ongoingProcess->Time <= 10){			
			processFinished++;
			ongoingProcess->lifeCycle +=1;			
		}
		ongoingProcess->Time -= 10;
		ongoingProcess->lifeCycle += 1;
		temp = temp->next;

	}
	return 1;
}