#include <stdio.h>
#include <stdlib.h>
#define COUNT 10

struct node 
{
    int key;
    struct node *left, *right;
};
static int count=0;

struct node *newNode(int item) 
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}

void printPostorder(struct node* root)
{
    if (root != NULL)
    {
        printPostorder(root->left);
        printPostorder(root->right);
        printf(" %d -> ", root->key);
    }
}
void printInorder(struct node *root) 
{
    if (root != NULL) 
    {
        printInorder(root->left);
        printf(" %d -> ", root->key);
        printInorder(root->right);
    }
}

void printPreorder(struct node* root)
{
    if (root != NULL)
    {
        printf(" %d -> ", root->key);
        printPreorder(root->left);
        printPreorder(root->right);
    }
}

struct node *insert(struct node *node, int key) 
{
    if (node == NULL) 
        return newNode(key);
    
    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }
    else
    {
        node->right = insert(node->right, key);
    }
    return node;
}

void search(struct node *root, int item, struct node *temp)
{
    if(root == NULL)
    {
        printf("\n Key not found....");
        return;
    }
    if(root->key == item)
    {
        if(temp == NULL)
        {
            printf("\n The node with key %d is root node. \n", item);
        }
        else if(item < temp->key)
        {
            printf("\n The given key %d is the left node of the node with key %d. \n", item, temp->key);
        }
        else
        {
            printf("\n The given key %d is the left node of the node with key %d. \n", item, temp->key);
        }
    }
    if (item < root->key)
        search(root->left, item, root);
    else 
        search(root->right, item, root);
}

int maxValueNode(struct node *root) 
{
	  if (root == NULL)
        	return -1;
	  int res = root->key;
	  int lres = maxValueNode(root->left);
	  int rres = maxValueNode(root->right);
	  if (lres > res)
		res = lres;
	  if (rres > res)
		res = rres;
	return res;
}

struct node *minValueNode(struct node *node) 
{
	  struct node *current = node;
	  
	  if(current==NULL)
	  	return current;
	  else if (current->left==NULL)
	  	return current;
	  else
	  {
	  	while (current->left != NULL)
	    	current = current->left;
	   }

	  return current;
}

struct node *delete(struct node *root, int key) 
{
	  if (root == NULL) 
	  	return root;

	  if (key < root->key)
	    	root->left = delete(root->left, key);
	  else if (key > root->key)
	    	root->right = delete(root->right, key);

	  else 
	  {
		    if (root->left == NULL) 
		    {
			      struct node *temp = root->right;
			      free(root);
			      return temp;
		    } 
		    else if (root->right == NULL) 
		    {
			      struct node *temp = root->left;
			      free(root);
			      return temp;
		    }
		    struct node *temp = minValueNode(root->right);
		    root->key = temp->key;

		    root->right = delete(root->right, temp->key);
	  }
	  return root;
}

int height(struct node* node)
{
    if (node == NULL)
        return -1;
    else 
    {
        int lh = height(node->left);
        int rh = height(node->right);
        
        if (lh > rh)
            return (lh + 1);
        else
            return (rh + 1);
    }
}

int getLeafCount(struct node* node)
{
	  if(node == NULL)      
	    return 0;
	  if(node->left == NULL && node->right==NULL)     
	    return 1;           
	  else
	    return getLeafCount(node->left)+
		   getLeafCount(node->right);     
}

struct node * mirror(struct node* root) 
{
	  if (root == NULL) 
	    	return root;  
	  else 
	  {
		    struct node* temp;

		    mirror(root->left);			//passing values for change
		    mirror(root->right);

		    temp = root->left;			//swapping
		    root->left = root->right;
		    root->right = temp;
	  }
} 

int countNode(struct node *root)
{
    if(root != NULL)
    {
        countNode(root->left);
        count++;
        countNode(root->right);
    }
    return count;
}

void display(struct node *root, int space)
{
    int i;
    if(root == NULL )        
    	return;
    else
    {
	display(root->right, space+1);
        printf("\n");
        for (i=0; i<space; i++)
        	printf("    ");
        printf("%d", root->key);
        display(root->left, space+1);
    }
}

int main() 
{
    struct node *root = NULL;
    int j, k, n;
    do
    {
        printf("\n\n 1. Insert a value ");
        printf("\n 2. Traverse in (PostOrder, InOrder, PreOrder) ");
        printf("\n 3. Search ");
        printf("\n 4. Deletion ");
        printf("\n 5. Height of Tree ");
        printf("\n 6. Max and Min ");
        printf("\n 7. Count number of leaves ");
        printf("\n 8. Count total nodes ");
        printf("\n 9. Mirror image ");
        printf("\n 10. Display ");        
        printf("\n 11. Exit ");
        printf("\n\n Enter your choice : ");
        scanf("%d", &j);
        switch(j)
        {
            case 1: printf("\n Enter a value : ");
                    scanf("%d", &n);
                    root = insert(root,n);
                            	break;
            case 2: do
            	    {
		    	    printf("\n\t -------TRAVERSAL DISPLAY------- \n");
		    	    printf("\n\n 1. Preorder Traversal");
		    	    printf("\n 2. Inorder Traversal ");
		    	    printf("\n 3. Postorder Traversal ");
		    	    printf("\n 4. Exit ");
		    	    printf("\n\n Enter your choice : ");
		    	    scanf("%d", &k);
			    switch(k)
			    {
			    	case 1: printf("\n Preorder traversal of binary tree is : \n");
		            		printPreorder(root);
		            			break;
		                case 2: printf("\n\n Inorder traversal of binary tree is : \n");
		            		printInorder(root);  
		           			break;
		         	case 3: printf("\n\n Postorder traversal of binary tree is : \n");
				        printPostorder(root);
				               	break;
				case 4: exit(0);
						break;
			    }
		     }
		     while(k!=4);
		    		break;
	    /*case 2: printf("\n Preorder traversal of binary tree is : \n");
                    printPreorder(root);
                    printf("\n\n Inorder traversal of binary tree is : \n");
                    printInorder(root);  
                    printf("\n\n Postorder traversal of binary tree is : \n");
		    printPostorder(root);
		        break;*/		              
            case 3: printf("\n Enter a value to be searched : ");
                    scanf("%d", &n);
                    search(root,n, NULL);
                        break;
            case 4: printf("\n Enter a value to be deleted : ");
            	    scanf("%d", &n);
            	    root = delete(root, n);            	    
            	    	break;
            case 5: printf("\n Height of tree is %d", height(root));
                        break;
            case 6: printf("\n Maximum value is %d", maxValueNode(root));
            	    struct node *p;
            	    p = minValueNode(root);
            	    printf("\n Minimum value is %d", p->key);
                        break;
            case 7: printf("\n Leaf count of the tree is %d", getLeafCount(root));
                        break;
            case 8: printf("\n Number of nodes = %d ",countNode(root));
		    count = 0;
                        break;  
            case 9: //struct node *a;
            	    //a = mirror(root);
            	    printf("\n\n Displaying mirror image : \n");
		    display(mirror(root),0);
                        break;  
            case 10: display(root,0);
                        break;                                                                           	 
            case 11: exit(0);
                        break;
            default: printf("\n Invalid choice....TRY AGAIN !!! \n");
        }
    }
    while(j!=11);
    
    return 0;
}