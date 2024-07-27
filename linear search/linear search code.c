#include <stdio.h>

void main() {
    int limit, num[10], i;
    int flag = 0;
    int searchkey;

    printf("Enter the limit: "); // Asking the size of the array
    scanf("%d", &limit); 

    printf("Enter the integer numbers:\n");
    for (i = 0; i < limit; i++) {
        printf("No%d: ", i + 1);
        scanf("%d", &num[i]);
    }

    printf("Enter the searchkey: "); // Search number
    scanf("%d", &searchkey);

    for (i = 0; i < limit; i++) {
        if (searchkey == num[i]) { // Check if the current element is equal to the searching number
            flag = 1;
            break;
        }
    }

    if (flag == 1) {
        printf("Element/Number %d is present in the array at position %d.\n", searchkey, i + 1);
    } else {
        printf("Element/Number %d is not present in the array.\n", searchkey);
    }

  
}
