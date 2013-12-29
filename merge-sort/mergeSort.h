typedef int (*compare)(void* first, void* second);
void mergeSort(void* base, int numberOfElements, int elementSize, compare comp); 