#include "testUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[15];

int hasCodeGenerator(void* key){
	return *(int*)key;
}

int compareIt(void* firstKey, void* secondkey){
    return *(int*)firstKey == *(int*)secondkey;
}

void test_hasCodeGenerator_should_give_hascode_for_a_string(){
	Hash_map *hash_map = create_hash(hasCodeGenerator, compareIt,10);
	ASSERT(hash_map->totelBuckets == 10);
}

