#include "hashMap.h"

int hasCodeGenerator(void* key){
	return ((char*)key)[0]%10;
}