#include <stdio.h>
#include <string.h>
 void squeeze(char[], char);

 void main(){
 	char s[30], c;
	printf("Enter any string: ");
	fgets(s, sizeof(s), stdin);
	printf("Enter any character to remove: ");
	scanf("%c",&c);
	squeeze(s,c);

 }

 void squeeze(char s[], char c){
 	int i, j, l=strlen(s);
	for(i=0; s[i]!='\n'; i++){
		if(s[i]==c || s[i]==c+32 || s[i]==c-32){
			for(j=i; s[j]!='\n'; j++){
				s[j]=s[j+1];
			}
			i--;
			s[l-1]=0;
			l=strlen(s);
		}
			
	}
	printf("New String is : %s",s);
 }
