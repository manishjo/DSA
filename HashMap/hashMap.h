#include "./include/doublyLinkedList.h"
#include "./include/arrayList.h"

typedef int (*KeyComparator)(void* firstKey, void* secondKey);

typedef struct hashMap{
	ArrayList buckets;
	int (*hasGenerator)(void* key);
	KeyComparator compare;
	int totalBucket;
	void* allKeys; 
}Hash_map;

typedef ListIterator HashIterator;

typedef int (*hasGenerator)(void* key);
Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totalBuckets);
int put(Hash_map *hashMap,void *value,void *key);
void* Get(Hash_map *hashMap , void *key);
int remove_hash(Hash_map* hashMap, void * key);
HashIterator* getKeys(Hash_map* hashMap);
void dispose_hash(Hash_map* hash);