#include "Functions.c"

void main()
{
    node *n = NULL;
    node *p = NULL;
    int choice, ch, element;
    do
    {
        printf("1 to create element\n2 to insert element\n3 for Counting Nodes\n4 for Counting leaves\n5 for Counting height\n6 for Deletion an element\n7 for Mirroring\n8 for Displaying In-Order\n9 for Displaying Pre-Order\n10 for Displaying Post Order\n11 for Searching an element\n12 for exit\nEnter your choice: ");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            n = create(element);
            break;
        case 2:
            printf("Enter the element to be inserted: ");
            scanf("%d", &element);
            insert(n, element);
            break;
        case 3:
            printf("Counting nodes\n\n");
            printf("%d\n\n", NodeCount(n));
            break;
        case 4:
            printf("\nCounting leaves\n\n");
            printf("%d\n\n", LeafCount(n));
            break;
        case 5:
            printf("\nCounting height\n\n");
            printf("%d\n\n",height(n)-1);
            break;
        case 6:
            printf("Deleting an element!\n");
            printf("Enter the element to be Deleted: ");
            scanf("%d", &element);
            DeleteNode(n, element);
            break;
        case 7:
            printf("Mirroring the tree\n");
            p = Mirror(n);
            inorder(p);
            break;
        case 8:
            printf("In Order traversal\n");
            inorder(n);
            break;
        case 9:
            printf("Pre Order traversal\n");
            preorder(n);
            break;
        case 10:
            printf("Post Order traversal\n");
            postorder(n);
            break;
        case 11:
            printf("Searching for an element!\n");
            printf("Enter the element to be searched: ");
            scanf("%d", &element);
            search(n, element);
            break;
        case 12:
            printf("\nThank you!\n");
            exit(0);
        }
    } while (1);
}
