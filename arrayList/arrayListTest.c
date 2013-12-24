#include <stdlib.h>

#include "testUtils.h"
#include "arrayList.h"

const int SUCCESS = 1;
const int FAILURE = 0;

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef struct {
	int id;
	char* name;
	int age;
} Intern;

Intern prateek = {15386, "Prateek", 18};
Intern md = {13432, "Immortal", 17};
Intern manish = {15398, "joshi" , 19};	
ArrayList interns;
ArrayList *internsPtr;

void setup() {
	int noOfElements = 2;	
	interns = create(noOfElements);
	internsPtr = &interns;
}

void tearDown() {
	dispose(internsPtr);	
}

void test_insert_element(){
	int result = insert(internsPtr, 0, &prateek);
	Intern *actual = (Intern*)get(internsPtr, 0);
	ASSERT(result == SUCCESS);
	ASSERT(prateek.id == actual->id);
}

void test_insert_multiple_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &md);
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&md == get(internsPtr, 1));
}

void test_interns_grows_beyond_capacity() {
	int noOfElements = 1;
	ArrayList list = create(noOfElements);
	ArrayList *listPtr = &list;

	insert(listPtr, 0, &prateek);
	insert(listPtr, 1, &md);

	ASSERT(&prateek == get(listPtr, 0));
	ASSERT(&md == get(listPtr, 1));

	dispose(listPtr);		
}

void test_should_not_insert_at_index_beyond_length() {
	int result = FAILURE;
	result = insert(internsPtr, 2, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_not_insert_at_negative_index() {
	int result = FAILURE;
	result = insert(internsPtr, -1, &prateek);
	ASSERT(result == FAILURE);
}

void test_insert_at_middle_should_shift_the_elements() {
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &md);
	insert(internsPtr, 1, &manish);
	
	ASSERT(&prateek == get(internsPtr, 0));
	ASSERT(&manish == get(internsPtr, 1));
	ASSERT(&md == get(internsPtr, 2));
}

void test_should_not_insert_when_list_is_null() {
	int result = insert(NULL, 1, &prateek);
	ASSERT(result == FAILURE);
}

void test_should_delete_from_last_of_array_list(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr, 1, &md);
	ASSERT(SUCCESS == remove(internsPtr,1));
	ASSERT(get(internsPtr,1) == NULL);
}

void test_should_delete_from_middle_of_an_array_list(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&md);
	insert(internsPtr,2,&manish);
	ASSERT(SUCCESS == remove(internsPtr,1));
	ASSERT(get(internsPtr,1) == &manish);
}

void test_should_delete_from_first_from_array_list(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&md);
	insert(internsPtr,2,&manish);
	ASSERT(SUCCESS == remove(internsPtr,0));
	ASSERT(get(internsPtr,0) == &md);	
}

void test_add_should_insert_at_last(){
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&md);
	ASSERT(add(internsPtr,&manish) == SUCCESS);	
}

int compareId(void* first,void* second){
	Intern firstIntern = *(Intern*)first;
	Intern secondIntern = *(Intern*)second;
	return firstIntern.id == secondIntern.id;
}

void test_search_should_search_the_element(){
	int id = 15398;
	int answer;
	insert(internsPtr, 0, &prateek);
	insert(internsPtr,1,&md);
	insert(internsPtr,2,&manish);
	answer = search(internsPtr,&id,compareId);
	ASSERT(answer == 2);
}

