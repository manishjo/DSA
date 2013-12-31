#include "hashMap.h"
#include <stdlib.h>

typedef struct{
	List *dlist;
}Bucket;

typedef struct{
    void* key;
    void* value;
}HashData;

Bucket *createBuckets(){
	Bucket *bucket = calloc(1,sizeof(Bucket));
	bucket->dlist = createList();
	return bucket;
};

Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totalBuckets){
	Hash_map* hashMap = calloc(1, sizeof(Hash_map));
	int i;
	hashMap->buckets = create(totalBuckets);
	for(i=0;i<totalBuckets;i++){
		hashMap->buckets.base[i]= createBuckets();
	};
	hashMap->compare = compareFunc;
	hashMap->totalBuckets = totalBuckets;
	hashMap->hasGenerator = hashCode;
    hashMap->allKeys = createList();
	return hashMap;
};

HashData* createHashData(void* key, void* value){
    HashData* hash_data = calloc(1,sizeof(HashData));
    hash_data->key = key;
    hash_data->value = value;
    return hash_data;
}

int put(Hash_map *hashMap,void *value,void *key){
	int index=0;
    int hashCode= hashMap->hasGenerator(key,hashMap);
    int bucketNo = hashCode%hashMap->totalBuckets;
    HashData* hash_data = createHashData(key,value);
    Bucket *bucket = (Bucket*)hashMap->buckets.base[bucketNo];
    index = ((List*)hashMap->allKeys)->length + 1;
    insertNode((List*)hashMap->allKeys,index,key);  
    insertNode(bucket->dlist,1,hash_data);
    return 1;
};

void* Get(Hash_map *hashMap, void *key){
	int i;
	HashData* currentData;
	ListIterator *iterator;
	int hashCode = hashMap->hasGenerator(key,hashMap);
	int bucketNo = hashCode % hashMap->totalBuckets;
    Bucket *bucket = (Bucket*)hashMap->buckets.base[bucketNo];
	iterator = getListIterator(bucket->dlist);
	while(iterator->hasNextNode(iterator)){
		currentData = iterator->nextNode(iterator);
		if(hashMap->compare(key,currentData->key))
			return currentData->value;
	}
	return NULL;
}

int remove_hash(Hash_map* hashMap, void * key){
	int index=0;
	HashData* currentData;
	List* list;
    Node* node;
	int hashCode = hashMap->hasGenerator(key,hashMap);
	int bucketNo = hashCode % hashMap->totalBuckets;
    Bucket *bucket = (Bucket*)hashMap->buckets.base[bucketNo];
    list = bucket->dlist;
    node = list->head;
	while(list->length){
		++index;
		currentData = node->data;
		if(hashMap->compare(currentData->key,key)){
			Remove(list,index);
			return 1;
			}
		node = node->next;
		}
	return 0;
}

HashIterator* getKeys(Hash_map* hashMap){
	HashIterator* iterator;
	List* list = ((List*)hashMap->allKeys);
	iterator = getListIterator(list);
	return iterator;
}