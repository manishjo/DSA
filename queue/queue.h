typedef struct{
	void *base;
	int numberOfElements;
	int elementSize;
	int front;
	int rear;
}queue;

queue* create(int elementSize, int length);
int enqueue(queue* q,void* element);
void* dequeue(queue* q);
int isEmpty(queue* q);
int isFull(queue* q);