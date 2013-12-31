#include "./include/doublyLinkedList.h"
#include "./include/arrayList.h"

typedef int (*KeyComparator)(void* firstKey, void* secondKey);

typedef struct hashMap{
	ArrayList buckets;
	int (*hasGenerator)(void* key,struct hashMap* hash_map);
	KeyComparator compare;
	int totalBuckets;
	void* allKeys; 
}Hash_map;

typedef ListIterator HashIterator;

typedef int (*hasGenerator)(void* key,Hash_map* hash_map);
Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totalBuckets);
int put(Hash_map *hashMap,void *value,void *key);
void* Get(Hash_map *hashMap , void *key);
int remove_hash(Hash_map* hashMap, void * key);
HashIterator* getKeys(Hash_map* hashMap);
void dispose_hash(Hash_map* hash);