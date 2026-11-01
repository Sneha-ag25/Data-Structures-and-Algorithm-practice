#include <stdio.h>

#define MAX 10

int pqueue[MAX];
int size = 0;

void insert(int value)
{
    if (size == MAX)
    {
        printf("Priority queue is full\n");
        return;
    }

    pqueue[size] = value;
    size++;
}

int peek()
{
    if (size == 0)
    {
        printf("Priority queue is empty\n");
        return -1;
    }

    int mvalue = pqueue[0];

    for (int i = 1; i < size; i++)
    {
        if (pqueue[i] > mvalue)
        {
            mvalue = pqueue[i];
        }
    }

    return mvalue;
}

int extractMax()
{
    if (size == 0)
    {
        printf("Priority queue is empty\n");
        return -1;
    }

    int mvalue = pqueue[0];
    int index = 0;

    for (int i = 1; i < size; i++)
    {
        if (pqueue[i] > mvalue)
        {
            mvalue = pqueue[i];
            index = i;
        }
    }

    pqueue[index] = pqueue[size - 1];
    size--;

    return mvalue;
}

int main()
{
    insert(30);
    insert(10);
    insert(50);
    insert(20);

    printf("Maximum value: %d\n", peek());
    printf("Extracted maximum: %d\n", extractMax());
    printf("Maximum after extraction: %d\n", peek());

    return 0;
}
