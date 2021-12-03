#include<stdio.h>
int a[100], n;
int delete(int *a)
{
    int pos;
    printf("Enter the index to be deleted \n");
    scanf("%d", &pos);
    if(pos>n||pos<0)
    {
        printf("Please choose a correct option\n");
        return 0;
    }
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
    if(n==0)
    {
        printf("No more possible. Thank you\n");
        return 0;
    }
    printf("Elements after deletion\n");
    for (int i = 0; i < c; i++)
        printf("%d\t", del[i]);
    for(int i=0;i<c;i++)
        a[i] = del[i];
    n=c;  
}

void AscSort(int *a)
{
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("Sorted array \n");
    for(int i=0;i<n;i++)
        printf("%d \t",a[i]);
}

int Search(int *a)
{
    int n1=0;
    int f[n1];
    int search;
    printf("Enter the number you want to search\n");
    scanf("%d",&search);
    for(int i=0;i<n;i++)
    {
        if(a[i]==search)
        {
            f[n1] = i+1;
            n1++;
        }
    }
    if(n1==0)
        printf("Element does not exist\n");
    else
    {
        printf("Number found at: ");
        for(int i=0;i<n1;i++)
            printf("%d ",f[i]);
    }
}

int main()
{
    int pos;
    int ch;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    while(1)
    {
        printf("1 for Deleting\n2 for Ascending Sort\n3 for Searching\nEnter your choice: ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            delete(a);
            break;
            case 2:
            AscSort(a);
            break;
            case 3:
            Search(a);
            break;
            default:
            printf("Wrong option\n");
        }
        char choice[1];
        printf("Do you want to continue? [y/n]: ");
        scanf("%s",choice);
        if(choice[0]=='n')
            return 0;
    }
}
