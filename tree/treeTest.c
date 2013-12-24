#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>
//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

void test_to_create_tree_and_insert_root_with_an_int_data(){
	Tree tree = createTree();
	int data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
	ASSERT(*(int*)tree.root->data == data);
	ASSERT(tree.depth == 0);
}


void test_to_create_tree_and_insert_root_with_an_char_data(){
	Tree tree = createTree();
	char data = 3;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
	ASSERT(*(char*)tree.root->data == data);
	ASSERT(tree.depth == 0);
}


void test_to_create_tree_and_insert_root_with_an_float_data(){
	Tree tree = createTree();
	float data = 3.5;
	int res = insertNode(&tree, NULL, &data);
	ASSERT(res == 1);
	ASSERT(*(float*)tree.root->data == data);
	ASSERT(tree.depth == 0);
}