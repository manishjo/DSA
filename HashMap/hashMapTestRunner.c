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

	testStarted("test_create_hash_should_create_a_hash_map");
	setup();
		test_create_hash_should_create_a_hash_map();
	tearDown();
	testEnded();
	testStarted("test_put_should_put_a_value_in_the_bucket");
	setup();
		test_put_should_put_a_value_in_the_bucket();
	tearDown();
	testEnded();
	testStarted("test_put_should_put_two_values_in_the_bucket");
	setup();
		test_put_should_put_two_values_in_the_bucket();
	tearDown();
	testEnded();
	testStarted("test_get_should_get_a_value_from_a_key");
	setup();
		test_get_should_get_a_value_from_a_key();
	tearDown();
	testEnded();
	testStarted("test_get_should_get_value_from_a_key_among_two");
	setup();
		test_get_should_get_value_from_a_key_among_two();
	tearDown();
	testEnded();
	testStarted("test_get_should_not_return_value_if_key_is_not_present");
	setup();
		test_get_should_not_return_value_if_key_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_delete_should_delete_given_key_value_from_the_hash");
	setup();
		test_delete_should_delete_given_key_value_from_the_hash();
	tearDown();
	testEnded();
	testStarted("test_delete_should_delete_if_there_is_only_one_key_in_hash");
	setup();
		test_delete_should_delete_if_there_is_only_one_key_in_hash();
	tearDown();
	testEnded();
	testStarted("test_delete_should_not_delete_if_value_is_not_find");
	setup();
		test_delete_should_not_delete_if_value_is_not_find();
	tearDown();
	testEnded();
	testStarted("test_getKeys_should_return_key");
	setup();
		test_getKeys_should_return_key();
	tearDown();
	testEnded();
	testStarted("test_getKeys_should_return_two_keys");
	setup();
		test_getKeys_should_return_two_keys();
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
