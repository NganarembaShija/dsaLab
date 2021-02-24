#include<stdio.h>

void search();
void insert();
void delete();
void display();

int size,arr[100];

void main(){
	int choice;
	do{
		printf("\nMAIN MENU\n1. Insert\n2. Search\n3. Delete\n4. Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: insert();
					display();
					break;

			case 2: search();
					break;

			case 3: delete();
					display();
					break;

			case 4: continue;

			default: printf("Enter a valid choice\n");
		}

	}
	while(choice!=4);
}


void insert(){
	int i;
	printf("Enter the size of the array: ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		printf("\nEnter arr[%d] data: ",i);
		scanf("%d",&arr[i]);
	}
}

void search(){
	int item,c=0,i;
	printf("Enter the data to search: ");
	scanf("%d",&item);
	for(i=0;i<size;i++){
		if(arr[i]==item){
			if(c==0){
				printf("%d is found at location: ",item);
			}
			printf("arr[%d] ",i);
			c++;
		}
	}
}

void delete(){
	int choice,data, location,i,j;
	printf("\nDeletion\n1. Delete with data\n2. Delete with location\nEnter choice: ");
	scanf("%i",&choice);
	switch(choice){
		case 1: printf("Enter the data to delete: ");
				scanf("%d",&data);
				for(i=0;i<size;i++){
					if(data==arr[i]){
						for(j=i;j<size;j++){
							arr[j]=arr[j+1];
						}
						i--;
						size--;
					}
				}
				break;

		case 2: printf("Enter the location no. to delete: ");
				scanf("%d",&location);
				for(i=location-1;i<size;i++){
						arr[i]=arr[i+1];
				}
				size--;
				break;

		default: printf("Wrong Input\n");

	}
}


void display(){
	int i;
	printf("\n\nArray Elements are: \n");
	for(i=0;i<size;i++){
		printf("arr[%d] = %d\n",i,arr[i]);
	}
}