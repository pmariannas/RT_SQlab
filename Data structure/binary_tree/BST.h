#ifndef H_BST
#define H_BST

typedef struct Tree Tree;


Tree* createTree();
int insertNode(Tree* tree, int value);
int searchBTree(Tree* tree, int value);
int deleteNode(Tree* tree, int value);


#endif
