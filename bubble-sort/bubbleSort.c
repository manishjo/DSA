#include "bubbleSort.h"
#include <memory.h>
#include <stdlib.h>

void swap(int j,void* base,int elementSize){
	void* temp = calloc(1, elementSize);
	memmove(temp,base+elementSize*(j),elementSize);
	memmove(base+elementSize*j,base+elementSize*(j+1),elementSize);
	memmove(base+elementSize*(j+1),temp,elementSize);
};

void bubbleSort(void* base, int numberOfElements, int elementSize, compare comp){
	int i,j,compareResult;
	for(i=1;i<numberOfElements;i++){
		for(j=0;j<numberOfElements-1;j++){
			if(0<comp(base+elementSize*j,(base+elementSize*(j+1)))){
				swap(j,base,elementSize);
			}
		}
	}
}