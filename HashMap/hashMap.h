#include "./include/doublyLinkedList.h"
#include "./include/arrayList.h"

typedef int (*hasGenerator)(void* key);
typedef int (*KeyComparator)(void* firstKey, void* secondKey);

typedef struct{
	ArrayList buckets;
	hasGenerator hasFunc;
	KeyComparator compare;
	int totelBuckets;
}Hash_map;

Hash_map* create_hash(hasGenerator hasFunc, KeyComparator compare, int totelBuckets);







