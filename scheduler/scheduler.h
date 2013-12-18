#include "./include/priorityQueue.h"

typedef struct 
{
        char processName[20];
        int Time;
        int lifeCycle;
}Process;

int insertProcess(list *start,int priority ,void * data);
int excuteProcess(list* start);