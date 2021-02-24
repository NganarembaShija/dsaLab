#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
}*head;

typedef struct node node;

void createList();
void display();

void main(){
	int i,choice;
	head=(node*)malloc(sizeof(node));
	do{
		printf("\nMain Menu\n1. Create List\n2. Display\n3. Exit\n\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: createList();
					break;

			case 2: display();
					break;

			case 3: return;

			default: printf("Wrong choice\n");
		}
	}
	while(choice!=3);
}

void createList(){
	int size,i;
	node *traverse, *newNode;
	traverse=head;
	printf("Enter the number of nodes: ");
	scanf("%d",&size);
	printf("\nEnter Node 1 Data: ");
	scanf("%d",&head->data);
	head->link=NULL;
	for(i=2;i<=size;i++){
		newNode=(node*)malloc(sizeof(node));
		printf("Enter Node %d data: ",i);
		scanf("%d",&newNode->data);
		newNode->link=NULL;
		traverse->link=newNode;
		traverse=traverse->link;
	}
	printf("\nList Created\n");
}

void display(){
	int i=0;
	node *traverse;
	printf("\nDisplaying\n\n");
	for(traverse=head; traverse!=NULL; traverse=traverse->link){
		printf("Node %d = %d\n",++i,traverse->data);
	}
}
