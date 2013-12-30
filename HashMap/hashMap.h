#include "./include/doublyLinkedList.h"
#include "./include/arrayList.h"

typedef int (*hasGenerator)(void* key);
typedef int (*KeyComparator)(void* firstKey, void* secondKey);

typedef struct{
	ArrayList* buckets;
	hasGenerator hasFunc;
	KeyComparator compare;
}hash_map;

int hasCodeGenerator(void* key);







