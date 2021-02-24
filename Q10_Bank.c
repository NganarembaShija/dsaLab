#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct bank{
	long long int accountNo;
	char name[50];
	long long int bal;
	int internetBanking;
	int pin;

}*b;
typedef struct bank bank;

void input(int);
void display(int, int);
void intBank(int);
void displayAll(int);

void main(){
	int total,class;
	printf("Enter the total number of Customers: ");
	scanf("%d",&total);
	b=(bank*)malloc(total*sizeof(bank));
	input(total);
	displayAll(total);
	intBank(total);
	while(1){
	printf("\n\nChoose any Customer type to display\n1. Golden\n2. Silver\n3. General\n4. Exit\n\nEnter choice: ");
	scanf("%d",&class);
	if(class==4)
	return;
	display(total,class);
	}
}

void input(int total){
	int i,l;
	for(i=0;i<total;i++){
		printf("\nCustomer %d\nAccount Number: ",i+1);
		scanf("%lld",&(b+i)->accountNo);
		getchar();
		printf("Account Holder Name: ");
		fgets((b+i)->name, sizeof((b+i)->name), stdin);
		l=strlen((b+i)->name)-1;
		(b+i)->name[l]=0;
		printf("Balance: ");
		scanf("%lld",&(b+i)->bal);
		printf("Avail Internet Banking\n1. Yes\n2. No\nEnter 1 or 2: ");
		scanf("%d",&(b+i)->internetBanking);
		printf("SET PIN: ");
		scanf("%d",&(b+i)->pin);

	}
}

void display(int total, int class){
	int i;
	switch(class){
		case 1:
			printf("\n\nGolden\n");
			for(i=0;i<total;i++){
                		if((b+i)->bal>=1000000){
                       			 printf("%s\n",(b+i)->name);
               			}
        		}
			break;
		
		case 2: 
			printf("\n\nSilver\n");
			for(i=0;i<total;i++){
               			 if((b+i)->bal>=500000 && (b+i)->bal<1000000){
                       			 printf("%s\n",(b+i)->name);
               			 }
       			 }
			 break;
		case 3:
			printf("\n\nGeneral\n");
			for(i=0;i<total;i++){
               			if((b+i)->bal<500000){
					printf("%s\n",(b+i)->name);
				}
       			 }
			 break;
		default: printf("Please input a valid choice\n");
	}
	printf("\n");
		
}

void intBank(int total){
	int i;
	printf("\n\nList of Customers availing Internet Banking are\n");
	for(i=0; i<total; i++){
		if((b+i)->internetBanking==1){
			printf("%s\n",(b+i)->name);
		}
	}
	
}

void displayAll(int total){
	int i;
	printf("\n\nCUSTOMERS DETAILS\n");
	for(i=0;i<total;i++){
		printf("\n\nCustomer No. %d\nAccount No.: %lld\n",i+1,(b+i)->accountNo);
		printf("Acount Holder Name: %s\n",(b+i)->name);
		printf("Balance: %lld\n",(b+i)->bal);
		printf("Internet Banking: ");
		if((b+i)->internetBanking==1)
			printf("Yes");
		else
			printf("No");
	}
}
