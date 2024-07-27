#include <stdio.h>

void sort(int arr[], int n) {
    int i, j, temp;
    for(i = 0; i < n-1; i++) {
        for(j = i+1; j < n; j++) {
            if(arr[i] > arr[j]) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void main() {
    int i, low, high, mid, n, key, array[100];
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    printf("Enter %d integers:\n", n);
    for(i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Sort the array
    sort(array, n);
    
    printf("Enter value to find: ");
    scanf("%d", &key);
    
    low = 0;
    high = n - 1;
    mid = (low + high) / 2;
    
    while (low <= high) {
        if(array[mid] < key) {
            low = mid + 1;
        } else if (array[mid] == key) {
            printf("%d found at location %d.\n", key, mid + 1);
            break;
        } else {
            high = mid - 1;
        }
        mid = (low + high) / 2;
    }
    
    if(low > high) {
        printf("Not found! %d isn't present in the list.\n", key);
    }
    
    
}
