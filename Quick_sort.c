#include <stdio.h>
#include <stdlib.h>

int *a;

void swap(int *start, int *end)
{
    int temp = *start;
    *start = *end;
    *end = temp;
}

int partition(int lb, int ub)
{
    int pivot = a[lb];
    int start = lb, end = ub;

    while (start < end)
    {
        while (start <= ub && a[start] <= pivot)
            start++;

        while (end > lb && a[end] > pivot)
            end--;

        if (start < end)
            swap(&a[start], &a[end]);
    }

    swap(&a[lb], &a[end]);
    return end;
}

void quickSort(int lb, int ub)
{
    if (lb < ub)
    {
        int loc = partition(lb, ub);
        quickSort(lb, loc - 1);
        quickSort(loc + 1, ub);
    }
}

int main()
{
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    if (n <= 0)
        return 1;

    a = malloc(n * sizeof(int));

    if (a == NULL)
        return 1;

    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    quickSort(0, n - 1);

    printf("The sorted array is: ");
    for (int i = 0; i < n; i++)
        printf("%d ", a[i]);

    free(a);
    return 0;
}
