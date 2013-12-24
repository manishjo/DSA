typedef struct {
	void** base;
	int capacity;
	int length;
} ArrayList;

ArrayList create(int capacity);

typedef int (*compare)(void* first, void* second);

int insert(ArrayList *list, int index, void* data);

void* get(ArrayList *list, int index);

void dispose(ArrayList *list);

int remove(ArrayList* list, int index);

int add(ArrayList* list, void* data);

int search(ArrayList* list, void*data, compare comp);