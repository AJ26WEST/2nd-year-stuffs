#include <stdio.h>

int main() {
    int n, i, j, min, temp;
    int count = 0;  // Counter for time complexity
    int space;      // Variable for space complexity

    // Get the number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);
    count += 2;  // 1 for scanf, 1 for assignment of n

    int arr[n];
    space = n * sizeof(int) + 7 * sizeof(int); // Space for array + 7 integer variables (n, i, j, min, temp)

    // Get the elements of the array
    printf("Enter elements:\n");
    count++;  // 1 for loop initialization
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        count += 2;  // 1 for scanf, 1 for array access
    }
    count++;  // 1 for final condition check of the loop

    // Selection Sort Algorithm
    for (i = 0; i < n-1; i++) {
        min = i;
        count += 2;  // 1 for loop initialization, 1 for assignment to min

        // Find the minimum element in unsorted array
        for (j = i+1; j < n; j++) {
            count += 2;  // 1 for loop initialization, 1 for condition check
            if (arr[j] < arr[min]) {
                min = j;
                count++;  // 1 for assignment to min
            }
        }
        count++;  // 1 for final condition check of the inner loop

        // Swap the found minimum element with the first element
        if (min != i) {
            temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
            count += 4;  // 1 for condition check, 3 for assignments in the swap
        }
    }
    count++;  // 1 for final condition check of the outer loop

    // Print sorted array
    printf("Sorted array: \n");
    count++;  // 1 for loop initialization
    for (i = 0; i < n; i++) {
        printf("%d ", arr[i]);
        count += 2;  // 1 for printf, 1 for array access
    }
    count++;  // 1 for final condition check of the loop
    printf("\n");

    // Output space and time complexity
    printf("Space complexity: %d bytes\n", space);
    printf("Time complexity (in terms of operations): %d\n", count);

    return 0;
}
