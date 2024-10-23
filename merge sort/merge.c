#include <stdio.h>

// Function to merge two subarrays
void merge(int array[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int leftArray[n1], rightArray[n2];

    // Copy data to temporary subarrays leftArray[] and rightArray[]
    for (int i = 0; i < n1; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < n2; j++)
        rightArray[j] = array[mid + 1 + j];

    // Merge the temporary arrays back into array[left..right]
    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2) {
        if (leftArray[i] <= rightArray[j]) {
            array[k] = leftArray[i];
            i++;
        } else {
            array[k] = rightArray[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of leftArray[], if any
    while (i < n1) {
        array[k] = leftArray[i];
        i++;
        k++;
    }

    // Copy the remaining elements of rightArray[], if any
    while (j < n2) {
        array[k] = rightArray[j];
        j++;
        k++;
    }
}

// Function to implement merge sort
void mergeSort(int array[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        // Sort first and second halves
        mergeSort(array, left, mid);
        mergeSort(array, mid + 1, right);

        // Merge the sorted halves
        merge(array, left, mid, right);
    }
}

// Function to print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
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

    // Perform Merge Sort
    mergeSort(array, 0, n - 1);

    printf("Sorted array: ");
    printArray(array, n);

    return 0;
}
