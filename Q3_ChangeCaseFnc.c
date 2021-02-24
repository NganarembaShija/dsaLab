#include<stdio.h>

void CaseChange(char[]);

void main(){
	char str[60];
	printf("Enter any string: ");
	fgets(str, sizeof(str), stdin);
	CaseChange(str);
}

void CaseChange(char str[]){
	int i;
	for(i=0; str[i]!='\n'; i++){
		if(str[i]>=65 && str[i]<=90)
		{
			str[i] += 32;
		}
		else if(str[i]>=97 && str[i]<=123){
			str[i] -=32;
		}
		else
		{
			printf("Please input string only\n");
			return;	
		}
	}
	puts(str);
}


