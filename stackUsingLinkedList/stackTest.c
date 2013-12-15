#include "testUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
stack* stackPtr;

void test_should_create_top_to_null(){
	stackPtr = create();
	ASSERT(stackPtr->length == 0);
	ASSERT(stackPtr->top == NULL);
}

void test_push_should_push_an_int_element_to_stack(){
	int answer;
	int element = 100;
	stackPtr = create();
	answer = push(stackPtr,&element);
	ASSERT(answer == 1);
	ASSERT(*(int*)stackPtr->top->data = 100);
}

void test_push_should_push_a_float_element_to_stack(){
	int answer;
	float element = 10.5;
	stackPtr = create();
	answer = push(stackPtr,&element);
	ASSERT(answer == 1);
	ASSERT(*(float*)stackPtr->top->data = 10.5);
}

void test_push_should_push_a_char_element_to_stack(){
	int answer;
	char element = 'a';
	stackPtr = create();
	answer = push(stackPtr,&element);
	ASSERT(answer == 1);
	ASSERT(*(char*)stackPtr->top->data = 'a');
}

void test_push_should_push_a_double_element_to_stack(){
	int answer;
	double element = 19.321;
	stackPtr = create();
	answer = push(stackPtr,&element);
	ASSERT(answer == 1);
	ASSERT(*(double*)stackPtr->top->data = 19.321);
}

void test_push_should_push_a_string_element_to_stack(){
	int answer;
	string element;
	strcpy(element,"manish");
	stackPtr = create();
	answer = push(stackPtr,&element);
	ASSERT(answer == 1);
	ASSERT(strcmp(*(string*)stackPtr->top->data,"manish")==0);
}

void test_push_should_push_more_then_one_int_element_in_stack(){
	int answer;
	int element1 = 100;
	int element2 = 200;
	stackPtr = create();
	answer = push(stackPtr,&element1);
	answer = push(stackPtr,&element2);
	ASSERT(answer == 1);
	ASSERT(stackPtr->length == 2);
	ASSERT(*(int*)stackPtr->top->data == 200);
}