#include "bst.h"
#include <stdlib.h>

typedef struct node{
	void* data;
	struct node* leftChild;
	struct node* rightChild;
}Bst_node;

Bst_node* getNode(Bst* tree,Bst_node* nodeData, void* data);

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

Bst_node* searchNodeToLeft(Bst_node* nodeData,Bst* tree,void* data){
	if(nodeData->leftChild == NULL) return nodeData;
	return getNode(tree,nodeData,data);
}

Bst_node* searchNodeToRight(Bst_node* nodeData,Bst* tree,void* data){
	if(nodeData->rightChild == NULL) return nodeData;
	return getNode(tree,nodeData,data);
}

Bst_node* getNode(Bst* tree,Bst_node* nodeData, void* data){
	Bst_node* bstNode;
	int result = tree->compare(nodeData->data,data);
	if(result == 1)
		bstNode = searchNodeToLeft(nodeData,tree,data);
	bstNode = searchNodeToRight(nodeData,tree,data);
	return bstNode;
}

void putNodeToRightLocation(Bst_node* bstNode,Bst_node* childNode,Bst* tree){
	int decide = tree->compare(bstNode->data,childNode->data);
	if(decide == 1)
		bstNode->leftChild = childNode;
	bstNode->rightChild = childNode;
}

int insert(Bst* tree, void* data){
	Bst_node* childNode = giveBstNode(data);
	Bst_node* bstNode;
	if(tree->root == NULL){
		tree->root = childNode;
		return 1;
	}
	bstNode = getNode(tree,((Bst_node*)tree->root),data);
	putNodeToRightLocation(bstNode,childNode,tree);
	return 1;
}

void* getRootData(Bst* tree){
	Bst_node* root = tree->root;
	return root->data;
}
