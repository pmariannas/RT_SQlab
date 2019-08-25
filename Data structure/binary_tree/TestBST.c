#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "BST.h"

int insertTest();

int main()
{
    Tree *t1;
    t1 = createTree();
    if(t1==NULL)
    {
        printf("ERROR in CREATING TREE\n");
    }
    else
    {
        printf("TREE ccreated\n");

    }
    insertTest(t1);
    return 0;
}



int insertTest(Tree** root)
{
    srand(time(NULL));
    int i,value;
    for(i=0 ; i<10 ; i++)
    {
	    value = rand()%99;
        insertChild(root, value);
    }

}