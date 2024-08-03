//Program to perform linear search on an array of numbers
#include <stdio.h>
int main()
{
int i, n, key;
 printf ("Enter the value of N: \n");
 scanf("%d", &n);
 int array[n];
 printf("Enter %d numbers: \n", n);
 for (i = 0; i < n; i++)
 {
   scanf("%d", &array[i]);
 }
 printf("Enter element to search: \n");
 scanf("%d", &key);
 for(i = 0; i < n; i++)
 {
  if(array[i] == key)
   {
     break;
   }
 }
 if(i < n)
 {
   printf("Element found at position %d\n", i + 1);
 }
 else
 {
   printf("Element not found\n");
 }
 return 0;
}
