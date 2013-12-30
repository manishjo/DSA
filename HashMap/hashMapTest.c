#include "testUtils.h"
#include "hashMap.h"

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed
typedef char string[15];

void test_hasCodeGenerator_should_give_hascode_for_a_string(){
	int hashCode;
	string key = "hello";
	hashCode = hasCodeGenerator(key);
	ASSERT(4 == hashCode);
}