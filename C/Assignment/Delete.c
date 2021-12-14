#include <stdio.h>
int main()
{
    int a[100], n, pos;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    printf("Enter the index to be deleted \n");
    scanf("%d", &pos);
    int del[n - 1];
    int c = 0;
    for (int i = 0; i < n; i++)
    {

        if (i == pos)
            continue;
        else if (i < pos)
        {
            del[c] = a[i];
            c++;
        }
        else if (i > pos)
        {
            del[c] = a[i];
            c++;
        }
    }

    printf("Elements after deletion\n");
    for (int i = 0; i < (n - 1); i++)
        printf("%d\t", del[i]);
    return 0;
}
