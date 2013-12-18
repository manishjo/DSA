#include <stdio.h>

int testCount=-1;
int passCount=0;
void setup();
void tearDown();

void fixtureSetup();
void fixtureTearDown();
void incrementTestCount();
void incrementPassCount();
int currentTestFailed=0;

void testStarted(char* name){
	incrementTestCount();
	currentTestFailed=0;
	printf("\t%s\n",name);
}

void testEnded(){
	if(!currentTestFailed)
		incrementPassCount();
}

void resetTestCount(){
	testCount=0;
	passCount=0;
	printf("********* Starting tests\n\n");
}

void summarizeTestCount(){
	printf("\n********* Ran %d tests passed %d failed %d\n",testCount,passCount,testCount-passCount);
}

void incrementTestCount(){
	testCount++;
}

void incrementPassCount(){
	passCount++;
}

void testFailed(const char* fileName, int lineNumber, char* expression){
	currentTestFailed = 1;
	printf("\t\t %s : failed at %s:%d\n",expression, fileName,lineNumber);
}

int main(){
	fixtureSetup();
	resetTestCount();

	testStarted("test_should_create_a_stack_adt_of_int");
	setup();
		test_should_create_a_stack_adt_of_int();
	tearDown();
	testEnded();
	testStarted("test_should_create_a_stack_adt_of_float");
	setup();
		test_should_create_a_stack_adt_of_float();
	tearDown();
	testEnded();
	testStarted("test_should_create_a_stack_adt_for_double");
	setup();
		test_should_create_a_stack_adt_for_double();
	tearDown();
	testEnded();
	testStarted("test_should_create_a_stack_adt_for_char");
	setup();
		test_should_create_a_stack_adt_for_char();
	tearDown();
	testEnded();
	testStarted("test_should_push_int_element_in_stack");
	setup();
		test_should_push_int_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_should_push_float_element_in_stack");
	setup();
		test_should_push_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_should_push_double_element_in_stack");
	setup();
		test_should_push_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_should_push_srting_element_in_stack");
	setup();
		test_should_push_srting_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_should_push_two_int_elements_in_stack");
	setup();
		test_should_push_two_int_elements_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_one_int_element");
	setup();
		test_pop_should_poped_out_one_int_element();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_float_element");
	setup();
		test_pop_should_poped_out_float_element();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_char_element");
	setup();
		test_pop_should_poped_out_char_element();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_one_string_element");
	setup();
		test_pop_should_poped_out_one_string_element();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_two_int_element");
	setup();
		test_pop_should_poped_out_two_int_element();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_the_top_most_int_element_in_stack");
	setup();
		test_top_should_return_the_top_most_int_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_the_top_most_float_element_in_stack");
	setup();
		test_top_should_return_the_top_most_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_top_should_return_the_top_most_element_of_char_element_in_stack");
	setup();
		test_top_should_return_the_top_most_element_of_char_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_is_empty_should_return_1_if_there_are_no_elements_in_stack");
	setup();
		test_is_empty_should_return_1_if_there_are_no_elements_in_stack();
	tearDown();
	testEnded();
	testStarted("test_is_empty_should_return_0_if_there_is_a_element_in_stack");
	setup();
		test_is_empty_should_return_0_if_there_is_a_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_pop_should_poped_out_string_element");
	setup();
		test_pop_should_poped_out_string_element();
	tearDown();
	testEnded();
	testStarted("test_pop_should_not_pop_string_if_it_is_empty");
	setup();
		test_pop_should_not_pop_string_if_it_is_empty();
	tearDown();
	testEnded();
	testStarted("test_push_should_resize_array_and_push_int_elements");
	setup();
		test_push_should_resize_array_and_push_int_elements();
	tearDown();
	testEnded();
	testStarted("test_push_should_resize_array_and_push_float_elements");
	setup();
		test_push_should_resize_array_and_push_float_elements();
	tearDown();
	testEnded();
	testStarted("test_push_should_resize_array_and_push_double_elements");
	setup();
		test_push_should_resize_array_and_push_double_elements();
	tearDown();
	testEnded();
	testStarted("test_push_should_resize_array_and_push_char_elements");
	setup();
		test_push_should_resize_array_and_push_char_elements();
	tearDown();
	testEnded();
	testStarted("test_push_should_resize_array_and_push_string_elements");
	setup();
		test_push_should_resize_array_and_push_string_elements();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
