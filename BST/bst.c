#include "bst.h"
#include <stdlib.h>

typedef struct node{
	void* data;
	struct node* leftChild;
	struct node* rightChild;
}Bst_node;

Bst_node* getNode(Bst* tree,Bst_node* nodeData, void* data);
Bst_node* searchParent(Bst *tree,Bst_node* bstNode,void *parent,compareFunc* compare);

Bst* create(compareFunc* compareFunction){
	Bst* tree = calloc(1,sizeof(Bst));
	tree->compare = compareFunction;
	tree->root = NULL;
	return tree;
};

Bst_node* getBstNode(void* data){
	Bst_node* bstNode = calloc(1,sizeof(Bst_node));
	bstNode->data = data;
	return bstNode;
};

Bst_node* searchNodeToLeft(Bst_node* nodeData,Bst* tree,void* data){
	if(nodeData->leftChild == NULL) return nodeData;
	return getNode(tree,nodeData->leftChild,data);
}

Bst_node* searchNodeToRight(Bst_node* nodeData,Bst* tree,void* data){
	if(nodeData->rightChild == NULL) return nodeData;
	return getNode(tree,nodeData->rightChild,data);
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
	Bst_node* childNode = getBstNode(data);
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

Bst_node* goToLeft(Bst *tree,Bst_node* bstNode,void *parent,compareFunc* compare){
	if(compare(bstNode->leftChild,parent) == 1) return bstNode;
	return searchParent(tree,bstNode->leftChild,parent,compare);
};

Bst_node* goToRight(Bst *tree,Bst_node* bstNode,void *parent,compareFunc* compare){
	if(compare(bstNode->rightChild,parent) == 1) return bstNode;
	return searchParent(tree,bstNode->rightChild,parent,compare);
};

Bst_node* searchParent(Bst *tree,Bst_node* bstNode,void *parent,compareFunc* compare){
	int result;
	if(compare(bstNode->data,parent) == 1) return bstNode;
	result = tree->compare(bstNode->data,parent);
	if(result == 1)
		bstNode = goToLeft(tree,bstNode,parent,compare);
	bstNode = goToRight(tree,bstNode,parent,compare);
	return bstNode;
}

childs* getChildrens(Bst *tree,void *parent,compareFunc* compare){
	Bst_node* bstNode = tree->root;
	childs* childNode = calloc(1,sizeof(childs));
	if(parent == NULL) return NULL;
	bstNode = searchParent(tree,bstNode,parent,compare);
	if(bstNode->leftChild == NULL && bstNode->rightChild == NULL) return NULL;
	if(bstNode->leftChild == NULL) 
		childNode->rightData = bstNode->rightChild->data;
	if(bstNode->rightChild == NULL)
		childNode->leftData = bstNode->leftChild->data;
	return childNode;
};