#include "testUtils.h"
#include "hashMap.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

typedef char string[15];

int hasCodeGenerator(void* key,Hash_map *hashMap){
	char* res =  (char*)key;
	int a = res[0];
	return a;
}

int compareIt(void* firstKey, void* secondkey){
    return (0 == strcmp((char*)firstKey,(char*)secondkey));
}

void test_create_hash_should_create_a_hash_map(){
	Hash_map *hash_map = create_hash(hasCodeGenerator, compareIt,10);
	ASSERT(hash_map->totalBuckets == 10);
};

void test_put_should_put_a_value_in_the_bucket(){
	int result;
	string key = "mango";
	string value = "aam";
	Hash_map *hash_map = create_hash(hasCodeGenerator,compareIt,10);
	result = put(hash_map,value,key);
	ASSERT(result == 1);
}

void test_put_should_put_two_values_in_the_bucket(){
	int result;
	string key = "formidable";
	string value = "powerfull";
	string key2 = "apple";
	string value2 = "saeb";
	Hash_map* hash_map = create_hash(hasCodeGenerator,compareIt,10);
	result = put(hash_map,value,key);
	ASSERT(result == 1);
	result = put(hash_map,value2,key2);
	ASSERT(result == 1);
}

void test_get_should_get_a_value_from_a_key(){
	void* result;
	string key = "formidable";
	string value = "powerfull";
	Hash_map* hash_map = create_hash(hasCodeGenerator,compareIt,10);
	put(hash_map,&value,&key);
	result = Get(hash_map,&key);
	ASSERT(strcmp(*(string*)value,*(string*)result) == 0);
}


void test_get_should_get_value_from_a_key_among_two(){
	void* result;
	string key = "chair";
	string value = "kursi";
	string key2 = "stick";
	string value2 = "chadi";
	Hash_map* hash_map = create_hash(hasCodeGenerator,compareIt,10);
	put(hash_map,&value,&key);
	put(hash_map,&value2,&key2);
	result = Get(hash_map,&key2);
	ASSERT(strcmp(*(string*)value2,*(string*)result) == 0);
}

void test_get_should_not_return_value_if_key_is_not_present(){
	void* result;
	string key = "makad";
	string value = "monkey";
	string key2 = "gap";
	Hash_map* hash_map = create_hash(hasCodeGenerator,compareIt,10);
	put(hash_map,&value,&key);
	result = Get(hash_map,&key2);
	ASSERT(result == NULL);
}

void test_delete_should_delete_given_key_value_from_the_hash(){
	int result;
	string key = "chair";
	string value = "kursi";
	string key2 = "stick";
	string value2 = "chadi";
	Hash_map* hash_map = create_hash(hasCodeGenerator,compareIt,10);
	put(hash_map,&value,&key);
	put(hash_map,&value2,&key2);
	result = remove_hash(hash_map,&key2);
	ASSERT(result == 1);
}








