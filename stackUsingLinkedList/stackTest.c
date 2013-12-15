#include "testUtils.h"
#include "stack.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

list* top;

void test_should_create_top_to_null(){
	top = create();
	ASSERT(top->head == NULL);
	ASSERT(top->length == 0);
}

void test_should_push_int_element_to_stack(){
	int answer;
	int element = 20;
	top = create();
	answer = push(top,&element);
	ASSERT(1 == answer);
	ASSERT(*(int*)top->head->data == 20);
}

void test_should_push_two_int_element_to_stack(){
	int answer;
	int element = 20;
	int element1 = 21;
	top = create();
	answer = push(top,&element);
	answer = push(top,&element1);
	ASSERT(1 == answer);
	ASSERT(2 == top->length);
	ASSERT(*(int*)top->head->data == 21);
	ASSERT(*(int*)top->head->next->data == 20);
}

void test_should_push_two_float_element_to_stack(){
	int answer;
	float element = 20.22;
	float element1 = 21.2;
	top = create();
	answer = push(top,&element);
	answer = push(top,&element1);
	ASSERT(1 == answer);
	ASSERT(2 == top->length);
	ASSERT(*(float*)top->head->data == 21.2f);
	ASSERT(*(float*)top->head->next->data == 20.22f);
}

void test_should_push_two_double_element_to_stack(){
	int answer;
	double element = 20.22;
	double element1 = 21.2;
	top = create();
	answer = push(top,&element);
	answer = push(top,&element1);
	ASSERT(1 == answer);
	ASSERT(2 == top->length);
	ASSERT(*(double*)top->head->data == 21.2);
	ASSERT(*(double*)top->head->next->data == 20.22);
}

void test_should_push_two_char_element_to_stack(){
	int answer;
	char element = 'a';
	char element1 = 'b';
	top = create();
	answer = push(top,&element);
	answer = push(top,&element1);
	ASSERT(1 == answer);
	ASSERT(2 == top->length);
	ASSERT(*(char*)top->head->data == 'b');
	ASSERT(*(char*)top->head->next->data == 'a');
}

void test_should_push_two_string_element_to_stack(){
	int answer;
	string element;
	string element1;
	strcpy(element,"yogesh");
	strcpy(element1,"manish");
	top = create();
	answer = push(top,&element);
	answer = push(top,&element1);
	ASSERT(1 == answer);
	ASSERT(2 == top->length);
	ASSERT(strcmp(*(string*)top->head->data,"manish")==0);
	ASSERT(strcmp(*(string*)top->head->next->data ,"yogesh")==0);
}

void test_should_pop_out_one_int_element_from_stack(){
	int answer;
	int element = 20;
	int element1 = 21;
	top = create();
	push(top,&element);
	push(top,&element1);
	answer = pop(top);
	ASSERT(1 == answer);
	ASSERT(1 == top->length);
	ASSERT(*(int*)top->head->data == 20);
}

void test_should_pop_out_one_float_element_from_stack(){
	int answer;
	float element = 20.20;
	float element1 = 21.99;
	top = create();
	push(top,&element);
	push(top,&element1);
	answer = pop(top);
	ASSERT(1 == answer);
	ASSERT(1 == top->length);
	ASSERT(*(float*)top->head->data == 20.20f);
}

void test_should_pop_out_one_double_element_from_stack(){
	int answer;
	double element = 20.20;
	double element1 = 21.99;
	top = create();
	push(top,&element);
	push(top,&element1);
	answer = pop(top);
	ASSERT(1 == answer);
	ASSERT(1 == top->length);
	ASSERT(*(double*)top->head->data == 20.20);
}

void test_should_pop_out_one_char_element_from_stack(){
	int answer;
	char element = 'a';
	char element1 = 'b';
	top = create();
	push(top,&element);
	push(top,&element1);
	answer = pop(top);
	ASSERT(1 == answer);
	ASSERT(1 == top->length);
	ASSERT(*(char*)top->head->data == 'a');
}

void test_should_pop_out_one_string_element_from_stack(){
	int answer;
	string element;
	string element1;
	strcpy(element,"yogesh");
	strcpy(element1,"manish");
	top = create();
	push(top,&element);
	push(top,&element1);
	answer = pop(top);
	ASSERT(1 == answer);
	ASSERT(1 == top->length);
	ASSERT(strcmp(*(string*)top->head->data,"yogesh")==0);
}

void test_isEmpty_should_return_1_if_stack_is_empty(){
	int answer;
	top = create();
	answer = isEmpty(top);
	ASSERT(1 == answer);
} 

void test_isEmpty_should_return_0_if_stack_is_not_empty(){
	int answer;
	int element = 20;
	top = create();
	push(top,&element);
	answer = isEmpty(top);
	ASSERT(0 == answer);
}