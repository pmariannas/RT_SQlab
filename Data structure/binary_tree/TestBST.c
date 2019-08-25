#include "BST.h"
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

void printTree(Tree* tree);
int testInserNode(Tree* tree);
int testSearchNode(Tree* tree);
int testDeleteNode(Tree* tree);

int main()
{
    Tree* tree;
    int i = 1, value, result, option;
    tree = createTree();

    if(tree == NULL)
    {
        return 0;
    }
    else 
    {
        printf("NO ERROR in creating TREE\n");
    }
    while(i)
    {
        printf("\n Choose option:\n");
		printf("1: Insert node\n");
		printf("2: Search node\n");
        printf("3: Delete node\n");
        printf("4: Walk \n");
		printf("0 - stop\n");
		
		scanf("%d", &option);
		switch(option)
		{
            case 1:
                result = testInserNode(tree);
                if(result==-1)
                {
                    printf("ERROR function insert\n");
                }
                else if(result==0)
                {
                    printf("insert Done\n");
                }
                break;
            case 2:
                result = testSearchNode(tree);
                if(result==-1)
                {
                    printf("Error function search\n");
                }
                else if(result==1)
                {
                    printf("value exist in tree\n");
                }
                if(result==0)
                {
                    printf("value not exist in tree\n");
                }
                break;
            case 3:
                result = testDeleteNode(tree);
                if(result==-1)
                {
                    printf("Error function delete\n");
                }
                else if(result==0)
                {
                    printf("value not exist in tree\n");
                }
                else if(result==1)
                {
                    printf("value deleted fron tree\n");
                }
                break;
            case 4:
                printf("The function Walk not exist now -SORRY \n");
                break;
            default:
                i = 0;
                break;
        }
    }

    return 0;
}


int testInserNode(Tree* tree)
{
    int i,j,option, value, result, arr[7]={7,11,12,10,15,9,8};
    
    printf("\n Choose option:\n");
    printf("1: Insert 2 node\n");
    printf("2: Insert node in for from 1-10 \n");
    printf("3: Insert node from array \n");
    printf("0 - stop\n");
    
    scanf("%d", &option);
    switch(option)
    {
        case 1:
            result = insertNode(tree, 5);
            result = insertNode(tree, 4);
            break; 
        case 2:
            for(j=0 ; j<10 ; j++)
            {
	            value = j;
                result = insertNode(tree, value);
            }
            break; 
        case 3:
            for(j=0 ; j < 7 ; j++)
            {
                value = arr[j];
                result = insertNode(tree, value);
            }
            break; 
    }
    return result;
}

int testSearchNode(Tree* tree)
{
    int i, value, result;
    printf("Enter value for search \n");
    scanf("%d", &value);
    result = searchBTree(tree, value);
    return result;
}

int testDeleteNode(Tree* tree)
{
    int i, value, result;
    printf("Enter value for delete \n");
    scanf("%d", &value);
    result = deleteNode(tree,value);
    return result;
}
