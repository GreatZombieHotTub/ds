#include <stdio.h>
#define MAX 100
struct Queue {
int items[MAX];
int front, rear;
};
// Initialize the queue
void initialize(struct Queue* q) {
q->front = -1;
q->rear = -1;
}
// Check if queue is empty
int isEmpty(struct Queue* q) {
return q->front == -1;
}
// Check if queue is full
int isFull(struct Queue* q) {
return q->rear == MAX - 1;
}
// Enqueue operation
void enqueue(struct Queue* q, int value) {
if (isFull(q)) {
printf("Queue is full.\n");
return;
}
if (isEmpty(q)) q->front = 0;
q->items[++q->rear] = value;
printf("Enqueued: %d\n", value);
}
// Dequeue operation
int dequeue(struct Queue* q) {
if (isEmpty(q)) {
printf("Queue is empty.\n");
return -1;
}

int value = q->items[q->front];
if (q->front == q->rear)
q->front = q->rear = -1;
else
q->front++;
return value;
}
// Peek operation
int peek(struct Queue* q) {
if (isEmpty(q)) {
printf("Queue is empty.\n");
return -1;
}
return q->items[q->front];
}
// Main menu-driven function
int main() {
struct Queue q;
initialize(&q);
int choice, value;
while (1) {
printf("\n--- Queue Menu ---\n");
printf("1. Enqueue\n2. Dequeue\n3. Peek\n4. Exit\n");
printf("Enter your choice: ");
scanf("%d", &choice);
switch (choice) {
case 1:
printf("Enter value to enqueue: ");
scanf("%d", &value);
enqueue(&q, value);
break;
case 2:
value = dequeue(&q);
if (value != -1)
printf("Dequeued: %d\n", value);
break;
case 3:
value = peek(&q);
if (value != -1)
printf("Front of queue: %d\n", value);
break;
case 4:
return 0;
default:
printf("Invalid choice.\n"); } } }
