#include "testUtils.h"
#include "stack.h"
#include <string.h>
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[20];

stack* stackPtr;

void tearDown(){
	free(stackPtr);
}

void test_should_push_a_int_element_in_the_stack(){
	int answer;
	int element1 = 10;
	stackPtr = create(2);
	answer = push(stackPtr,&element1);
	ASSERT(answer == 1);
}

void test_should_push_two_float_element_in_the_stack(){
	int answer;
	float element1 = 10.5;
	float element2 = 20.5;
	stackPtr = create(2);
	answer = push(stackPtr,&element1);
	answer = push(stackPtr,&element2);
	ASSERT(answer == 1);
}

void test_should_push_two_double_element_in_the_stack(){
	int answer;
	double element1 = 10.56;
	double element2 = 20.54;
	stackPtr = create(2);
	answer = push(stackPtr,&element1);
	answer = push(stackPtr,&element2);
	ASSERT(answer == 1);
}

void test_should_push_two_char_element_in_the_stack(){
	int answer;
	char element1 = 'a';
	char element2 = 'b';
	stackPtr = create(2);
	answer = push(stackPtr,&element1);
	answer = push(stackPtr,&element2);
	ASSERT(answer == 1);
}

void test_should_push_two_string_element_in_the_stack(){
	int answer;
	string element1;
	string element2;
	strcpy(element1,"us");
	strcpy(element1,"india");
	stackPtr = create(2);
	answer = push(stackPtr,&element1);
	answer = push(stackPtr,&element2);
	ASSERT(answer == 1);
}

void test_should_pop_int_element_from_stack(){
	void* answer;
	int element1 = 10;
	int element2 = 20;
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = pop(stackPtr);
	ASSERT(*(int*)answer == 20);
}

void test_should_pop_float_element_from_stack(){
	void* answer;
	float element1 = 10.43;
	float element2 = 20.66;
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = pop(stackPtr);
	ASSERT(*(float*)answer == 20.66f);
}

void test_should_pop_double_element_from_stack(){
	void* answer;
	double element1 = 10.434;
	double element2 = 20.664;
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = pop(stackPtr);
	ASSERT(*(double*)answer == 20.664);
}

void test_should_pop_char_element_from_stack(){
	void* answer;
	char element1 = 'a';
	char element2 = 'b';
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = pop(stackPtr);
	ASSERT(*(char*)answer == 'b');
}
void test_should_pop_string_element_from_stack(){
	void* answer;
	string element1;
	string element2;
	strcpy(element1,"us");
	strcpy(element2,"india");
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = pop(stackPtr);
	ASSERT(strcmp(*(string*)answer,"india") == 0);
}

void test_should_return_top_int_element_from_stack(){
	void* answer;
	int element1 = 10;
	int element2 = 20;
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	pop(stackPtr);
	answer = top(stackPtr);
	ASSERT(*(int*)answer == 10);
}

void test_should_return_top_float_element_from_stack(){
	void* answer;
	float element1 = 10.5;
	float element2 = 20.5;
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	pop(stackPtr);
	answer = top(stackPtr);
	ASSERT(*(float*)answer == 10.5f);
}

void test_should_return_top_char_element_from_stack(){
	void* answer;
	char element1 = 'a';
	char element2 = 'b';
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = top(stackPtr);
	ASSERT(*(char*)answer == 'b');
}

void test_should_return_top_string_element_from_stack(){
	void* answer;
	string element1;
	string element2;
	strcpy(element1,"us");
	strcpy(element2,"india");
	stackPtr = create(2);
	push(stackPtr,&element1);
	push(stackPtr,&element2);
	answer = top(stackPtr);
	ASSERT(strcmp(*(string*)answer,"india") == 0);
}