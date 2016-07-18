//. Write a program to construct a queue using Linked List with comments on each line.
#include <stdio.h> 
#include <stdlib.h> 

struct node{
	int info;
	struct node *next; 
};
typedef struct node NodeType; 
NodeType *rear=0,*front=0; 


int insert(int item) {
NodeType *nnode;// declaration of node
nnode=( NodeType *)malloc(sizeof(NodeType));
if(rear==0) {// if there is no node, program enters here.
	nnode->info=item;  //the item is placed in nnode->info
	nnode->next=NULL; //to place nnode->next content with NULL value. 
	rear=front=nnode; // rear and front contains NULL value
} 
else {//if there is more than one nodes, program enters here.
	nnode->info=item; 
	nnode->next=NULL; //nnode->next contains NULL value
	rear->next=nnode; 
	rear=nnode;
	} 
}

// to delete a node
int delete() {
	NodeType *temp; 
	if(front==0){// if there is no nodes
		printf("Queue contain no elements:\n");
		return; 
	}
	else if(front->next==NULL) {// if there is only one nodes 
		temp=front;// temp contains the address of front
		rear=front=NULL;// rear and front contains NULL value
		printf("\nDeleted item is %d\n",temp->info); // display the deleated items
		free(temp);
	} 
	else {// if there is more than one nodes .
		temp=front;// temp contains the address of front
		front=front->next;//front is pointed to next
		printf("\nDeleted item is %d\n",temp->info);
		free(temp); 
	}
}
// to display all the nodes 
int display() {
	NodeType *temp; 
	temp=front;//temp contains the address of front
	printf("\nqueue items are:\t"); 
	while(temp!=NULL){
		printf("%d\t",temp->info);
		temp=temp->next; 
	}
}
int main(){
	int choice, item;
	do
	{
	printf("\n1.Insert \n2.Delete \n3.Display\n4:Exit\n"); 
	printf("enter ur choice\n");
	scanf("%d",&choice);
	switch(choice){
		case 1:
			printf("\nEnter the data:\n"); 
			scanf("%d",&item); 
			insert(item);
			break;
		case 2:
			delete();
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

