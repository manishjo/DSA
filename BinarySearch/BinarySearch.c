#include "BinarySearch.h"

void* binarySearch(void* key,void* base, int noOfElements, int elementSize ,
 int (*compare)( void* , void*)){
 	int frist = 0, last = noOfElements-1;
 	while(frist<=last){
 		int compareResult;
 		int middleValue = (frist+last)/2;
 		compareResult = compare(key,base+middleValue*elementSize);
 		if(compareResult == 0)
 			return base+middleValue*elementSize;
 		else if (compareResult == -1)
 			last = middleValue-1;
 		else
 			frist = middleValue+1;
 	}
 	return NULL;
}