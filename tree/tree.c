#include "tree.h"
#include <stdlib.h>


Tree createTree(compareFunc* compare){
	Tree tree;
	tree.root = NULL;
	tree.compare =  compare;
	return tree;
}

TreeNode* getNode(void *dataToInsert){
	TreeNode* node = calloc(1, sizeof(TreeNode));
	node->children = NULL;
	node->data = dataToInsert;
	node->parent = NULL;
	return node;
}

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	if(parentData == NULL){
		tree->root = getNode(dataToInsert);
		return 1;
	}

	return 1;
}