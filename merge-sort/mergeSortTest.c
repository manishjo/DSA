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


void test_should_sort_float_data(){
	int count;
	float data[4] = {4.5,3.5,2.5,1.5};
	float after_sorting[4] = {1.5,2.5,3.5,4.5};
	mergeSort(&data,4,sizeof(float),compareFloat);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==after_sorting[count]);
	}
}

void test_should_sort_double_data(){
	int count;
	double data[4] = {4.5,3.5,2.5,1.5};
	double after_sorting[4] = {1.5,2.5,3.5,4.5};
	mergeSort(&data,4,sizeof(double),compareDouble);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==after_sorting[count]);
	}
}


void test_should_sort_string_data(){
	int count;
	string data[4] = {"deepak","chandu","bhanu","amit"};
	string after_sorting[4] = {"amit","bhanu","chandu","deepak"};
	mergeSort(&data,4,sizeof(string),compareString);
	for(count=0 ; count < 4 ; count++){
		ASSERT(strcmp(data[count],after_sorting[count])==0);
	}
}

void test_should_sort_int_data_if_there_is_only_one_data(){
	int count;
	int data[1] = {4};
	mergeSort(&data,1,sizeof(int),compareInt);
	for(count=0 ; count < 1 ; count++){
		ASSERT(data[count]==4);
	}
}

void test_should_manage_if_it_is_already_sorted(){
	int count;
	double data[4] = {1.5,2.5,3.5,4.5};
	double after_sorting[4] = {1.5,2.5,3.5,4.5};
	mergeSort(&data,4,sizeof(double),compareDouble);
	for(count=0 ; count < 4 ; count++){
		ASSERT(data[count]==after_sorting[count]);
	}
}