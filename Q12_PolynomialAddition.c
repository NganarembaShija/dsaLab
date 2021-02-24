#include<stdio.h>
#include<stdlib.h>

struct polynomial{
	int coef;
	char variable;
	int exp;
	struct polynomial *link;
}*start, *start2, *res;

int j;

typedef struct polynomial poly;

void insert();
void addition();
void display();

void main(){
	printf("\nADDITION OF TWO POLYNOMIALS\n\n");
			insert();
			printf("\nEntered Polynomials are: \n");
			display();
			printf("\n");
			addition();
			printf("\n");
}


void insert(){
	int i,term,choice;
	poly *traverse, *newTerm;
	start=(poly*)malloc(sizeof(poly));
	start2=(poly*)malloc(sizeof(poly));
	traverse=start;
	printf("\nFOR FIRST POLYNOMIAL\n\nEnter the number of term: ");
	scanf("%d",&term);
	for(i=0;i<term;i++){
		if(i==0){
			printf("\nTerm %d \nCoefficient= ",i+1);
			scanf("%d",&start->coef);
			printf("Variable= ");
			scanf(" %c",&start->variable);
			printf("Exponent: ");
			scanf("%d",&start->exp);
			start->link=NULL;
		}
		else{
			newTerm=(poly*)malloc(sizeof(poly));
			printf("\n\nTerm %d\nCoefficient= ",i+1);
			scanf("%d",&newTerm->coef);
			printf("Variable= ");
			scanf(" %c",&newTerm->variable);
			printf("Exponent: ");
			scanf("%d",&newTerm->exp);
			newTerm->link=NULL;
			traverse->link=newTerm;
			traverse=traverse->link;
		}
	}
	printf("\n\nFOR SECOND POLYNOMIAL\n");
	traverse=start2;
	printf("\nEnter the number of term: ");
	scanf("%d",&term);
	for(i=0;i<term;i++){
		if(i==0){
			printf("\nTerm %d\nCoefficient= ",i+1);
			scanf("%d",&start2->coef);
			printf("Variable= ");
			scanf(" %c",&start2->variable);
			printf("Exponent: ");
			scanf("%d",&start2->exp);
			start2->link=NULL;
		}
		else{
			newTerm=(poly*)malloc(sizeof(poly));
			printf("\n\nTerm %d\nCoefficient= ",i+1);
			scanf("%d",&newTerm->coef);
			printf("Variable= ");
			scanf(" %c",&newTerm->variable);
			printf("Exponent: ");
			scanf("%d",&newTerm->exp);
			newTerm->link=NULL;
			traverse->link=newTerm;
			traverse=traverse->link;
		}
	}

}

void display(){
	poly *traverse=start;
	int c=1;
	while(traverse!=NULL){
		printf("%d%c^%d ",traverse->coef, traverse->variable, traverse->exp);
		traverse=traverse->link;
		if(traverse!=NULL){
			if(traverse->coef>0)
			printf(" + ");
		}
		else{
			++c;
			if(c==2){
				traverse=start2;
				printf("\n");
			}
			else
				return;
		}
	}

}

void addition(){
	poly *traverse, *traverse2,*t,*new, *sup;
	res=(poly*)malloc(sizeof(poly));
	t=res;
	int i=0,count;

		for(traverse=start; traverse!=NULL; traverse=traverse->link){
			count=0;
				for(traverse2=start2; traverse2!=NULL; traverse2=traverse2->link){
					sup=traverse2->link;
					if(traverse->variable == traverse2->variable && traverse->exp == traverse2->exp){
						if(i==0){
							res->coef=traverse->coef+traverse2->coef;
							res->variable=traverse->variable;
							res->exp=traverse->exp;
							res->link=NULL;
						}
						else{
							new=(poly*)malloc(sizeof(poly));
							new->coef=traverse->coef+traverse2->coef;
							new->variable=traverse->variable;
							new->exp=traverse->exp;
							new->link=NULL;
							t->link=new;
							t=t->link;
						}
						i++;
						count++;

					}
					else if(count==0 && sup==NULL){
						if(i==0){
							res->coef=traverse->coef;
							res->variable=traverse->variable;
							res->exp=traverse->exp;
							res->link=NULL;
						}
						else{
							new=(poly*)malloc(sizeof(poly));
							new->coef=traverse->coef;
							new->variable=traverse->variable;
							new->exp=traverse->exp;
							new->link=NULL;
							t->link=new;
							t=t->link;
						}
						i++;
					}
				}
		}
		for(traverse2=start2; traverse2!=NULL; traverse2=traverse2->link){
			count=0;
			for(traverse=start; traverse!=NULL; traverse=traverse->link){
				sup=traverse->link;
				if(traverse2->variable == traverse->variable && traverse2->exp == traverse->exp){
					count++;
				}
				else if(count==0 && sup==NULL){
					new=(poly*)malloc(sizeof(poly));
					new->coef=traverse2->coef;
					new->variable=traverse2->variable;
					new->exp=traverse2->exp;
					new->link=NULL;
					t->link=new;
					t=t->link;
				}
			}
		}
	printf("\nThe sum is \n");
	t=res;
	display();
	printf("\n-----------------------------\n");
	while(t!=NULL){
		printf("%d%c^%d ",t->coef, t->variable, t->exp);
		t=t->link;
		if(t!=NULL){
			if(t->coef>0)
			printf(" + ");
		}
	}

}
