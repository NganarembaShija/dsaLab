#include <stdio.h>
#include <stdlib.h>

struct polynomial{
	int num;
	int exp;
	struct polynomial *link;
}*p;
typedef struct polynomial poly;

void store(int);
void display(int);

int main(){
	int term=0,choice;
	poly *tmp;
	p=(poly*)malloc(sizeof(poly));
	tmp=p;
	do{
		printf("\nMenu\n1. Enter Polynomial\n2. Display\n3. Exit\nEnter choice: ");
		scanf("%d",&choice);
		switch(choice){
			case 1: 
						printf("Enter the number of terms of the polynomial: ");
						scanf("%d",&term);
						store(term);
						break;

			case 2: 
						display(term);
						break;

			case 3: 	printf("Exiting...\n");
						continue;

			default: 	printf("Wrong Input\n");
		}
	}
	while(choice!=3);


}

void store(int term){
	int i;
	poly *newTerm,*tmp;
	tmp=p;
	printf("\nTerm 1\n");
	printf("\nEnter Coefficient: ");
	scanf("%d",&p->num);
	printf("Enter Exponent: ");
	scanf("%d",&p->exp);
	p->link=NULL;
	for(i=2;i<=term;i++){
		newTerm=(poly*)malloc(sizeof(poly));
		printf("\nTerm %d\n",i);
		printf("\nEnter Coefficient: ");
		scanf("%d",&newTerm->num);
		printf("Enter Exponent: ");
		scanf("%d",&newTerm->exp);
		newTerm->link=NULL;
		tmp->link=newTerm;
		tmp=tmp->link;
	}
	printf("\nPolynomial Entered\n");
}

void display(int term){
	poly *tmp;
	if(term==0){
		printf("Please enter polynomial first\n");
		return;
	}
	printf("\n\nDisplaying\n");
	for(tmp=p; tmp!=NULL; tmp=tmp->link){
		printf("%dx^%d",tmp->num,tmp->exp);
		if(tmp->link!=NULL){
			printf(" + ");
		}
	}
	printf("\n");
}