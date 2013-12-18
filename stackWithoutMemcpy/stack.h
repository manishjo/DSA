typedef struct{
	void** data;
	int numOfElements;
	int top;
}Stack;

Stack* create( int length);
int push(Stack* s,void* element);
void* pop(Stack* s);
void* top(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);