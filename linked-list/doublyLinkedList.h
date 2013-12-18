typedef struct node{
        void *data;
        struct node* next;
        struct node* pre;
}Node;

typedef struct{
        Node* head;
        int length;
}List;

List* create();
int insert(List* , int , void*);
int Remove(List* , int index);
int findIndex(List*, void*,int);
int length(List*);
void dispose(List* start);
