#include <stdio.h>
#include <stdlib.h>
#define MAX 100
#define N 5
#define INIT 1
#define VISITED 2
int adj[MAX][MAX];
int visited[MAX];
int n, SIZE;
int stack[MAX];
int top = -1;
int p[MAX];
int front = -1, rear = -1, arr[20];
void create_graph();
void dfs_traversal();
void dfs(int v);
void push(int v);
int pop();
int isEmpty_stack();
void bfs_traversal();
void enqueue(int elmt);
void dequeue();
int is_empty();
void get_unexplored(int vertex);
int not_in_queue(int elmt);
int main() {
    int choice;
    while (1) {
        printf(“\nMenu:\n”);
        printf(“1. Perform DFS\n”);
        printf(“2. Perform BFS\n”);
        printf(“3. Exit\n”);
        printf(“Enter your choice: “);
        scanf(“%d”, &choice);
        switch (choice) {
            case 1:
                dfs_traversal();
                break;
            case 2:
                bfs_traversal();
                break;
            case 3:
                exit(0);
            default:
                printf(“\nInvalid choice! Try again.\n”);
        }
    }
    return 0;
}
void create_graph() {
    int i, edge, o, p;
    printf(“\nEnter number of nodes: “);
    scanf(“%d”, &n);
    SIZE = n; // Set size for BFS
    for (i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            adj[i][j] = 0; // Initialize adjacency matrix
        }
    }
    printf(“\nEnter number of edges: “);
    scanf(“%d”, &edge);
    for (i = 1; i <= edge; i++) {
        printf(“\nEnter edge %d (format: source destination): “, i);
        scanf(“%d %d”, &o, &p);
        if (o >= n || p >= n || o < 0 || p < 0) {
            printf(“\nInvalid edge!\n”);
            i--;
        } else {
            adj[o][p] = 1;
            adj[p][o] = 1; // Assuming undirected graph
        }
    }
}
void dfs_traversal() {
    int v;
    for (int i = 0; i < n; i++)
        p[i] = INIT;
    printf(“\nEnter starting node for DFS: “);
    scanf(“%d”, &v);
    dfs(v);
    printf(“\n”);
}
void dfs(int v) {
    int i;
    push(v);
    while (!isEmpty_stack()) {
        v = pop();
        if (p[v] == INIT) {
            printf(“%d “, v);
            p[v] = VISITED;
        }
        for (i = n – 1; i >= 0; i--) {
            if (adj[v][i] == 1 && p[i] == INIT) {
                push(i);
            }
        }
    }
}
void push(int v) {
    if (top == (MAX – 1)) {
        printf(“\nStack Overflow\n”);
        return;
    }
    top = top + 1;
    stack[top] = v;
}
int pop() {
    if (top == -1) {
        printf(“\nStack Underflow\n”);
        exit(1);
    } else {
        return stack[top--];
    }
}
int isEmpty_stack() {
    return top == -1;
}
void bfs_traversal() {
    int S;
    front = rear = -1; // Reset queue
    for (int i = 0; i < SIZE; i++) {
        visited[i] = 0; // Reset visited array
        arr[i] = -1;    // Reset queue
    }
    printf(“\nEnter starting vertex for BFS: “);
    scanf(“%d”, &S);
    printf(“\nThe result of BFS traversal is:\n”);
    enqueue(S);
    while (!is_empty()) {
        int vertex = arr[front];
        printf(“%d “, vertex);
        dequeue();
        get_unexplored(vertex);
    }
    printf(“\n”);
}
void enqueue(int elmt) {
    if (rear == SIZE – 1) {
        printf(“\nQueue Overflow\n”);
        return;
    }
    if (front == -1)
        front = 0;
    arr[++rear] = elmt;
}

void dequeue() {
    if (front == -1) {
        printf(“\nQueue Underflow\n”);
        return;
    }
    if (front == rear)
        front = rear = -1;
    else
        front++;
}
int is_empty() {
    return front == -1;
}
void get_unexplored(int vertex) {
    for (int i = 0; i < SIZE; i++) {
        if (adj[vertex][i] == 1 && visited[i] == 0 && not_in_queue(i)) {
            enqueue(i);
            visited[i] = 1;
        }
    }
}
int not_in_queue(int elmt) {
    for (int i = front; i <= rear; i++) {
        if (arr[i] == elmt)
            return 0;
    }
    return 1;
}
