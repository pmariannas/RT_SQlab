#include <stdlib.h>
#include <stdio.h>
#include <time.h>
/**/
struct Node{
	int value;
	struct Node* next;
};

typedef struct Node Node;

/**/
Node* createList();
Node* createNode();

void printList(Node* head);
void reverseList(Node** head);
int middElementList(Node* head);
int findLoop(Node* head);
int findComm(Node* head1, Node* head2);
int getComm(Node* head1, Node* head2, int dis);
int getLenList(Node* head);
void deleteList(Node** head);

/*function create one node*/
Node* createNode()
{
	Node* myNode;
	myNode = (Node*)malloc(sizeof(Node));

	int value = rand()%99;
	if(myNode == NULL)
	{
		return NULL;
	}
	myNode->value = value;
	myNode->next = NULL;

	return myNode;
}
/*function create list*/
Node* createList()
{
	int i;
	Node* head = createNode();
	Node* last;

	if(head == NULL)
	{
		return NULL;
	}

	last = head;

	for(i=0 ; i < 10 ; i++)
	{
		last->next = createNode();
		last = last->next;
	}

	return head;
}
/*function flip a linked list*/
void reverseList(Node** head)
{
	Node* prev = NULL;
    Node* current = NULL;
	current = *head; 
    Node* next = NULL; 

    while (current != NULL) { 
        next = current->next; 
  
        current->next = prev; 
  
        prev = current; 
        current = next; 
    } 
    *head = prev; 
}
/*function print the list*/
void printList(Node* head)
{
	Node* temp = head;
	
	while(temp->next!=NULL)
	{			
		printf("%d  ", temp->value);
		temp = temp->next;
	}
	printf("\n");
}
/*function find the middle of a linked list*/
int middElementList(Node* head)
{
	Node* slowPtr = head;
	Node* fastPtr = head;
	int i = 1;
	if(head != NULL)
	{
		while(fastPtr != NULL && fastPtr->next !=NULL)
		{
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
			i++;
		}
		return (slowPtr->value);
	}	
}
/*function find if there is a loop in a linked list*/
int findLoop(Node* head)
{
	Node* slowPtr = head;
	Node* fastPtr = head;
	if(head != NULL)
	{
		while(fastPtr != NULL && fastPtr->next !=NULL)
		{
			fastPtr = fastPtr->next->next;
			slowPtr = slowPtr->next;
			if(fastPtr == slowPtr)
			{
				return 1;
			}
		}
		return 0;
	}	
}
/*function find the commin node */
int findComm(Node* head1, Node* head2)
{
	Node* hd1 = head1;
	Node* hd2 = head2;
	int countH1=0, countH2=0, dis=0, result;

	countH1 = getLenList(head1);
	countH2 = getLenList(head2);
	if(countH1 >= countH2)
	{
		dis = countH1 - countH2;
		result = getComm(head1, head2, dis);
	}
	if(countH1 < countH2)
	{
		dis = countH2 - countH1;
		result = getComm(head2, head1, dis);
	}
	return result;
	
}
/**/
int getComm(Node* head1, Node* head2, int dis)
{
	int i=0;
	/*move head1 to the same place head2 start*/
	for(i = 0 ; i < dis ; i++)
	{
		head1 = head1->next;
	}
	while(head1 != NULL && head2 != NULL)
	{
		if(head1 == head2)
		{
			return head1->value;
		}
		head1 = head1->next;
		head2 = head2->next;
	}
}
/*function get len of list*/
int getLenList(Node* head)
{
	Node* temp = head;
	int count=0;
	while(temp != NULL)
	{
		count++;
		temp = temp->next;
	}
	return count;

}
void deleteList(Node** head)
{
	Node* curr = *head;
	Node* temp;
	while(curr!=NULL)
	{
		temp = curr->next;
		free(curr);
		curr = temp;
	}
	*head = NULL;
}


/*MAIN FUNCTION*/
int main()
{
	int opt = 1, result=0;
	Node* myNode;
	srand(time(NULL));
	myNode = createList();
	
	if(myNode == NULL)
	{
		return -1;
		printf("list not created\n");

	}
	printf("list created\n");
	printf("\n The list: \n");
	printList(myNode);
	printf("\n The reversed list: \n");
	reverseList(&myNode);
	printList(myNode);
	
	result = middElementList(myNode);
	printf("\n The middle: %d\n", result);

	result = findLoop(myNode);
	if(result==1)
	{
		printf("\n There is a loop\n");
	}
	else
	{
		printf("\n There is no loop\n");

	}


	/*findComm(Node* head1, Node* head2);*/


	
/*
printf("0 - exit\n");
		printf("1 - print list\n");
		printf("2 - reverse list\n");
		printf("3 - find middle element\n");
		printf("4 - find loop\n");
		printf("5 - \n");
		printf("7 - \n");
*/
}