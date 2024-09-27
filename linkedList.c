#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at the beginning of the list
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Function to insert at the end of the list
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to insert at any position (1-based index)
void insertAtPosition(struct Node** head, int data, int position) {
    struct Node* newNode = createNode(data);

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        return;
    }

    struct Node* temp = *head;
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of bounds\n");
        free(newNode);
        return;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

// Function to delete from the beginning of the list
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Node deleted from the beginning.\n");
}

// Function to delete from the end of the list
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct Node* temp = *head;

    // If there's only one node
    if (temp->next == NULL) {
        free(temp);
        *head = NULL;
        printf("Node deleted from the end.\n");
        return;
    }

    // Traverse to the second last node
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    struct Node* lastNode = temp->next;
    temp->next = NULL;
    free(lastNode);
    printf("Node deleted from the end.\n");
}

// Function to delete from a specific position (1-based index)
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    struct Node* temp = *head;

    // If the head node is to be deleted
    if (position == 1) {
        *head = temp->next;
        free(temp);
        printf("Node deleted from position 1.\n");
        return;
    }

    // Traverse to the node just before the one to be deleted
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }

    // If the position is out of bounds
    if (temp == NULL || temp->next == NULL) {
        printf("Position out of bounds\n");
        return;
    }

    struct Node* nodeToDelete = temp->next;
    temp->next = nodeToDelete->next;
    free(nodeToDelete);
    printf("Node deleted from position %d.\n", position);
}

// Function to display the list
void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int choice, data, position;

    while (1) {
        printf("\nMenu:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert at a specific position\n");
        printf("4. Delete from the beginning\n");
        printf("5. Delete from the end\n");
        printf("6. Delete from a specific position\n");
        printf("7. Display the list\n");
        printf("8. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the data to insert at the beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
            case 2:
                printf("Enter the data to insert at the end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
            case 4:
                deleteFromBeginning(&head);
                break;
            case 5:
                deleteFromEnd(&head);
                break;
            case 6:
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
            case 7:
                displayList(head);
                break;
            case 8:
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
