#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *deleteEnd(struct node *head)
{
    struct node *p, *s;
    p=head;
    if(head==NULL)
    {
        printf("The list is empty");
    }
    else if(head->next==NULL)
    {
        free(head);
        head=NULL;
    }
    else 
    {
        while (p->next!=NULL)
            {
                s=p;
                p=p->next;
            }
        s->next=NULL;
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

    head=deleteEnd(head);

    return 0;

}
