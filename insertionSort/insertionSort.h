#include <stdlib.h>
typedef struct {
	char name[20];
	int accountNumber;
	float balance;
} Account;

typedef int (*compare)(void* first, void* second);
void isort(void* base, size_t numberOfElements, size_t elementSize,compare comp);