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

	testStarted("test_1_should_create_a_stack_adt_of_int");
	setup();
		test_1_should_create_a_stack_adt_of_int();
	tearDown();
	testEnded();
	testStarted("test_2_should_create_a_stack_adt_of_float");
	setup();
		test_2_should_create_a_stack_adt_of_float();
	tearDown();
	testEnded();
	testStarted("test_3_should_create_a_stack_adt_for_double");
	setup();
		test_3_should_create_a_stack_adt_for_double();
	tearDown();
	testEnded();
	testStarted("test_4_should_create_a_stack_adt_for_char");
	setup();
		test_4_should_create_a_stack_adt_for_char();
	tearDown();
	testEnded();
	testStarted("test_5_pushing_int_element_in_stack");
	setup();
		test_5_pushing_int_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_6_pushing_float_element_in_stack");
	setup();
		test_6_pushing_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_7_pushing_double_element_in_stack");
	setup();
		test_7_pushing_double_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_8_pushing_two_int_elements_in_stack");
	setup();
		test_8_pushing_two_int_elements_in_stack();
	tearDown();
	testEnded();
	testStarted("test_9_pop_should_poped_out_one_int_element");
	setup();
		test_9_pop_should_poped_out_one_int_element();
	tearDown();
	testEnded();
	testStarted("test_10_pop_should_poped_out_float_element");
	setup();
		test_10_pop_should_poped_out_float_element();
	tearDown();
	testEnded();
	testStarted("test_11_pop_should_poped_out_char_element");
	setup();
		test_11_pop_should_poped_out_char_element();
	tearDown();
	testEnded();
	testStarted("test_12_pop_should_poped_out_two_int_element");
	setup();
		test_12_pop_should_poped_out_two_int_element();
	tearDown();
	testEnded();
	testStarted("test_13_top_should_return_the_top_most_int_element_in_stack");
	setup();
		test_13_top_should_return_the_top_most_int_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_14_top_should_return_the_top_most_float_element_in_stack");
	setup();
		test_14_top_should_return_the_top_most_float_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_15_top_should_return_the_top_most_element_of_char_element_in_stack");
	setup();
		test_15_top_should_return_the_top_most_element_of_char_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_16_is_empty_should_return_1_if_there_are_no_elements_in_stack");
	setup();
		test_16_is_empty_should_return_1_if_there_are_no_elements_in_stack();
	tearDown();
	testEnded();
	testStarted("test_17_is_empty_should_return_0_if_there_is_a_element_in_stack");
	setup();
		test_17_is_empty_should_return_0_if_there_is_a_element_in_stack();
	tearDown();
	testEnded();
	testStarted("test_18_isFull_should_return_1_when_stack_is_full");
	setup();
		test_18_isFull_should_return_1_when_stack_is_full();
	tearDown();
	testEnded();
	testStarted("test_19_isFull_should_return_1_when_stack_is_full_using_string");
	setup();
		test_19_isFull_should_return_1_when_stack_is_full_using_string();
	tearDown();
	testEnded();
	testStarted("test_20_isFull_should_return_0_when_stack_is_not_full");
	setup();
		test_20_isFull_should_return_0_when_stack_is_not_full();
	tearDown();
	testEnded();
	testStarted("test_21_pop_should_poped_out_string_element");
	setup();
		test_21_pop_should_poped_out_string_element();
	tearDown();
	testEnded();
	testStarted("test_22_push_should_push_string_element");
	setup();
		test_22_push_should_push_string_element();
	tearDown();
	testEnded();
	testStarted("test_23_push_should_not_push_if_it_is_full");
	setup();
		test_23_push_should_not_push_if_it_is_full();
	tearDown();
	testEnded();
	testStarted("test_24_pop_should_not_pop_string_if_it_is_empty");
	setup();
		test_24_pop_should_not_pop_string_if_it_is_empty();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
