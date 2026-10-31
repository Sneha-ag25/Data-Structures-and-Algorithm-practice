#include<stdio.h>
#include<stdlib.h>

int n, *a;

void merge(int lb, int ub, int mid)
{
    int b[n], k=lb;
    int i=lb, j=mid+1;

    while (i<=mid && j<=ub)
    {
        if (a[i]<a[j])
        {
            b[k]=a[i];
            i++;
        }
        else
        {
            b[k]=a[j];
            j++;
        }
        k++;
    }

    if (i>mid)
    {
        while (j<=ub)
        {
            b[k]=a[j];
            j++;
            k++;
        }
    }
    else if (j>ub)
    {
        while (i<=mid)
        {
            b[k]=a[i];
            i++;
            k++;
        }
    }

    for (i=lb; i<=ub; i++)
    {
        a[i]=b[i];
    }
}

void sort(int lb, int ub)
{
    int mid=(lb+ub)/2;

    if (lb<ub)
    {
        sort(lb, mid);
        sort(mid+1, ub);
        merge(lb,ub,mid);
    }
}

int main()
{
    printf("Enter the number of elements:");
    scanf("%d",&n);

    a = malloc(n * sizeof(int));

    printf("Enter the elements:");
    for (int x=0; x<n; x++)
    {
        scanf("%d", &a[x]);
    }

    printf("Sorted array:");
    sort(0,n-1);

    for(int i=0; i<n; i++)
        printf("%d ",a[i]);

    free(a);
    return 0;
}
