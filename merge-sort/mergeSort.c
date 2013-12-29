#include "mergeSort.h"
#include <stdlib.h>
#include <memory.h>

void merge(void* left, void* right, void* base,int lenthLeft,int lenthRight,
	int elementSize,compare comp){
	int i=0,j=0,k=0;
	while(i<lenthLeft && j<lenthRight){
		if(comp(left+i*elementSize,right+j*elementSize)){
			memmove(base+k*elementSize,left+i*elementSize,elementSize);
			i++;
		}
		else{
			memmove(base+k*elementSize,right+j*elementSize,elementSize);
			j++;
		}
		k++;
	}
	while(i<lenthLeft){
		memmove(base+k*elementSize,left+i*elementSize,elementSize);
		i++;
		k++;
	}
	while(j<lenthRight){
		memmove(base+k*elementSize,right+j*elementSize,elementSize);
		j++;
		k++;
	}
}


void mergeSort(void* base, int numberOfElements, int elementSize, compare comp){
	int mid = numberOfElements/2,i,j,lenthOfLeft,lenthOfRight;
	void* left = calloc(mid,elementSize);
	void* right = calloc((numberOfElements-mid),elementSize);
	if(numberOfElements < 2) return;
	lenthOfLeft = mid;
	lenthOfRight = numberOfElements-mid;
	for(i=0;i<mid;i++)
		memmove(left+i*elementSize,base+i*elementSize,elementSize);
	for(i=mid;i<numberOfElements;i++)
		memmove(right+elementSize*(i-mid),base+elementSize*i,elementSize);
	mergeSort(left,lenthOfLeft,elementSize,comp);
	mergeSort(right,lenthOfRight,elementSize,comp);
	merge(left,right,base,lenthOfLeft,lenthOfRight,elementSize,comp);
}