#include "testUtils.h"
#include "BracketMatch.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

Stack* stack;

void tearDown(){
        free(stack->base);
}

void test_1_should_create_a_stack_of_given_lenth_and_element_size(){
	String msg = "if(3==3){ return 7; }";
	int length =strlen(msg); 
	stack = create(sizeof(char),length);
	ASSERT(length == stack->numberOfElements);
	ASSERT(1 == stack->elementSize);
}

void test_2_should_return_0_if_open_brackets_come_frist(){
	String msg = "function }(return 0;)}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
}

void test_3_should_return_1_if_brackets_matches(){
	String msg = "function {(return 0;)}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(1 == result);
}

void test_4_should_return_0_if_brackets_does_not_matched(){
	String msg = "if(manish == 420) {return false";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
}

void test_5_should_return_0_when_it_does_not_match_with_ending_brackets(){
	String msg = "}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
} 

void test_6_should_return_0_when_brackets_does_not_matches(){
	String msg = "{udaykant(manish})";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
}

void test_7_should_return_0_when_bracket_does_not_matches(){
	String msg = "{udaykant(manish])";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
}

void test_8_should_return_1_when_bracket_matches(){
	String msg = "{udaykant(manish)}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(1 == result);
}

void test_9_should_return_1_when_bracket_matches(){
	String msg = "else if(msg[i] == ){if(*top(stack)!=)return 0;pop(stack);}else if(msg[i] == ){if(*top(stack)!=)}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(1 == result);
}

void test_10_should_return_0_when_bracket_does_not_match(){
	String msg = "else if(msg[i] == ){if(*top(stack)!=return 0;pop(stack);}else if(msg[i] == ){if(*top(stack)!=)}";
	int length = strlen(msg);
	int result;
	stack = create(sizeof(char),length);
	result = match(stack,length,msg);
	ASSERT(0 == result);
}