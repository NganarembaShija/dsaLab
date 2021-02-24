#include <stdio.h>
void main(){
	int mat[100][100], size,  i, j;
	printf("Enter the order of the square matrix: ");
	scanf("%d",&size);
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			if(i<j){
				mat[i][j]=1;
			}
			else if(i==j){\
				mat[i][j]=0;
			}
			else{
				mat[i][j]=-1;
			}
		}
	}
	for(i=0;i<size;i++){
		for(j=0;j<size;j++){
			printf("%d\t",mat[i][j]);
		}
		printf("\n");
	}
	
}
