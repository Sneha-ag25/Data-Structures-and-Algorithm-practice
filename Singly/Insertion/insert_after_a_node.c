#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *insertAnywhere(struct node *head, int x, int value)
{
    struct node *p, *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    p=head;
    while(p!=NULL && p->data!=x)
        {
            p=p->next;
        }
    if (p!=NULL && p->data==x)
    {
        new->next=p->next;
        p->next=new;
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

    head=insertAnywhere(head, 45, 76);

    return 0;

}
