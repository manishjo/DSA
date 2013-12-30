typedef struct node{
        void *data;
        struct node* next;
        struct node* pre;
}Node;

typedef struct{
        Node* head;
        int length;
}List;

typedef struct iterator{
	int (*hasNextNode)(struct iterator* it);
	void* (*nextNode)(struct iterator* it);
	List* list;
	int currentPosition;
}ListIterator;

List* createList();
int insertNode(List* , int , void*);
int Remove(List* , int index);
int findIndex(List*, void*,int);
int length(List*);
void disposeList(List* start);
ListIterator* getListIterator(List* list);
int hasNextNode(ListIterator* iterator);
void* nextNode(ListIterator* iterator);

