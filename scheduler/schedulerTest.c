#include "testUtils.h"
#include "scheduler.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

list *start;
process *processPtr;

void test_create_should_assign_null_to_head_and_0_to_length(){
	start = create();
	ASSERT(start->head == NULL);
	ASSERT(start->length == 0);
}

void test_createProcess_should_create_the_process(){
	int priority,time;
	string name= "gcc";
	start = create();
	time = 100;
	priority = 3;
	processPtr= createProcess(start,name,time,priority);
	ASSERT(processPtr->priority == 3);
	ASSERT(processPtr->time == 100);
}

void test_insertProcess_should_insert_one_process(){
	int priority,time;
	string name= "gcc";
	start = create();
	time = 100;
	priority = 3;
	processPtr= createProcess(start,name,time,priority);
	start = insertProcess(start,processPtr);
	ASSERT(start->length == 1);
}

void test_insertProcess_should_return_null_if_used_it_without_createProcess(){
	string name= "gcc";
	start = create();
	start = insertProcess(start,processPtr);
	ASSERT(start == NULL);
}

void test_insertProcess_should_insert_two_processes(){
	int priority,time;
	string name1= "browser";
	string name2= "ms word";
	start = create();
	processPtr= createProcess(start,name1,100,3);
	start = insertProcess(start,processPtr);
	processPtr = createProcess(start,name2,200,5);
	start = insertProcess(start,processPtr);
	ASSERT(start->length == 2);
}

