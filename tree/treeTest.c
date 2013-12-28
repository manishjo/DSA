#include "testUtils.h"
#include "tree.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int data[10]={1,2,3,4,5,6,7,8,9,10};		

int compareIntData(void*first, void*second){
	return *(int*)first == *(int*)second;
}

void test_to_create_tree_and_insert_root_with_an_int_data(){
	Tree tree = createTree(compareIntData);
	int res = insertNode(&tree, NULL, &data[0]);
	ASSERT(res == 1);
}


void test_to_create_tree_and_insert_root_with_an_char_data(){
	Tree tree = createTree(compareIntData);
	char data = 'a';
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
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0],&data[1]);
	ASSERT(res == 1);
}

void test_insert_should_insert_two_children_to_root_node(){
	Tree tree = createTree(compareIntData);
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0],&data[1]);
	res = insertNode(&tree, &data[0],&data[2]);
	ASSERT(res == 1);
}

void test_insert_should_insert_children_to_a_children_node(){
	Tree tree = createTree(compareIntData);
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0] , &data[1]);
	res = insertNode(&tree, &data[1] , &data[2]);
	ASSERT(res == 1);
}

void test_insert_should_insert_2_childrens_to_a_children_node(){
	Tree tree = createTree(compareIntData);
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0] , &data[1]);
	res = insertNode(&tree, &data[1] , &data[2]);
	res = insertNode(&tree,&data[1],&data[3]);
	ASSERT(res == 1);
}

void test_insert_should_insert_children_to_any_child(){
	Tree tree = createTree(compareIntData);
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0] ,&data[1]);
	res = insertNode(&tree, &data[1] ,&data[2]);
	res = insertNode(&tree,&data[2],&data[3]);
	res = insertNode(&tree,&data[3],&data[4]);
	res = insertNode(&tree,&data[4],&data[5]);
	ASSERT(res == 1);
}

void test_insert_should_not_insert_if_child_parents_is_not_present(){
	Tree tree = createTree(compareIntData);
	int res;
	res = insertNode(&tree, NULL, &data[0]);
	res = insertNode(&tree, &data[0] , &data[1]);
	res = insertNode(&tree, &data[4] , &data[2]);
	ASSERT(res == 0);	
}

void test_should_not_delete_if_root_node_is_not_present(){
	Tree tree = createTree(compareIntData);
	int res;
	res = deleteNode(&tree,&data[0]);
	ASSERT(res == 0);	
}

void test_delete_should_delete_if_it_is_a_node_without_children(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	res = deleteNode(&tree,&data[0]);
	ASSERT(res == 1); 
}

void test_deleteNode_should_not_delete_root_if_node_has_children(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	insertNode(&tree, &data[0] , &data[1]);
	res = deleteNode(&tree,&data[0]);
	ASSERT(res == 0); 
}

void test_deleteNode_should_not_delete_node_if_it_has_children(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	insertNode(&tree, &data[0] , &data[1]);
	insertNode(&tree, &data[1] ,&data[2]);
	insertNode(&tree,&data[2],&data[3]);
	res = deleteNode(&tree,&data[1]);
	ASSERT(res == 0); 	
}

void test_deleteNode_should_delete_if_it_is_a_leaf_node(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	insertNode(&tree, &data[0] , &data[1]);
	insertNode(&tree, &data[1] ,&data[2]);
	insertNode(&tree,&data[2],&data[3]);
	res = deleteNode(&tree,&data[3]);
	ASSERT(res == 1); 		
}

void test_searchNode_should_give_1_if_node_is_found(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	insertNode(&tree, &data[0] , &data[1]);
	insertNode(&tree, &data[1] ,&data[2]);
	insertNode(&tree,&data[2],&data[3]);
	res = searchNode(&tree,&data[3]);
	ASSERT(res == 1); 	
}

void test_searchNode_should_give_0_if_node_is_not_found(){
	Tree tree = createTree(compareIntData);
	int res;
	insertNode(&tree, NULL, &data[0]);
	insertNode(&tree, &data[0] , &data[1]);
	insertNode(&tree, &data[1] ,&data[2]);
	insertNode(&tree,&data[2],&data[3]);
	res = searchNode(&tree,&data[4]);
	ASSERT(res == 0); 	
}





