#include "testUtils.h"
#include "queue.h"
#include <string.h>
#include <stdlib.h>

typedef char string[256];

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

queue* myQueue;

void tearDown(){
        free(myQueue->base);
}

int areEqual(queue a, queue b){
    int result = a.front == b.front && a.rear == b.rear && a.numberOfElements == b.numberOfElements && a.elementSize == b.elementSize;
    if(!result) return result;
    return 0 == memcmp(a.base,b.base,a.numberOfElements*a.elementSize);
}

void test_should_create_a_int_queue(){
	int arr[3]={0,0,0};
	queue expected = {arr,3,sizeof(int),-1,-1};
	myQueue = create(sizeof(int),3);
	ASSERT(areEqual(*myQueue,expected));
}

void test_should_create_a_float_queue(){
	float arr[3]={0,0,0};
	queue expected = {arr,3,sizeof(float),-1,-1};
	myQueue = create(sizeof(float),3);
	ASSERT(areEqual(*myQueue,expected));
}

void test_should_create_a_char_queue(){
	char arr[3]={'\0','\0','\0'};
	queue expected = {arr,3,sizeof(char),-1,-1};
	myQueue = create(sizeof(char),3);
	ASSERT(areEqual(*myQueue,expected));
}

void test_should_create_string_queue(){
	string arr[2]={"manish","yogesh"};
	queue expected = {arr,2,sizeof(string),-1,-1};
	myQueue = create(sizeof(string),2);
	memcpy(myQueue->base, arr, 2*sizeof(string));
	ASSERT(areEqual(*myQueue,expected));
}

void test_should_enqueue_a_int_element_in_queue(){
	int arr[1] = {10},result;
	int element = 10;
	queue expected = {arr,1,sizeof(int),0,0};
	myQueue = create(sizeof(int),1);
	result = enqueue(myQueue,&element);
	ASSERT(areEqual(*myQueue,expected));
	ASSERT(result == 1);
}

void test_should_enqueue_float_element_in_queue(){
	float arr[2] = {10.1,2.5};
	int result;
	float element1 = 10.1;
	float element2 = 2.5;
	queue expected = {arr,2,sizeof(float),0,1};
	myQueue = create(sizeof(float),2);
	result = enqueue(myQueue,&element1);
	result = enqueue(myQueue,&element2);
	ASSERT(areEqual(*myQueue,expected));
	ASSERT(result == 1);
}

void test_should_enqueue_char_element_in_queue(){
	char arr[2] = {'a','y'};
	int result;
	char element1 = 'a';
	char element2 = 'y';
	queue expected = {arr,2,sizeof(char),0,1};
	myQueue = create(sizeof(char),2);
	result = enqueue(myQueue,&element1);
	result = enqueue(myQueue,&element2);
	ASSERT(areEqual(*myQueue,expected));
	ASSERT(result == 1);
}

void test_should_enqueue_string_in_queue(){
	string arr[2] = {"dubey","tiwari"};
	int result;
	string element1 = "dubey";
	string element2 = "tiwari";
	queue expected = {arr,2,sizeof(string),0,1};
	myQueue = create(sizeof(string),2);
	result = enqueue(myQueue,&element1);
	result = enqueue(myQueue,&element2);
	ASSERT(areEqual(*myQueue,expected));
	ASSERT(result == 1);
}

void test_should_dequeue_int_element_from_queue(){
	int element1 = 5, *result;
	int element2 = 10;
	int element3 = 15;
	myQueue = create(sizeof(int),3);
	enqueue(myQueue,&element1);
	enqueue(myQueue,&element2);
	
	enqueue(myQueue,&element3);
	 result = dequeue(myQueue);
	ASSERT(myQueue->front==0);
	ASSERT(myQueue->rear ==1);
	ASSERT(*result==5);
}

void test_should_dequeue_float_element_from_queue(){
	float element1 = 5.2;
	float element2 = 10.3;
	float element3 = 15.5;
	float *result;
	myQueue = create(sizeof(float),3);
	enqueue(myQueue,&element1);
	enqueue(myQueue,&element2);
	enqueue(myQueue,&element3);
	result = dequeue(myQueue);
	ASSERT(myQueue->front==0);
	ASSERT(myQueue->rear ==1);
	ASSERT(*result==5.2f);
}

void test_should_dequeue_char_element_from_queue(){
	char element1 = 'a';
	char element2 = 'b';
	char* result;
	myQueue = create(sizeof(char),2);
	enqueue(myQueue,&element1);
	enqueue(myQueue,&element2);
	result = dequeue(myQueue);
	ASSERT(myQueue->front==0);
	ASSERT(myQueue->rear ==0);
	ASSERT(*result=='a');
}

void test_should_returns_1_when_queue_is_empty(){
	int result;
	myQueue = create(sizeof(int),2);
	result = isEmpty(myQueue);
	ASSERT(1==result);
}

void test_should_returns_0_when_queue_is_empty(){
	int result;
	int element = 5;
	myQueue = create(sizeof(int),2);
	enqueue(myQueue,&element);
	result = isEmpty(myQueue);
	ASSERT(0==result);
}

void test_should_return_1_when_queue_is_full(){
	int result;
	int element = 10;
	myQueue = create(sizeof(int),1);
	enqueue(myQueue,&element);
	result = isFull(myQueue);
	ASSERT(1==result);
}

void test_should_return_0_when_queue_is_not_full(){
	int result;
	int element = 10;
	myQueue = create(sizeof(int),2);
	enqueue(myQueue,&element);
	result = isFull(myQueue);
	ASSERT(0==result);
}

void test_should_return_0_on_enqueue_if_queue_is_full(){
	int result;
	int element = 20;
	int element1 = 30;
	myQueue = create(sizeof(int),1);
	enqueue(myQueue,&element);
	result = enqueue(myQueue,&element1);
	ASSERT(0==result);
}

void test_should_return_0_on_dequeue_if_queue_is_empty(){
	int* result;
	myQueue = create(sizeof(int),2);
	result = dequeue(myQueue);
	ASSERT(result==NULL);
}
