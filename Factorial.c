#include <stdio.h>
int factorial(int value)
{
    if (value==0 || value == 1)
    {
        return 1;
    }
    else 
    {
        int fact= value*factorial(value-1);
        return fact;
    }
}

int main ()
{
    int n;
    printf("Enter an integer: ");
    scanf("%d", &n);
    int f= factorial(n);
    printf("Fatorial of %d is %d", n, f);
    return 0; 
}
