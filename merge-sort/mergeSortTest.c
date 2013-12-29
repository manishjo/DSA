#include "testUtils.h"
#include "mergeSort.h"
#include <string.h>

typedef char string[10];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* first, void* second){
        return *(int*)first < *(int*)second;
}

int compareFloat(void* first, void* second){
        return (*(float*)first < *(float*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first < *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first < *(char*)second);
}

int compareString(void* first, void* second){
        return (0 > strcmp((char*)first, (char*)second));
}

void test_should_sort_int_data(){
	int count;
	int data[4] = {4,3,2,1};
	mergeSort(&data,4,sizeof(int),compareInt);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==count+1);
	}
}

void test_should_sort_char_data(){
	int count;
	char data[4] = {'d','c','b','a'};
	char after_sorting[4] = {'a','b','c','d'};
	mergeSort(&data,4,sizeof(char),compareChar);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==after_sorting[count]);
	}
}