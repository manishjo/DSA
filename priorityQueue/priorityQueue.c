#include "priorityQueue.h"
list* create(){
	list* listPtr = (list*)calloc(sizeof(list),1);
	return listPtr;
};
void createNode(node *temp,void* data,int priority){
	temp->data = data;
	temp->priority = priority;
};

int createFirstNode(node* nodePtr,list* listPtr,void* data,int priority){
	createNode(nodePtr,data,priority);
	listPtr->head = nodePtr;
	listPtr->length +=1;
	return 1;
}

int insertFirst(node* nodePtr,node* temp,list* listPtr){
	nodePtr->next = temp;
	listPtr->head = nodePtr;
	listPtr->length +=1;
	return 1;
};

int insertLast(node* temp,node* nodePtr,list* listPtr){
	temp->next = nodePtr;
	listPtr->length +=1;
	return 1;	
};

int enqueue(list* listPtr,int priority,void* data){
	node* nodePtr = calloc(sizeof(node),1);
	node *temp=calloc(sizeof(node),1);
	node *temp2=calloc(sizeof(node),1);
	if(listPtr->length == 0){
		return createFirstNode(nodePtr,listPtr,data,priority);
	}
	else{
		createNode(nodePtr,data,priority);
		temp = listPtr->head;
		if(temp->priority > nodePtr->priority)
			return insertFirst(nodePtr,temp,listPtr);
		while(temp->next!=NULL)
			temp= temp->next;	
		if(temp->priority < nodePtr->priority)
			return insertLast(temp,nodePtr,listPtr);
		temp = listPtr->head;
		while(temp->priority < nodePtr->priority){
			temp2=temp;
			temp=temp->next;
		}
		temp2->next = nodePtr;
		nodePtr->next=temp;
		listPtr->length +=1;
		return 1;	
	};
}

int dequeue(list* listPtr){
	node *temp=calloc(sizeof(node),1);
	if(listPtr->length == 0)
		return 0;
	temp = listPtr->head->next;
	listPtr->head = temp;
	listPtr->length -=1;
		return 1;
};

