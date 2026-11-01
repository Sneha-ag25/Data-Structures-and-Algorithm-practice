#include <stdio.h>
int fibonacci(int value)
{
    if (value==0)
    {
        return 0;
    }
    else if (value==1)
    {
        return 1;
    }
    else 
    {
        return fibonacci(value-1) + fibonacci (value-2);
    }
}
int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d",&n);
    int arr[n];
    printf("Fibonacci series is as follows: ");
    for (int i=0; i<n; i++)
        {
            arr[i]=fibonacci(i);
            printf("%d ",arr[i]);
        }
    return 0;        
}
