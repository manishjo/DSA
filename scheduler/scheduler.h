#include "./include/priorityQueue.h"

typedef struct 
{
        int Time;
        char processName[20];
}process;

int insertProcess(list *,int ,void *);
int excuteProcess(list* start);