# include <stdio.h>
int main()
{
    int i, j, choice, size, key ;
    printf("Enter the size of the array :");
    scanf("%d",&size);
    int a[size];
    int arr[size];
    printf("Enter %d elements : \n",size);
    for(i=0 ; i<size ; i++)
    {
        scanf("%d",&a[i]);
    }
    for (i=0; i<size; i++)
    {
        arr[i]=a[i];
    }
    do
    {
        printf("\nMenu : \n");
        printf("1. Linear search \n");
        printf("2. Binary Search \n");
        printf("3. Exit\n");
        printf("Enter your choice : ");
        scanf("%d",&choice);
        
        switch (choice)
        {
            case 1: {
                printf("Enter the element to search : ");
                scanf("%d",&key);
                int found = 0;
                for(i=0; i < size; i++)
                {
                    if (a[i]==key)
                    {
                        printf("Element %d found at %d \n",key,i+1);
                        found=1;
                        break;
                    }
                }
                if (!found)
                {
                    printf("Element %d not found in the array \n",key);
                }
                break;
            }
            
            case 2: {
                for(i=0; i<size-1; i++)
                {
                    for(j=0; j<size-1; j++)
                    {
                        if (arr[j]>arr[j+1])
                        {
                            int temp = arr[j];
                            arr[j]=arr[j+1];
                            arr[j+1]=temp;
                        }
                    }
                }
                printf("Array sorted for binary search. \n");
                for(i=0; i<size; i++)
                {
                    printf("%d",arr[i]);
                    printf("\t");
                }
                printf("\n");
                printf("Enter the element to search : ");
                scanf("%d",&key);
                int left = 0, right = size -1;
                int found=0;
                while(left<=right)
                {
                    int mid = left + (right - left)/2;
                    if(arr[mid] == key)
                    {
                        printf("Element %d found at %d \n",key, mid+1);
                        found = 1;
                        break;
                    }
                    if (arr[mid]<key)
                    {
                        left=mid+1;
                    }
                    else
                    {
                        right=mid-1;
                    }
                }
                if (!found)
                {
                    printf("Element %d not found in the array \n",key);
                }
                break;
            }
            
            case 3: 
             printf("Exiting the program. \n");
             break;
             default:
              printf("Invalid choice. Please try again. \n");
        }
    }
    while (choice != 3);
    return 0;
}
