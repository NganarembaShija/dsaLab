#include<stdio.h>

void callByVal(int, int);
void callByRef(int*, int*);

void main(){
	int num1, num2;
	printf("Enter any two number to swap: ");
	scanf("%d %d",&num1, &num2);
	printf("\nBefore Swapping\nFirst Number: %d\nSecond Number: %d\n",num1,num2);
	callByVal(num1,num2);
	callByRef(&num1,&num2);
	printf("\nAfter Swapping using Call By Reference\nFirst Number: %d\nSecond Number: %d\n",num1,num2);
	return;
}

void callByVal(int x, int y){
	int swap;
	swap=x;
	x=y;
	y=swap;
	printf("\nAfter swapping using Call by Value\nFirst Number: %d\nSecond Number: %d\n",x,y);
	return;
}

void callByRef(int* x, int* y){
	int swap;
	swap = *x;
	*x = *y;
	*y = swap;
}  

