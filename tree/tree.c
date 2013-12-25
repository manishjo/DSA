#include "tree.h"
#include <stdlib.h>


Tree createTree(compareFunc* compare){
	Tree tree;
	tree.root = NULL;
	tree.compare =  compare;
	return tree;
};

TreeNode* getNode(TreeNode* parentNode,void *dataToInsert){
	TreeNode* node = calloc(1, sizeof(TreeNode));
	node->children = create();
	node->data = dataToInsert;
	node->parent = parentNode;
	return node;
};

TreeNode* searchParent(Tree* tree,void* parentData){
	if(1==tree->compare(tree->root->data,parentData))
		return tree->root;
	return NULL;
};

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	TreeNode* parentNode;
	TreeNode* childNode;
	if(parentData == NULL){
		tree->root = getNode(parentData,dataToInsert);
		return 1;
	};
	parentNode = searchParent(tree,parentData);
	childNode = getNode(parentNode,dataToInsert);
	return insert(parentNode->children,1,childNode);
	return 1;
};