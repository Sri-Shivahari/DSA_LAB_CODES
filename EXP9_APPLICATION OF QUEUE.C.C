#include <stdio.h>
#include <stdlib.h>

// Structure to represent a process
struct Process {
    int processID;
    int burstTime;
    int priority;
};

// Structure for a node in the priority queue
struct Node {
    struct Process data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(struct Process process) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = process;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a process into the priority queue
void enqueue(struct Node** front, struct Node** rear, struct Process process) {
    struct Node* newNode = createNode(process);
    if (*front == NULL) {
        *front = *rear = newNode;
    } else {
        if (process.priority < (*front)->data.priority) {
            newNode->next = *front;
            *front = newNode;
        } else {
            struct Node* temp = *front;
            while (temp->next != NULL && temp->next->data.priority <= process.priority) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
            if (newNode->next == NULL) {
                *rear = newNode;
            }
        }
    }
}

// Function to dequeue a process from the priority queue
struct Process dequeue(struct Node** front) {
    if (*front == NULL) {
        struct Process emptyProcess;
        emptyProcess.processID = -1;
        return emptyProcess;
    } else {
        struct Node* temp = *front;
        struct Process process = temp->data;
        *front = (*front)->next;
        free(temp);
        return process;
    }
}

int main() {
    int n;
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    struct Node* front = NULL;
    struct Node* rear = NULL;

    for (int i = 0; i < n; i++) {
        struct Process process;
        printf("Enter Process ID, Burst Time, and Priority for Process %d: ", i + 1);
        scanf("%d %d %d", &process.processID, &process.burstTime, &process.priority);
        enqueue(&front, &rear, process);
    }

    printf("\nProcess execution order:\n");
    while (front != NULL) {
        struct Process process = dequeue(&front);
        printf("Process %d\n", process.processID);
    }

    return 0;
}
