#include <stdio.h>

int findMin(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int min = findMin(arr, n - 1);

    if (arr[n - 1] < min)
        return arr[n - 1];
    else
        return min;
}

int findMax(int arr[], int n)
{
    if (n == 1)
        return arr[0];

    int max = findMax(arr, n - 1);

    if (arr[n - 1] > max)
        return arr[n - 1];
    else
        return max;
}

int main()
{
    int arr[100], n, i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Minimum = %d\n", findMin(arr, n));
    printf("Maximum = %d\n", findMax(arr, n));

    return 0;
}
