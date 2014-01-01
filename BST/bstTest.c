#include "testUtils.h"
#include "bst.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareIntData(void*first, void*second){
	return *(int*)first == *(int*)second;
}

int compareCharData(void*first, void*second){
	return *(char*)first == *(char*)second;
}
