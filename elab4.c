#include <stdio.h>
#include <stdlib.h>

void input(long *, int);

int main() {
    int n;

    // Prompt for the number of elements
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Allocating memory for n long integers
    long *ptr = (long *)malloc(n * sizeof(long));

    // Check if malloc succeeded
    if (ptr == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    // Taking input
    input(ptr, n);

    // Freeing the allocated memory
    free(ptr);

    return 0;
}

void input(long *ptr, int n) {
    int i, j;
    long max_and = 0;  // To store the maximum AND result

    // Prompt for array elements
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%ld", &ptr[i]);
    }

    // Find maximum AND result from pairs
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            long temp = ptr[i] & ptr[j];
            // Update max_and if temp is greater
            if (temp > max_and) {
                max_and = temp; // Update max_and if a new max is found
            }
        }
    }

    // Print the maximum AND result
    printf("The maximum AND result is: %ld\n", max_and);
}