#include <stdio.h>

// Function to perform Insertion Sort
void insertionSort(int array[], int n) {
    for (int i = 1; i < n; i++) {
        int key = array[i];
        int j = i - 1;

        // Move elements of array[0..i-1], that are greater than key, to one position ahead
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j = j - 1;
        }
        array[j + 1] = key;
    }
}

// Function to print the array
void printArray(int array[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input number of elements
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int array[n];

    // Input array elements from user
    printf("Enter %d elements: \n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    printf("Original array: ");
    printArray(array, n);

    // Perform Insertion Sort
    insertionSort(array, n);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
