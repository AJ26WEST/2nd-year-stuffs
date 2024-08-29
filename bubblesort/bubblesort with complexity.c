#include <stdio.h>

int main() {
    int n, i, j, temp, count = 0, space;

    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    count += 2;  // 1 for scanf, 1 for assignment of n

    int arr[n];
    space = n * sizeof(int) + 6 * sizeof(int); // Space for array + 3 integer variables

    // Get the elements of the array
    printf("Enter elements:\n");
    count++;  // 1 for the loop initialization
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count += 2;  // 1 for scanf, 1 for array access
    }
    count++;  // 1 for the final condition check of the loop

    // Bubble Sort Algorithm
    for (i = 0; i < n-1; i++) {
        count += 2;  // 1 for the loop initialization, 1 for the final condition check
        for (j = 0; j < n-i-1; j++) {
            count += 2;  // 1 for the loop initialization, 1 for the final condition check

            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                count += 6;  // 1 for comparison, 1 for each assignment (4 total)
            }
        }
    }
    count++;  // 1 for the final condition check of the outer loop

    // Print sorted array
    printf("Sorted array: \n");
    count++;  // 1 for loop initialization
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count += 2;  // 1 for printf, 1 for array access
    }
    count++;  // 1 for the final condition check of the loop
    printf("\n");

    // Output space and time complexity
    printf("Space complexity: %d bytes\n", space);
    printf("Time complexity (in terms of operations): %d\n", count);

    return 0;
}
