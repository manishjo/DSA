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

void test_insert_should_insert_children_to_a_children_node(){
	Tree tree = createTree(compareIntData);
	int res;
	int data = 3;
	int child1 = 4;
	int child12 = 5;
	res = insertNode(&tree, NULL, &data);
	res = insertNode(&tree, &data , &child1);
	res = insertNode(&tree, &child1 , &child12);
	ASSERT(res == 1);
}

void test_insert_should_insert_2_childrens_to_a_children_node(){
	Tree tree = createTree(compareIntData);
	int res;
	int data = 3;
	int child1 = 4;
	int child12 = 5;
	int child13 = 6;
	res = insertNode(&tree, NULL, &data);
	res = insertNode(&tree, &data , &child1);
	res = insertNode(&tree, &child1 , &child12);
	res = insertNode(&tree,&child1,&child13);
	ASSERT(res == 1);
}

void test_insert_should_insert_children_to_any_child(){
	Tree tree = createTree(compareIntData);
	int data[10]={1,2,3,4,5,6,7,8,9,10};
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0] ,&data[1]);
	res = insertNode(&tree, &data[1] ,&data[2]);
	res = insertNode(&tree,&data[2],&data[3]);
	res = insertNode(&tree,&data[3],&data[4]);
	res = insertNode(&tree,&data[4],&data[5]);
	ASSERT(res == 1);
}





