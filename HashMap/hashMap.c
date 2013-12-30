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
	return hashMap;
};

HashData* createHashData(void* key, void* value){
    HashData* hash_data = calloc(1,sizeof(HashData));
    hash_data->key = key;
    hash_data->value = value;
    return hash_data;
}

int put(Hash_map *hashMap,void *value,void *key){
    int hashCode= hashMap->hasGenerator(key,hashMap);
    int bucketNo = hashCode%hashMap->totalBuckets;
    HashData* hash_data = createHashData(key,value);
    Bucket *bucket = (Bucket*)hashMap->buckets.base[bucketNo];
    insertNode(bucket->dlist,1,hash_data);
    return 1;
};

void* Get(Hash_map *hashMap, void *key){
	int i;
	HashData* currentData;
	List* list;
	ListIterator *it;
	int hashCode = hashMap->hasGenerator(key,hashMap);
	int bucketNo = hashCode % hashMap->totalBuckets;
    Bucket *bucket = (Bucket*)hashMap->buckets.base[bucketNo];
	it = getListIterator(bucket->dlist);
	while(it->hasNextNode(it)){
		currentData = it->nextNode(it);
		if(hashMap->compare(key,currentData->key))
			return currentData->value;
	}
	return NULL;
}


