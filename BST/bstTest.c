#include "testUtils.h"
#include "bst.h"
#include <stdlib.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntData(void*first, void*second){
	return *(int*)first == *(int*)second;
}

int compareCharData(void*first, void*second){
	return *(char*)first == *(char*)second;
}

void test_create_should_create_a_tree(){
	Bst* tree = create(compareIntData);
	ASSERT(tree->root == NULL);	
}