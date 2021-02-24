#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *link;
}*start;


void createList();
void display();

void main(){
	int i,choice;
	start=(struct node*)malloc(sizeof(struct node));
	while(1){
		printf("\n1. Create List\n2. Display\n3. Exit\nEnter choice: ");
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
}

void createList(){
	int size,i;
	struct node *tmp, *newNode;
	tmp=start;
	printf("Enter the number of nodes: ");
	scanf("%d",&size);
	printf("\nEnter Node 1 Data: ");
	scanf("%d",&start->data);
	start->link=NULL;
	for(i=2;i<=size;i++){
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Enter Node %d data: ",i);
		scanf("%d",&newNode->data);
		newNode->link=NULL;
		tmp->link=newNode;
		tmp=tmp->link;
	}
}

void display(){
	struct node *tmp;
	tmp=start;
	printf("\nDisplay\n\n");
	while(tmp!=NULL){
		printf("%d\n",tmp->data);
		tmp=tmp->link;
	}
}
