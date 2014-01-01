#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntData(void*first, void*second){
	if(*(int*)first > *(int*)second) return 1;
	return -1;
}

int compareCharData(void*first, void*second){
	if(*(char*)first > *(char*)second) return 1;
	return -1;
}

void test_create_should_create_a_tree(){
	Bst* tree = create(compareIntData);
	ASSERT(tree->root == NULL);	
}

void test_should_create_root_node_with_int_data_in_tree(){
	Bst* tree = create(compareIntData);
	int data = 5,answer;
	answer = insert(tree,&data);
	ASSERT(&data == getRootData(tree));
	ASSERT(answer == 1);
}

void test_should_create_root_node_with_char_data_in_tree(){
	Bst* tree = create(compareIntData);
	char data = 'm';
	int answer;
	answer = insert(tree,&data);
	ASSERT(&data == getRootData(tree));
	ASSERT(answer == 1);
}

void test_should_insert_int_children_data_to_root_node(){
	Bst* tree = create(compareIntData);
	int data = 5,data2 = 10,answer;
	answer = insert(tree,&data);
	answer = insert(tree,&data2);
	// ASSERT(&data == getRootData(tree));
	ASSERT(answer == 1);	
} 