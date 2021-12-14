//header files
#include<stdio.h>
#include<stdlib.h>

//function prototypes
int ** create(int);
int ** input(int **,int);
int checkLowerTriangular(int **, int);
int checkUpperTriangular(int **, int);
int checkDiagonal(int **, int);
int checkIdentity(int **,int);
int checkTridiagonal(int **,int);
void display(int);

//driver function
int main()
{
    int **arr;
    int n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d",&n);
    arr = create(n);
    printf("Enter the elements of the array\n");
    arr = input(arr,n);
    int choice;
    printf("1 for Lower Triangular Matrix check \n");
    printf("2 for Upper Triangular Matrix check\n");
    printf("3 for Diagonal Matrix check\n");
    printf("4 for Identity matrix check\n");
    printf("5 for Tridiagonal Matrix check\n");
    printf("Enter the condition you want to check for: ");
    scanf("%d",&choice);
    int x;
    switch(choice)
    {
        case 1:
        x = checkLowerTriangular(arr,n);
        display(x);
        break;
        case 2:
        x = checkUpperTriangular(arr,n);
        display(x);
        break;
        case 3:
        x = checkDiagonal(arr,n);
        display(x);
        break;
        case 4:
        x = checkIdentity(arr,n);
        display(x);
        break;
        case 5:
        x = checkTridiagonal(arr,n);
        display(x);
        break;
        default:
        printf("Wrong choice\n");
    }
}

int ** create(int n)
{
    int **a;
    a = (int **)malloc(n * sizeof(int *));
    for(int i=0;i<n;i++)
        a[i] = (int *)malloc(n * sizeof(int));
    return a;
}

int ** input(int **a,int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            scanf("%d",&a[i][j]);
    return a;
}

int checkLowerTriangular(int **a, int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(a[i][j]!=0)
                return 0;
    return 1;
}

int checkUpperTriangular(int **a, int n)
{
    for(int i=1;i<n;i++)
        for(int j=0;j<i;j++)
            if(a[i][j] != 0)
                return 0;
    return 1;
}

int checkDiagonal(int **a, int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(a[i][j]!=0 && i!=j)
                return 0;
    return 1;
}

int checkIdentity(int **a,int n)
{
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
            if(a[i][j]!=0 && i!=j)
                return 0;
            else if(a[i][j] != 1 && i==j)
                return 0;
        }
    return 1;
}

int checkTridiagonal(int **a,int n)
{
    for(int i=0;i<n;i++)
        for(int j=i+2;j<n;j++)
            if(a[i][j]!=0)
                return 0;
    for(int i=2;i<n;i++)
        for(int j=0;j<i-1;j++)
            if(a[i][j] != 0)
                return 0;
    return 1;
}

void display(int n)
{
    if(n==1)
        printf("True\n");
    else
        printf("False\n");
}