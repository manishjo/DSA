typedef int compareFunc (void* frist, void* second);

typedef struct bst{
	compareFunc* compare;
	void* root;
}Bst;

typedef struct {
	void *leftData;
	void *rightData;
}childs;

Bst* create(compareFunc* compareFunction);
int insert(Bst* tree, void* data);
void* getRootData(Bst* tree);
childs* getChildrens(Bst *tree,void *parent,compareFunc* compareFunction);

// int remove(Bst* tree, void* data);
// int search(Bst* tree, void* data);