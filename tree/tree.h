#include "./include/doublyLinkedList.h"

typedef int compareFunc (void* frist, void* second);

typedef struct {
	void* root;
	compareFunc *compare;
} Tree;

Tree createTree(compareFunc* compare);
int insertNode(Tree* tree, void* parentData, void* dataToInsert );
int deleteNode(Tree* tree, void* dataToDelete);