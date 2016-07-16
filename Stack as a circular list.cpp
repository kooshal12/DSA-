// Write a program to implement Stack as a circular list with comments on each line.
#include <stdio.h> 
#include <stdlib.h> 

struct node{
	int info;
	struct node *next; 
};
typedef struct node NodeType; 
NodeType *pstack=NULL;

int push(int item)
{
	NodeType *newnode;// declaration of node
	newnode=(NodeType*)malloc(sizeof(NodeType));
	newnode->info=item;
	if(pstack==NULL)
	{
		pstack=newnode;
		pstack->next=pstack;
	}
	else{
		newnode->next=pstack;
		pstack->next=newnode;
	}
}
int pop(){
	NodeType *temp;
	if(pstack==NULL)
	{
		printf("Stack underflow");
		exit(1);
	}
	else if(pstack->next==pstack)// for one node
	{
		printf("poped item is %d",pstack->info);
		pstack=NULL;
	}
	else
	{//if more than one node
		temp=pstack->next;
		pstack->next=temp->next;
		printf("poped item is %d",temp->info);
		free(temp);
	}
}
int display(){
	NodeType *temp; 
	if(pstack==NULL)
	{
		printf("stack is empty");
		return;
	}else{
		temp=pstack;//temp contains the address of pstack
		printf("\nstack items are:\t"); 
		while(temp!=NULL){
			printf("%d\t",temp->info);
			temp=temp->next; 
	}
	}
}
int main(){
	int choice, item;
	do
	{
	printf("\n1.push \n2.pop \n3.Display\n4:Exit\n"); 
	printf("enter ur choice\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the item to push:\n"); 
			scanf("%d",&item); 
			push(item);
			break;
		case 2:
			pop();
			break; 
		case 3:
			display();
			break; 
		case 4:
			exit(1);
			break; 
		default:
			printf("invalid choice\n");
			break; 
		}
	}while(choice<5);
	return 0;
} 
