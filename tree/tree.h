#include "../linked-list/doublyLinkedList.h"

typedef struct TreeNode{
	void* data;
	struct TreeNode* parent;
	List* children;
} TreeNode;

typedef struct {
	TreeNode* root;
	int depth;
} Tree;

Tree createTree();
int insertNode(Tree* tree, void* parentData, void* dataToInsert );