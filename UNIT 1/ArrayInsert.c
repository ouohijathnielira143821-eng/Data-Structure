#include <stdio.h>

int main() {
    int a[20], n, i, position, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    printf("Enter value to insert: ");
    scanf("%d", &value);

    printf("Enter position: ");
    scanf("%d", &position);

    /* Shift elements to the right */
    for (i = n; i >= position; i--) {
        a[i] = a[i - 1];
    }

    a[position - 1] = value;
    n++;

    printf("Array after insertion:\n");

    for (i = 0; i < n; i++) {
        printf("%d ", a[i]);
    }

    return 0;
}
