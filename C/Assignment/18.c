/*Write a menu driven C program to take input of an array and then to perform the following operation on it: (all operations are to be performed using separate functions)
a.	Searching for a given element
b.	Sorting the array in ascending order
c.	Sorting the array in descending order
d.	Inserting a new element into the array as taken from the user.
e.	Delete an element from the array whose index will be given by the user.
f.	Exit*/

#include <stdio.h>
int Search(int[], int);
int AscSort(int[], int);
int DescSort(int[], int);
int Insert(int[], int);
int Del(int[], int);

int main()
{
    int arr[100], n, choice;
    printf("Enter the number of elements in the array\n");
    scanf("%d", &n);
    printf("Enter the elements of the array\n");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter your choice \n");
    scanf("%d", &choice);
    switch (choice)
    {
    case 1:
        Search(arr, n);
        break;
    case 2:
        AscSort(arr, n);
        break;
    case 3:
        DescSort(arr, n);
        break;
    case 4:
        Insert(arr, n);
        break;
    case 5:
        Del(arr, n);
        break;
    default:
        printf("Exit");
    }
    return 0;
}
int Search(int a[], int n)
{
    int search;
    printf("Enter the number you want to search\n");
    scanf("%d", &search);
    for (int i = 0; i < n; i++)
    {
        if (a[i] == search)
        {
            printf("Number found at %d ", (i + 1));
            return 0;
        }
    }
    printf("Element does not exist");
    return 0;
}

int AscSort(int a[], int n)
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
    printf("Sorted array int ascending order\n");
    for (int i = 0; i < n; i++)
        printf("%d \t", a[i]);
    return 0;
}

int DescSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int t = 0;
        for (int j = 0; j < n - 1; j++)
        {
            if (a[j] < a[j + 1])
            {
                t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
            }
        }
    }
    printf("Sorted array in descending order\n");
    for (int i = 0; i < n; i++)
        printf("%d \t", a[i]);
    return 0;
}

int Insert(int a[], int n)
{
    int e, pos;
    printf("Enter the value to be inserted \n");
    scanf("%d", &e);
    printf("Enter the position you want to insert it in\n");
    scanf("%d", &pos);
    int ins[n + 1];
    for (int i = 0; i < (n + 1); i++)
    {
        if (i == (pos - 1))
            ins[i] = e;
        else if (i < (pos - 1))
            ins[i] = a[i];
        else if (i > (pos - 1))
            ins[i] = a[i - 1];
    }
    printf("The array after insertion of the element \n");
    for (int i = 0; i <= n; i++)
        printf("%d\t", ins[i]);
    return 0;
}

int Del(int a[], int n)
{
    int pos;
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