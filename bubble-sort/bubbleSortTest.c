#include "testUtils.h"
#include "bubbleSort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* first, void* second){
        return (*(int*)first - *(int*)second);
}

int compareFloat(void* first, void* second){
        return (*(float*)first - *(float*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first - *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first - *(char*)second);
}

int compareString(void* first, void* second){
        return strcmp((char*)first, (char*)second);
}

void test_should_sort_int_data(){
	int count;
	int data[4] = {4,3,2,1};
	int after_sorting[4] = {1,2,3,4};
	bubbleSort(&data,4,sizeof(int),compareInt);
	// for(count=0;count<4;count++){
	// 	ASSERT(data[count]==after_sorting[count]);
	// }
}