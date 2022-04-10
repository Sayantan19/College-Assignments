#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
int count(struct node* head)
{
    int c;
    if(head==NULL) return 0;
    else{
        c=0;
        struct node* temp=head;
        while(temp!=NULL)
        {
            c++;
            temp=temp->next;
        }
      return c;  
    }
}
struct node* create_list_of_n_nodes(struct node* head)
{
    int n;
    printf("Enter number of nodes to be inserted:");
    scanf("%d",&n);
    struct node* temp,*change;
    int i;
    if(head!=NULL)
    {
        printf("List already exists");
    }
    else
    {
       
        if(n==1)
        {
            head=(struct node*)malloc(sizeof(struct node));
            head->next=NULL;
            scanf("%d",&head->data);
        }
        else
        {
            for(i=0;i<n;i++)
            {
                temp=(struct node*)malloc(sizeof(struct node));
                temp->next=NULL;
                scanf("%d",&temp->data);
                if(head==NULL)
                {
                    head=temp;
                    change=temp;
                }
                else
                {
                    change->next=temp;
                    change=temp;
                }
            }
        }
    }
    return head;
}
struct node* create_list_of_user_choice(struct node* head)
{
    int c;
    struct node* temp,*change;
    if(head!=NULL)
      printf("List already exists.");
    else
    {
        do{
            temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            scanf("%d",&temp->data);
            if(head==NULL)
            {
                head=temp;
                change=temp;
            }
            else
            {
                change->next=temp;
                change=temp;
            }
            printf("1 for more 0 for none");
            scanf("%d",&c);
        }while(c);
    }
    return head;
}
//***********FUNCTIONS FOR INSERTION OPERATIONS***************
struct node* insert_at_beg(struct node* head)
{
    struct node* temp=NULL;
    if(head==NULL)
    {
        head=(struct node*)malloc(sizeof(struct node));
        head->next=NULL;
        scanf("%d",&head->data);
    }
    else{
    temp=(struct node*)malloc(sizeof(struct node));
    scanf("%d",&temp->data);
    temp->next=head;
    head=temp;
    }
    
return head;    
}
struct node* insert_at_end(struct node* head)
{
    struct node* temp,*change;
    if(head==NULL)
    {
        
        head=(struct node*)malloc(sizeof(struct node));
        head->next=NULL;
        scanf("%d",&head->data);
    }
    else
    {
      temp=(struct node*)malloc(sizeof(struct node));
      temp->next=NULL;
      printf("Enter element to be inserted at the end");
      scanf("%d",&temp->data);
      change=head;
      while(change->next!=NULL)
      {
         change=change->next;
      }
      change->next=temp;
    }
    return head;
}
struct node* insert_at_nth_pos(struct node* head)
{
    struct node* temp,*change;
    int n,i;
    printf("Enter n:");
    scanf("%d",&n);
    if((n<1)||n>count(head)+1)
    {
        printf("Invalid n.Re-enter");
        scanf("%d",&n);
    }
    if(n==1)
    {
        head=insert_at_beg(head);
    }
    else
    {
        change=head;
        for(i=0;i<n-2;i++)
        {
            change=change->next;
        }
        temp=(struct node*)malloc(sizeof(struct node));
        temp->next=NULL;
        printf("Enter value to be inserted:");
        scanf("%d",&temp->data);
        temp->next=change->next;
        change->next=temp;
    }
    return head;
}
struct node* insert_after_n(struct node* head)
{
    struct node* temp,*change;
    printf("Enter the value after which the node will be inserted:");
    int n;
    scanf("%d",&n);
    int flag=0;
    change=head;
    while((change->data!=n)&&(change!=NULL))
    {
        change=change->next;
    }
    if(change==NULL){
        printf("Node with value n doesnt exist");
        return head;
    }
    else{
    temp=(struct node*)malloc(sizeof(struct node));
    temp->next=NULL;
    printf("Enter the element to be inserted:");
    scanf("%d",&temp->data);
    temp->next=change->next;
    change->next=temp;
    }
    return head;
}
struct node* insert_before_n(struct node* head)
{
    struct node* temp,*change;
    printf("Enter the value before which node will be inserted");
    int n;
    scanf("%d",&n);
    if(head->data==n)
        head=insert_at_beg(head);
    else
    {
        change=head;
        while(change->next!=NULL&&change->next->data!=n)
        {
            change=change->next;
        }
        if(change->next==NULL)
        printf("Not Found");
        else
        {
            temp=(struct node*)malloc(sizeof(struct node));
            temp->next=NULL;
            printf("Enter the node");
            scanf("%d",&temp->data);
            temp->next=change->next;
            change->next=temp;
        }
    }
     return head;
}
//***********FUNCTIONS REGARDING DELETION****************
struct node* del_first_node(struct node* head)
{
    struct node*temp;
    temp=head;
    head=head->next;
    free(temp);
    return head;
}
struct node* del_last_node(struct node* head)
{
    struct node*change;
    if(head->next==NULL)
    {
        free(head);
    }
    else
    {
        change=head;
        while(change->next->next!=NULL)
        {
            change=change->next;
        }
        free(change->next);
        change->next=NULL;
    }
    return head;
}
struct node* del_value_n(struct node* head)
{
    struct node* temp,*change;
    int n;
    printf("Enter value to be deleted:");
    scanf("%d",&n);
    if(head->data==n)
    head=del_first_node(head);
    else
    {
        change=head;
        while(change->next!=NULL&&change->next->data!=n)
        {
            change=change->next;
        }
        if(change->next==NULL)
        printf("Node doesnt exist");
        else
        {
            temp=change->next;
            change->next=temp->next;
            free(temp);
        }
    }
    return head;
    
}
struct node* del_before_n(struct node* head)
{
    struct node* temp,*change;
    int n;
    printf("Enter the value before which the node will be deleted");
    scanf("%d",&n);
    if(head->data==n)
    printf("Node doesnt exist");
    if(head->next->data==n)
    head=del_first_node(head);
    else
    {
        change=head;
        while(change->next!=NULL&&change->next->next->data!=n)
        {
            change=change->next;
        }
        if(change->next==NULL)
        {
            printf("Node doesnt exist\n");
        }
        else
        {
            temp=change->next;
            change->next=temp->next;
            free(temp);
        }
    }
    return head;
}
struct node* del_after_n(struct node* head)
{
    struct node* temp,*change;
    change=head;
    int n;
    printf("Enter value after which the node will be deleted");
    scanf("%d",&n);
    while(change!=NULL&&change->data!=n)
    {
        change=change->next;
    }
    if(change==NULL)
    printf("No node with value n exists\n");
    if(change->next==NULL)
    printf("No node present after value n\n");
    else
    {
        temp=change->next;
        change->next=temp->next;
    }
    return head;
}
void search(struct node* head)
{
    struct node* temp;
    int item,i,flag=0;
    temp=head;
    if(temp==NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Enter element to be searched:");
        scanf("%d",&item);
        while(temp!=NULL)
        {
            if(temp->data==item)
            {
                flag=1;
                printf("Element found at %dth position",i+1);
                break;
            }
            i++;
            temp=temp->next;
        }
        if(flag==0)
        {
            printf("Not found\n");
        }
        
    }
}
struct node* reverse_list(struct node* head)
{
    struct node* prev=NULL;
    struct node* change=NULL;
    struct node* curr=head;
    while(curr!=NULL)
    {
        change=curr->next;
        curr->next=prev;
        prev=curr;
        curr=change;
    }
    head=prev;
    return head;
}
void display(struct node* head)
{
     struct node* temp=head;
    while(temp!=NULL)
    {
        printf("\n %d",temp->data);
        temp=temp->next;
    } 
}

int main()
{
    struct node *head=NULL;
    int ch;
    do{
    printf("Select from one of the following options:\n");
    printf("1.Create a list\n");
    printf("2.Insert a node\n");
    printf("3.Delete a node\n");
    printf("4.Display the list\n");
    printf("5.Count the number of nodes\n");
    printf("6.Reverse the list\n");
    printf("7.Search an element in the list\n");
    int ch1;
    scanf("%d",&ch);
    if(ch==1)
    {//CREATION OF LIST
        printf("    Choose from the following:\n");
        printf("    1.Create a list of n nodes\n");
        printf("    2.Create a list based on user choice\n");
     
        scanf("%d",&ch1);
        if(ch1==1)
        {
            head=create_list_of_n_nodes(head);
            display(head);
        }
        else if(ch1==2)
        {
            head=create_list_of_user_choice(head);
            display(head);
        }
    }
    else if(ch==2)
    {//INSERTION
        printf("    Choose from the following:\n");
        printf("    1.Insert at beginning\n");
        printf("    2.Insert at end\n");
        printf("    3.Insert at nth position\n");
        printf("    4.Insert after the node having value n\n");
        printf("    5.Insert before the node having value n\n");
        scanf("%d",&ch1);
        if(ch1==1)
        {
            head=insert_at_beg(head);
            display(head);
        }
        else if(ch1==2)
        {
            head=insert_at_end(head);
            display(head);
        }
        else if(ch1==3)
        {
            head=insert_at_nth_pos(head);
            display(head);
        }
        else if(ch1==4)
        {
            head=insert_after_n(head);
            display(head);
        }
        else if(ch1==5)
        {
            head=insert_before_n(head);
            display(head);
        }
    }
    else if(ch==3)
    {//DELETION
        printf("    Choose from the following:\n");
        printf("    1.Delete the first node\n");
        printf("    2.Delete the last node\n");
        printf("    3.Delete the node having value n\n");
        printf("    4.Delete the node before the node value n\n");
        printf("    5.Delete the node after the node value n\n");
        scanf("%d",&ch1);
        if(ch1==1)
        {
            head=del_first_node(head);
            display(head);
        }
        else if(ch1==2)
        {
            head=del_last_node(head);
            display(head);
        }
        else if(ch1==3)
        {
            head=del_value_n(head);
            display(head);
        }
        else if(ch1==4)
        {
            head=del_before_n(head);
            display(head);
        }
        else if(ch1==5)
        {
            head=del_after_n(head);
            display(head);
        }
    }
    else if(ch==4)
    {//DISPLAY THE LIST
        display(head);
    }
    else if(ch==5)
    {//COUNT OF NODES
        int c=count(head);
        printf("The count of nodes is:%d\n",c);
    }
    else if(ch==6)
    {//REVERSE A LIST
        head=reverse_list(head);
        display(head);
    }
    else if(ch==7)
    {//SEARCHING AN ELEMENT IN THE LIST
        search(head);
    }
    }
    while(ch!=0);
}