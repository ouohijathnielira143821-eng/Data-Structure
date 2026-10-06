#include <stdio.h>

int main() {
    int A[3], B[3], C[6];
    int i;

    printf("Enter 3 elements of A:\n");

    for (i = 0; i < 3; i++) {
        scanf("%d", &A[i]);
    }

    printf("Enter 3 elements of B:\n");

    for (i = 0; i < 3; i++) {
        scanf("%d", &B[i]);
    }

    /* Copy A into C */
    for (i = 0; i < 3; i++) {
        C[i] = A[i];
    }

    /* Copy B into C */
    for (i = 0; i < 3; i++) {
        C[i + 3] = B[i];
    }

    printf("\nMerged Array C:\n");

    for (i = 0; i < 6; i++) {
        printf("%d ", C[i]);
    }

    return 0;
}
