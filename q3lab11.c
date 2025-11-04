#include <stdio.h>
#include <stdlib.h>

// Structure for adjacency list node
typedef struct graphNode {
    int vertex;
    struct graphNode* next;
} graphNode;

int numVertex;
int isDirected;

// Function to create a new node
graphNode* createGraphNode(int vertex) {
    graphNode* newNode = (graphNode*)malloc(sizeof(graphNode));
    newNode->vertex = vertex;
    newNode->next = NULL;
    return newNode;
}

// Function to read the graph
void readGraph(graphNode* head[]) {
    int vertex, neighbour, k;
    for (int i = 0; i < numVertex; i++) {
        graphNode* tail = NULL;
        printf("Enter vertex: ");
        scanf("%d", &vertex);

        // Create head if empty
        if (head[vertex] == NULL)
            head[vertex] = tail = createGraphNode(vertex);
        tail = head[vertex];

        // Go to end of current list
        while (tail->next != NULL)
            tail = tail->next;

        printf("Enter the number of neighbours for vertex %d: ", vertex);
        scanf("%d", &k);

        for (int j = 0; j < k; j++) {
            printf("Enter neighbour vertex: ");
            scanf("%d", &neighbour);

            // Add neighbour
            graphNode* newNode = createGraphNode(neighbour);
            tail->next = newNode;
            tail = newNode;

            // If undirected, add reverse edge
            if (!isDirected) {
                graphNode* revNode = createGraphNode(vertex);
                if (head[neighbour] == NULL) {
                    head[neighbour] = createGraphNode(neighbour);
                    head[neighbour]->next = revNode;
                } else {
                    revNode->next = head[neighbour]->next;
                    head[neighbour]->next = revNode;
                }
            }
        }
    }
}

// Function to print adjacency list
void printGraph(graphNode* head[]) {
    printf("\nAdjacency List:\n");
    for (int i = 0; i < numVertex; i++) {
        graphNode* temp = head[i];
        while (temp != NULL) {
            if (temp == head[i])
                printf("Vertex %d -> ", temp->vertex);
            else
                printf("%d ", temp->vertex);
            temp = temp->next;
        }
        printf("\n");
    }
}

// ------------------------ BFS --------------------------
typedef struct Node {
    graphNode* data;
    struct Node* next;
} Node;

Node* front = NULL;
Node* rear = NULL;

int isEmpty() {
    return front == NULL;
}

void enqueue(graphNode* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    if (isEmpty())
        front = rear = newNode;
    else {
        rear->next = newNode;
        rear = newNode;
    }
}

graphNode* dequeue() {
    if (isEmpty())
        return NULL;
    Node* temp = front;
    graphNode* data = front->data;
    front = front->next;
    free(temp);
    return data;
}

// BFS Traversal
void BFS(graphNode* head[], int start) {
    int visited[100] = {0};
    enqueue(head[start]);
    visited[start] = 1;
    printf("BFS Traversal: ");
    while (!isEmpty()) {
        graphNode* node = dequeue();
        printf("%d ", node->vertex);
        graphNode* temp = node->next;
        while (temp != NULL) {
            if (visited[temp->vertex] == 0) {
                visited[temp->vertex] = 1;
                enqueue(head[temp->vertex]);
            }
            temp = temp->next;
        }
    }
    printf("\n");
}

// ------------------------ DFS --------------------------
int visited[100] = {0};

void DFS(graphNode* head[], int start) {
    visited[start] = 1;
    printf("%d ", head[start]->vertex);
    graphNode* temp = head[start]->next;
    while (temp != NULL) {
        if (!visited[temp->vertex])
            DFS(head, temp->vertex);
        temp = temp->next;
    }
}

// ------------------------ MAIN --------------------------
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertex);

    printf("Enter 1 if graph is directed and 0 if undirected: ");
    scanf("%d", &isDirected);

    graphNode* head[numVertex];
    for (int i = 0; i < numVertex; i++)
        head[i] = NULL;

    readGraph(head);
    printGraph(head);

    printf("\n");
    BFS(head, 0);

    for (int i = 0; i < 100; i++)
        visited[i] = 0; // reset visited array

    printf("DFS Traversal: ");
    DFS(head, 0);
    printf("\n");

    return 0;
}
