#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct task {
    int id;
    char name[50];
};
struct task qt[100];
int front = -1, rear = -1;

int isEmpty() {
    return (front == -1);
}

int isFull() {
    return (rear == 99);
}

void enqueue(int i, char* doc) {
    if (isFull()) {
        printf("Queue full!\n");
        return;
    }
    if (front == -1)
        front = 0;
    rear++;
    qt[rear].id = i;
    strcpy(qt[rear].name, doc);
}

void dequeue() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("dequeued: %d, %s\n", qt[front].id, qt[front].name);
    if (front == rear) {
        front = rear = -1;
    } else {
        front++;
    }
}

void peek() {
    if (isEmpty()) {
        printf("Queue empty\n");
        return;
    }
    printf("peek: %d, %s\n", qt[front].id, qt[front].name);
}

int main() {
    int id, opt;
    char name[50];
    do {
        printf("\n1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\nChoose option: ");
        scanf("%d", &opt);
        switch (opt) {
            case 1:
                printf("Enter doc id and name: ");
                scanf("%d %s", &id, name);
                enqueue(id, name);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                peek();
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid option\n");
        }
    } while (opt != 4);

    return 0;
}

