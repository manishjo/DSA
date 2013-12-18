typedef struct node{
	void *data;
	int priority;
	struct node* next;
}Node;

typedef struct{
	Node* head;
	int length;
}list;

list* create();
int enqueue(list*,int priority,void* data);
int dequeue(list*);
