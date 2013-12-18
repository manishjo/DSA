#include "testUtils.h"
#include "BinarySearch.h"
#include <string.h>


//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareOfInt( void* key, void* middle){
	if(*(int*)key < *(int*)middle)
		return -1;
	else if(*(int*)key > *(int*)middle)
		return 1;
	else
		return 0;
	}

int compareOfFloat( void*key,  void*middle){
	if(*(float*)key < *(float*)middle)
		return -1;
	else if(*(float*)key > *(float*)middle)
		return 1;
	else
		return 0;
}

int compareOfDouble( void*key,  void*middle){
	if(*(double*)key < *(double*)middle)
		return -1;
	else if(*(double*)key > *(double*)middle)
		return 1;
	else
		return 0;
}

int compareOfChar( void*key,  void*middle){
	if(*(char*)key < *(char*)middle)
		return -1;
	else if(*(char*)key > *(char*)middle)
		return 1;
	else
		return 0;
}

int compareOfString( void*key,  void*middle){
	if(strcmp(*(string*)key,*(string*)middle)>0)
		return 1;
	if(strcmp(*(string*)key,*(string*)middle)<0)
		return -1;
	else 
	return 0;
}

void test_should_search_and_return_the_address_of_found_int_element(){
	int elements[5] = {5,7,9,10,12};
	int *answer;
	int key = 9;
	answer = binarySearch(&key,elements,5,sizeof(int),compareOfInt);
	ASSERT(*answer == 9);
}

void test_should_search_and_return_NULL_if_not_found(){
	int elements[5] = {5,7,9,10,12};
	void *answer;
	int key = 100;
	answer = binarySearch(&key,elements,5,sizeof(int),compareOfInt);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_frist_int_element(){
	int elements[5] = {5,7,9,10,12};
	int *answer;
	int key = 5;
	answer = binarySearch(&key,elements,5,sizeof(int),compareOfInt);
	ASSERT(*answer == 5);
}

void test_should_search_and_return_the_last_int_element(){
	int elements[5] = {5,7,9,10,12};
	int *answer;
	int key = 12;
	answer = binarySearch(&key,elements,5,sizeof(int),compareOfInt);
	ASSERT(*answer == 12);
}

void test_should_search_and_give_int_element_if_there_is_ony_one(){
	int elements[1] = {19};
	int *answer;
	int key = 19;
	answer = binarySearch(&key,elements,1,sizeof(int),compareOfFloat);
	ASSERT(*answer == 19);
}

void test_should_return_null_if_there_is_no_int_element(){
	int elements[0] = {};
	int *answer;
	int key = 19;
	answer = binarySearch(&key,elements,1,sizeof(int),compareOfFloat);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_float_element(){
	float elements[4] = {10.1,12.44,23.3,56.33};
	float *answer;
	float key = 12.44;
	answer = binarySearch(&key,elements,4,sizeof(float),compareOfFloat);
	ASSERT(*answer == 12.44f);
}

void test_should_search_and_return_Null_if_float_value_not_found(){
	float elements[4] = {10.1,12.44,23.3,56.33};
	float *answer;
	float key = 12.4;
	answer = binarySearch(&key,elements,4,sizeof(float),compareOfFloat);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_first_float_element(){
	float elements[4] = {10.1,12.44,23.3,56.33};
	float *answer;
	float key = 10.1;
	answer = binarySearch(&key,elements,4,sizeof(float),compareOfFloat);
	ASSERT(*answer == 10.1f);
}

void test_should_search_and_return_the_address_of_last_float_element(){
	float elements[4] = {10.1,12.44,23.3,56.33};
	float *answer;
	float key = 56.33;
	answer = binarySearch(&key,elements,4,sizeof(float),compareOfFloat);
	ASSERT(*answer == 56.33f);
}

void test_should_search_and_give_float_element_if_there_is_only_one(){
	float elements[1] = {19.3};
	float *answer;
	float key = 19.3;
	answer = binarySearch(&key,elements,1,sizeof(float),compareOfFloat);
	ASSERT(*answer == 19.3f);
}

void test_should_return_null_if_there_is_no_float_element(){
	float elements[0] = {};
	float *answer;
	float key = 19.3;
	answer = binarySearch(&key,elements,1,sizeof(float),compareOfFloat);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_double_element(){
	double elements[4] = {60.1,12.44,3.3,3.33};
	double *answer;
	double key = 12.44;
	answer = binarySearch(&key,elements,4,sizeof(double),compareOfDouble);
	ASSERT(*answer == 12.44);
}

void test_should_search_and_return_Null_if_a_double_value_not_found(){
	double elements[4] = {60.1,12.44,3.3,3.33};
	double *answer;
	double key = 12.4;
	answer = binarySearch(&key,elements,4,sizeof(double),compareOfDouble);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_first_double_element(){
	double elements[4] = {10.10,12.44,23.3,56.33};
	double *answer;
	double key = 10.10;
	answer = binarySearch(&key,elements,4,sizeof(double),compareOfDouble);
	ASSERT(*answer == 10.10);
}

void test_should_search_and_return_the_address_of_last_double_element(){
	double elements[4] = {10.1,12.44,23.3,56.336};
	double *answer;
	double key = 56.336;
	answer = binarySearch(&key,elements,4,sizeof(double),compareOfDouble);
	ASSERT(*answer == 56.336);
}

void test_should_search_and_give_double_element_if_there_is_ony_one(){
	double elements[1] = {13.3};
	double *answer;
	double key = 13.3;
	answer = binarySearch(&key,elements,1,sizeof(double),compareOfDouble);
	ASSERT(*answer == 13.3);
}

void test_should_return_null_if_there_is_no_double_element(){
	double elements[0] = {};
	double *answer;
	double key = 169.3;
	answer = binarySearch(&key,elements,1,sizeof(double),compareOfDouble);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_a_char_element(){
	char elements[4] = {'a','b','c','d'};
	char *answer;
	char key = 'b';
	answer = binarySearch(&key,elements,4,sizeof(char),compareOfChar);
	ASSERT(*answer=='b');

}

void test_should_search_and_return_Null_if_a_char_not_found(){
	char elements[4] = {'a','b','c','d'};
	char *answer;
	char key = 'z';
	answer = binarySearch(&key,elements,4,sizeof(char),compareOfChar);
	ASSERT(answer==NULL);
}

void test_should_search_and_return_the_address_of_frist_found_char_element(){
	char elements[4] = {'a','b','c','d'};
	char *answer;
	char key = 'a';
	answer = binarySearch(&key,elements,4,sizeof(char),compareOfChar);
	ASSERT(*answer == 'a');
}

void test_should_search_and_return_the_address_of_last_found_char_element(){
	char elements[4] = {'a','b','c','d'};
	char *answer;
	char key = 'd';
	answer = binarySearch(&key,elements,4,sizeof(char),compareOfChar);
	ASSERT(*answer == 'd');
}

void test_should_search_and_give_char_element_if_there_is_only_one(){
	char elements[1] = {'z'};
	char *answer;
	char key = 'z';
	answer = binarySearch(&key,elements,1,sizeof(char),compareOfChar);
	ASSERT(*answer == 'z');
}

void test_should_return_null_if_there_is_no_char_element(){
	char elements[0] = {};
	char *answer;
	char key = 'a';
	answer = binarySearch(&key,elements,1,sizeof(char),compareOfChar);
	ASSERT(answer == NULL);
}

void test_should_search_and_return_the_address_of_a_string_element(){
	string elements[4] = {"a","b","c","d"};
	string *answer;
	string key = "b";
	answer = binarySearch(&key,elements,4,sizeof(string),compareOfString);
	ASSERT(strcmp(*answer,"b")==0);
}

void test_should_search_and_return_Null_if_a_string_not_found(){
	string elements[4] = {"a","b","c","d"};
	string *answer;
	string key = "z";
	answer = binarySearch(&key,elements,4,sizeof(string),compareOfString);
	ASSERT(answer==NULL);
}

void test_should_search_and_return_the_address_of_frist_string_element(){
	string elements[4] = {"a","b","c","d"};
	string *answer;
	string key = "a";
	answer = binarySearch(&key,elements,4,sizeof(string),compareOfString);
	ASSERT(strcmp(*answer,"a")==0);
}

void test_should_search_and_return_the_address_of_last_found_string_element(){
	string elements[4] = {"a","b","c","d"};
	string *answer;
	string key = "d";
	answer = binarySearch(&key,elements,4,sizeof(string),compareOfString);
	ASSERT(strcmp(*answer,"d")==0);
}

void test_should_search_and_give_string_element_if_there_is_only_one(){
	string elements[1] = {"z"};
	string *answer;
	string key = "z";
	answer = binarySearch(&key,elements,1,sizeof(string),compareOfString);
	ASSERT(strcmp(*answer,"z")==0);
}

void test_should_return_null_if_there_is_no_string_element(){
	string elements[0] = {};
	string *answer;
	string key = "a";
	answer = binarySearch(&key,elements,1,sizeof(string),compareOfString);
	ASSERT(answer == NULL);
}

