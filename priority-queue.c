#include <stdio.h>
#include <limits.h>

#define MAX 100

typedef struct {
    int data[MAX];
    int priority[MAX];
    int size;
} PriorityQueue;

// Function to insert an element into the priority queue
void insert(PriorityQueue *pq, int value, int prio) {
    if (pq->size == MAX) {
        printf("Priority Queue is full!\n");
        return;
    }
    int i;
    for (i = pq->size - 1; i >= 0; i--) {
        if (pq->priority[i] > prio) {
            pq->data[i + 1] = pq->data[i];
            pq->priority[i + 1] = pq->priority[i];
        } else {
            break;
        }
    }
    pq->data[i + 1] = value;
    pq->priority[i + 1] = prio;
    pq->size++;
}

// Function to delete an element from the priority queue
int delete(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return INT_MIN;
    }
    int value = pq->data[0];
    for (int i = 0; i < pq->size - 1; i++) {
        pq->data[i] = pq->data[i + 1];
        pq->priority[i] = pq->priority[i + 1];
    }
    pq->size--;
    return value;
}

// Function to display the elements in the priority queue
void display(PriorityQueue *pq) {
    if (pq->size == 0) {
        printf("Priority Queue is empty!\n");
        return;
    }
    printf("Priority Queue:\n");
    for (int i = 0; i < pq->size; i++) {
        printf("Value: %d, Priority: %d\n", pq->data[i], pq->priority[i]);
    }
}

int main() {
    PriorityQueue pq;
    pq.size = 0;

    int choice, value, prio;

    while (1) {
        printf("\nPriority Queue Operations:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                printf("Enter its priority: ");
                scanf("%d", &prio);
                insert(&pq, value, prio);
                break;
            case 2:
                value = delete(&pq);
                if (value != INT_MIN) {
                    printf("Deleted element: %d\n", value);
                }
                break;
            case 3:
                display(&pq);
                break;
            case 4:
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
