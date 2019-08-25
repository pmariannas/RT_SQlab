#ifndef H_BST
#define H_BST
#include <stdlib.h>

typedef enum  {OK, AllocationError, WrongInput} BSTStatus;

typedef struct Tree Tree;
/*
typedef void (* elementDestroy)(void *_elem, void *context);
typedef int (* elementCompare)(void *_elemA, void *_elemB);

*/

Tree* createTree();
int insertChild(Tree* root, int child);
BSTStatus searchBTree();
BSTStatus deleteChild();
BSTStatus walkTree();

#endif