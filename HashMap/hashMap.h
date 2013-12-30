#include "./include/doublyLinkedList.h"
#include "./include/arrayList.h"

typedef int (*KeyComparator)(void* firstKey, void* secondKey);

typedef struct hashMap{
	ArrayList buckets;
	int (*hasGenerator)(void* key,struct hashMap* hash_map);
	KeyComparator compare;
	int totelBuckets;
}Hash_map;

typedef int (*hasGenerator)(void* key,Hash_map* hash_map);
Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totelBuckets);
int put(Hash_map *hashMap,void *value,void *key);







