#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *deleteStart(struct node *head)
{
    struct node *p;
    p=head;
    if(head==NULL)
    {
        printf("The list is already empty");
    }
    else 
    {
        head=head->next;
        free(p);
    }
    return head;
};

int main()
{
    struct node *head, *second, *third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=35;
    head->next=second;

    second->data=45;
    second->next=third;

    third->data=66;
    third->next=NULL;

    head=deleteStart(head);

    return 0;

}
