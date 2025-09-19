#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* top = NULL;

void push(int val) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = val;
    newNode->next = top;
    top = newNode;
}

int pop() {
    if (top == NULL) {
        printf("Stack underflow\n");
        return -1;
    }
    Node* temp = top;
    int val = temp->data;
    top = top->next;
    free(temp);
    return val;
}

int isEmpty() {
    return top == NULL;
}

int evaluatePostfix(char* postfix) {
    for (int i = 0; postfix[i] != '\0'; i++) {
        char c = postfix[i];

        if (isdigit(c)) {
            push(c - '0');  // Convert char digit to int
        } else {
            int val2 = pop();
            int val1 = pop();
            int res;

            switch (c) {
                case '+': res = val1 + val2; break;
                case '-': res = val1 - val2; break;
                case '*': res = val1 * val2; break;
                case '/': res = val1 / val2; break;
                case '^': {
                    res = 1;
                    for (int j = 0; j < val2; j++) res *= val1;
                    break;
                }
                default:
                    printf("Invalid operator %c\n", c);
                    return -1;
            }
            push(res);
        }
    }
    return pop();
}

int main() {
    char postfix[100];
    printf("Enter a postfix expression (single digit operands): ");
    scanf("%s", postfix);
    int result = evaluatePostfix(postfix);
    printf("Evaluated Result: %d\n", result);
    return 0;
}
