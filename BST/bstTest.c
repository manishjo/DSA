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

int compareIntParents(void* first, void* second){
	return *(int*)first == *(int*)second;
}

int compareCharParents(void* first, void* second){
	return *(char*)first == *(char*)second;
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
	childs* Childs;
	int data = 5,data2 = 10,answer;
	answer = insert(tree,&data);
	answer = insert(tree,&data2);
	Childs = getChildrens(tree,&data,compareIntParents);
	ASSERT(10 == *(int*)(Childs->rightData));
	ASSERT(answer == 1);
} 

void test_should_insert_char_children_data_to_root_node(){
	Bst* tree = create(compareCharData);
	childs* childs;
	char data = 'a',data2 = 'b';
	int answer;
	answer = insert(tree,&data);
	answer = insert(tree,&data2);
	childs = getChildrens(tree,&data,compareCharParents);
	ASSERT('b' == *(char*)(childs->rightData));
	ASSERT(answer == 1);	
}

void test_should_insert_int_children_data_to_a_child_node(){
	Bst* tree = create(compareIntData);
	childs* childs;
	int data = 10, data2 = 20, data3 = 30;
	int answer;
	answer = insert(tree,&data);
	answer = insert(tree,&data2);
	answer = insert(tree,&data3);
	childs = getChildrens(tree,&data2,compareCharParents);
	ASSERT(30 == *(int*)(childs->rightData));
	ASSERT(answer == 1);		
}

void test_should_insert_data_anywhere_in_the_tree(){
	int data[5] = {5,4,8,6,12};
	childs* Childs;
	Bst* tree = create(compareIntData);
	insert(tree,&data[0]);
	insert(tree,&data[1]);
	insert(tree,&data[2]);
	insert(tree,&data[3]);
	insert(tree,&data[4]);
	Childs = getChildrens(tree,&data[2],compareIntParents);
	ASSERT(12 == *(int*)(Childs->rightData));
	ASSERT(6 == *(int*)(Childs->leftData));
}

void test_should_search_the_node_in_the_bst(){
	int data[5] = {5,4,8,6,12};
	int success = 1;
	Bst* tree = create(compareIntData);
	insert(tree,&data[0]);
	insert(tree,&data[1]);
	insert(tree,&data[2]);
	insert(tree,&data[3]);
	insert(tree,&data[4]);
	ASSERT(success==search(tree,&data[2],compareIntParents));
}


