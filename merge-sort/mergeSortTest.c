#include "testUtils.h"
#include "mergeSort.h"
#include <string.h>

//create setup, tearDown, fixtureSetup, fixtureTearDown methods if needed

int compareInt (void* first, void* second){
        return (*(int*)first - *(int*)second);
}

int compareFloat(void* first, void* second){
        return (*(float*)first - *(float*)second);
}

int compareDouble(void* first, void* second){
        return (*(double*)first - *(double*)second);
}

int compareChar(void* first, void* second){
        return (*(char*)first - *(char*)second);
}

int compareString(void* first, void* second){
        return strcmp((char*)first, (char*)second);
}
