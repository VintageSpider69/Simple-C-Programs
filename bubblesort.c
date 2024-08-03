//Program to perform Bubble sort operation on an array (Here ascending order)
#include <stdio.h>
int main()
{
int i, j, n, tmp;
 printf ("Enter the number of elements in the array : \n");
 scanf("%d", &n);
 int array[n];
 printf("Enter %d numbers: \n", n);
 for (i = 0; i < n; i++)
  {
   scanf("%d", &array[i]);
  }
 for (i = 0; i < n; i++)
  {  
     for (j = 0; j < n - i - 1; j++)
     {
        if (array[j] > array[j + 1])    //For sorting in descending order change the > to < sign .
         {
            tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
         }
     }
  }
 printf("Printing the sorted array: \n", n);
 for (i = 0; i < n; i++)
  {
    printf("%d\n", array[i]);
  }
 return 0;
}
