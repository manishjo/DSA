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

Hash_map* create_hash(hasGenerator hashCode, KeyComparator compareFunc, int totelBuckets){
	Hash_map* hashMap = calloc(1, sizeof(Hash_map));
	int i;
	hashMap->buckets = create(totelBuckets);
	for(i=0;i<totelBuckets;i++){
		hashMap->buckets.base[i]= createBuckets();
	};
	hashMap->compare = compareFunc;
	hashMap->totelBuckets = totelBuckets;
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
	int bucketNo= hashMap->hasGenerator(&key,hashMap);
	HashData* hash_data = createHashData(key,value);
	insertNode(((List*)hashMap->buckets.base[bucketNo-1]),1,key);
	return 1;
};
