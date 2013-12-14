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

	testStarted("test_create_should_create_a_head_with_null");
	setup();
		test_create_should_create_a_head_with_null();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_first_int_element_with_priority");
	setup();
		test_enqueue_should_insert_first_int_element_with_priority();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_first_float_element_with_priority");
	setup();
		test_enqueue_should_insert_first_float_element_with_priority();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_first_double_element_with_priority");
	setup();
		test_enqueue_should_insert_first_double_element_with_priority();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_second_int_element_priorty_in_sorted_order");
	setup();
		test_enqueue_should_insert_second_int_element_priorty_in_sorted_order();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_multiple_int_elements_at_first");
	setup();
		test_enqueue_should_insert_multiple_int_elements_at_first();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_multiple_double_elements_at_first");
	setup();
		test_enqueue_should_insert_multiple_double_elements_at_first();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_int_element_in_middle");
	setup();
		test_enqueue_should_insert_int_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_float_element_in_middle");
	setup();
		test_enqueue_should_insert_float_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_char_element_in_middle");
	setup();
		test_enqueue_should_insert_char_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_two_int_element_in_middle");
	setup();
		test_enqueue_should_insert_two_int_element_in_middle();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_int_element_of_same_priorty");
	setup();
		test_enqueue_should_insert_int_element_of_same_priorty();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_float_element_of_same_priorty");
	setup();
		test_enqueue_should_insert_float_element_of_same_priorty();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_integer_element_of_decreasing_priority");
	setup();
		test_enqueue_should_insert_integer_element_of_decreasing_priority();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_char_element_of_decreasing_priority");
	setup();
		test_enqueue_should_insert_char_element_of_decreasing_priority();
	tearDown();
	testEnded();
	testStarted("test_enqueue_should_insert_double_element_of_decreasing_priority");
	setup();
		test_enqueue_should_insert_double_element_of_decreasing_priority();
	tearDown();
	testEnded();
	testStarted("test_should_dequeue_int_element_of_higest_priority");
	setup();
		test_should_dequeue_int_element_of_higest_priority();
	tearDown();
	testEnded();
	testStarted("test_should_dequeue_float_element_of_higest_priority");
	setup();
		test_should_dequeue_float_element_of_higest_priority();
	tearDown();
	testEnded();
	testStarted("test_should_dequeue_char_element_of_higest_priority");
	setup();
		test_should_dequeue_char_element_of_higest_priority();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void fixtureSetup(){}

void fixtureTearDown(){}
