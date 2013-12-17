#include "scheduler.h"
#include "testUtils.h"


list *start;

void test_create_should_create_list(){
	start= create();
	ASSERT(start->head == NULL);
	ASSERT(start->length==0);
};
void test_insertProcess_should_insert_a_process(){
	int answer;
	int element = 200;
	start= create();
	answer = insertProcess(start,&element,3);
	ASSERT(answer == 1);
};