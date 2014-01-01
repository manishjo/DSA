#include "./include/doublyLinkedList.h"

typedef int compareFunc (void* frist, void* second);

typedef struct {
        void* root;
        compareFunc *compare;
} Tree;

Tree createTree(compareFunc* compare);
int insertNode(Tree* tree, void* parentData, void* dataToInsert );
int deleteNode(Tree* tree, void* dataToDelete);
int searchNode(Tree* tree, void* data);
Iterator* getChildren(Tree* tree, void *parentData);
void dispose_tree(Tree* tree);