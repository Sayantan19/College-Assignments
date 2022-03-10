#include<bits/stdc++.h>
using namespace std;

int ** Generate2AtRandomPosition(int **a)
{
    int i,j;
    do
    {
        i = (rand()%4);
        j = (rand()%4);
        if(a[i][j]==0)
        {
            a[i][j] = 2;
            break;
        }
    }while(true);
    return a;    
}

int ** GenerateInitialMatrix(int **a)
{
    a = (int **)malloc(sizeof(int *)*4);
    for(int i=0;i<4;i++)
        a[i] = (int *)malloc(sizeof(int)*4);

    for(int i=0;i<4;i++) 
        for(int j=0;j<4;j++)
            a[i][j] = 0;
    a = Generate2AtRandomPosition(a);
    a = Generate2AtRandomPosition(a);
    return a;
}

void display(int ** a)
{
    for(int i=0;i<4;i++) 
    {
        for(int j=0;j<4;j++)
            cout<<a[i][j]<<"\t";
        cout<<"\n";
    }
}
int main()
{
    srand(time(0));
    int **a = GenerateInitialMatrix(a);
    display(a);
    return 0;
}