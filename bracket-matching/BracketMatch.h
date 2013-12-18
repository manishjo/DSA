#include <stdio.h>
#include <stdlib.h>
#include <memory.h>
#include <string.h>
#include "./include/stack.h"

Stack* create(int elementSize, int length);
int match(Stack* s, int length, char* msg);
