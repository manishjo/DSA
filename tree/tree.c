#include "tree.h"
#include <stdlib.h>

typedef struct TreeNode{
	void* data;
	struct TreeNode* parent;
	List* children;
} TreeNode;

TreeNode* compareNodes(List* list, compareFunc* compareFunc, void* parentData);

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

TreeNode* compareNodes(List* list, compareFunc* compareFunc, void* parentData){
    Iterator* iterator = getIterator(list);
    TreeNode* treeNode,result;
    Iterator* iteratorChild;
    List *listOfChildren = create();
    if (0 == iterator->hasNext(iterator)){
    	return NULL;
    }
    while(iterator->hasNext(iterator)){
        treeNode = (TreeNode*)iterator->next(iterator);
        if(compareFunc(treeNode->data,parentData)){
            return treeNode;
        }
        if(treeNode->children->head != NULL){
	        iteratorChild = getIterator(treeNode->children);
	        while(iteratorChild->hasNext(iteratorChild)){
	            insert(listOfChildren, listOfChildren->length + 1, iteratorChild->next(iteratorChild));
	        }
        }
    }
    return compareNodes(listOfChildren,compareFunc,parentData);
};


TreeNode* searchParent(Tree* tree,void* parentData){
	TreeNode* parent;
 	TreeNode* root = tree->root;
    if(NULL == root)
        return NULL;
    if(tree->compare(root->data, parentData)) return root;
    parent = compareNodes(root->children, tree->compare, parentData);
    return parent;
};

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	TreeNode* parentNode;
	TreeNode* childNode;	
	if(parentData == NULL && tree->root == NULL){
		tree->root = getNode(parentData,dataToInsert);
		return 1;
	};

	parentNode = searchParent(tree,parentData);
	if(parentNode == NULL) return 0;	
	childNode = getNode(parentNode,dataToInsert);
	return insert(parentNode->children,1,childNode);
};

int getChildIndex(List* list,void* childData, compareFunc* compareFunc){
    Iterator* iterator = getIterator(list);
    TreeNode *ptNode;
    int result;
    while(iterator->hasNext(iterator)){
        ptNode = iterator->next(iterator);
        result = compareFunc(ptNode->data, childData);
        if(result) return iterator->currentPosition;
    }
    return -1;
}

int deleteNode(Tree* tree, void* dataToDelete){
	TreeNode* parentNode;
	TreeNode* nodeToSearch;
	int index;
	if(tree->root == NULL) return 0;
	parentNode = tree->root;
	if(((List*)(parentNode->children))->head == NULL){
		tree->root = NULL;
		return 1;
	}
	nodeToSearch = searchParent(tree,dataToDelete);
	parentNode = nodeToSearch->parent;
	if(nodeToSearch == NULL)return 0;
	if(nodeToSearch->children->head != NULL) return 0;
	index = getChildIndex(parentNode->children,dataToDelete,tree->compare);
	if(index == -1) return 0;
	return Remove(parentNode->children,index);
}



