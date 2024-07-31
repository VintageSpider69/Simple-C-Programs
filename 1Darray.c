//Program to create a 1 dimensional array, recieve input for user and to display it. 
#include <stdio.h>
void main()
{
    int n,i;                                                                      //initialising the variables.
    printf("Enter the number of elements in the array :\t");
    scanf("%d",&n);                                                               //recieving the number of elements in the array and storing it to variable - n
    int array[n];                                                                 //initialising the array with size-n
    printf("Enter the elements of the array :");
    for(i=0;i<n;i++)                                                              //entering elemnts to the array(user input)
    {
        printf("%d.\t",i+1);
        scanf("%d",&array[i]);
    }
    printf("The array is : ");                                                    //printing the array
    for(i=0;i<n;i++)
    {
        printf("%d\t",array[i]);
    }
}
