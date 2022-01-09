#include<stdio.h>
#include<stdlib.h>

typedef struct treenode
{
    struct treenode *left;
    int data;  
    struct treenode *right;
}node;

node * create(int n)
{
    node * s = (node *)malloc(sizeof(node));
    s->left = NULL;
    s->data = n;
    s->right = NULL;
    return s;
}

int main()
{
    node * n;
    int choice,ch,element;
    printf("1 to create root\n2 to insert to the left\n3 to insert to the right\nEnter your choice: ");
}