#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

struct node *create(int n)
{
    struct node *temp;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = n;
    temp->next = NULL;
    return temp;
}

struct node *insert_end(struct node *start, int n)
{
    struct node *ptr, *fpt = start;
    ptr = (struct node *)malloc(sizeof(struct node));
    if (start == NULL)
    {
        ptr->data = n;
        start = ptr;
        ptr->next = NULL;
        return start;
    }
    while (fpt->next != NULL)
        fpt = fpt->next;
    ptr->data = n;
    fpt->next = ptr;
    ptr->next = NULL;
    return start;
}

void fun(struct node *start)
{
    if (start == NULL)
        return;
    printf("%d ", start->data);

    if (start->next != NULL)
        fun(start->next->next);
    printf("%d ", start->data);
}

void display(struct node *head)
{
    struct node *p;
    p = head;
    if (p == NULL)
    {
        printf("Empty set\n");
        return;
    }
    while (p != NULL)
    {
        printf("%d\n", p->data);
        p = p->next;
    }
}

int main()
{
    struct node *head = NULL;
    head = create(1);
    insert_end(head, 2);
    insert_end(head, 3);
    insert_end(head, 4);
    insert_end(head, 5);
    insert_end(head, 6);
    display(head);
    fun(head);
}