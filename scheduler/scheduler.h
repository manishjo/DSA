#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef char string[20];

typedef struct Process{
	string name;
	int priority;
	int time;
	int attempts;
	struct Process* next; 
}process;

typedef struct{
	process* head;
	int length;
}list;

list* create();
process* createProcess(list* ,string , int ,int);
list* insertProcess(list*,process*);
int scheduler(list*);