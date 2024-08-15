// Program to implement queue using arrays 
#include<stdio.h>
#include<stdlib.h>
int n,a[20];
int rear=-1;
int front=-1;
void enqueue()
{
    int e;
    if(rear==n-1)
    {
        printf("Queue is full - Overflow \n\n");
    }
    else
    {
        printf("enter the element : \n");
        scanf("%d",&e);
        rear++;
        if(front==-1)
        {
            front=0;
        }
        a[rear]=e;
        printf("%d Enqueued successfully",a[rear]);
        printf("\n");
    }
}

void dequeue()
{
    if(front==-1)
    printf("The queue is empty - Underflow.\n\n");
    else
    {
        printf("%d is dequeued from the queue \n",a[front]);
        front++;
        printf("\n");
        if(front>rear)
        {
            front=rear=-1;
        }
    }
}

void display()
{
    int i;
    if(rear==-1)
    printf("There are no elements to print - queue empty \n\n");
    else
    {
        printf("Elements in the queue are :\n");
        for(i=front;i<=rear;i++)
        printf("%d\t",a[i]);
        printf("\n");
    }
}
int main()
{
    int c;
    printf("Enter the maximum size of the queue : \n");
    scanf("%d",&n);
    printf("The options are : \n");
    printf("1- Enqueue an element.\n");
    printf("2- Dequeue an element.\n");
    printf("3- Display the elements.\n");
    printf("4- Exit.\n");
    while(1)
    {
        printf("Select your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1: enqueue();
             break;
            case 2: dequeue();
             break;
            case 3: display();
             break;
            case 4: exit(0);
             break;
            default: printf("You have entered a wrong choice \n\n");
        }
    }
    return 0;
}
