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

TreeNode* compareAgain(List* list, compareFunc* compareFunc, void* parentData){
	if(list->head->next == NULL){
		return compareNodes(list,compareFunc,parentData);
	}
	return NULL;
}

TreeNode* compareNodes(List* list, compareFunc* compareFunc, void* parentData){
    Iterator* iterator = getIterator(list);
    List* tempList = create();
    TreeNode* pNode;
    Iterator* iteratorChild;
    while(iterator->hasNext(iterator)){
        pNode = (TreeNode*)iterator->next(iterator);
        if(compareFunc(pNode->data,parentData)){
            return pNode;
        }
        iteratorChild = getIterator(pNode->children);
        while(iteratorChild->hasNext(iteratorChild)){
            insert(list, list->length, iteratorChild->next(iteratorChild));
        }
        return compareAgain(list,compareFunc,parentData);
    }
    return NULL;
};


TreeNode* searchParent(Tree* tree,void* parentData){
	TreeNode* parent;
 	TreeNode* root = tree->root;
    if(NULL == parentData || NULL == root)
        return NULL;
    if(tree->compare(root->data, parentData)) return root;
    parent = compareNodes(root->children, tree->compare, parentData);
    return parent;
};

int insertNode(Tree* tree, void* parentData, void* dataToInsert ){
	TreeNode* parentNode;
	TreeNode* childNode;
	if(parentData == NULL){
		tree->root = getNode(parentData,dataToInsert);
		return 1;
	};
	parentNode = searchParent(tree,parentData);
	if(parentNode == NULL) return 0;	
	childNode = getNode(parentNode,dataToInsert);
	return insert(parentNode->children,1,childNode);
};