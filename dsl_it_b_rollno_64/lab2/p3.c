#include<stdio.h>
#include<stdlib.h>



void display_mat(int **mat, int row, int col)
{
for(int i = 0; i<row; i++)
{
for(int j = 0; j<col; j++)
{
printf("%d ", *(*(mat+i)+j));

}
printf("\n");
}
}


int mult_matrices(int **A, int **B, int **C,int rowA, int colA, int rowB, int colB)
{
for(int i = 0; i<rowA; i++)
{
for(int j = 0; j<colB; j++)
{
*(*(C+i)+j)=0;
for (int k =0; k<colA; k++)
{
*(*(C+i)+j)+=*(*(A+i)+k)*(*(*(B+k)+j));
}
}
}
}
int main()
{
int n, **A, **B, **C, rowA, colA, rowB, colB;
printf("Enter the number of rows in A: ");
scanf("%d", &rowA);
printf("Enter the number of columns in A: ");
scanf("%d", &colA);
printf("Enter the number of rows in B: ");
scanf("%d", &rowB);
printf("Enter the number of columns in B: ");
scanf("%d", &colB);
A = (int **)malloc(rowA*sizeof(int *));
B = (int **)malloc(rowB*sizeof(int *));
C = (int **)malloc(rowA*sizeof(int *));
for(int i = 0; i<rowA; i++)
{
*(A+i)=(int *)malloc(colA*sizeof(int ));
*(C+i)=(int *)malloc(colB*sizeof(int ));
}
for(int i = 0; i<rowB; i++)
{
*(B+i)=(int *)malloc(colB*sizeof(int ));
}
printf("Enter the matrix A: \n");
for(int i = 0; i<rowA; i++)
{
for(int j = 0; j<colA; j++)
{
printf("Enter the element: ");
scanf("%d", (*(A+i)+j));
}
}

printf("Enter the matrix B: \n");
for(int i = 0; i<rowB; i++)
{
for(int j = 0; j<colB; j++)
{
printf("Enter the element: ");
scanf("%d", (*(B+i)+j));
}
}
mult_matrices(A, B, C, rowA,colA, rowB, colB);

printf("\nA matrix is: \n");
display_mat(A, rowA, colA);

printf("\nB matrix is: \n");
display_mat(B, rowB, colB);

printf("\nC matrix is: \n");
display_mat(A, rowA, colB);

free(A);
free(B);
free(C);
return 0;
}
