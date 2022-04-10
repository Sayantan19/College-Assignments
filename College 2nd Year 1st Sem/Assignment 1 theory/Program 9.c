#include <stdio.h>
#include <stdlib.h>
#define MAX 7

typedef struct _queue_t 
{
    int *arr;
    int rear, front, count, max;
} queue_t;
 
queue_t *queue_allocate(int n);
void queue_insert(queue_t * q, int v);
int queue_remove(queue_t * q);
int queue_count(queue_t * q);
int queue_is_empty(queue_t * q);

void stack_push(queue_t * q, int v) 
{
    queue_insert(q, v);
}
 
int stack_pop(queue_t * q) 
{
    int i, n = queue_count(q);
    int removed_element;
    for (i = 0; i < (n - 1); i++) 
    {
        removed_element = queue_remove(q);
        queue_insert(q, removed_element);
    }
    removed_element = queue_remove(q);
    return removed_element;
}
 
int stack_is_empty(queue_t * q) 
{
    return queue_is_empty(q);
}
 
int stack_count(queue_t * q) 
{
    return queue_count(q);
}
 
int queue_count(queue_t * q) 
{
    return q->count;
}
 
queue_t *queue_allocate(int n) 
{
    queue_t *queue;
    queue = malloc(sizeof(queue_t));
    if (queue == NULL)
        return NULL;
    queue->max = n;
    queue->arr = malloc(sizeof(int) * n);
    queue->rear = n - 1;
    queue->front = n - 1;
    return queue;
}
 
void queue_insert(queue_t * q, int v) 
{
    if (q->count == q->max)
        return ;
    q->rear = (q->rear + 1) % q->max;
    q->arr[q->rear] = v;
    q->count++;
}
 
int queue_remove(queue_t * q) 
{
    int retval;
    if (q->count == 0)
        return 0;
    q->front = (q->front + 1) % q->max;
    retval = q->arr[q->front];
    q->count--;
    return retval;
}
 
int queue_is_empty(queue_t * q) 
{
    return (q->count == 0);
}
void queue_display(queue_t * q) 
{
    printf("\n\t ____DISPLAYING ELEMENTS____ \n");
    int i = (q->front + 1) % q->max, elements = queue_count(q);
    while (elements--) 
    {
        printf(" \t%d ", q->arr[i]);
        i = (i >= q->max) ? 0 : (i + 1);
    }
}

int main(void) 
{
    queue_t *q;
    int x, j;
    q = queue_allocate(MAX);
    do 
    {
        printf("\n 1. Push \n 2. Pop \n 3. Display \n 4. Exit");
        printf("\n\n Enter your choice : ");
        scanf(" %d", &j);
        switch (j) 
        {
            case 1:
                printf("\n Enter value to Push : ");
                scanf(" %d", &x);
                stack_push(q, x);
                    break;
                    
            case 2:
                x = stack_pop(q);
                if (x == 0)
                    printf("\n QUEUE IS EMPTY..... \n");
                else
                    printf("\n\n Popped Value : %d ", x);
                    break;
     
            case 3:
                queue_display(q);
                    break;
            case 4:
                exit(0);
                    break;
     
            default:
                printf("\n Invalid choice. \n");
        }
    } 
    while (j!=4);
    return 0;
}
