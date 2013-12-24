#include "arrayList.h"
#include <stdlib.h>

ArrayList create(int capacity) {
	ArrayList list;
	list.base = (void*)malloc(sizeof(void*) * capacity);
	list.capacity = capacity;
	list.length = 0;
	return list;
}

void shiftElementsIfNeeded(ArrayList *list, int index) {
	int i;
	if (index < list->length) {
		for (i = list->length - 1; i >= index; i--) {
			list->base[i+1] = list->base[i];
		}
	}	
}

int isFull(ArrayList *list) {
	return list->length == list->capacity;
}

void increaseCapacity(ArrayList *list) {
	int targetCapacity;
	if (isFull(list)) {
		targetCapacity = list->capacity * 2;
		list->base = realloc(list->base, targetCapacity * sizeof(void*));
		list->capacity = targetCapacity;
	}	
}

int add(ArrayList *list, void* data){
	int index = list->length;
	return insert(list,index,data);
}

int insert(ArrayList *list, int index, void* data) {
	if (list == NULL) return 0;
	if (index < 0 || index > list->length) return 0;

	increaseCapacity(list);
	shiftElementsIfNeeded(list, index);

	list->base[index] = data;
	list->length++;

	return 1;
}

void* get(ArrayList *list, int index) {
	if (index < 0 || index >= list->length) return NULL;

	return list->base[index];
}

void shiftElementsOnDelete(ArrayList* list, int index){
	int i;
	if(index < list->length){
		for(i=index;i < list->length ;i++){
			list->base[i] = list->base[i+1];
		}
	}
}

int remove(ArrayList* list, int index){
	if(index < 0 || index >= list->length) return 0;
	--list->length;
	shiftElementsOnDelete(list,index);
	return 1;
}

int search(ArrayList* list, void*data, compare compareFunc){
	int i;
	for(i=0;i<list->length;i++){
		if(1==compareFunc(list->base[i],data))
			return i;
	}
	return -1;
}

int hasNext(Iterator* iterator){
	if(iterator->list->length-1 == iterator->currentPosition)
		return 0;
	return 1;
}

void* next(Iterator* iterator){
	int i;
	if(hasNext(iterator) == 0)return NULL;
	++iterator->currentPosition;
	return iterator->list->base[iterator->currentPosition];

}

Iterator* getIterator(ArrayList* list){
	Iterator *iterator = (Iterator*)calloc(1,sizeof(Iterator));
	iterator->currentPosition = -1;
	iterator->hasNext = hasNext;
	iterator->list = list;
	iterator->next = next;
	return iterator;
}

void dispose(ArrayList *list) {
	free(list->base);
}

