#include <stdio.h>
#include <stdlib.h>

//Defining the structure for the nodes of the tree
typedef struct treenode
{
    struct treenode *left;
    int data;
    struct treenode *right;
} node;

//function prototypes
node *create(int);
node *insert(node *, int);
void preorder(node *);
void inorder(node *);
void postorder(node *);

//driver function
int main()
{
    node *n;
    int choice, ch, element;
    do{
        printf("1 to create element\n2 to insert element\n3 for Preorder traversal\n4 for Inorder traversal\n5 for Postorder traversal\n6 for exit\nEnter your choice: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:     printf("Enter the element to be inserted: ");
                        scanf("%d",&element);
                        n = create(element);
                        break;
            case 2:     printf("Enter the element to be inserted: ");
                        scanf("%d",&element);
                        insert(n,element);
                        break;
            case 3:     printf("Preorder Traversal\n\n");
                        preorder(n);
                        break;
            case 4:     printf("\nInorder Traversal\n\n");
                        inorder(n);
                        break;
            case 5:     printf("\nPostOrder Traversal\n\n");
                        postorder(n);
                        break;
            case 6:     exit(0);
        }
    }while(1);
    return 0;
}

//Creates memory block for the root/node of the tree, and inserts the root/node element
node *create(int n)
{
    node *s = (node *)malloc(sizeof(node));
    s->left = NULL;
    s->data = n;
    s->right = NULL;
    return s;
}

//function for inserting a value to the node/root.
//for root, it calls the create function directly.
//for nodes, it checks whether the value to be inserted is less than the parent/root.
//if yes, then recursively calls the left node.
//else it recursively calls the right node.
//Eventually it creates a node at the required position and inserts the element in it.

node *insert(node *n, int value)
{
    if (n == NULL)
        return create(value);
    else if (value < n->data)
        n->left = insert(n->left, value);
    else if (value > n->data)
        n->right = insert(n->right, value);
    return n;
}

//Pre order traversal.
//Order of traversal: Root->left->right
void preorder(node *n)
{
    node *p = n;
    if (n)
    {
        printf("%d", n->data);
        // printf("\n");
        printf("\n");
        preorder(n->left);
        preorder(n->right);
    }
    // printf("\n");
}

//in order traversal
//order of traversal: left->root>right
void inorder(node *n)
{
    node *p = n;
    if (n)
    {
        inorder(n->left);
        // printf("\n");
        printf("%d", n->data);
        printf("\n");
        inorder(n->right);
    }
}

//Post order traversal
//Order of traversal: left->right->root
void postorder(node *n)
{
    node *p = n;
    if (n)
    {
        postorder(n->left);
        // printf("\n");
        postorder(n->right);
        printf("%d", n->data);
        printf("\n");
    }
}

