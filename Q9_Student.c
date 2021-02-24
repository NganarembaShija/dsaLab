#include<stdio.h>
void main(){
	int i,j, stu[5][3],highest;
	for(i=0;i<5;i++){
		printf("\n\nStudent %i\n\n",i+1);
		for(j=0;j<3;j++){
			printf("Subject %i Mark = ",j+1);
			scanf("%i",&stu[i][j]);
		}
	}
	for(i=0;i<3;i++){
		highest=stu[0][i];
		for(j=0;j<5;j++){
			if(highest<stu[j][i]){
				highest=stu[j][i];
			}
		}
		printf("\nSubject %d Highest Mark is %d",i+1,highest);
	}
	puts("\n");
}