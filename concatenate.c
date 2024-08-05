//program to read two strings ending with $ sign and concatenate them at the $ sign
#include <stdio.h>
#include <string.h>
int main()
{
 char str1[100],str2[100];
 int i,j;
 printf("Enter the string1: ");
 gets(str1);
 printf("Enter the string2: ");
 gets(str2);
 for(i=0;str1[i]!='$';i++);
 for(j=0;str2[j]!='$';j++,i++)
 str1[i]=str2[j];
 str1[i]='\0';
 printf("Concatenated string is \n");
 printf("%s\t",str1);
}
