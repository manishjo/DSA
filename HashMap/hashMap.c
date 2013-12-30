#include "hashMap.h"
#include <stdlib.h>
typedef struct{
	List *dlist;
}Bucket;
Bucket *createBuckets(){
	Bucket *bucket = calloc(1,sizeof(Bucket));
	bucket->dlist = createList();
	return bucket;
};

Hash_map* create_hash(hasGenerator hasFunc, KeyComparator compare, int totelBuckets){
	Hash_map* hashMap = calloc(1, sizeof(Hash_map));
	int i;
	hashMap->buckets = create(totelBuckets);
	for(i=0;i<totelBuckets;i++){
		hashMap->buckets.base[i]= createBuckets();
	};
	hashMap->compare = compare;
	hashMap->totelBuckets = totelBuckets;
	hashMap->hasFunc = hasFunc;
	return hashMap;
};
int put(Hash_map *hashMap,void *value,void *key){
	int userKey= hashMap->hasFunc(&key);
	return 1;
};
