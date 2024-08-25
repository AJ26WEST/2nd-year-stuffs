#include <stdio.h>

int main() {
    int limit, num[10], i;
    int flag = 0;
    int searchkey, count = 0, space = 0;

    space = 16 * sizeof(int); // Assuming 4-byte integers

    printf("Enter the limit: "); // Asking the size of the array
    scanf("%d", &limit);
    count += 2;

    printf("Enter the integer numbers:\n");
    count++;
    for (i = 0; i < limit; i++) {
        printf("No%d: ", i + 1);
        scanf("%d", &num[i]);
        count += 3;
    }
    count++;

    printf("Enter the searchkey: "); // Search number
    scanf("%d", &searchkey);
    count += 2;

    for (i = 0; i < limit; i++) {
        if (searchkey == num[i]) { // Check if the current element is equal to the searching number
            flag = 1;
            break;
        }
        count += 4;
    }
    count++;

    if (flag == 1) {
        printf("Element/Number %d is present in the array at position %d.\n", searchkey, i + 1);
        count += 2;
    } else {
        printf("Element/Number %d is not present in the array.\n", searchkey);
        count += 2;
    }

    printf("Space complexity: %d bytes\n", space);
    printf("Time complexity: O(%d)\n", count);

    return 0;
}
