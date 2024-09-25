#include <stdio.h>

int main() {
    int choice, size, key;

    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size];

    printf("Enter %d elements:\n", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Linear Search\n");
        printf("2. Binary Search\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                // Linear Search
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int found = 0;
                for (int i = 0; i < size; i++) {
                    if (arr[i] == key) {
                        printf("Element %d found at index %d\n", key, i);
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("Element %d not found in the array\n", key);
                }
                break;
            }
            case 2: {
                // Sort the array using Bubble Sort
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (arr[j] > arr[j + 1]) {
                            // Swap
                            int temp = arr[j];
                            arr[j] = arr[j + 1];
                            arr[j + 1] = temp;
                        }
                    }
                }
                printf("Array sorted for binary search.\n");

                // Binary Search
                printf("Enter the element to search: ");
                scanf("%d", &key);
                int left = 0, right = size - 1;
                int found = 0;

                while (left <= right) {
                    int mid = left + (right - left) / 2;
                    if (arr[mid] == key) {
                        printf("Element %d found at index %d\n", key, mid);
                        found = 1;
                        break;
                    }
                    if (arr[mid] < key) {
                        left = mid + 1;
                    } else {
                        right = mid - 1;
                    }
                }
                if (!found) {
                    printf("Element %d not found in the array\n", key);
                }
                break;
            }
            case 3:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 3);

    return 0;
}
