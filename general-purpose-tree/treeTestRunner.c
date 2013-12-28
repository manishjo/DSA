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

	testStarted("test_to_create_tree_and_insert_root_with_an_int_data");
	setup();
		test_to_create_tree_and_insert_root_with_an_int_data();
	tearDown();
	testEnded();
	testStarted("test_to_create_tree_and_insert_root_with_an_char_data");
	setup();
		test_to_create_tree_and_insert_root_with_an_char_data();
	tearDown();
	testEnded();
	testStarted("test_to_create_tree_and_insert_root_with_an_float_data");
	setup();
		test_to_create_tree_and_insert_root_with_an_float_data();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_a_child_to_root_node");
	setup();
		test_insert_should_insert_a_child_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_two_children_to_root_node");
	setup();
		test_insert_should_insert_two_children_to_root_node();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_children_to_a_children_node");
	setup();
		test_insert_should_insert_children_to_a_children_node();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_2_childrens_to_a_children_node");
	setup();
		test_insert_should_insert_2_childrens_to_a_children_node();
	tearDown();
	testEnded();
	testStarted("test_insert_should_insert_children_to_any_child");
	setup();
		test_insert_should_insert_children_to_any_child();
	tearDown();
	testEnded();
	testStarted("test_insert_should_not_insert_if_child_parents_is_not_present");
	setup();
		test_insert_should_not_insert_if_child_parents_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_should_not_delete_if_root_node_is_not_present");
	setup();
		test_should_not_delete_if_root_node_is_not_present();
	tearDown();
	testEnded();
	testStarted("test_delete_should_delete_if_it_is_a_node_without_children");
	setup();
		test_delete_should_delete_if_it_is_a_node_without_children();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_not_delete_root_if_node_has_children");
	setup();
		test_deleteNode_should_not_delete_root_if_node_has_children();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_not_delete_node_if_it_has_children");
	setup();
		test_deleteNode_should_not_delete_node_if_it_has_children();
	tearDown();
	testEnded();
	testStarted("test_deleteNode_should_delete_if_it_is_a_leaf_node");
	setup();
		test_deleteNode_should_delete_if_it_is_a_leaf_node();
	tearDown();
	testEnded();
	testStarted("test_searchNode_should_give_1_if_node_is_found");
	setup();
		test_searchNode_should_give_1_if_node_is_found();
	tearDown();
	testEnded();
	testStarted("test_searchNode_should_give_0_if_node_is_not_found");
	setup();
		test_searchNode_should_give_0_if_node_is_not_found();
	tearDown();
	testEnded();
	testStarted("test_searchNode_should_search_root_node");
	setup();
		test_searchNode_should_search_root_node();
	tearDown();
	testEnded();
	testStarted("test_inserts_a_root_node_into_tree");
	setup();
		test_inserts_a_root_node_into_tree();
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
