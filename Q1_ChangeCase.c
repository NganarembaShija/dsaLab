#include<stdio.h>
int main(){
	char str[30];
	int i;
	printf("Enter any string: ");
	fgets(str, 30, stdin);
	for(i=0; str[i]!='\n'; i++){
		if(str[i]>=65 && str[i]<=90){
			str[i] += 32;
		}
		else if(str[i]>=97 && str[i]<=123){
			str[i] -= 32;
		}
		else
		{
			printf("Please input strings only\n");
		}
	}
	printf("%s",str);
	
}

