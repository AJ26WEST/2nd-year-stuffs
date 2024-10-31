#include <stdio.h>

int main() {
    int n, i, j, key, count = 0, space;

    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    count += 2;  // 1 for scanf, 1 for assignment of n

    int array[n];  // Ensure n is defined before declaring array

    // Calculate space after array declaration
    space = n * sizeof(int) + 6 * sizeof(int);  // Space for array + other integer variables

    // Get the elements of the array
    printf("Enter elements:\n");
    count++;  // 1 for loop initialization
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
        count += 2;  // 1 for scanf, 1 for array access
    }
    count++;  // 1 for the final condition check of the loop

    // Insertion Sort Algorithm
    for (i = 1; i < n; i++) {
        key = array[i];
        j = i - 1;
        count += 3;  // 1 for loop initialization, 2 for key assignment and j assignment

        // Move elements of array[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
            count += 4;  // 1 for comparison, 1 for j+1 assignment, 1 for array assignment, 1 for j decrement
        }
        array[j + 1] = key;
        count++;  // 1 for the final assignment of key
    }
    count++;  // 1 for the final condition check of the outer loop

    // Print sorted array
    printf("Sorted array: \n");
    count++;  // 1 for loop initialization
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
        count += 2;  // 1 for printf, 1 for array access
    }
    count++;  // 1 for the final condition check of the loop
    printf("\n");

    // Output space and time complexity
    printf("Space complexity: %d bytes\n", space);
    printf("Time complexity (in terms of operations): %d\n", count);

    return 0;
}
