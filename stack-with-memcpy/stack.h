typedef struct{
	void *base;
	int numberOfElements;
	int elementSize;
	int top;
}Stack;

typedef char string[256];

Stack* create(int elementSize, int length);
int push(Stack* s,void* element);
void* pop(Stack* s);
void* top(Stack* s);
int isEmpty(Stack* s);
int isFull(Stack* s);