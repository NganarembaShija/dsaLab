#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *link;
}*head;

typedef struct node node;


void createList();
void display();
void insert();
void delete();

void main(){
    int choice;
    do{
        printf("\nMenu\n1. Create List\n2. Delete\n3. Insert\n4. Display\n\nEnter choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1: createList();
            break;

        case 2: delete();
            break;

        case 3: insert();
            break;

        case 4: display();
            break;
        case 5: break;
        
        default: printf("Wrong choice\n");
            break;
        }
    }
    while(choice!=5);
}

void createList(){
    int size,i;
    head=(node*)malloc(sizeof(node));
    node *traverse, *newNode;
    printf("Enter the number of nodes: ");
    scanf("%d",&size);
    traverse=head;
    printf("Enter Node 1 data: ");
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
    printf("\n\nLinked List Created\n");
}

void display(){
    int i=0;
    node *traverse;
    if(head==NULL){
        printf("\n\nList empty\nPlease create list first to delete\n");
        return;
    }
    printf("\n\nDisplaying\n");
    for(traverse=head; traverse!=NULL; traverse=traverse->link){
        printf("Node %d data = %d\n",++i,traverse->data);
    }
}

void delete(){
    int choice, data, loc, count=0;
    node *t, *prev, *p;
    if(head==NULL){
        printf("\n\nList empty\nPlease create list first to delete\n");
        return;
    }
    printf("\n\n1. Deletion at the begining\n2. Delete at the end\n3. Deletion before a node\n4. Deletion after a node\n\nEnter choice: ");
    scanf("%d",&choice);
    switch (choice)
    {
        case 1: 
        {
            head=head->link;
        }
            break;

        case 2: 
        {
            for(t=head;t!=NULL;t=t->link){
                if(t->link==NULL){
                    prev->link=NULL;
                }
                prev=t;
            }
        }
            break;

        case 3: 
        {
            printf("Enter the data of the node: ");
            scanf("%d",&data);
            prev=head;
            for(t=head; t!=NULL; t=t->link){
                if(head->data==data){
                    printf("No previous node\n");
                    break;
                }
                else if(t->data==data){
                    if(head->link==t){
                        head=t;
                        break;
                    }
                    p->link=t;
                    break;
                }
                p=prev;
                prev=t;
            }
        }
        break;

        case 4: 
        {
            printf("Enter the data of the node: ");
            scanf("%d",&data);
            p=head->link;
            for(t=head; t!=NULL; t=t->link){
                if(t->link==NULL){
                    printf("No next node\n");
                    break;
                }
                else if(t->data==data){
                    t->link=p->link;
                    break;
                }
                p=p->link;
            }
        }
        
        default:
            break;
    }
    printf("\n\nDeleted\n");
}

void insert(){
    int data, choice, nodeData,count=0;
    node *t, *newNode, *prev, *p;
    if(head==NULL){
        printf("\n\nList empty\nPlease create list first to delete\n");
        return;
    }
    printf("\n\n1. Insertion at the begining\n2. Insertion at the end\n3. Insertion before a node\n4. Insertion after a node\n\nEnter choice: ");
    scanf("%d",&choice);
    printf("Enter the data to insert: ");
    scanf("%d",&data);
    newNode=(node*)malloc(sizeof(node));
    switch (choice)
    {
    case 1: 
    {
        newNode->data=data;
        newNode->link=head;
        head=newNode;
    }
        break;

    case 2: 
    {
        for(t=head; t!=NULL; t=t->link){
            if(t->link==NULL){
                newNode->data=data;
                newNode->link=NULL;
                t->link=newNode;
                break;
            }
        }
    }
        break;

    case 3: 
    {
        printf("Enter the node data to insert before: ");
        scanf("%d",&nodeData);
        for(t=head, prev=head; t!=NULL; t=t->link){
            if(head->data==nodeData){
                newNode->data=data;
                newNode->link=head;
                head=newNode;
                count++;
                break;
            }
            else if(t->data==nodeData){
                    newNode->data=data;
                    newNode->link=t;
                    prev->link=newNode;
                    count++;
                }

            prev=t;
        }
        if(count==0)
            printf("\n\nEntered data not found\n");
    }
        break;
    
    case 4: 
    {
        printf("Enter the data to insert after: ");
        scanf("%d",&nodeData);
        for(t=head; t!=NULL; t=t->link){
            if(t->data==nodeData && t->link==NULL){
                newNode->data=data;
                newNode->link=NULL;
                t->link=newNode;
                count++;
                break;
            }
            else if(t->data==nodeData){
                    newNode->data=data;
                    newNode->link=t->link;
                    t->link=newNode;
                    count++;
            }
        }
        if(count==0)
            printf("Node data to search not found\n");
        break;
    }
    
    default:
        break;
    }
    printf("\n\nDone\n");
}