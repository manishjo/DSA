typedef struct{
	void *base;
	int numberOfElements;
	int elementSize;
	int front;
	int rear;
}Queue;

Queue* create(int elementSize, int length);
int enqueue(Queue* q,void* element);
void* dequeue(Queue* q);
int isEmpty(Queue* q);
int isFull(Queue* q);