#include <stdio.h>
#include <stdlib.h>

// Define a structure for the queue node
struct Node {
    int data;
    struct Node* next;
};

// Global variables for tracking the current size of the queue and its maximum size
int currentSize = 0;
int maxSize = 0;

// Function to enqueue an element (add at the end of the queue)
void enqueue(struct Node** front, struct Node** rear, int value) {
    if (currentSize >= maxSize) {
        printf("Queue overflow: Maximum queue size reached\n");
        return;
    }

    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed\n");
        return;
    }
    newNode->data = value;
    newNode->next = NULL;

    // If queue is empty, both front and rear will point to the new node
    if (*rear == NULL) {
        *front = *rear = newNode;
    } else {
        // Add the new node at the end and update the rear
        (*rear)->next = newNode;
        *rear = newNode;
    }

    currentSize++;  // Increment the size count
    printf("%d enqueued to queue\n", value);
}

// Function to dequeue an element (remove from the front of the queue)
int dequeue(struct Node** front, struct Node** rear) {
    if (*front == NULL) {
        printf("Queue underflow: Queue is empty\n");
        return -1;
    }

    struct Node* temp = *front;
    int dequeuedValue = temp->data;

    // Move the front to the next node
    *front = (*front)->next;

    // If the front becomes NULL, then set rear to NULL as well (queue is empty)
    if (*front == NULL) {
        *rear = NULL;
    }

    free(temp);  // Free the dequeued node
    currentSize--;  // Decrement the size count
    return dequeuedValue;
}

// Function to display the queue
void display(struct Node* front) {
    if (front == NULL) {
        printf("Queue is empty\n");
        return;
    }

    struct Node* temp = front;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function to demonstrate queue operations
int main() {
    struct Node* front = NULL;
    struct Node* rear = NULL;
    int choice, value;

    // Ask the user for the maximum size of the queue
    printf("Enter the maximum size of the queue: ");
    scanf("%d", &maxSize);

    // Menu-driven queue operations
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Display Queue\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                if (currentSize < maxSize) {
                    printf("Enter value to enqueue: ");
                    scanf("%d", &value);
                    enqueue(&front, &rear, value);
                } else {
                    printf("Queue overflow: Maximum queue size reached\n");
                }
                break;

            case 2:
                value = dequeue(&front, &rear);
                if (value != -1) {
                    printf("Dequeued element is %d\n", value);
                }
                break;

            case 3:
                display(front);
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
