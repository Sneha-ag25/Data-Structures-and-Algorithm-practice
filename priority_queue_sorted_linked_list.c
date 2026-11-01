#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insert(struct node *head, int value)
{
    struct node *ptr, *newnode;

    newnode = malloc(sizeof(struct node));

    if (newnode == NULL)
    {
        printf("Memory allocation failed\n");
        return head;
    }

    newnode->data = value;

    if (head == NULL || head->data < value)
    {
        newnode->next = head;
        return newnode;
    }

    ptr = head;

    while (ptr->next != NULL && ptr->next->data > value)
    {
        ptr = ptr->next;
    }

    newnode->next = ptr->next;
    ptr->next = newnode;

    return head;
}

int peek(struct node *head)
{
    if (head == NULL)
    {
        printf("Priority queue is empty\n");
        return -1;
    }

    return head->data;
}

struct node *extractMAX(struct node *head)
{
    if (head == NULL)
    {
        printf("Priority queue is empty\n");
        return NULL;
    }

    struct node *ptr = head;

    head = head->next;
    free(ptr);

    return head;
}

void display(struct node *head)
{
    while (head != NULL)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}

int main()
{
    struct node *head = NULL;

    head = insert(head, 30);
    head = insert(head, 10);
    head = insert(head, 50);
    head = insert(head, 20);

    printf("Priority queue: ");
    display(head);

    printf("Maximum value: %d\n", peek(head));

    head = extractMAX(head);

    printf("After extraction: ");
    display(head);

    while (head != NULL)
    {
        head = extractMAX(head);
    }

    return 0;
}
