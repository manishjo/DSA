typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

typedef struct it{
	int (*hasNext)(struct it* it);
	void* (*next)(struct it* it);
	ArrayList* list;
	int currentPosition;
}Iterator;

ArrayList create(int capacity);

typedef int (*compare)(void* first, void* second);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);

int remove(ArrayList* list, int index);

int add(ArrayList* list, void* data);

int search(ArrayList* list, void*data, compare compareFunc);

Iterator* getIterator(ArrayList* list);

int hasNext(Iterator* iterator);

void* next(Iterator* iterator);



