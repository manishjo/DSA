#include "doublyLinkedList.h"

list *create(){
	list* start = (list*)calloc(sizeof(list),1);
	start->length = 0;
	return start;
};

node* createNode(){
	node* nodePtr = (node*)calloc(sizeof(node),1);
	return nodePtr;
}

int insert(list* start , int index , void* data){
	node* nodePtr = createNode();
	node* temp = createNode();
	node* temp2 = createNode();
	if(index > start->length+1) return 0;
		if(start->head == NULL && index == 1){
			nodePtr->data = data;
			start->head = nodePtr;
			start->length += 1; 
			return 1;	
		}
		else if(index == 1){
			nodePtr->data = data;
			nodePtr->next = start->head;
			start->head = nodePtr;
			start->length += 1;
			return 1; 
		}

		else if(index == start->length+1){
			nodePtr->data = data;
			temp->next = start->head;
			while(temp->next!=NULL){
				temp = temp->next;
			}
			temp->next = nodePtr;
			nodePtr->pre = temp;
			start->length += 1;
			return 1;
		}
		else {
			int i;
			nodePtr->data = data;
			temp = start->head;
			for(i=1;i<index-1;i++){
				temp = temp->next;
			}
			temp2 = temp->next;
			temp->next = nodePtr;
			nodePtr->pre = temp;
			nodePtr->next = temp2;
			temp2->pre = nodePtr;
			start->length += 1;
			return 1;
		}
		return 0;
}