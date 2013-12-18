#include "testUtils.h"
#include "stack.h"
#include <stdlib.h>
#include <memory.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
Stack *stack;

void tearDown(){
        free(stack->base);
}

int areEqual(Stack a, Stack b){
    int result = a.top == b.top && a.numberOfElements == b.numberOfElements && a.elementSize == b.elementSize;
    if(!result) return result;
    return 0 == memcmp(a.base,b.base,a.numberOfElements*a.elementSize);
}

int compareResult(void* expected, void* actual, Stack* a){
	return 0 == memcmp(expected,actual,a->elementSize);
}

// ........................tests for create ..........................................

void test_should_create_a_stack_adt_of_int(){
	  int arr[3] = {0,0,0};
	  Stack expected = {arr,3,sizeof(int),-1};
	  stack = create(sizeof(int),3);
	  ASSERT(areEqual(expected, *stack)); 
}

void test_should_create_a_stack_adt_of_float(){
	  float arr[3] = {0.0,0.0,0.0};
	  Stack expected = {arr,3,sizeof(float),-1};
	  stack = create(sizeof(float),3);
	  ASSERT(areEqual(expected, *stack)); 
}

void test_should_create_a_stack_adt_for_double(){
	  double arr[4] = {0.0,0.0,0.0,0.0};
	  Stack expected = {arr,3,sizeof(double),-1};
	  stack = create(sizeof(double),3);
	  ASSERT(areEqual(expected, *stack)); 
}

void test_should_create_a_stack_adt_for_char(){
	  double arr[4] = {'\0','\0','\0','\0'};
	  Stack expected = {arr,3,sizeof(char),-1};
	  stack = create(sizeof(char),3);
	  ASSERT(areEqual(expected, *stack)); 
}

// ................................... test for push ...................................

void test_should_push_int_element_in_stack(){
	int array[1] = {100};
	int element = 100,answer;
	Stack expected = {array,1,sizeof(int),0};
	stack = create(sizeof(int),1);
	answer = push(stack, &element);
	ASSERT(areEqual(expected, *stack));
	ASSERT(answer == 1);
}

void test_should_push_float_element_in_stack(){
	float array[1] = {10.5};
	float element = 10.5;
	Stack expected = {array,1,sizeof(float),0};
	stack = create(sizeof(float),1);
	push(stack, &element);
	ASSERT(areEqual(expected, *stack));
}

void test_should_push_double_element_in_stack(){
	double array[1] = {12.1};
	double element = 12.1;
	Stack expected = {array,1,sizeof(double),0};
	stack = create(sizeof(double),1);
	push(stack, &element);
	ASSERT(areEqual(expected, *stack));
}

void test_should_push_srting_element_in_stack(){
	string element;
	strcpy(element,"manish");
	stack = create(sizeof(string),1);
	push(stack,&element);
	ASSERT(strcmp(*(string*)stack->base,"manish")==0);
}


void test_should_push_two_int_elements_in_stack(){
	int array[2]= {12,4};
	int element1 = 12;
	int element2 = 4;
	Stack expected = {array,2,sizeof(int),1};
	stack = create(sizeof(int),2);
	push(stack, &element1);
	push(stack, &element2);
	ASSERT(areEqual(expected, *stack));
}

// ...................................test for pop.................................

void test_pop_should_poped_out_one_int_element(){
	int element1 = 1;
	int element2 = 2;
	void* popedElement;
	stack = create(sizeof(int),2);
	push(stack,&element1);
	push(stack,&element2);
	popedElement =  pop(stack);
 	ASSERT(compareResult(&element2,popedElement,stack)); 
}

void test_pop_should_poped_out_float_element(){
	float element1 = 1.3;
	float element2 = 2.4;
	float element3 = 3.5;
	void* popedElement;
	stack = create(sizeof(float),3);
	push(stack,&element1);
	push(stack,&element2);
	push(stack,&element3);
	popedElement =  pop(stack);
 	ASSERT(compareResult(&element3,popedElement,stack)); 
}

void test_pop_should_poped_out_char_element(){
	char element1 = 'a';
	char element2 = 'b';
	char element3 = 'c';
	void* popedElement;
	stack = create(sizeof(char),3);
	push(stack,&element1);
	push(stack,&element2);
	push(stack,&element3);
	popedElement =  pop(stack);
 	ASSERT(compareResult(&element3,popedElement,stack)); 
}

void test_pop_should_poped_out_one_string_element(){
	string* answer;
	string element;
	strcpy(element,"manish");
	stack = create(sizeof(string),1);
	push(stack,&element);
	answer = pop(stack);
	ASSERT(strcmp(*answer,"manish")==0);
}


void test_pop_should_poped_out_two_int_element(){
	int element1 = 1;
	int element2 = 2;
	void* popedElement;
	stack = create(sizeof(int),2);
	push(stack,&element1);
	push(stack,&element2);
	popedElement =  pop(stack);
 	popedElement =  pop(stack);
 	ASSERT(compareResult(&element1,popedElement,stack)); 
}

// .................................test for top .......................................

void test_top_should_return_the_top_most_int_element_in_stack(){
	int element1 = 2;
	int element2 = 4;
	int topElement;
	stack = create(sizeof(int),2);
	push(stack,&element1);
	push(stack,&element2);
	topElement = *(int*)top(stack);
	ASSERT(4==topElement);
}

void test_top_should_return_the_top_most_float_element_in_stack(){
	float element1 = 1.3;
	float element2 = 2.4;
	float element3 = 3.5;
	float topElement;
	stack = create(sizeof(float),3);
	push(stack,&element1);
	push(stack,&element2);
	push(stack,&element3);
	pop(stack);
	topElement = *(float*)top(stack);
 	ASSERT(2.4f==topElement);
}

void test_top_should_return_the_top_most_element_of_char_element_in_stack(){
	char element1 = 'a';
	char element2 = 'b';
	char element3 = 'c';
	char topElement;
	stack = create(sizeof(char),3);
	push(stack,&element1);
	push(stack,&element2);
	push(stack,&element3);
	pop(stack);
	topElement = *(char*)top(stack);
	ASSERT('b'==topElement);
}

//...................................... test for is empty .......................

void test_is_empty_should_return_1_if_there_are_no_elements_in_stack(){
	int answer;
	stack = create(sizeof(int),3);
	answer = isEmpty(stack);
	ASSERT(1==answer);
} 

void test_is_empty_should_return_0_if_there_is_a_element_in_stack(){
	int answer;
	int element = 10;
	stack = create(sizeof(int),3);
	push(stack,&element);
	answer = isEmpty(stack);
	ASSERT(0==answer);
}

void test_pop_should_poped_out_string_element(){
	string element1 = "a";
	string element2 = "b";
	string element3 = "c";
	void* popedElement;
	stack = create(sizeof(string),3);
	push(stack,&element1);
	push(stack,&element2);
	push(stack,&element3);
	popedElement =  pop(stack);
 	ASSERT(compareResult(&element3,popedElement,stack)); 
}

void test_pop_should_not_pop_string_if_it_is_empty(){
	void* answer;
	stack = create(sizeof(string),2);
	answer = pop(stack);
	ASSERT(answer == NULL);
}

//................................ test for resize array..................................

void test_push_should_resize_array_and_push_int_elements(){
	int element1 = 12;
	int element2 = 4;
	stack = create(sizeof(int),1);
	push(stack, &element1);
	push(stack, &element2);
	ASSERT(stack->numberOfElements ==2);
}

void test_push_should_resize_array_and_push_float_elements(){
	float element1 = 1.99;
	float element2 = 4.78;
	stack = create(sizeof(float),1);
	push(stack, &element1);
	push(stack, &element2);
	ASSERT(stack->numberOfElements ==2);
}

void test_push_should_resize_array_and_push_double_elements(){
	double element1 = 1.99;
	double element2 = 4.78;
	double element3 = 4.79;
	double element4 = 4.80;
	double element5 = 4.77;
	stack = create(sizeof(double),4);
	push(stack, &element1);
	push(stack, &element2);
	push(stack, &element3);
	push(stack, &element4);
	push(stack, &element5);
	ASSERT(stack->numberOfElements ==8);
}

void test_push_should_resize_array_and_push_char_elements(){
	char element1 = 'a';
	char element2 = 'b';
	char element3 = 'c';
	char element4 = 'd';
	stack = create(sizeof(char),3);
	push(stack, &element1);
	push(stack, &element2);
	push(stack, &element3);
	push(stack, &element4);
	ASSERT(stack->numberOfElements ==6);
}

void test_push_should_resize_array_and_push_string_elements(){
	string element1 = "a";
	string element2 = "b";
	string element3 = "c";
	string element4 = "d";
	stack = create(sizeof(string),3);
	push(stack, &element1);
	push(stack, &element2);
	push(stack, &element3);
	push(stack, &element4);
	ASSERT(stack->numberOfElements ==6);
}