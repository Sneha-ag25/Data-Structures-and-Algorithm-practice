#include <stdio.h>
#include <stdlib.h>
struct node{
    int data;
    struct node *next;
};

struct node *insertEnd(struct node *head, int value)
{
    struct node *p, *new;
    new=(struct node*)malloc(sizeof(struct node));
    new->data=value;
    new->next=NULL;
    if(head!=NULL)
    {
        p=head;
        while(p->next!=NULL)
            {
                p=p->next;
            } 
         p->next=new;
    }
    else
        head=new;
    return head;
};

int main()
{
    struct node *head, *second, *third;
    head=(struct node*)malloc(sizeof(struct node));
    second=(struct node*)malloc(sizeof(struct node));
    third=(struct node*)malloc(sizeof(struct node));

    head->data=10;
    head->next=second;

    second->data= 30;
    second->next=third;

    third->data= 40;
    third->next=NULL;

    head=insertEnd(head,35);

    return 0;
}
