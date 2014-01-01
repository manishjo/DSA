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

Bst_node* giveBstNode(void* data){
	Bst_node* bstNode = calloc(1,sizeof(Bst_node));
	bstNode->data = data;
	return bstNode;
}

Bst_node* searchNodeToLeft(){

}

Bst_node* searchNodeToRight(){

}

Bst_node* getNode(Bst* tree, void* data){
	Bst_node* bstNode;
	Bst_node* rootData = tree->root;
	int result = tree->compare(rootData->data,data);
	if(result == 1)
		bstNode = searchNodeToLeft();
	bstNode = searchNodeToRight();
	return bstNode;
}

int insert(Bst* tree, void* data){
	Bst_node* childNode = giveBstNode(data);
	Bst_node* bstNode;
	if(tree->root == NULL){
		tree->root = childNode;
		return 1;
	}
	bstNode = getNode(tree,data);
	return 0;
}

void* getRootData(Bst* tree){
	Bst_node* root = tree->root;
	return root->data;
}
