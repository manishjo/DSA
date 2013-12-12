#include "testUtils.h"
#include "circulerQueue.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
circulerQueue *cq;

void tearDown(){
        free(cq->base);
}

int areEqual(circulerQueue a, circulerQueue b){
    int result = a.front == b.front && a.rear == b.rear && a.numberOfElements == b.numberOfElements && a.elementSize == b.elementSize;
    if(!result) return result;
    return 1;
}

int Compare(void* expected, void* actual,int size){
    return 0 == memcmp(expected,actual,size);
}

void test_should_create_a_int_circulerQueue(){
	int arr[2];
	circulerQueue expected = {arr,2,sizeof(int),-1,-1};
	cq = create(sizeof(int),2);
	ASSERT(areEqual(expected,*cq));
}

void test_should_create_a_float_circulerQueue(){
	float arr[3];
	circulerQueue expected = {arr,3,sizeof(float),-1,-1};
	cq = create(sizeof(float),3);
	ASSERT(areEqual(expected,*cq));
}

void test_should_create_a_char_circulerQueue(){
	char arr[3];
	circulerQueue expected = {arr,3,sizeof(char),-1,-1};
	cq = create(sizeof(char),3);
	ASSERT(areEqual(expected,*cq));
}

void test_should_create_a_double_circulerQueue(){
	double arr[3];
	circulerQueue expected = {arr,3,sizeof(double),-1,-1};
	cq = create(sizeof(double),3);
	ASSERT(areEqual(*cq,expected));
}

void test_should_create_a_string_circulerQueue(){
	string arr[2];
	circulerQueue expected = {arr,2,sizeof(string),-1,-1};
	cq=create(sizeof(string),2);
	memcpy(cq->base,arr,2*sizeof(string));
	ASSERT(areEqual(*cq,expected));
}

void test_should_enqueue_a_int_element_in_circulerQueue(){
	int arr[3];
	int element = 3, answer;
	circulerQueue expected = {arr,3,sizeof(int),0,0};
	cq = create(sizeof(int),3);
	answer = enqueue(cq,&element);
	ASSERT(areEqual(*cq,expected));
	ASSERT(answer == 1);
}

void test_should_enqueue_a_float_element_in_circulerQueue(){
	float arr[3];
	float element = 3.5, answer;
	circulerQueue expected = {arr,3,sizeof(float),0,0};
	cq = create(sizeof(float),3);
	answer = enqueue(cq,&element);
	ASSERT(areEqual(*cq,expected));
	ASSERT(answer == 1);
}

void test_should_enqueue_a_double_element_in_circulerQueue(){
	double arr[3];
	double element = 8.99, answer;
	double element2 = 7.9;
	circulerQueue expected = {arr,3,sizeof(double),0,1};
	cq = create(sizeof(double),3);
	answer = enqueue(cq,&element);
	answer = enqueue(cq,&element2);
	ASSERT(areEqual(*cq,expected));
	ASSERT(answer == 1);	
}

void test_should_enqueue_a_char_element_in_circulerQueue(){
	char arr[2];
	char element = 'a';
	int answer;
	char element2 = 'b';
	circulerQueue expected = {arr,2,sizeof(char),0,1};
	cq = create(sizeof(char),2);
	answer = enqueue(cq,&element);
	answer = enqueue(cq,&element2);
	ASSERT(areEqual(*cq,expected));
	ASSERT(answer == 1);		
}

void test_should_enqueue_a_string_element_in_circulerQueue(){
	string arr[2];
	int answer;
	string element = "swamiji";
	string element2 = "jayanth";
	circulerQueue expected = {arr,2,sizeof(string),0,1};
	cq = create(sizeof(string),2);
	answer = enqueue(cq,&element);
	answer = enqueue(cq,&element2);
	ASSERT(areEqual(*cq,expected));
	ASSERT(answer == 1);	
}

void test_should_return_0_if_enqueueing_int_in_a_full_circulerQueue(){
	int answer;
	int element1 = 10;
	int element2 = 20;
	int element3 = 30;
	cq = create(sizeof(int),2);
	answer = enqueue(cq,&element1);
	answer = enqueue(cq,&element2);
	answer = enqueue(cq,&element3);
	ASSERT(answer == 0);
}

void test_should_return_0_if_enqueueing_string_in_a_full_circulerQueue(){
	int answer;
	string name1 = "amit";
	string name2 = "arjun";
	string name3 = "manish";
	cq = create(sizeof(string),2);
	answer = enqueue(cq,&name1);
	answer = enqueue(cq,&name2);
	answer = enqueue(cq,&name3);
	ASSERT(answer == 0);
}

void test_should_return_0_if_enqueueing_double_in_a_full_circulerQueue(){
	int answer;
	double number1 = 12.44;
	double number2 = 23.4;
	double number3 = 11.5;
	cq = create(sizeof(string),2);
	answer = enqueue(cq,&number1);
	answer = enqueue(cq,&number2);
	answer = enqueue(cq,&number3);
	ASSERT(answer == 0);
}

void test_should_dequeue_int_element_and_return_the_element(){
	int *dequeuedElement;
	int number1 = 12;
	int number2 = 13;
	int number3 = 15;
	cq = create(sizeof(int),3);
	enqueue(cq,&number1);
	enqueue(cq,&number2);
	enqueue(cq,&number3);
	dequeuedElement = dequeue(cq);
	ASSERT(*dequeuedElement == 12);
}

void test_should_dequeue_float_element_and_return_the_element(){
	float *dequeuedElement;
	float number1 = 1.2;
	float number2 = 12.3;
	float number3 = 14.5;
	cq = create(sizeof(float),3);
	enqueue(cq,&number1);
	enqueue(cq,&number2);
	enqueue(cq,&number3);
	dequeuedElement = dequeue(cq);
	ASSERT(*dequeuedElement == 1.2f);
}

void test_should_dequeue_char_element_and_return_the_element(){
	char *dequeuedElement;
	char number1 = 'm';
	char number2 = 'c';
	cq = create(sizeof(char),2);
	enqueue(cq,&number1);
	enqueue(cq,&number2);
	dequeuedElement = dequeue(cq);
	ASSERT(*dequeuedElement == 'm');
}

void test_should_dequeue_string_element_and_return_the_element(){
	string *dequeuedElement;
	string number1 = "hello";
	string number2 = "world";
	cq = create(sizeof(string),2);
	enqueue(cq,&number1);
	enqueue(cq,&number2);
	dequeuedElement = dequeue(cq);
	ASSERT(strcmp(*dequeuedElement ,"hello")==0);
}

void test_should_return_0_if_there_is_no_element_in_the_circulerQueue(){
	int* result;
	cq = create(sizeof(int),2);
	result = dequeue(cq);
	ASSERT(result == NULL);
}

void test_rear_should_go_reverse_if_int_element_is_deleted_from_full_circulerQueue(){
	int result;
	int num1 = 2;
	int num2 = 3;
	int num3 = 4;
	int num4 = 5;
	cq = create(sizeof(int),3);
	result = enqueue(cq,&num1);
	result = enqueue(cq,&num2); 
	result = enqueue(cq,&num3);
	dequeue(cq);
	result = enqueue(cq,&num4);  
	ASSERT(result == 1);
	ASSERT(cq->rear == 0);
	ASSERT(cq->front == 1);
}

void test_rear_should_go_reverse_if_double_element_is_deleted_from_full_circulerQueue(){
	int result;
	double num1 = 2.33;
	double num2 = 3.44;
	double num3 = 4.55;
	double num4 = 5.66;
	cq = create(sizeof(double),3);
	result = enqueue(cq,&num1);
	result = enqueue(cq,&num2); 
	result = enqueue(cq,&num3);
	dequeue(cq);
	result = enqueue(cq,&num4);  
	ASSERT(result == 1);
	ASSERT(cq->rear == 0);
	ASSERT(cq->front == 1);
}

void test_should_be_able_to_dequeue_twice_in_reverse(){
	int result;
	char element1 = 'a';
	char element2 = 'b';
	char element3 = 'c';
	char element4 = 'd';
	cq = create(sizeof(char),3);
	result = enqueue(cq,&element1);
	result = enqueue(cq,&element2); 
	result = enqueue(cq,&element3);
	dequeue(cq);
	dequeue(cq);
	result = enqueue(cq,&element4);  
	ASSERT(result == 1);
	ASSERT(cq->rear == 0);
	ASSERT(cq->front == 2);
}

void test_should_be_able_to_reverse_the_front_back_to_element_0(){
	int no1 = 1;
	int no2 = 2;
	int no3 = 3;
	cq = create(sizeof(int),3);
	enqueue(cq,&no1);
	enqueue(cq,&no2); 
	enqueue(cq,&no3);
	dequeue(cq);
	dequeue(cq);
	dequeue(cq);
	ASSERT(cq->front == 0);	
}

void test_should_return_1_if_circulerQueue_isEmpty(){
	int result;
	cq = create(sizeof(int),2);
	result = isEmpty(cq);
	ASSERT(result == 1);
}

void test_should_return_0_if_circulerQueue_isEmpty(){
	int result;
	float element = 4.5;
	cq = create(sizeof(float),2);
	enqueue(cq,&element);
	result = isEmpty(cq);
	ASSERT(result == 0);
}

void test_should_return_1_if_circulerQueue_isFull(){
	int result;
	int element = 5;
	cq = create(sizeof(int),1);
	enqueue(cq,&result);
	result = isFull(cq);	
	ASSERT(result == 1);
}

void test_should_return_0_if_circulerQueue_is_not_Full(){
	int result;
	int element = 5;
	cq = create(sizeof(int),2);
	result = isFull(cq);	
	ASSERT(result == 0);
}