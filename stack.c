//program to implement stack using array.
#include<stdio.h>
#include<stdlib.h>
int n,a[20];
int top=-1;
void push()
{
    int e;
    if(top==n-1)
    {
        printf("Stack is full- Stack Overflow.\n\n");
    }
    else 
    {
        printf("\n");
        printf("Enter the element\n");
        scanf("%d",&e);
        top++;
        a[top]=e;
        printf("\n");
    }
    
}
void pop()
{
    if(top==-1)
     printf("The stack is empty - Stack  Underflow\n");
    else
    {
        printf("%d is popped from the stack \n",a[top]);
        top--;
        printf("\n");
    }
}
void display()
{
    int i;
    if(top==-1)
     printf("There are no elements to print .");
    else 
    {
        printf("Elements in the stack are : ");
        for(i=0;i<=top;i++)
         printf("%d\t",a[i]);
        printf("\n");
    }
}
int main()
{
    int c;
    printf("Enter the maximum size of the stack : \n");
    scanf("%d",&n);
    printf("Choices are :\n");
    printf("1- Push an element to the stack.\n");
    printf("2- Pop an elements from the stack.\n"); 
    printf("3- Display the elements. \n");
    printf("4- Exit the program.\n");
    while(1)
    {
        printf("Select your choice :\n");
        scanf("%d",&c);
        switch(c)
        {
            case 1: push();
             break;
            case 2: pop();
             break;
            case 3: display();
             break;
            case 4: exit(0);
            default: printf("You have entered a wrong choice \n\n");
        }
    }
    return 0;
}
