#include<stdio.h>
void display(int[3][3]);
void main(){
	int i,j,mat[3][3],swap;
	printf("Enter the elements of the 3x3 matrix: \n");
	for(i=0;i<3;i++){
		for(j=0;j<3;j++)
			scanf("%d",&mat[i][j]);
	}
	printf("Entered Matrix:\n");
	display(mat);
	for(i=0;i<3;i++){
		for(j=i;j<3;j++){
			swap=mat[i][j];
			mat[i][j]=mat[j][i];
			mat[j][i]=swap;
		}
		
	}
	printf("The transpose is:\n");
	display(mat);
}

void display(int mat[3][3]){
	int i,j;
	for(i=0;i<3;i++){
                for(j=0;j<3;j++)
                        printf("%d\t",mat[i][j]);
                printf("\n");
        }
}
