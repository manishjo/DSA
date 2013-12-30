#include <memory.h>
#include <stdlib.h>
#include "testUtils.h"
#include "doublyLinkedList.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
List* start;

void tearDown(){
    free(start);
}

void test_create_should_assign_null_to_head_and_0_to_length(){
	start = createList();
	ASSERT(start->head == NULL);
	ASSERT(start->length == 0);
 };

void test_insert_should_insert_first_node(){
 	int element = 100, answer;
 	start = createList();
 	answer = insertNode(start,1,&element);
 	ASSERT(answer == 1);
};

void test_insert_should_insert_node_in_the_frist_position(){
 	int element = 100, element2 = 200,answer;
 	start = createList();
 	answer = insertNode(start,1,&element);
 	answer = insertNode(start,1,&element2);
 	ASSERT(answer == 1);

};

void test_insert_should_insert_node_in_the_last_position(){
 	int element = 100, element2 = 200,answer;
 	start = createList();
 	answer = insertNode(start,1,&element);
 	answer = insertNode(start,1,&element2);
 	answer = insertNode(start,3,&element2);
  	ASSERT(answer == 1);
};

void test_insert_should_return_0_when_index_is_more_than_required_index(){
	int answer,element=10;
	start = createList();
	answer = insertNode(start,5,&element);
	ASSERT(answer==0);	
};

void test_insert_should_return_1_if_element_inserted_in_the_middle(){
	int answer,element=10;
	start = createList();
	answer = insertNode(start,1,&element);
	answer = insertNode(start,2,&element);
	answer = insertNode(start,3,&element);
	answer = insertNode(start,2,&element);
	ASSERT(answer==1);
};

void test_Remove_should_delete_the_first_element(){
	int answer;
	int element = 10;
	int element2 = 20;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element);
	insertNode(start,3,&element2);
	answer = Remove(start,1);
	ASSERT(answer == 1);
}

void test_Remove_should_delete_the_last_element(){
	int answer;
	int element = 190;
	int element2 = 200;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element);
	insertNode(start,3,&element2);
	answer = Remove(start,3);
	ASSERT(answer == 1);
}
void test_Remove_should_delete_the_middle_element(){
	int answer;
	int element = 190;
	int element2 = 200;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element);
	insertNode(start,3,&element2);
	insertNode(start,4,&element2);
	answer = Remove(start,2);
	ASSERT(answer == 1);
}

void test_length_should_return_the_totel_no_of_elements(){
	int answer;
	int element = 190;
	int element2 = 200;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element);
	insertNode(start,3,&element2);
	insertNode(start,4,&element2);
	answer = length(start);
	ASSERT(answer == 4);
}

void test_findIndex_should_return_the_position_of_element_in_list(){
	int answer;
	int element = 190;
	int element2 = 200;
	int element3 = 200;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	answer = findIndex(start,&element2,sizeof(int));
	ASSERT(answer == 2);	
}

void test_findIndex_should_return_0_if_element_not_found(){
	int answer;
	int element = 190;
	int element2 = 200;
	int element3 = 200;
	int element4 = 50;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	answer = findIndex(start,&element4,sizeof(int));
	ASSERT(answer == 0);	
}

void test_getIterator_should_make_a_iterator(){
	int element = 190;
	int element2 = 200;
	int element3 = 200;
	ListIterator* iterator;	
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	iterator = getListIterator(start);
	ASSERT(0 == iterator->currentPosition);
}

void test_next_should_give_first_value(){
	int element = 190;
	int element2 = 200;
	int element3 = 200;
	ListIterator* iterator;	
	int *answer;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	iterator = getListIterator(start);
	answer = iterator->nextNode(iterator);
	ASSERT(190 == *answer);
}

void test_hasNextNode_should_tell_that_it_has_next_value(){
	int element = 190;
	int element2 = 200;
	int element3 = 200;
	ListIterator* iterator;	
	int answer;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	iterator = getListIterator(start);
	answer = iterator->hasNextNode(iterator);
	ASSERT(1 == answer);
}

void test_hasNextNode_should_tell_that_it_does_not_have_next_value_(){
	int element = 190;
	ListIterator* iterator;	
	int answer;
	start = createList();
	insertNode(start,1,&element);
	iterator = getListIterator(start);
	answer = iterator->hasNextNode(iterator);
	iterator->currentPosition++;
	answer = iterator->hasNextNode(iterator);
	ASSERT(0 == answer);
}

void test_next_should_give_each_element_one_by_one(){
	int element = 190;
	int element2 = 200;
	int element3 = 210;
	ListIterator* iterator;	
	int *answer;
	start = createList();
	insertNode(start,1,&element);
	insertNode(start,2,&element2);
	insertNode(start,3,&element3);
	iterator = getListIterator(start);
	answer = iterator->nextNode(iterator);
	ASSERT(190 == *answer);
	answer = iterator->nextNode(iterator);
	ASSERT(200 == *answer);
	answer = iterator->nextNode(iterator);
	ASSERT(210 == *answer);
}

void test_next_should_give_null_if_there_is_no_data(){
	int element = 190;
	ListIterator* iterator;	
	int *answer;
	start = createList();
	insertNode(start,1,&element);
	iterator = getListIterator(start);
	answer = iterator->nextNode(iterator);
	ASSERT(190 == *answer);
	answer = iterator->nextNode(iterator);
	ASSERT(NULL == answer);
}