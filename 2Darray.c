//program to create a two dimensional array i.e a matrix, with user inputting the order of matrix and the elements in matrix.
#include <stdio.h>
void main()
{
    int row,column,i,j;
    printf("Enter the number of rows in the matrix :\t");
    scanf("%d",&row);
    printf("Enter the number of columns of the matrix : \t");
    scanf("%d",&column);
    int matrix[row][column];                                                          //initialising the 2D array
    printf("Enter the elements of the matrix of order %dx%d :\n",row,column);
    for(i=0;i<row;i++)                                                                //recieving the elements of the matrix as input
    {
        for(j=0;j<column;j++)
        {
            scanf("%d",&matrix[i][j]);
        }
        
    }
    printf("Elements stored.\n");
    printf("Printing the matrix : \n");
     for(i=0;i<row;i++)                                                               //printing the elements of the matrix in the shape of the matrix
    {
        for(j=0;j<column;j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}
