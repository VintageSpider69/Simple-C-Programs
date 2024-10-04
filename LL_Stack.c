#include <stdio.h>
#include <stdlib.h>

// Define a structure for the stack node
struct Node {
    int data;
    struct Node* next;
};

// Global variable to track the current size of the stack
int currentSize = 0;
int maxSize = 0;  // Variable for user-defined maximum stack size

// Function to push an element onto the stack
void push(struct Node** top, int value) {
    if (currentSize >= maxSize) {
        printf("Stack overflow: Maximum stack size reached\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = *top;
    *top = newNode;
    currentSize++;  // Increment the size count
    printf("%d pushed to stack\n", value);
}

// Function to pop an element from the stack
int pop(struct Node** top) {
    if (*top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    struct Node* temp = *top;
    *top = (*top)->next;
    int popped = temp->data;
    free(temp);
    currentSize--;  // Decrement the size count
    return popped;
}

// Function to display the stack
void display(struct Node* top) {
    if (top == NULL) {
        printf("Stack is empty\n");
        return;
    }
    struct Node* temp = top;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate stack operations
int main() {
    struct Node* stack = NULL;
    int choice, value;

    // Ask the user for the maximum size of the stack
    printf("Enter the maximum size of the stack: ");
    scanf("%d", &maxSize);

    // Menu-driven stack operations
    do {
        printf("\n1. Push\n2. Pop\n3. Display Stack\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentSize < maxSize) {
                    printf("Enter value to push: ");
                    scanf("%d", &value);
                    push(&stack, value);
                } else {
                    printf("Stack overflow: Maximum stack size reached\n");
                }
                break;

            case 2:
                value = pop(&stack);
                if (value != -1) {
                    printf("Popped element is %d\n", value);
                }
                break;

            case 3:
                display(stack);
                break;

            case 4:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}
