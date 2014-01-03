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

	testStarted("test_create_should_create_a_tree");
	setup();
		test_create_should_create_a_tree();
	tearDown();
	testEnded();
	testStarted("test_should_create_root_node_with_int_data_in_tree");
	setup();
		test_should_create_root_node_with_int_data_in_tree();
	tearDown();
	testEnded();
	testStarted("test_should_create_root_node_with_char_data_in_tree");
	setup();
		test_should_create_root_node_with_char_data_in_tree();
	tearDown();
	testEnded();
	testStarted("test_should_insert_int_children_data_to_root_node");
	setup();
		test_should_insert_int_children_data_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_should_insert_char_children_data_to_root_node");
	setup();
		test_should_insert_char_children_data_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_should_insert_int_children_data_to_a_child_node");
	setup();
		test_should_insert_int_children_data_to_a_child_node();
	tearDown();
	testEnded();
	testStarted("test_should_insert_data_anywhere_in_the_tree");
	setup();
		test_should_insert_data_anywhere_in_the_tree();
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
