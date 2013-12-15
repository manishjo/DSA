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

	testStarted("test_should_create_top_to_null");
	setup();
		test_should_create_top_to_null();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_an_int_element_to_stack");
	setup();
		test_push_should_push_an_int_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_a_float_element_to_stack");
	setup();
		test_push_should_push_a_float_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_a_char_element_to_stack");
	setup();
		test_push_should_push_a_char_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_a_double_element_to_stack");
	setup();
		test_push_should_push_a_double_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_a_string_element_to_stack");
	setup();
		test_push_should_push_a_string_element_to_stack();
	tearDown();
	testEnded();
	testStarted("test_push_should_push_more_then_one_int_element_in_stack");
	setup();
		test_push_should_push_more_then_one_int_element_in_stack();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void setup(){}

void tearDown(){}

void fixtureSetup(){}

void fixtureTearDown(){}
