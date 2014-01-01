#include "bst.h"
#include <stdlib.h>

typedef struct node{
	void* data;
	struct node* leftChild;
	struct node* rightChild;
}Bst_node;

Bst* create(compareFunc* compareFunction){
	Bst* tree = calloc(1,sizeof(Bst));
	tree->compare = compareFunction;
	tree->root = NULL;
	return tree;
}

Bst_node* getNode(void* data){
	Bst_node* bstNode = calloc(1,sizeof(Bst_node));
	bstNode->data = data;
	return bstNode;
}

int insert(Bst* tree, void* data){
	Bst_node* bstNode;
	if(tree->root == NULL){
		bstNode = getNode(data);
		return 1;
	}
	return 0;
}
