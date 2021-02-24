#include <stdio.h>
#define size 5
int top=-1, arr[size];

void push();
void pop();
void display();

void main(){
	int choice;
	do{
		printf("\nMenu\n1. PUSH\n2. POP\n3. DISPLAY\n\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: push();
					break;

			case 2: pop();
					break;

			case 3: display();
					break;

			case 4: break;

			default: printf("Wrong choice!\n");
		}
	}
	while(choice!=4);
}

void push(){
	int data;
	if(top==size-1){
		printf("\nStack Overflow\n");
		return;
	}
	printf("Enter any data to push: ");
	scanf("%d",&data);
	top++;
	arr[top]=data;
}

void pop(){
	int data;
	if(top==-1){
		printf("\nStack Underflow\n");
		return;
	}
	data=arr[top];
	top--;
	printf("%d POP Successfully\n",data);

}

void display(){
	int i;
	if(top==-1){
		printf("\nStack Empty\n");
		return;
	}
	printf("\nDisplaying\n");
	for(i=top; i>-1; i--){
		printf("%d\n",arr[i]);
	}
}