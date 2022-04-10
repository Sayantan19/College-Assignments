#include<stdio.h>
#include<stdlib.h>

#define MAX(a,b) ((a>b)?(a):(b)) //Greater than macro
//Matrix Structure definition
struct Matrix
{
    int row;
    int col;
    int** data;
};
typedef struct Matrix mat;


//Basic operations
void choice();
mat * create(mat *,int ,int );
mat * inputDimensions(mat * );
mat * inputElements(mat * );
int isSquareMatrix(mat *);
void display1(mat *);
void display2(int);

//Operations to be chosen by the user
mat * add(mat * ,mat * );
int productPossible(mat *,mat *);
mat * product(mat *,mat *);
int isLowerTriangular(mat * );
int isUpperTriangular(mat * );
int isDiagonal(mat * );
int isIdentity(mat * );
int isTriDiagonal(mat * );

//Driver Function
int main()
{
    choice();
    return 0;
}

//Function to take the choices from the user
void choice()
{
    mat * m1, * m2, * m3;
    int choice,x;
    do
    {
        printf("1 for Matrix Addition\n");
        printf("2 for Matrix Multiplication\n");
        printf("3 for Lower Triangular Matrix check\n");
        printf("4 for Upper Triangular Matrix check\n");
        printf("5 for Diagonal Matrix check\n");
        printf("6 for Identity matrix check\n");
        printf("7 for Tridiagonal Matrix check\n");
        printf("Enter the condition you want to check for: ");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
                printf("Welcome to Matrix Addition\n");
                printf("For the First Matrix:\n");
                m1 = inputDimensions(m1);
                m1 = inputElements(m1);
                printf("For the Second Matrix:\n");
                m2 = inputDimensions(m2);
                m2 = inputElements(m2);
                printf("The sum of the 2 matrices is:\n");
                m3 = add(m1,m2);
                display1(m3);
                break;
            case 2:
                printf("Welcome to Matrix Multiplication\n");
                printf("For First Matrix:\n");
                m1 = inputDimensions(m1);
                printf("For the Second Matrix:\n");
                m2 = inputDimensions(m2);
                if(productPossible(m1,m2))
                {
                    printf("For First Matrix:\n");
                    m1 = inputElements(m1);
                    printf("For the Second Matrix:\n");
                    m2 = inputElements(m2);
                    printf("The product of the 2 matrices is:\n");
                    m3 = product(m1,m2);
                    display1(m3);
                }
                break;
            case 3:
                printf("Welcome to checking Lower Triangular Matrix\n");
                printf("Enter the details of the matrix\n");
                m1 = inputDimensions(m1);
                printf("Checking\n");
                if(isSquareMatrix(m1))
                {
                    m1 = inputElements(m1);
                    x = isLowerTriangular(m1);
                    display2(x);
                }
                break;
            case 4:
                printf("Welcome to checking Upper Triangular Matrix\n");
                printf("Enter the details of the matrix\n");
                m1 = inputDimensions(m1);
                printf("Checking\n");
                if(isSquareMatrix(m1))
                {
                    m1 = inputElements(m1);
                    x = isUpperTriangular(m1);
                    display2(x);
                }
                break;
            case 5:
                printf("Welcome to checking Diagonal Matrix\n");
                printf("Enter the details of the matrix\n");
                m1 = inputDimensions(m1);
                printf("Checking\n");
                if(isSquareMatrix(m1))
                {
                    m1 = inputElements(m1);
                    x = isDiagonal(m1);
                    display2(x);
                }
                break;
            case 6:
                printf("Welcome to checking Identity Matrix\n");
                printf("Enter the details of the matrix\n");
                m1 = inputDimensions(m1);
                printf("Checking\n");
                if(isSquareMatrix(m1))
                {
                    m1 = inputElements(m1);
                    x = isIdentity(m1);
                    display2(x);
                }
                break;
            case 7:
                printf("Welcome to checking Tridiagonal Matrix\n");
                printf("Enter the details of the matrix\n");
                m1 = inputDimensions(m1);
                printf("Checking\n");
                if(isSquareMatrix(m1))
                {
                    m1 = inputElements(m1);
                    x = isTriDiagonal(m1);
                    display2(x);
                }
                break;
            default:
                printf("Wrong choice\n");
        }
        int ch;
        printf("Do you want to continue?[1/0]\n");
        scanf("%d",&ch);
        if(ch==0)
            exit(0);
    }while(1);
}

//Creates memory block for the matrix dynamically
mat * create(mat * m,int row,int col)
{
    //Memory allocation for the structure
    m = (mat *)malloc(sizeof(mat));
    m->row = row;
    m->col = col;

    //Memory allocation for the rows of the matrix
    m->data = (int **)malloc(sizeof(int *)*row);

    //memory allocation for the columns of the matrix
    for(int i=0;i<row;i++)
        m->data[i] = (int *)malloc(sizeof(int)*col);
    
    return m;
}

//Takes the dimenstions of the array from the user
mat * inputDimensions(mat * m)
{
    int r,c;
    //Input the rows and columns of the matrix
    printf("Enter the number of rows of the matrix: ");
    scanf("%d",&r);
    printf("Enter the number of columns of the matrix: ");
    scanf("%d",&c);

    //Creating the memory block for the matrix by dynamic allocation
    m = create(m,r,c);
}

//takes input of the matrix elements from the user
mat * inputElements(mat * m)
{
    //Entering the elements of the array
    printf("Enter the elements of the array\n");
    for(int i=0;i<m->row;i++)
        for(int j=0;j<m->col;j++)
            scanf("%d",&m->data[i][j]);

    return m;
}

//Checks whether the matrix is a square matrix or not
int isSquareMatrix(mat * m)
{
    if(m->row!=m->col)
    {
        printf("Not a square matrix. Checking not possible\n");
        return 0;
    }
    return 1;
}

//display function for sum and product functions
void display1(mat * m)
{
    for (int i = 0; i < m->row; i++)
        {
            for (int j = 0; j < m->col; j++)
                printf("%d\t", m->data[i][j]);
            printf("\n");
        }
}

//display function for other functions
void display2(int n)
{
    if(n==1)
        printf("True\n");
    else
        printf("False\n");
}

//function to add 2 matrices
mat * add(mat * m1,mat * m2)
{
    int r,c;
    r = MAX(m1->row,m2->row);
    c = MAX(m1->col,m2->col);
    mat * m3;
    m3 = create(m3,r,c);
    for(int i=0;i<m3->row;i++)
        for(int j=0;j<m3->col;j++)
                m3->data[i][j] = 0;
    for(int i=0;i<m1->row;i++)
        for(int j=0;j<m1->col;j++)
                m3->data[i][j] += m1->data[i][j];
    for(int i=0;i<m2->row;i++)
        for(int j=0;j<m2->col;j++)
                m3->data[i][j] += m2->data[i][j];
    return m3;
}

//checks whether product of 2 matrices can be possible or not
int productPossible(mat * m1, mat * m2)
{
    if(m1->col==m2->row)
    {
        printf("Can be multiplied\n");
        return 1;
    }
    else
    {
        printf("Cannot be multiplied\n");
        return 0;
    }
}

//finds product of 2 matrices
mat * product(mat * m1, mat * m2)
{
    mat * m3;
        m3 = create(m3,m1->row,m2->col);
    for(int i=0;i<m1->row;i++)
    {
        for(int j=0;j<m2->col;j++)
        {
            m3->data[i][j]==0;
            for(int k=0;k<m1->col;k++)
                m3->data[i][j] += m1->data[i][k] * m2->data[k][j];;
        }
    }
    return m3;
}

//checks whether matrix is Lower triangular or not
int isLowerTriangular(mat * m)
{
    for(int i=0;i<m->row;i++)
        for(int j=i;j<m->col;j++)
            if(m->data[i][j]!=0)
                return 0;
    return 1; 
}

//checks whether matrix is Upper triangular or not
int isUpperTriangular(mat * m)
{
    if(isSquareMatrix(m))
    {
        for(int i=1;i<m->row;i++)
            for(int j=0;j<i;j++)
                if(m->data[i][j] != 0)
                    return 0;
        return 1;
    }
}

//checks whether matrix is a Diagonal matrix or not
int isDiagonal(mat * m)
{
    for(int i=0;i<m->row;i++)
        for(int j=0;j<m->col;j++)
            if(m->data[i][j]!=0 && i!=j)
                return 0;
    return 1;
}

//checks whether matrix is an Identity matrix or not
int isIdentity(mat * m)
{
    int i=0,j=0;
    if(isDiagonal(m))
    {
        while(i<m->row&&j<m->col)
        {
            if(m->data[i][j]!=1)
                return 0;
            i++;
            j++;    
        }
        return 1;
    }
}

//checks whether matrix is a Tridiagonal matrix or not
int isTriDiagonal(mat * m)
{
    for(int i=0;i<m->row;i++)
        for(int j=i+2;j<m->col;j++)
            if(m->data[i][j]!=0)
                return 0;
    for(int i=2;i<m->row;i++)
        for(int j=0;j<i-1;j++)
            if(m->data[i][j] != 0)
                return 0;
    return 1;
}
