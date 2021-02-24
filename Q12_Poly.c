#include <stdio.h>
#include <stdlib.h>

struct polynomial{
	int num;
	int exp;
	struct polynomial *link;
}*p;

int main(){
	int term,i;
	struct polynomial *tmp, *newTerm;
	p=(struct polynomial*)malloc(sizeof(struct polynomial));
	printf("Enter the number of terms of the polynomial: ");
	scanf("%d",&term);
	tmp=p;
	printf("\nTerm 1\n");
	printf("\nEnter Coefficient: ");
	scanf("%d",&p->num);
	printf("Enter Exponent: ");
	scanf("%d",&p->exp);
	p->link=NULL;
	for(i=2;i<=term;i++){
		newTerm=(struct polynomial*)malloc(sizeof(struct polynomial));
		printf("\nTerm %d\n",i);
		printf("\nEnter Coefficient: ");
		scanf("%d",&newTerm->num);
		printf("Enter Exponent: ");
		scanf("%d",&newTerm->exp);
		newTerm->link=NULL;
		tmp->link=newTerm;
		tmp=tmp->link;
	}

	printf("\n\nDisplaying\n");
	tmp=p;
	while(tmp!=NULL){
		printf("%dx^%d",tmp->num,tmp->exp);
		if(tmp->link!=NULL){
			printf(" + ");
		}
		tmp=tmp->link;
	}
	printf("\n");

}