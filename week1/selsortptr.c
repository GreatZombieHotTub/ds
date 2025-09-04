#include <stdio.h>
#include <stdlib.h>

// Recursive Selection Sort using pointers
void selsort(int *arr, int start, int n) {
    if (start >= n - 1) {
        return;  // base case
    }

    int i, j = start;
    int *p = arr;
    int small = *(p + start);

    // find the smallest element in the unsorted part
    for (i = start + 1; i < n; i++) {
        if (small > *(p + i)) {
            small = *(p + i);
            j = i;
        }
    }

    // swap if needed
    if (j != start) {
        *(p + j) = *(p + start);
        *(p + start) = small;
    }

    // recursive call
    selsort(p, start + 1, n);
}

int main() {
    int *a, n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    a = (int *)malloc(n * sizeof(int));
    if (a == NULL) {
        printf("Memory not allocated!\n");
        return 1;
    }

    printf("Enter elements: ");
    for (i = 0; i < n; i++) {
        scanf("%d", (a + i));
    }

    selsort(a, 0, n);

    printf("Sorted array: ");
    for (i = 0; i < n; i++) {
        printf("%d ", *(a + i));
    }
    printf("\n");

    free(a);
    return 0;
}

