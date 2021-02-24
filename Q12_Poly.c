#include <stdio.h>
#include <stdlib.h>

struct polynomial{
	int num;
	int exp;
	struct node *link;
}*p;

int main(){
	int term,i;
	printf("Enter the number of terms of the polynomial: ");
	scanf("%d",&term);
	p=(struct polynomial*)malloc(term*sizeof(struct polynomial));
	for(i=0; i<term; i++){
		printf("\nTerm %d",i+1);
		printf("\n\nEnter Coefficient: ");
		scanf("%d",&(p+i)->num);
		printf("Enter the exponent: ");
		scanf("%d",&(p+i)->exp);
	}

	for(i=0; i<term; i++){
		printf("%dx^%d",(p+i)->num,(p+i)->exp);
		if(i!=term-1){
			printf(" + ");
		}
	}
	printf("\n");

}