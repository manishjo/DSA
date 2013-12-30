#include "testUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[15];

int hasCodeGenerator(void* key,Hash_map *hashMap){
	return *(int*)key%hashMap->totelBuckets;
}

int compareIt(void* firstKey, void* secondkey){
    return *(int*)firstKey == *(int*)secondkey;
}

void test_create_hash_should_create_a_hash_map(){
	Hash_map *hash_map = create_hash(hasCodeGenerator, compareIt,10);
	ASSERT(hash_map->totelBuckets == 10);
};

void test_put_should_put_a_value_in_the_bucket(){
	int result;
	string key = "mango";
	string value = "aam";
	Hash_map *hash_map = create_hash(hasCodeGenerator,compareIt,10);
	result = put(hash_map,value,key);
	ASSERT(result == 1);
}

