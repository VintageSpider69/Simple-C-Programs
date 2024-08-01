//Program to find the average of n numbers using arrays
#include <stdio.h>
void main()
{
    int n,i,sum=0,avg;
    printf("Enter the number of elements in the array :\t");
    scanf("%d",&n);
    int array[n];
    printf("Enter the elements of the array :\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&array[i]);
    }
    for(i=0;i<n;i++)
    {
        sum+=array[i];
    }
    avg=sum/n;
    printf("The average of the elements in the array is : %d ",avg);
}

