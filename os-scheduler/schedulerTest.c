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
        Process Process = {"browser",20};
        start= create();
        result = insertProcess(start,3,&Process);
        ASSERT(result == 1);
};

void test_insert_process_should_insert_two_processes(){
        int result;
        Process Process1 = {"browser",30}; 
        Process Process2 = {"browser1",10};                               
        start= create();
        result = insertProcess(start,3,&Process1);
        result = insertProcess(start,4,&Process2);
        ASSERT(result == 1);
};

void test_excuteProcess_should_excute_the_process(){
	int result;
    Process Process1 = {"browser",10}; 
    Process Process2 = {"browser1",40};                               
    start= create();
    result = insertProcess(start,3,&Process1);    
    result = insertProcess(start,5,&Process2);
    result = excuteProcess(start);
    ASSERT(result == 1);
}

void test_excuteProcess_should_excute_five_process(){
    int result;
    Process Process1 = {"browser",10}; 
    Process Process2 = {"vlc",20};
    Process Process3 = {"gcc",50};        
    Process Process4 = {"subline",5};                             
    Process Process5 = {"crome",45};                                                  
    start= create();
    result = insertProcess(start,3,&Process1);    
    result = insertProcess(start,5,&Process2);
    result = insertProcess(start,1,&Process3);
    result = insertProcess(start,10,&Process4);
    result = insertProcess(start,2,&Process5);
    result = excuteProcess(start);
    ASSERT(result == 1);
}

void test_excuteProcess_should_return_0_if_no_process_is_inserted(){
    int result;                                                
    start= create();
    result = excuteProcess(start);
    ASSERT(result == 0);
}