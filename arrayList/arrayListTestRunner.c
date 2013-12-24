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

	testStarted("test_insert_element");
	setup();
		test_insert_element();
	tearDown();
	testEnded();
	testStarted("test_insert_multiple_elements");
	setup();
		test_insert_multiple_elements();
	tearDown();
	testEnded();
	testStarted("test_interns_grows_beyond_capacity");
	setup();
		test_interns_grows_beyond_capacity();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_index_beyond_length");
	setup();
		test_should_not_insert_at_index_beyond_length();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_at_negative_index");
	setup();
		test_should_not_insert_at_negative_index();
	tearDown();
	testEnded();
	testStarted("test_insert_at_middle_should_shift_the_elements");
	setup();
		test_insert_at_middle_should_shift_the_elements();
	tearDown();
	testEnded();
	testStarted("test_should_not_insert_when_list_is_null");
	setup();
		test_should_not_insert_when_list_is_null();
	tearDown();
	testEnded();
	testStarted("test_should_delete_from_last_of_array_list");
	setup();
		test_should_delete_from_last_of_array_list();
	tearDown();
	testEnded();
	testStarted("test_should_delete_from_middle_of_an_array_list");
	setup();
		test_should_delete_from_middle_of_an_array_list();
	tearDown();
	testEnded();
	testStarted("test_should_delete_from_first_from_array_list");
	setup();
		test_should_delete_from_first_from_array_list();
	tearDown();
	testEnded();
	testStarted("test_add_should_insert_at_last");
	setup();
		test_add_should_insert_at_last();
	tearDown();
	testEnded();
	testStarted("test_search_should_search_the_id");
	setup();
		test_search_should_search_the_id();
	tearDown();
	testEnded();
	testStarted("test_search_should_not_give_id_index_if_not_found");
	setup();
		test_search_should_not_give_id_index_if_not_found();
	tearDown();
	testEnded();
	testStarted("test_search_should_search_the_age");
	setup();
		test_search_should_search_the_age();
	tearDown();
	testEnded();
	testStarted("test_search_should_not_give_index_if_age_not_found");
	setup();
		test_search_should_not_give_index_if_age_not_found();
	tearDown();
	testEnded();
	testStarted("test_getIterator_should_return_a_Iterator");
	setup();
		test_getIterator_should_return_a_Iterator();
	tearDown();
	testEnded();
	testStarted("test_getIterator_next_should_give_first_data");
	setup();
		test_getIterator_next_should_give_first_data();
	tearDown();
	testEnded();
	testStarted("test_getIterator_next_should_give_2nd_data");
	setup();
		test_getIterator_next_should_give_2nd_data();
	tearDown();
	testEnded();
	testStarted("test_getIterator_next_should_not_give_data_if_there_is_no_data");
	setup();
		test_getIterator_next_should_not_give_data_if_there_is_no_data();
	tearDown();
	testEnded();
	testStarted("test_getIterator_hasNext_should_tell_there_is_a_node");
	setup();
		test_getIterator_hasNext_should_tell_there_is_a_node();
	tearDown();
	testEnded();

	summarizeTestCount();
	fixtureTearDown();
	return 0;
}

void fixtureSetup(){}

void fixtureTearDown(){}
