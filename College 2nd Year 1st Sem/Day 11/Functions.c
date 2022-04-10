#include<stdio.h>
#include<stdlib.h>

//Defining the structure for the nodes of the tree
typedef struct treenode
{
    struct treenode *left;
    int data;
    struct treenode *right;
} node;

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

//Recursively searches for an element and tells whether it is present in the tree or not
int search(node *n, int value)
{
    if (n == NULL)
    {
        printf("Element is not present!\n");
        return -1;
    }
    else if (value < n->data)
        search(n->left, value);
    else if (value > n->data)
        search(n->right, value);
    else if (value == n->data)
        printf("Element present in the tree!\n");
    return 1;
}
//Pre order traversal.
//Order of traversal: Root->left->right
void preorder(node *n)
{
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
    if (n)
    {
        postorder(n->left);
        // printf("\n");
        postorder(n->right);
        printf("%d", n->data);
        printf("\n");
    }
}

//Counts the number of nodes in the tree
int NodeCount(node *n)
{
    int i = 0;
    if (n)
    {
        i++;
        i = i + NodeCount(n->left);
        i = i + NodeCount(n->right);
    }
    else
        return 0;
    return i;
}

//Counts the number of leaves in the node
int LeafCount(node *n)
{
    if(n==NULL)
        return 0;
    if(n->left == NULL && n->right == NULL)
        return 1;
    else
        return LeafCount(n->left) + LeafCount(n->right);
}

//Finds the height of the tree
int height(node * n)
{
    int lh=0,rh=0;
    if(n == NULL)
    {
        return 0;
    }
    else
    {
        lh = height(n->left);
        rh = height(n->right);
        if(lh>rh)
            return lh+1;
        else
            return rh+1;
    }
}

//Checks the largest node in a tree
node * findLargestNode(node *n) 
{
	node * temp = n;
    if(temp==NULL)
        return temp;
    else if(temp->right==NULL)
        return temp;
    else
    {
        while(temp->right!=NULL)
            temp = temp->right;
    }
    return temp;
}

//Deletes an element from the node
node * DeleteNode(node * n, int value)
{
    node * temp = NULL;
    if(n == NULL)
        printf("No element in the tree");
    else if(value < n->data)
        n->left = DeleteNode(n->left,value);
    else if(value > n->data)
        n->right = DeleteNode(n->right,value);
    else if(n->left && n->right)
    {
        temp = findLargestNode(n->left);
        n->data = temp->data;
        n->left = DeleteNode(n->left,temp->data);
    }
    else
    {
        temp = n;
        if(n->left == NULL && n->right == NULL)
            n = NULL;
        else if(n->left = NULL)
            n = n->left;
        else
            n = n->right;
        free(temp);
    }
    return n;
}

//Mirrors the tree
node * Mirror(node * n)
{
    node * p;
    if(n)
    {
        p = NULL;
        Mirror(n->left);			//passing values for change
		Mirror(n->right);

		p = n->left;			//swapping
		n->left = n->right;
		n->right = p;
    }
    return n;
}
