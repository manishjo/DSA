#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntData(void*first, void*second){
	return *(int*)first == *(int*)second;
}

void test_to_create_tree_and_insert_root_with_an_int_data(){
	Tree tree = createTree(compareIntData);
	int data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
}


void test_to_create_tree_and_insert_root_with_an_char_data(){
	Tree tree = createTree(compareIntData);
	char data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
}


void test_to_create_tree_and_insert_root_with_an_float_data(){
	Tree tree = createTree(compareIntData);
	float data = 3.5;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
}

void test_insert_should_insert_a_child_to_root_node(){
	Tree tree = createTree(compareIntData);
	int res;
	int parent_data = 3;
	int child_data = 4;
	res = insertNode(&tree, NULL, &parent_data);
	res = insertNode(&tree, &parent_data,&child_data);
	ASSERT(res == 1);
}

void test_insert_should_insert_two_children_to_root_node(){
	Tree tree = createTree(compareIntData);
	int res;
	int parent_data = 3;
	int child1 = 4;
	int child2 = 5;
	res = insertNode(&tree, NULL, &parent_data);
	res = insertNode(&tree, &parent_data,&child1);
	res = insertNode(&tree, &parent_data,&child2);
	ASSERT(res == 1);
}