#include "bst.h"

typedef struct node{
	void* data;
	struct node* leftChild;
	struct node* rightChild;
}Bst_node;