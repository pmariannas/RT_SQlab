#include <stdlib.h>
#include <time.h>
#include "BST.h"

typedef struct Node{
	int _data;
	struct Node* _left;
    struct Node* _right;
};

struct Tree{
    int _numOfNodes;
	struct Node* _root;
};

Tree* createTree()
{
    Tree* t1 ;
    t1 = malloc(sizeof(Tree));
    
    if(t1==NULL)
    {
        return NULL;
    }

	return t1;
}

Node* createNode(int value)
{
    Node* node ;
    node = malloc(sizeof(Node));
    
    if(node==NULL)
    {
        return NULL;
    }

    node->_data = value;
    node->_left = NULL;
    node->_right = NULL;

	return node;
}


int insertChild(Tree* t, int value)
{
    Node* child;

    /*check if root exist with value*/
    if(t->_root == NULL)
    {
        t->_root->_data = value;
        t->_root->_left = NULL;
        t->_root->_right = NULL;
        return t;
    }

    child = createNode(value);

    if(t->_root->_data > child->_data)
    {
        t->_root->_left = child;

    }
    else
    {
        t->_root->_right = child;
    }
    
   	
}


