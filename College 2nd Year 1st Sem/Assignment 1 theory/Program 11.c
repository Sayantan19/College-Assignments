#include<stdio.h>   
#include<stdlib.h>

//Structure definition for linked list
struct node   
{  
    int data;   
    struct node *next;  
};

//Front and rear node declaration
struct node *front= NULL;  
struct node *rear= NULL;   

//Queue operations
void enqueue();  
void dequeue();  
void display();  

//Driver function
int main ()  
{  
    int j;   
    do   
    {      
        printf("\n 1. Enqueue an element \n 2. Dequeue an element \n 3. Display the queue \n 4. Exit ");  
        printf("\n\n Enter your choice : ");  
        scanf("%d", &j);  
        switch(j)  
        {  
            case 1:  enqueue();  
            		break;  
            case 2:  dequeue();  
            		break;  
            case 3:  display();  
            		break;  
            case 4:  exit(0);  
            		break;  
            default: printf("\n Invalid choice \n");  
        }  
    }  
    while(j!=4);
    return 0;
}  
void enqueue()  
{  
    struct node *ptr;  
    int item;   
      
    ptr = (struct node *) malloc (sizeof(struct node));  
    if(ptr == NULL)  
    {  
        printf("\n Overflow!\n");  
        return;  
    }  
    else  
    {   
        printf("\n Enter a value to be inserted : ");  
        scanf("%d",&item);  
        ptr -> data = item;  
        if(front == NULL)  
        {  
            front = ptr;  
            rear = ptr;   
            front -> next = NULL;  
            rear -> next = NULL;  
        }  
        else   
        {  
            rear -> next = ptr;  
            rear = ptr;  
            rear->next = NULL;  
        }  
    }  
}     
void dequeue()  
{  
    struct node *ptr;  
    if(front == NULL)  
    {  
        printf("\n OUEUE UNDERFLOW..... \n");  
        return;  
    }  
    else   
    {  
        ptr = front;  
        front = front -> next;  
        printf("\n The popped out value is %d\n", ptr->data);
        free(ptr);  
    }  
}  
void display()  
{  
    struct node *ptr;  
    ptr = front;      
    if(front == NULL)  
    {  
        printf("\n Empty Queue \n");  
    }  
    else  
    {     
        while(ptr != NULL)   
        {  
            printf("\t%d",ptr -> data);  
            ptr = ptr -> next;  
        }  
    }  
}
