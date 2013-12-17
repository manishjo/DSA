#include "scheduler.h"
#include "testUtils.h"

list *start;

typedef char string[20];

void test_create_should_create_start(){
        start= create();
        ASSERT(start->head == NULL);
        ASSERT(start->length == 0);        
};

void test_insert_process_should_insert_one_process(){
        int result;
        process Process = {20,"browser"};                
        start= create();
        result = insertProcess(start,3,&Process);
        ASSERT(result == 1);
};

void test_insert_process_should_insert_two_processes(){
        int result;
        process Process1 = {20,"browser"}; 
        process Process2 = {10,"browser1"};                               
        start= create();
        result = insertProcess(start,3,&Process1);
        result = insertProcess(start,3,&Process2);
        ASSERT(result == 1);
};

void test_excuteProcess_should_excute_the_process(){
	int result;
    process Process1 = {20,"browser"}; 
    process Process2 = {10,"browser1"};                               
    start= create();
    result = insertProcess(start,3,&Process1);
    result = insertProcess(start,3,&Process2);
    result = excuteProcess(start);
    ASSERT(result == 1);
}