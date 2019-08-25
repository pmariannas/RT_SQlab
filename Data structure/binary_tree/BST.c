#include "BST.h"
#include <stdlib.h>

typedef struct Node Node;

struct Node{
	int _value;
	Node* _left;
    Node* _right;
};

struct Tree{
    int _numOfNodes;
	Node* _root;
};

static Node* createNode(int value);
static Node* findMinimum(Node* current);
static Node* myDeleteNode(Node* current, int value);


/*-----------------------------------------------*/
Tree* createTree()
{
    Tree* t1;

    t1 = (Tree*)malloc(sizeof(Tree));
    
    if(t1==NULL)
    {
        return NULL;
    }

    t1->_root = NULL;

	return t1;
}
/*-----------------------------------------------*/
static Node* createNode(int value)
{
    Node* node ;
    node = malloc(sizeof(Node));
    
    if(node==NULL)
    {
        return NULL;
    }

    node->_value = value;
    node->_left = NULL;
    node->_right = NULL;

	return node;
}
/*-----------------------------------------------*/
int insertNode(Tree* tree, int value)
{
    Node* node;
    Node* current;
    Node* parent;

    if(tree == NULL)
    {
        return 1;
    }   
    
    node = createNode(value);

    if(node == NULL)
    {
        return -1;
    }
    /*check if tree is empty*/
    if(tree->_root == NULL)
    {
        tree->_root = node;
        return 0;
    }
    /*if tree is not empty*/
    current = tree->_root;
    parent = NULL;
    /*move to place to put the value*/
    while(current != NULL)
    {
        parent = current;
        if(current->_value > value)
        {
            current = current->_left;
        }
        else
        {
            current = current->_right;
        }
    }
    /*put the node in place*/
    if(parent->_value > value)
    {
        parent->_left = node;
    }
    else
    {
        parent->_right = node;
    }

    return 0;
}
/*-----------------------------------------------*/
int searchBTree(Tree* tree, int value)
{
    Node* current;
    Node* parent;

    if(tree == NULL)
    {
        return -1;
    }   

    /*check if tree is empty*/
    if(tree->_root == NULL)
    {
        return -1;
    }
    /*if tree is not empty*/
    current = tree->_root;
    parent = NULL;
    
    while(current != NULL)
    {
        if(current->_value == value)
        {
            return 1;
        }

        parent = current;
        if(current->_value > value)
        {
            current = current->_left;
        }
        else
        {
            current = current->_right;
        }
    }
    return 0;
}
/*-----------------------------------------------*/
int deleteNode(Tree* tree, int value)
{
    Node* current;
    Node* result;
    if(tree == NULL)
    {
        return -1;
    }   
    /*check if tree is empty*/
    if(tree->_root == NULL)
    {
        return -1;
    }
    /*if tree is not empty*/
    current = tree->_root;
    result = myDeleteNode(current, value);
    if(result == NULL)
    {
        return 0;
    }
    else
        return 1;
}
/*-----------------------------------------------*/
static Node* myDeleteNode(Node* current, int value)
{
    if(current==NULL)
    {
        return NULL;
    }
    else if(current->_value > value)
    {
        current->_left = myDeleteNode(current->_left, value);
    }
    else if(current->_value < value)
    {
        current->_right = myDeleteNode(current->_right, value);
    }
    else if(current->_value == value)/*node found - delete*/
    {
        /*node has no children*/
        if(current->_left == NULL && current->_right == NULL)
        {
            current = NULL;
        }
        else if(current->_left == NULL)
        {
            current = current->_right;
        }
        else if(current->_right == NULL)
        {
            current = current->_left;
        }
        else /*has 2 children*/
        {
            Node* temp = findMinimum(current->_right);
            current->_value = temp->_value;
            current->_right = myDeleteNode(current->_right, temp->_value);
        }
    }
    else /*node not found (not exist in tree)*/
    {
        return NULL;
    }
    return current;
}

static Node* findMinimum(Node* current)
{
    if(current->_left == NULL)
    {   
        return current;
    }
    return findMinimum(current->_left);
}
