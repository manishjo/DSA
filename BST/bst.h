typedef int compareFunc (void* frist, void* second);

typedef struct bst{
	compareFunc* compare;
	void* root;
}Bst;

Bst* create(compareFunc* compareFunction);
int insert(Bst* tree, void* data);
int getRootData(Bst* tree);
int remove(Bst* tree, void* data);
int search(Bst* tree, void* data);