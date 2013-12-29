typedef int (*compare)(void* first, void* second);
void mergeSort(void* base, int numberOfElements, int elementSize, compare comp); 
void merge(void* left, void* right, void* base,int lenthLeft,int lenthRight,
	int elementSize,compare comp);