#include<stdio.h>
#include<string.h>
void main(){
	int i,l;
	char str[30];
	printf("Enter any string to check: ");
	fgets(str, sizeof(str), stdin);
	l=strlen(str)-2;
	str[strlen(str)-1]=0; //Removing the new line
	for(i=0; str[i]!=0; i++){ // changing all characters to small case if not
		if(str[i]>=65 && str[i]<=90){
			str[i] += 32;
		}
		else if(str[i]<65 || str[i]>90 && str[i]<97 || str[i]>123){
			printf("Please enter strings only\n");
			return;
		}
	}
	i=0;
	while(i<l)
	{
		if(str[i]==str[l]){
			i++;
			l--;
		}
		else{
			printf("Not Palindrome\n");
			return;
		}
	}
	printf("Palindrome\n");
}

