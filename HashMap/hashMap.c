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

void assignListToBuckets(Hash_map* hashMap,int totalBucket){
	int i;
	for(i=0;i<totalBucket;i++)
	hashMap->buckets.base[i]= createBuckets();
}

Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totalBucket){
	Hash_map* hashMap = calloc(1, sizeof(Hash_map));
	hashMap->buckets = create(totalBucket);
	assignListToBuckets(hashMap,totalBucket);
	hashMap->compare = compareFunc;
	hashMap->totalBucket = totalBucket;
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

void DisposeExistingList(Hash_map* hashMap){
	int i;
	List* bucket;
	for(i=0;i<hashMap->totalBucket;i++){
		bucket = ((List*)hashMap->buckets.base[i]);
		disposeList(bucket);
	}
}

void Put_hashData_agian_in_HashMap(Hash_map *hashMap,HashData* bucket){
	HashIterator* iterator;
	iterator = getListIterator(hashMap->allKeys);
	while(iterator->hasNextNode(iterator)){
		bucket = iterator->nextNode(iterator);
		put(hashMap,bucket->value,bucket->key);
	}
}

int rehashing(Hash_map *hashMap){
	int i;
	HashData* bucket;
	int totalBucket = hashMap->totalBucket;
   	DisposeExistingList(hashMap);
   	hashMap->totalBucket =totalBucket*2;
   	hashMap->buckets.base = realloc(hashMap->buckets.base ,hashMap->totalBucket*sizeof(void*));
   	assignListToBuckets(hashMap,hashMap->totalBucket);
	Put_hashData_agian_in_HashMap(hashMap,bucket);
	return 1;
}

int checkForRehashing(Hash_map *hashMap, int bucketNo){
	List* HashList = ((List*)hashMap->buckets.base[bucketNo]);
	if(HashList->length <= 2)
		return 0;
	return rehashing(hashMap);
}

int put(Hash_map *hashMap,void *value,void *key){
	int index=0,hashCode,bucketNo;
	HashData* hash_data;
	Bucket *bucket;
    hashCode= hashMap->hasGenerator(key);
    bucketNo = hashCode%hashMap->totalBucket;
    hash_data = createHashData(key,value);
    index = ((List*)hashMap->allKeys)->length + 1;
    insertNode((List*)hashMap->allKeys,index,hash_data);  
	if(1 == checkForRehashing(hashMap,bucketNo)) return 1;
    bucket = (Bucket*)hashMap->buckets.base[bucketNo];
    insertNode(bucket->dlist,1,hash_data);
    return 1;
};

void* Get(Hash_map *hashMap, void *key){
	int i;
	HashData* currentData;
	ListIterator *iterator;
	int hashCode = hashMap->hasGenerator(key);
	int bucketNo = hashCode % hashMap->totalBucket;
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
	int hashCode = hashMap->hasGenerator(key);
	int bucketNo = hashCode % hashMap->totalBucket;
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

void* allKeys(HashIterator* iterator){
	HashData* hashdata;
	HashIterator* iterator2 = getListIterator(iterator->list);
	iterator2->currentPosition = iterator->currentPosition;
	hashdata = iterator2->nextNode(iterator2);
	iterator->currentPosition++;
	if(hashdata == NULL) return NULL;
	return hashdata->key;		
}

HashIterator* getKeys(Hash_map* hashMap){
	HashIterator* iterator;
	List* list = ((List*)hashMap->allKeys);
	iterator = getListIterator(list);
	iterator->nextNode = allKeys; 
	return iterator;
}

void dispose_hash(Hash_map* hash){
    ArrayList* arrlist = &hash->buckets;
    Bucket* bucket;
    Iterator* itBucket = getIterator(arrlist);
    while(itBucket->hasNext(itBucket)){
        bucket = itBucket->next(itBucket);
        disposeList(bucket->dlist);
        free(bucket);
    }
    disposeList(hash->allKeys);
}